/*
 * =====================================================================================
 *
 *       Filename:  test_epoll.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/11/2009 02:49:56 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Guo Shiwei (), guoshiwei@sohu-rd.com
 *        Company:  sohu
 *
 * =====================================================================================
 */

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_EVENTS 10
int __set_fd_nonblock(int fd)
{
    int flags = fcntl(fd, F_GETFL);

    if (flags >= 0)
	flags = fcntl(fd, F_SETFL, flags | O_NONBLOCK);

    return flags;
}

int forked = 0;

int do_use_fd(int fd)
{
    char buf[1024];
    int n;

    while ((n = recv(fd, buf, sizeof(buf), 0)) > 0);

    if (n == 0) {
	printf("close fd[%d]\n", fd);
	close(fd);
	return 0;
    }

    if (errno != EAGAIN) {
	perror("recv");
	return -1;
    }

    printf("data recv on fd[%d]\n", fd);
    if (forked) {
	close(fd);
	printf("Forked. Close fd[%d]\n", fd);
    }

    return 0;
}

int main(int argc, char **argv)
{
    struct epoll_event ev, events[MAX_EVENTS];
    int listen_sock, conn_sock, n, nfds, epollfd;
    int flags;
    struct sockaddr_in addr;
    struct sockaddr_in local;
    int addrlen;
    int conn_num = 0;

    listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock < 0) {
	perror("listen_sock");
	exit(EXIT_FAILURE);
    }
    flags = fcntl(listen_sock, F_GETFL);

    if (flags >= 0)
	flags = fcntl(listen_sock, F_SETFL, flags | SO_REUSEADDR);


    addr.sin_family = AF_INET;
    addr.sin_port = 20000;
    addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(listen_sock, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
	perror("bind");
	exit(EXIT_FAILURE);
    }

    if (listen(listen_sock, 100) < 0) {
	perror("listen");
	exit(EXIT_FAILURE);
    }

    /*  Set up listening socket, 'listen_sock' (socket(),
     *                bind(), listen()) */

    epollfd = epoll_create(10);
    if (epollfd == -1) {
	perror("epoll_create");
	exit(EXIT_FAILURE);
    }

    ev.events = EPOLLIN;
    ev.data.fd = listen_sock;
    if (epoll_ctl(epollfd, EPOLL_CTL_ADD, listen_sock, &ev) == -1) {
	exit(EXIT_FAILURE);
    }

    for (;;) {
	nfds = epoll_wait(epollfd, events, MAX_EVENTS, -1);
	if (nfds == -1) {
	    perror("epoll_pwait");
	    exit(EXIT_FAILURE);
	}

	for (n = 0; n < nfds; ++n) {
	    if (events[n].data.fd == listen_sock) {
		conn_sock = accept(listen_sock,
				   (struct sockaddr *) &local, &addrlen);
		if (conn_sock == -1) {
		    perror("accept");
		    exit(EXIT_FAILURE);
		}

		__set_fd_nonblock(conn_sock);
		ev.events = EPOLLIN | EPOLLET;
		ev.data.fd = conn_sock;
		if (epoll_ctl(epollfd, EPOLL_CTL_ADD, conn_sock, &ev) == -1) {
		    perror("epoll_ctl: conn_sock");
		    exit(EXIT_FAILURE);
		}

		printf("new connection on fd[%d], conn_num == %d \n", conn_sock,
		       ++conn_num);
	    } else {
		// Consume bytes in 

		do_use_fd(events[n].data.fd);
	    }
	}

	if (!forked && conn_num > 1) {
	    printf("forking\n");
	    pid_t child = fork();
	    if (child == 0) {
		// child
		while (1) {
		    sleep(10);
		}
	    } else {
		forked = 1;
		printf("forked\n");
	    }
	}
    }
}
