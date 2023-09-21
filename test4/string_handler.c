#include "main.h"
/**
 * Print_String - print a string.
 * @val: argumen t.
 * Return: the length of the string.
 */

int Print_String(const char *str)
{
	int i;
	int len;
	
    if (str == NULL) 
    {
       str = "(null)";
	    
		len = _strlen(str);
		for (i = 0; i < len; i++)
			_putchar(str[i]);
		return(len);
    }
    else
    {
        const char *p; /*Declare the variable before the loop*/
        for (p = str; *p != '\0'; p++)
	{
            putchar(*p);
        }
    }
    return(0);
}
