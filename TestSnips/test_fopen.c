/*
 * =====================================================================================
 *
 *       Filename:  test_fopen.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/25/2009 04:34:23 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Guo Shiwei (), guoshiwei@sohu-rd.com
 *        Company:  sohu
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
//     int ret,fd;
//     char buf[1204];
    if(argc != 3){
        fprintf(stderr, "usage: test_fopen file mode\n");
        exit(EXIT_FAILURE);
    }

    FILE *fp = fopen(argv[1], argv[2]);
    if(!fp){
        printf("fopen(%s, %s) failed\n", argv[1], argv[2]);
    }
    else{

        printf("fopen(%s, %s) succeed\n", argv[1], argv[2]);
        fprintf(fp, "%20d %20ld", 300, 10000000);
        fseek(fp, 0, SEEK_SET);
        fprintf(fp, "%20d %20ld", 300, 9);
        int fd = fileno(fp);
        if(fd > 0){
            printf("reading 0 bytes ... \n");
            char buf[1024];
            int ret = read(fd, buf, 0);
            printf("reading 0 bytes end. ret == %d\n", ret);
        }

    }

    getc(stdin);

    return 0;
}
