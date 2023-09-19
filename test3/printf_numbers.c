#include "main.h"

/**
 * _isdigit - check char is digit
 * @c: char to check
 *
 * Return: 1 if digit,and return 0 if otherwise
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - returns string length
 * @s: string length to check
 *
 * Return: integer length of string
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}

/**
 * print_number - This print a no  with options
 * @str: base no as string
 * @params: parameter structure
 *
 * Return: The character printed
 */
int print_number(char *str, pmtrs_t *params)
{
	unsigned int i = _strlen(str);
	int neg = (!params->usg && *str == '-');

	if (!params->precision && *str == '0' && !str[1])
		str = "";
	if (neg)
	{
		str++;
		i--;
	}
	if (params->precision != UINT_MAX)
		while (i++ < params->precision)
			*--str = '0';
	if (neg)
		*--str = '-';

	if (!params->flg_ms)
		return (print_number_right_shift(str, params));
	else
		return (print_number_left_shift(str, params));
}

/**
 * print_number_right_shift - This prints no with options
 * @str:  base no as  string
 * @params: parameter structure
 *
 * Return: xter printed
 */
int print_number_right_shift(char *str, pmtrs_t *params)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (params->flg_z && !params->flg_ms)
		pad_char = '0';
	neg = neg2 = (!params->usg && *str == '-');
	if (neg && i < params->width && pad_char == '0' && !params->flg_ms)
		str++;
	else
		neg = 0;
	if ((params->flag_pls && !neg2) ||
		(!params->flag_pls && params->space_flag && !neg2))
		i++;
	if (neg && pad_char == '0')
		n += _putchar('-');
	if (params->flag_pls && !neg2 && pad_char == '0' && !params->usg)
		n += _putchar('+');
	else if (!params->flag_pls && params->space_flag && !neg2 &&
		!params->usg && params->flg_z)
		n += _putchar(' ');
	while (i++ < params->width)
		n += _putchar(pad_char);
	if (neg && pad_char == ' ')
		n += _putchar('-');
	if (params->flag_pls && !neg2 && pad_char == ' ' && !params->usg)
		n += _putchar('+');
	else if (!params->flag_pls && params->space_flag && !neg2 &&
		!params->usg && !params->flg_z)
		n += _putchar(' ');
	n += _puts(str);
	return (n);
}

/**
 * print_number_left_shift - prints no with options
 * @str:  base no as string
 * @params: parameter structure
 *
 * Return: printed xter
 */
int print_number_left_shift(char *str, pmtrs_t *params)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (params->flg_z && !params->flg_ms)
		pad_char = '0';
	neg = neg2 = (!params->usg && *str == '-');
	if (neg && i < params->width && pad_char == '0' && !params->flg_ms)
		str++;
	else
		neg = 0;

	if (params->flag_pls && !neg2 && !params->usg)
		n += _putchar('+'), i++;
	else if (params->space_flag && !neg2 && !params->usg)
		n += _putchar(' '), i++;
	n += _puts(str);
	while (i++ < params->width)
		n += _putchar(pad_char);
	return (n);
}
