#include <stdio.h>
#include "Util.h"

static int FormatOutput_Impl(const char * format, ...)
{
    /* To Do Something Here!!! */
    printf("Here we are in the FormatOutput_Impl() function.\n");
    return 0;
}

/*int (*FormatOutput)(const char * format, ...) = FormatOutput_Impl;*/
int (*FormatOutput)(const char * format, ...) = printf;