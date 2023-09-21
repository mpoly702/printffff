#include "main.h"

/**
 * Print_String - this function prints a string
 * @args: the argument
 *
 * Return: the length of the string.
 */
void Print_String(va_list args)
{
    char *str = va_arg(args, char *);
    
    if (str == NULL) {
        return; /*Handle NULL pointer gracefully*/
    }

    while (*str != '\0')
    {
        _putchar(*str);
        str++;
    }
}
