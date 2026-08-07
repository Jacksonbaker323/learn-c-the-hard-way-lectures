#pragma once

#include <stdio.h>

// Log Levels
typedef enum {
    LOG_LEVEL_DEBUG,
    LOG_LEVEL_INFO,
    LOG_LEVEL_WARN,
    LOG_LEVEL_ERROR
} LogLevel;

// Default log level threshold (change at compile or runtime)
#ifndef LOG_LEVEL
#define LOG_LEVEL LOG_LEVEL_INFO
#endif

// ANSI Color Codes for terminal formatting
#define COLOR_RESET  "\x1b[0m"
#define COLOR_DEBUG  "\x1b[36m" // Cyan
#define COLOR_INFO   "\x1b[32m" // Green
#define COLOR_WARN   "\x1b[33m" // Yellow
#define COLOR_ERROR  "\x1b[31m" // Red

#define LOG_MSG(level, color, label, fmt, ...) \
    do { \
        if (level >= LOG_LEVEL) { \
            fprintf(stderr, color "[%-5s]" COLOR_RESET " (%s:%d) " fmt "\n", \
                    label, __FILE__, __LINE__, ##__VA_ARGS__); \
        } \
    } while (0)

#define log_debug(fmt, ...) LOG_MSG(LOG_LEVEL_DEBUG, COLOR_DEBUG, "DEBUG", fmt, ##__VA_ARGS__)
#define log_info(fmt, ...)  LOG_MSG(LOG_LEVEL_INFO,  COLOR_INFO,  "INFO",  fmt, ##__VA_ARGS__)
#define log_warn(fmt, ...)  LOG_MSG(LOG_LEVEL_WARN,  COLOR_WARN,  "WARN",  fmt, ##__VA_ARGS__)
#define log_error(fmt, ...) LOG_MSG(LOG_LEVEL_ERROR, COLOR_ERROR, "ERROR", fmt, ##__VA_ARGS__)


