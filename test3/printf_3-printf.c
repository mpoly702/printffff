#include "main.h"

/**
 * print_char - This prints char
 * @ap: argument pointer
 * @params: parameters structure
 *
 * Return: The no char to be  printed
 */
int print_char(va_list ap, pmtrs_t *params)
{
	char pad_char = ' ';
	unsigned int pad = 1, sum = 0, ch = va_arg(ap, int);

	if (params->flg_ms)
		sum += _putchar(ch);
	while (pad++ < params->width)
		sum += _putchar(pad_char);
	if (!params->flg_ms)
		sum += _putchar(ch);
	return (sum);
}

/**
 * print_int - This  prints  d integer
 * @ap: argument pointer
 * @params: parameters structure
 *
 * Return: no xter  printed
 */
int print_int(va_list ap, pmtrs_t *params)
{
	long l;

	if (params->l_modifier)
		l = va_arg(ap, long);
	else if (params->modi_h)
		l = (short int)va_arg(ap, int);
	else
		l = (int)va_arg(ap, int);
	return (print_number(convert(l, 10, 0, params), params));
}

/**
 * print_string - print the string
 * @ap: This is the argument pointer
 * @params: this is the structure of the parameter
 *
 * Return: The no character to be printed
 */
int print_string(va_list ap, pmtrs_t *params)
{
	char *str = va_arg(ap, char *), pad_char = ' ';
	unsigned int pad = 0, sum = 0, i = 0, j;

	(void)params;
	switch ((int)(!str))
		case 1:
			str = NULL_STR;

	j = pad = _strlen(str);
	if (params->precision < pad)
		j = pad = params->precision;

	if (params->flg_ms)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	while (j++ < params->width)
		sum += _putchar(pad_char);
	if (!params->flg_ms)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	return (sum);
}

/**
 * print_percent - This is to  string
 * @ap: The argument pointer
 * @params: parameters structure
 *
 * Return: no of  printed xter
 */
int print_percent(va_list ap, pmtrs_t *params)
{
	(void)ap;
	(void)params;
	return (_putchar('%'));
}

/**
 * print_S - custom format spec.
 * @ap: The argument pointer
 * @params: structure of the parameter
 *
 * Return: no of character printed
 */
int print_S(va_list ap, pmtrs_t *params)
{
	char *str = va_arg(ap, char *);
	char *hex;
	int sum = 0;

	if ((int)(!str))
		return (_puts(NULL_STR));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			sum += _putchar('\\');
			sum += _putchar('x');
			hex = convert(*str, 16, 0, params);
			if (!hex[1])
				sum += _putchar('0');
			sum += _puts(hex);
		}
		else
		{
			sum += _putchar(*str);
		}
	}
	return (sum);
}
