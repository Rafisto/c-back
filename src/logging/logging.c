#include <stdio.h>
#include <stdarg.h>
#include <time.h>

void log_stdout(const char *type, const char *format, ...)
{
    time_t now = time(NULL);
    char buffer[80];

    struct tm *tm_info;
    tm_info = localtime(&now);

    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tm_info);
    printf("[%s] [%s] ", buffer, type);

    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);

    printf("\n");
}
