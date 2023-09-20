#include "main.h"

/**
 * print_w - prints addresses for char
 * @begin: the address to begin with
 * @end: the address it ends with
 * @except: address with exception
 *
 * Return: no of bytes to be outputted
 */
int print_w(char *begin, char *end, char *except)
{
	int add = 0;

	while (begin <= end)
	{
		if (begin != except)
			add += _putchar(*begin);
		begin++;
	}
	return (add);
}

/**
 * rev_str - outputs a reverse string
 * @ap: stringssssssssssss
 * @prmtr: parameter to a struct
 *
 * Return: number of  bites to print
 */
int rev_str(va_list ap, pmtrs_t *prmtr)
{
	int lenn, add = 0;
	char *str = va_arg(ap, char *);
	(void)prmtr;

	if (str)
	{
		for (lenn = 0; *str; str++)
			lenn++;
		str--;
		for (; lenn > 0; lenn--, str--)
			add += _putchar(*str);
	}
	return (add);
}

/**
 * print_root13 - This prints the string in rot13
 * @ap: still stringssssss
 * @prmtr: parameter to struct
 *
 * Return: no of bites to be printed
 */
int print_root13(va_list ap, pmtrs_t *prmtr)
{
	int i, indice;
	int count = 0;
	char array[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(ap, char *);
	(void)prmtr;

	i = 0;
	indice = 0;
	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] <= 'Z')
		    || (a[i] >= 'a' && a[i] <= 'z'))
		{
			indice = a[i] - 65;
			count += _putchar(array[index]);
		}
		else
			count += _putchar(a[i]);
		i++;
	}
	return (count);
}
