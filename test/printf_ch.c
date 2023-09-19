#include "main.h"

/**
 * printf_ch - prints a char.
 * @val: arguments.
 * Return: 1.
 */
int printf_ch(va_list val)
{
	char x;

	x = va_arg(val, int);
	_putchar(x);
	return (1);
}
