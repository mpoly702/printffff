#include "main.h"
/**
 * _printf - is a function that selects the correct function to print.
 * @format: identifier to look for.
 * Return: the length of the string.
 */
int _printf(const char * const format, ...)
{
	 struct SpecifierFunctionMap specifierFunctionMap[] = {
        {'s', Print_String},
        {'c', Print_Char}
  };

void customPrintf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    int i;
  
    while (*format) {
        if (*format == '%') {
            format++; /*Move past the '%'*/
            for (i = 0; i < 2; i++) { // Loop through the specifiers in the struct
                if (*format == specifierFunctionMap[i].specifier) {
                    specifierFunctionMap[i].function(args);
                    break;
                }
            }
        } else {
            _putchar(*format);
        }
        format++; /*Move to the next character in the format string*/
    }

    va_end(args);
}
