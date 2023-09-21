#include "main.h"
/**
 * _printf - is a function that selects the correct function to print.
 * @format: identifier to look for.
 * Return: the length of the string.
 */
int _printf(const char * const format, ...)
{

	va_list args;
    	va_start(args, format);
    	
	while (*format) 
    	{
		int i;

		if (format[i] == '%')/* if a directive ('%') is encountered */
		{
			i++; /* Move to the next character after '%' */
			if (format[i] == 's')
			{
				const char *str = va_arg(args, const char *);
				Print_String(str);
				break;
			}
			else if (format[i] == 'c')
			{
				Print_Char(args);
				break;
			}
			else
			{
				_putchar(format[i]);
			}
		}
		i++;
	}
	va_end(args);
	return(0);
}
