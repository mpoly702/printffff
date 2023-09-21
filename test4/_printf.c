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
	
    va_list args;
    va_start(args, format);
	
	char *formatPtr = (char *)format;
	int i;
    for (i = 0; format[i] != '\0'; i++) 
    {
	     if (format[i] == '%')/* if a directive ('%') is encountered */
	     {
		     i++; /* Move to the next character after '%' */
		     if (format[i] == 's')
		     {
			     Print_String(args);
			     break;
		     } else if (format[i] == 'c')
		     {
			     Print_Char(args);
			     break;
		     }
		     else 
		     {
			     _putchar(format[i]);
		     }		
        	format[i + 1]; /* Move to the next character in the format string */
		}
    }
	va_end(args);
}
