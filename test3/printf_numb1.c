#include "main.h"

/**
 * transform - converts functions
 * @num: nnumbbers
 * @base: baseeeeeeeeeeeeee
 * @flgs: argument flag
 * @prmtr: paramater to structure
 *
 * Return: A string
 */
char *transform(long int num, int base, int flgs, pmtrs_t *params)
{
	static char *arr;
	static char buffer[50];
	char sign = 0;
	char *p;
	unsigned long n = num;
	(void)prmtr;

	if (!(flgs & UNSIGNED_CONV) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	arr = flgs & LOWER_CASE ? "0123456789abcdef" : "0123456789ABCDEF";
	p = &buffer[49];
	*p = '\0';

	do	{
		*--p = arr[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--p = sign;
	return (p);
}

/**
 * unsigned_print - This prints unsigned integer numbers
 * @ap: points to an argument
 * @prmtr: parameter to struct
 *
 * Return: bytes printed
 */
int unsigned_print(va_list ap, pmtrs_t *prmtr)
{
	unsigned long li;

	if (prmtr->modif_l)
		li = (unsigned long)va_arg(ap, unsigned long);
	else if (prmtr->modi_h)
		li = (unsigned short int)va_arg(ap, unsigned int);
	else
		li = (unsigned int)va_arg(ap, unsigned int);
	prmtr->usg = 1;
	return (print_num(convert(l, 10, UNSIGNED_CONV, prmtr), prmtr));
}



/**
 * print_locate - This prints the address
 * @ap: pointer to argument
 * @prmtr: parameter to a struct
 *
 * Return: This is the bite to print
 *
 */
int print_address(va_list ap, pmtrs_t *prmtr)
{
	unsigned long int n = va_arg(ap, unsigned long int);
	char *str;

	if (!n)
		return (_puts("(nil)"));

	str = convert(n, 16, UNSIGNED_CONV | LOWER_CASE, prmtr);
	*--str = 'x';
	*--str = '0';
	return (print_num(str, prmtr));
}
