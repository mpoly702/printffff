#include "main.h"

/**
 * _printf - prints/input into std output
 * @format: Format of the string
 * Return: no of printed bytes
 */

int _printf(const char *format, ...)

{
	int add = 0;
	va_list ap;
	char *p, *start;

	pmtrs_t prmtr = INIT_PMTRS;

	va_start(ap, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		init_params(&prmtr, ap);
		if (*p != '%')
		{
			add += _putchar(*p);
			continue;
		}
		start = p;
		p++;
		while (flg_get(p, &prmtr))
		{
			p++;
		}
		p = width_get(p, &params, ap);
		p = get_precision(p, &params, ap);
		if (get_modifier(p, &params))
			p++;
		if (!get_specifier(p))
			sum += print_from_to(start, p,
					params.modi_l || params.modi_h ? p - 1 : 0);
		else
			sum += get_print_func(p, ap, &params);
	}
	_putchar(BUFF_FREE);
	va_end(ap);
	return (sum);
}
