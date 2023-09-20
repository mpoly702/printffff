#include "main.h"

/**
 * hexa_print - prints the  unsigned hexadecimal in lowercase
 * @ap: points to argument
 * @params: parameter to struct
 *
 * Return: This is the number of bytes printed
 */
int hexa_print(va_list ap, pmtrs_t *prmtr)
{
	unsigned long li;
	int ci = 0;
	char *str;

	if (prmtr->modi_l)
		li = (unsigned long)va_arg(ap, unsigned long);
	else if (prmtr->modi_h)
		li = (unsigned short int)va_arg(ap, unsigned int);
	else
		li = (unsigned int)va_arg(ap, unsigned int);

	str = transform(l, 16, UNSIGNED_CONV | LOWER_CASE, prmtr);
	if (prmtr->flg_htag && l)
	{
		*--str = 'x';
		*--str = '0';
	}
	prmtr->usg = 1;
	return (c += print_num(str, prmtr));
}

/**
 * HEXA_print - prints the unsigned hexa number in uppercase
 * @ap: points to argument
 * @params: parameter to struct
 *
 * Return: This is the number of  bytes to print
 */
int HEXA_print(va_list ap, pmtrs_t *prmtr)
{
	unsigned long li;
	int ci = 0;
	char *str;

	if (params->modi_l)
		li = (unsigned long)va_arg(ap, unsigned long);
	else if (prmtr->modi_h)
		li = (unsigned short int)va_arg(ap, unsigned int);
	else
		li = (unsigned int)va_arg(ap, unsigned int);

	str = transform(l, 16, UNSIGNED_CONV, prmtr);
	if (prmtr->flg_htag && l)
	{
		*--str = 'X';
		*--str = '0';
	}
	prmtr->usg = 1;
	return (ci += print_num(str, prmtr));
}
/**
 * binary_out - This prints the  unsigned binary numberssss
 * @ap: points to an argument
 * @prmtr: parameter to a struct
 *
 * Return: bytes printed
 */
int binary_out(va_list ap, pmtrs_t prmtr)
{
	unsigned int n = va_arg(ap, unsigned int);
	char *str = transform(n, 2, UNSIGNED_CONV, prmtr);
	int ci = 0;

	if (prmtr->flg_htag && n)
		*--str = '0';
	prmtr->usg = 1;
	return (c += print_num(str, prmtr));
}

/**
 * octal_out - This prints unsigned octal no
 * @ap: points to argument
 * @prmtr: parameter to struct
 *
 * Return:This is  bytes printed to stdout
 */
int octal_out(va_list ap, pmtrs_t *prmtr)
{
	unsigned long l;
	char *str;
	int c = 0;

	if (prmtr->modi_l)
		li = (unsigned long)va_arg(ap, unsigned long);
	else if (prmtr->modi_h)
		li = (unsigned short int)va_arg(ap, unsigned int);
	else
		li = (unsigned int)va_arg(ap, unsigned int);
	str = transform(l, 8, UNSIGNED_CONV, prmtr);

	if (prmtr->flg_htag && l)
		*--str = '0';
	prmtr->usg = 1;
	return (c += print_num(str, prmtr));
}
