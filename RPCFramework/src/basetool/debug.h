#ifndef DEBUG_H_INCLUDED
#define DEBUG_H_INCLUDED

#include <stdarg.h>
#include <stdio.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>

#ifdef __cplusplus
#define DEBUG_EXTERN extern "C" 
#else 
#define DEBUG_EXTERN 
#endif

DEBUG_EXTERN 
void DebugDumpBinary(
	const void*p,
	size_t Size,
	const void* StartingAddress
);

// @return length of the result hex_str
DEBUG_EXTERN size_t bin2hex(const char *p, size_t size, char *hex_str, size_t hex_str_len);
DEBUG_EXTERN void log_printf(FILE* stream, const char* format, ...) __attribute__((format(printf, 2, 3)));

#define LOG_INFO(format, ...) log_printf(stdout, format, ##__VA_ARGS__)
#define LOG_NOTICE(format, ...) log_printf(stderr, format, ##__VA_ARGS__)
#define LOG_WARNING(format, ...) log_printf(stderr, format, ##__VA_ARGS__)
#define LOG_ERROR(format, ...) log_printf(stderr, format, ##__VA_ARGS__)

#ifndef NDEBUG
#define LOG_DEBUG(format, ...) log_printf(stderr, format, ##__VA_ARGS__)
#else
#define LOG_DEBUG(format, ...)
#endif

#define LOG_LEVEL_NULL    0x00
#define LOG_LEVEL_TRACE   0x01
#define LOG_LEVEL_DEBUG   0x02
#define LOG_LEVEL_INFO    0x03
#define LOG_LEVEL_NOTICE  0x04
#define LOG_LEVEL_WARNING 0x05
#define LOG_LEVEL_ERROR   0x06
#define LOG_LEVEL_MASK    0x07
#define LOG_THREAD        0x40

DEBUG_EXTERN 
void std_log_printf(unsigned int flags, FILE* fp, const char *format, ...);

#define STD_LOG(flags, format, ...) std_log_printf(flags, stderr, format, ##__VA_ARGS__)
#define STD_LOG_LINE(flags, format, ...) std_log_printf(flags, stderr, "[%s:%s:%d] "format, __FILE__, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);

#ifndef NDEBUG
#define DEBUG_STD_LOG(flags, format, ...) std_log_printf(flags, stderr, format, ##__VA_ARGS__)
#define DEBUG_STD_LOG_LINE(flags, format, ...) std_log_printf(flags, stderr, format, "[%s:%s:%d] "format, __FILE__, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);
#else
#define DEBUG_STD_LOG(flags, format, ...)
#define DEBUG_STD_LOG_LINE(flags, format, ...)
#endif

#ifndef NDEBUG
#define LOG_TRACE(format, ...) std_log_printf(LOG_LEVEL_TRACE, stderr, format, ##__VA_ARGS__)
#else
#define LOG_TRACE(format, ...)
#endif

DEBUG_EXTERN void set_min_log_level(int level);

static inline void debug_break(void)
{
    __asm__ __volatile__ ("int $0x3\n");
}

#endif//DEBUG_H_INCLUDED

