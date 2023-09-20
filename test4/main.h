#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>



typedef struct format {
	char *id;
	int (*f)();
}function_strings;

int _putchar(char c);
void Print_String(va_list args);
void Print_Char(va_list args);

#endif
