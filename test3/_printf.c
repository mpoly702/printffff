#include "main.h"

/**
 * _printf - prints string to std output
 * @format: the string format
 * Return: no of printed bytes
 */

int _printf(const char *format, ...)

{
	int add = 0;
	va_list ap;
	char *p, *begin;

	pmtrs_t prmtr = INIT_PMTRS;

	va_start(ap, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		init_prmtr(&prmtr, ap);
		if (*p != '%')
		{
			add += _putchar(*p);
			continue;
		}
		begin = p;
		p++;
		while (flg_get(p, &prmtr))
		{
			p++;
		}
		p = width_get(p, &params, ap);
		p = precision_get(p, &params, ap);
		if (modif_get(p, &params))
			p++;
		if (!specifier_get(p))
			sum += print_w(begin, p,
					prmtr.modi_l || prmtr.modi_h ? p - 1 : 0);
		else
			add += func_get_pr(p, ap, &prmtr);
	}
	_putchar(BUFF_FREE);
	va_end(ap);
	return (add);
}
