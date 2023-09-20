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
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", unsigned_print},
		{"x", print_hex},
		{"X", print_HEX},
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
 * get_flag - finds flag functions
 * @s:  format string
 * @params: parameters struct
 * Return: if the flag was valid
 */

int get_flag(char *s, pmtrs_t *params)

{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = params->flag_pls = 1;
			break;
		case ' ':
			i = params->space_flag = 1;
			break;
		case '#':
			i = params->flg_htag = 1;
			break;
		case '-':
			i = params->flg_ms = 1;
			break;
		case '0':
			i = params->flg_z = 1;
			break;
	}
	return (i);
}

/**
 * get_modifier - finds  modifier function
 * @s: string format
 * @params: parameter struct
 * Return: if modifier valid
 */

int get_modifier(char *s, pmtrs_t *params)
{
	int i = 0;

	switch (*s)
	{
		case 'h':
			i = params->modi_h = 1;
			break;
		case 'l':
			i = params->l_modifier = 1;
			break;
	}
	return (i);
}

/**
 * get_width - retrieves width from  format string
 * @s: format string
 * @params: parameters structure
 * @ap: argument pointer
 * Return:a new pointer
 */

char *get_width(char *s, pmtrs_t *params, va_list ap)
{
	int d = 0;

	if (*s == '*')
	{
		d = va_arg(ap, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			d = d * 10 + (*s++ - '0');
	}
	params->width = d;
	return (s);
}
