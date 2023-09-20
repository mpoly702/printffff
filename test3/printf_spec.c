#include "main.h"

/**
 * specifier_get - This finds the function of the format
 * @s: format string
 * Return:number of bytes that was  printed
 */

int (*specifier_get(char *s))(va_list ap, pmtrs_t *prmtr)

{
	ind_t indicators[] = {
		{"c", print_ch},
		{"d", print_integer},
		{"i", print_integer},
		{"s", print_str1},
		{"%", print_per},
		{"b", binary_out},
		{"o", octal_out},
		{"u", unsigned_print},
		{"x", hexa_print},
		{"X", HEXA_print},
		{"p", print_locate},
		{"S", print_SOS},
		{"r", rev_str},
		{"R", print_root13},
		{NULL, NULL}
	};

	int i = 0;

	while (indicators[i].indicator)
	{
		if (*s == indicators[i].indicator[0])
		{
			return (indicators[i].f);
		}
		i++;
	}
	return (NULL);
}

/**
 * func_get_print - this function finds  function format
 * @s: parameter is a string
 * @ap: points to an argument
 * @prmtr:  parameter to a struct
 * Return: number of bytes printed
 */

int func_get_print(char *s, va_list ap, pmtrs_t *prmtr)
{
	int (*f)(va_list, pmtrs_t *) = specifier_get(s);

	if (f)
		return (f(ap, prmtr));
	return (0);
}

/**
 * flg_get - lookup flag functions
 * @s:  format string
 * @prmtr: parameter to struct
 * Return: valid flag
 */

int flg_get(char *s, pmtrs_t *prmtr)

{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = prmtr->flg_pls = 1;
			break;
		case ' ':
			i = prmtr->flg_sp = 1;
			break;
		case '#':
			i = prmtr->flg_htag = 1;
			break;
		case '-':
			i = prmtr->flg_ms = 1;
			break;
		case '0':
			i = prmtr->flg_z = 1;
			break;
	}
	return (i);
}

/**
 * modif_get - searches for modifier function
 * @s: a string
 * @prmtr: parameter to struct
 * Return: valid modifier
 */

int modif_get(char *s, pmtrs_t *prmtr)
{
	int i = 0;

	switch (*s)
	{
		case 'h':
			i = prmtr->modi_h = 1;
			break;
		case 'l':
			i = prmtr->modi_l = 1;
			break;
	}
	return (i);
}

/**
 * width_get - extracts width from  format string
 * @s: format string
 * @prmtr: parameter to struct
 * @ap: argument pointer
 * Return:a new pointer
 */

char *width_get(char *s, pmtrs_t *prmtr, va_list ap)
{
	int di = 0;

	if (*s == '*')
	{
		di = va_arg(ap, int);
		s++;
	}
	else
	{
		while (_Adigit(*s))
			di = di * 10 + (*s++ - '0');
	}
	prmtr->width = d;
	return (s);
}
