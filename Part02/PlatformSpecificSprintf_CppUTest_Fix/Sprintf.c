#include <stddef.h>
#include <stdarg.h>
#include <memory.h>
#include <stdio.h>
#include "Sprintf.h"

int PlatformSpecificSprintf(char *str, size_t size, const char *format, ...)
{
    va_list args;
    va_start(args, format);
    size_t count = vsnprintf(str, size, format, args);
    if (size < count)
        return -1;
    else
        return count;
}
