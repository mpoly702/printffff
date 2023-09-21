#include "main.h"
/**
 * Print_String - print a string.
 * @val: argumen t.
 * Return: the length of the string.
 */

void Print_String(const char *str)
{
    if (str == NULL) 
    {
       str = "(null)";
	    int i, len;
	    
		len = _strlen(s);
		for (i = 0; i < len; i++)
			_putchar(str[i]);
		return (len);
    }
    else
    {
        const char *p; /*Declare the variable before the loop*/
        for (p = str; *p != '\0'; p++)
	{
            putchar(*p);
        }
    }
}
