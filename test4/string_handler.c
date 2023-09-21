#include "main.h"
/**
 * Print_String - print a string.
 * @val: argumen t.
 * Return: the length of the string.
 */

void Print_String(const char *str)
{
    if (str == NULL) {
        _puts("(null)"); /*Print "(null)" if the string is NULL*/
    } 
    else 
    {
        /*Iterate through the characters of the string and print them*/
        for (const char *p = str; *p != '\0'; p++) 
	{
            _putchar(*p);
        }
    }
}
