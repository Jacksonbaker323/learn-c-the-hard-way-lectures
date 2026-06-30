#ifndef LOG_H
#define LOG_H

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <errno.h>

// 1. Define the Log Levels
typedef enum {
    LOG_DEBUG,
    LOG_INFO,
    LOG_WARN,
    LOG_ERROR
} LogLevel;

// 2. Define the Error Cleaner First
// (Must be above log_impl so the compiler knows it exists)
static inline const char* clean_errno(void) {
    return (errno == 0) ? "None" : strerror(errno);
}

// 3. The Unified Background Function
__attribute__((format(printf, 4, 5)))
static inline void log_impl(LogLevel level, const char *file, int line, const char *fmt, ...) {
    const char *level_strings[] = { "DEBUG", "INFO", "WARN", "ERROR" };

    // We weave clean_errno() right into the standard system prefix!
    fprintf(stderr, "[%s] (%s:%d: errno: %s) ", 
            level_strings[level], file, line, clean_errno());

    va_list args;
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);

    fprintf(stderr, "\n");
}

// 4. The Single Unified Macro Wrapper
#define log_msg(level, M, ...) log_impl(level, __FILE__, __LINE__, M __VA_OPT__(,) __VA_ARGS__)

#endif // LOG_H
