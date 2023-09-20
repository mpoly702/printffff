#include "main.h"

/**
 * _Adigit - check if character is a digit
 * @ch: character to be checked
 *
 * Return: 1 or 0
 */
int _Adigit(int ch)
{
	return (ch >= '0' && ch <= '9');
}

/**
 * _strlen - returns string length
 * @str: string length to check
 *
 * Return:length of string
 */
int _strlen(char *str)
{
	int i = 0;

	while (*str++)
		i++;
	return (i);
}

/**
 * print_num - This print options with number
 * @s: base number is a string
 * @prmtr: parameter to struct
 *
 * Return: The character to be printed
 */
int print_num(char *str, pmtrs_t *prmtr)
{
	unsigned int i = _strlen(str);
	int gen = (!prmtr->usg && *s == '-');

	if (!prmtr->precision && *s == '0' && !s[1])
		s = "";
	if (gen)
	{
		s++;
		i--;
	}
	if (prmtr->precision != UINT_MAX)
		while (i++ < prmtr->precision)
			*--s = '0';
	if (gen)
		*--s = '-';

	if (!prmtr->flg_ms)
		return (print_shift(s, prmtr));
	else
		return (print_shift(s, prmtr));
}

/**
 * print_shift - This prints numbers with options
 * @s:  base no as  string
 * @prmtr: parameter to struct
 *
 * Return: charactersssss printed
 */
int print_shift(char *s, pmtrs_t *prmtr)
{
	unsigned int n = 0, gen, gen2, i = _strlen(str);
	char pad_ch = ' ';

	if (prmtr->flg_z && !prmtr->flg_ms)
		pad_ch = '0';
	gen = gen2 = (!prmtr->usg && *s == '-');
	if (gen && i < prmtr->width && pad_ch == '0' && !prmtr->flg_ms)
		s++;
	else
		gen = 0;
	if ((prmtr->flg_pls && !gen2) ||
		(!prmtr->flg_pls && prmtr->flg_sp && !gen2))
		i++;
	if (gen && pad_ch == '0')
		n += _putchar('-');
	if (prmtr->flg_pls && !gen2 && pad_ch == '0' && !prmtr->usg)
		n += _putchar('+');
	else if (!prmtr->flg_pls && prmtr->flg_sp && !gen2 &&
		!prmtr->usg && prmtr->flg_z)
		n += _putchar(' ');
	while (i++ < prmtr->width)
		n += _putchar(pad_ch);
	if (gen && pad_ch == ' ')
		n += _putchar('-');
	if (prmtr->flg_pls && !gen2 && pad_ch == ' ' && !prmtr->usg)
		n += _putchar('+');
	else if (!prmtr->flg_pls && prmtr->flg_sp && !gen2 &&
		!prmtr->usg && !prmtr->flg_z)
		n += _putchar(' ');
	n += _puts(s);
	return (n);
}

/**
 * print_left - prints numbers with options
 * @s:  base number as string
 * @prmtr: parameter to struct
 *
 * Return: prints character
 */
int print_left(char *s, pmtrs_t *prmtr)
{
	unsigned int n = 0, gen, gen2, i = _strlen(str);
	char pad_ch = ' ';

	if (prmtr->flg_z && !prmtr->flg_ms)
		pad_ch = '0';
	gen = gen2 = (!prmtr->usg && *s == '-');
	if (gen && i < prmtr->width && pad_ch == '0' && !prmtr->flg_ms)
		s++;
	else
		gen = 0;

	if (prmtr->flg_pls && !gen2 && !prmtr->usg)
		n += _putchar('+'), i++;
	else if (prmtr->flg_sp && !gen2 && !prmtr->usg)
		n += _putchar(' '), i++;
	n += _puts(s);
	while (i++ < prmtr->width)
		n += _putchar(pad_ch);
	return (n);
}
