#include "main.h"

/**
 * Print_Char - this function
 * @args: arguments
 *
 * Return: 0
 */
void Print_Char(va_list args) 
{
	char value = va_arg(args, int);
	_putchar(value);
}
