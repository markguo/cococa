#ifndef DEBUG_H_INCLUDED
#define DEBUG_H_INCLUDE

#include <stdarg.h>
#include <stdio.h>
#include <ace/Log_Record.h>

#ifdef __cplusplus
extern "C" {
#endif

void DebugDumpBinary(
        FILE *stream, 
	const void*p,
	size_t Size,
	const void* StartingAddress
);

void log_printf_priority(FILE *stream, unsigned int priority, const char * format, ...);
void log_printf(FILE* stream, const char* format, ...) __attribute__((format(printf, 2, 3)));

void debug_break(void);

#ifdef __cplusplus
}
#endif

#ifndef NDEBUG

#define SSLOG_PREFIX "[%s:%d]: "

#define SSLOG_INFO(format, ...)	        log_printf_priority(stderr, LM_INFO, SSLOG_PREFIX format "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#define SSLOG_DEBUG(format, ...)	log_printf_priority(stderr, LM_DEBUG, SSLOG_PREFIX format "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#define SSLOG_WARNING(format, ...)	log_printf_priority(stderr, LM_WARNING, SSLOG_PREFIX format "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#define SSLOG_ERROR(format, ...)	log_printf_priority(stderr, LM_ERROR, SSLOG_PREFIX format "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#define HEX_DUMP(buf, size, text) DebugDumpBinary(stderr, buf, size, text)

#else

#define SSLOG_INFO(format, ...)	        log_printf_priority(stderr, LM_INFO, format "\n", ##__VA_ARGS__)
#define SSLOG_DEBUG(format, ...)	
#define SSLOG_WARNING(format, ...)	log_printf_priority(stderr, LM_WARNING, format "\n", ##__VA_ARGS__)
#define SSLOG_ERROR(format, ...)	log_printf_priority(stderr, LM_ERROR, format "\n", ##__VA_ARGS__)
#define HEX_DUMP(buf, size, text)
#endif

bool LogInit(const char * log_file);

/// Only output error log.
void TurnOffDebugLog();

#endif//DEBUG_H_INCLUDED

