/*
 * =====================================================================================
 *
 *       Filename:  test_statfs.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/24/2009 12:14:35 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Guo Shiwei (), guoshiwei@sohu-rd.com
 *        Company:  sohu
 *
 * =====================================================================================
 */

#include <sys/vfs.h>    /*  or <sys/statfs.h> */
#include <stdlib.h>
#include <stdio.h>

#define GB (1024 * 1024 * 1024)
int main(int argc, char **argv){

    if(argc != 2){
        fprintf(stderr, "usage: %s patch\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    struct statfs s;
    if(statfs(argv[1], &s) < 0){
        perror("statfs");
        exit(EXIT_FAILURE);
    }

    printf("f_type == 0x%X\n"
            "f_bsize == %d\n"
            "f_blocks == %d\n"
            "f_bfree == %d\n"
            "f_bavail == %d\n"
            "f_files == %d\n"
            "f_ffree == %d\n"
            "f_namelen == %d\n",


            s.f_type,     /*  type of filesystem (see below) */
            s.f_bsize,    /*  optimal transfer block size */
            s.f_blocks,   /*  total data blocks in file system */
            s.f_bfree,    /*  free blocks in fs */
            s.f_bavail,   /*  free blocks avail to non-superuser */
            s.f_files,    /*  total file nodes in file system */
            s.f_ffree,    /*  free file nodes in fs */
            s.f_namelen  /*  maximum length of filenames */
          );

    printf("total %dG, free %dG\n",
            s.f_blocks * s.f_bsize / GB,
            s.f_bavail * s.f_bsize / GB);
}
