#include <stdint.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <stdarg.h>
#include <string.h>

#include "debug.h"

int g_min_log_level = LOG_LEVEL_DEBUG;
void set_min_log_level(int level)
{
    g_min_log_level = level;
}

#define DUMPBIN_ADDRESS_WIDTH	5	// '0000 ', 4 characters and 1 space
#define DUMPBIN_BYTE_PER_LINE	16
#define DUMPBIN_WIDTH_PER_BYTE	3	// 'F0 ', 2 characters and 1 space

static const char* HexAlphabet = "0123456789ABCDEF";
size_t bin2hex(const char *p, size_t size, char *hex_str, size_t hex_str_max)
{
    hex_str_max -= 1;
    size_t hex_str_len = 0;
    for(size_t i = 0; i < size && hex_str_len < hex_str_max; ++i){
	unsigned char cur_char = *(const unsigned char *)(p + i);
	hex_str[hex_str_len] = HexAlphabet[(cur_char >> 4)];
	hex_str[hex_str_len + 1] = HexAlphabet[cur_char &0x0F];
	hex_str_len += 2;
    }

    return hex_str_len;
}

void DebugDumpBinary(
	const void*p,
	size_t Size,
	const void* StartingAddress
)
{
	const unsigned char* Data = (const unsigned char*)p;
	size_t i;

	if(StartingAddress)
	{
		printf("Starting address: %p\n", StartingAddress);
	}

	for(i=0; i<Size; i+=DUMPBIN_BYTE_PER_LINE)
	{
		int j;
		size_t a = (size_t)StartingAddress+i;
	//	uint32_t a = (uint32_t)StartingAddress+i;

		// DebugView display each DbgPrint output in one line,
		// so I gather them in one line
		char Line[
			DUMPBIN_ADDRESS_WIDTH+	// Address width
			DUMPBIN_BYTE_PER_LINE*(DUMPBIN_WIDTH_PER_BYTE+1) // contents
			+1	// tail NULL
			];

		// print the low 2 byte of address 
		Line[0] = HexAlphabet[(a>>12) & 0x0F];
		Line[1] = HexAlphabet[(a>>8) & 0x0F];
		Line[2] = HexAlphabet[(a>>4) & 0x0F];
		Line[3] = HexAlphabet[(a) & 0x0F];
		Line[4] = ' ';

		for(j=0; j<DUMPBIN_BYTE_PER_LINE; ++j)
		{
			size_t HexPos = DUMPBIN_ADDRESS_WIDTH + j*DUMPBIN_WIDTH_PER_BYTE;
			size_t CharPos = 
				DUMPBIN_ADDRESS_WIDTH + 
				DUMPBIN_BYTE_PER_LINE*DUMPBIN_WIDTH_PER_BYTE+
				j;

			if(i+j < Size)
			{
				unsigned char c = Data[i+j];

				Line[HexPos+0] = HexAlphabet[c>>4];
				Line[HexPos+1] = HexAlphabet[c&0x0F];
				Line[HexPos+2] = ' ';
				Line[CharPos] = isprint(c) ? c : '.';

				if(j==8)
					Line[HexPos-1] = '-';
			}
			else
			{
				Line[HexPos+0] = ' ';
				Line[HexPos+1] = ' ';
				Line[HexPos+2] = ' ';
				Line[CharPos] = ' ';
			}
		}
		Line[sizeof(Line)-1] = 0;
		printf("%s\n", Line);
	}
}

extern "C" void log_printf(FILE* stream, const char* format, ...)
{
	char buf[4096];

	time_t t = time(NULL);
	struct tm tm;
	int len = strftime(buf, sizeof(buf), "[%Y-%m-%d %H:%M:%S] ", localtime_r(&t, &tm));

	va_list va;
	va_start(va, format);
	len += vsnprintf(buf + len, sizeof(buf) - len, format, va);
	va_end(va);
	fwrite(buf, 1, len, stream);
}

extern "C" void std_log_printf(unsigned int flags, FILE* stream, const char* format, ...)
{
	int level = (flags & LOG_LEVEL_MASK);
	if(level < g_min_log_level)
	    return;

	char buf[4096];
	int len = 0;

	static const char *level_literal[] = {"NULL","TRACE","DEBUG","INFO","NOTICE","WARNING","ERROR"};

	time_t t = time(NULL);
	struct tm tm;
	len += strftime(buf + len, sizeof(buf) - len, "[%Y-%m-%d %H:%M:%S] ", localtime_r(&t, &tm));

	if (level > 0)
	{
		len += snprintf(buf + len ,sizeof(buf) - len, "%s ", level_literal[level]);
	}

	va_list va;
	va_start(va, format);
	len += vsnprintf(buf + len, sizeof(buf) - len, format, va);
	va_end(va);
	fwrite(buf, 1, len, stream);
}

