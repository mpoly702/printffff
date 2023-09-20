#include "main.h"

/**
 * precision_get - gets precision from format string
 * @s: string form
 * @prmtr: parameter to struct
 * @ap: pointer to argument
 * Return:new pointer
*/

char *precision_get(char *s, pmtrs_t *prmtr, va_list ap)
{
	int di = 0;

	if (*s != '.')
		return (s);
	s++;
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
	prmtr->precision = d;
	return (s);
}
