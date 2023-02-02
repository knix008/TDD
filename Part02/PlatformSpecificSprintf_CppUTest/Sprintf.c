#include <stddef.h>
#include <stdarg.h>
#include <memory.h>
#include <stdio.h>
#include "Sprintf.h"

int PlatformSpecificSprintf(char *str, size_t size, const char *format, ...)
{
    int result;
    va_list args;
    va_start(args, format);
    memset(str, 0, size);
    result = vsnprintf( str, size-1, format, args); /* For GCC */
    /*result = _vsnprintf( str, size-1, format, args);*/ /* For Visual Studio */
    va_end(args);
    return result;
}
