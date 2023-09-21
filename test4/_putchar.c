#include "main.h"

/**
* _puts - prints the string on a new line
* @str: this is the string to print
*
* Return:( str-a)
*/
int _puts(char *str)
{
char *a = str;/*declaration of variables*/

while (*str)
_putchar(*str++);
return (str - a);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * 
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
