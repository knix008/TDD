#include <stdio.h>
#include <stdarg.h>
#include "FormatOutputSpy.h"
#include <stdlib.h>
#include <stdarg.h>

static char *buffer = 0;
static size_t buffer_size = 0;
static int buffer_offset = 0;
static int buffer_used = 0;

void FormatOutputSpy_Create(int size)
{
    FormatOutputSpy_Destroy();
    buffer_size = size + 1;
    buffer = (char *)calloc(buffer_size, sizeof(char));
    buffer_offset = 0;
    buffer_used = 0;
    buffer[0] = '\0';
}

void FormatOutputSpy_Destroy(void)
{
    if (buffer == 0)
        return;

    free(buffer);
    buffer = 0;
}

int FormatOutputSpy(const char *format, ...)
{
    int written_size;
    va_list arguments;
    va_start(arguments, format);
    written_size = vsnprintf(buffer + buffer_offset, buffer_size - buffer_used, format, arguments);
    buffer_offset += written_size;
    buffer_used += written_size;
    va_end(arguments);
    return 1;
}

const char *FormatOutputSpy_GetOutput(void)
{
    return buffer;
}
