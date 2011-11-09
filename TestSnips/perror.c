#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
        int test = 1;
        int * p_test = &test;
        const int * p_const_int = &test;

        int **pp_test = &p_test;
        const int ** const_pp_test = &p_const_int;
        printf("test == %d\n", **const_pp_test);

        if(argc < 2)
                return 1;

  printf("errno == %s %s\n",
      argv[1], strerror(atoi(argv[1])));
  return 0;
}
