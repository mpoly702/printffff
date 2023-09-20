#include "main.h"

/**
 * print_ch - This prints characters only
 * @ap: points to argument
 * @prmtr: parameters structure
 *
 * Return: character
 */
int print_ch(va_list ap, pmtrs_t *prmtr)
{
	char pad_ch = ' ';
	unsigned int padd = 1, add = 0, ch = va_arg(ap, int);

	if (prmtr->flg_ms)
		add += _putchar(ch);
	while (padd++ < prmtr->width)
		add += _putchar(pad_ch);
	if (!prmtr->flg_ms)
		add += _putchar(ch);
	return (add);
}

/**
 * print_integer - This  prints  d integer
 * @ap: points to the argument
 * @prmtr: parameter for struct
 *
 * Return: nothing outrageous
 */
int print_integer(va_list ap, pmtrs_t *prmtr)
{
	long li;

	if (prmtr->modif_l)
		li = va_arg(ap, long);
	else if (prmtr->modi_h)
		li = (short int)va_arg(ap, int);
	else
		li = (int)va_arg(ap, int);
	return (print_num(transform(li, 10, 0, prmtr), prmtr));
}

/**
 * print_str1 - print the string
 * @ap: points to argument
 * @prmtr: parameter to struct
 *
 * Return: number of characters to be printed
 */
int print_str1(va_list ap, pmtrs_t *prmtr)
{
	char *str = va_arg(ap, char *), pad_ch = ' ';
	unsigned int padd = 0, add = 0, i = 0, j;

	(void)prmtr;
	switch ((int)(!str))
		case 1:
			str = NULL_STR;

	j = padd = _strlen(str);
	if (prmtr->precision < padd)
		j = padd = prmtr->precision;

	if (prmtr->flg_ms)
	{
		if (prmtr->precision != UINT_MAX)
			for (i = 0; i < padd; i++)
				add += _putchar(*str++);
		else
			add += _puts(str);
	}
	while (j++ < prmtr->width)
		add += _putchar(pad_ch);
	if (!prmtr->flg_ms)
	{
		if (prmtr->precision != UINT_MAX)
			for (i = 0; i < padd; i++)
				add += _putchar(*str++);
		else
			add += _puts(str);
	}
	return (add);
}

/**
 * print_per - For strings
 * @ap: points to an argument
 * @prmtr: parameter to struct
 *
 * Return: number of characters
 */
int print_per(va_list ap, pmtrs_t *prmtr)
{
	(void)ap;
	(void)prmtr;
	return (_putchar('%'));
}

/**
 * print_SOS - customized format specification
 * @ap: POINTS TO ARGUMENT
 * @prmtr: struct parameter
 *
 * Return: number of character to be  printed
 */
int print_SOS(va_list ap, pmtrs_t *prmtr)
{
	char *str = va_arg(ap, char *);
	char *hexa;
	int add = 0;

	if ((int)(!str))
		return (_puts(NULL_STR));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			add += _putchar('\\');
			add += _putchar('x');
			hexa = transform(*str, 16, 0, prmtr);
			if (!hexa[1])
				add += _putchar('0');
			add += _puts(hexa);
		}
		else
		{
			add += _putchar(*str);
		}
	}
	return (add);
}
