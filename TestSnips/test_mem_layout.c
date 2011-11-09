/*
 * =====================================================================================
 *
 *       Filename:  test_mem_layout.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2011年01月10日 12时28分07秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Guo Shiwei (), guoshiwei@sohu-rd.com
 *        Company:  sohu
 *
 * =====================================================================================
 */

#include <stdio.h>

struct RequestExtension
{
	unsigned client_id:6;
	unsigned insert_host:1;
	unsigned redirect:1;
}__attribute__((packed));
#define CLIENT_ID_URLLIB    0x30

void TestConstStringMemLayout()
{
    const char * const_string = "This string should in static memory storage.";
}
static const char* HexAlphabet = "0123456789ABCDEF";
size_t bin2hex(const char *p, size_t size, char *hex_str, size_t hex_str_max)
{
    size_t hex_str_len = 0;
    size_t i;

    hex_str_max -= 1;
    for(i = 0; i < size && hex_str_len < hex_str_max; ++i){
	unsigned char cur_char = *(const unsigned char *)(p + i);
	hex_str[hex_str_len] = HexAlphabet[(cur_char >> 4)];
	hex_str[hex_str_len + 1] = HexAlphabet[cur_char &0x0F];
	hex_str_len += 2;
    }

    return hex_str_len;
}

int main()
{
    
    struct RequestExtension ext;
    ext.client_id = 4;
    ext.insert_host = 1;
    ext.redirect = 1;

    char hex_buf[1024];
    size_t hex_len = bin2hex((const char *)&ext, sizeof(ext), hex_buf, sizeof(hex_buf) - 1 );
    hex_buf[hex_len] = 0;
    fprintf(stderr, "client_id=%u insert_host=%d redirect=%d, hex:%s\n",
	    ext.client_id, ext.insert_host, ext.redirect, hex_buf);

//write(1, &ext, sizeof(ext));
    return 0;
}
