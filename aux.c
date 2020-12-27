#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void* fatalError(char* fmt, ...) {
    va_list lst;
    va_start(lst, fmt);
    printf("Fatal error: ");
    vprintf(fmt, lst);
    exit(1);
    return NULL;
}
