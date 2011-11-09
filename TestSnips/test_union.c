#include <stdio.h>
#include <stdint.h>

struct A{
    union{
	uint8_t a;
	uint8_t b;
    };
} __attribute__((packed));

int main()
{
    struct A a;
    printf("sizeof(a)==%lu\n", sizeof(a));
    return 0;
}
