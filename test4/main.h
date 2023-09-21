#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>



struct SpecifierFunctionMap 
{
	char specifier;
	void (*function)(va_list);
};

int _putchar(char c);
int _printf(const char * const format, ...);
int Print_String(va_list args);
void Print_Char(va_list args);
size_t _strlen(const char *str);

#endif
