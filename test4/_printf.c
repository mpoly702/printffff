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
    while (*formatPtr) 
    {
        if (*formatPtr == '%') 
	{
            formatPtr++; /*Move past the '%'*/
		
		int i;
            for (i = 0; i < 2; i++) 
	    if (*formatPtr == 's') 
	    {
                    Print_String(args);
                    break;
	    } else if (*formatPtr == 'c') 
	    {
                    Print_Char(args);
                    break;
	    }
            else 
	    {
            _putchar(*formatPtr);
	    }
        	formatPtr++; /* Move to the next character in the format string */
	}
    }
	va_end(args);
}
