#ifndef _PRINTF_H_
#define _PRINTF_H_

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define LOWER_CASE	1
#define CONVERT_UNSIGNED 2

#define BUFF_FREE -1
#define OUTPUT_BUFFER 1024

#define NULL_STR "(null)"

#define INIT_PMTRS {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define BUF_FIELD 50

/**
 * struct pmeter - pmeter struct
 *
 * @usg: usg defined
 *
 * @space_flag: flg_sp defined
 * @flag_pls: 	flg_pls defined
 * @flg_z: 	flg_z defined
 * @flg_ms: flg_ms defined
 * @htag_flg:	flg_htag defined
 *
 * @width: field width defined
 * @precision: field defined
 *
 * @modi_h: on if modi_h is specified
 * @modi_l: on if modi_h is specified
 *
 */

typedef struct pmeter
{
	unsigned int usg			: 1;

	unsigned int flg_pls		: 1;
	unsigned int flg_sp		: 1;
	unsigned int flg_htag		: 1;
	unsigned int flg_z		: 1;
	unsigned int flg_ms		: 1;

	unsigned int modi_h		: 1;
	unsigned int modi_l		: 1;

	unsigned int width;
	unsigned int precision;
} pmtrs_t;

/**
 * struct indicator - Struct token
 *
 * @indicator: token for formatt
 * @f: The function called
 */
typedef struct indicator
{
	char *indicator;
	int (*f)(va_list, pmtrs_t *);
} ind_t;

int print_ch(va_list ap, pmtrs_t *prmtr);
int print_integer(va_list ap, pmtrs_t *prmtr);
int print_str1(va_list ap, pmtrs_t *prmtr);
int print_per(va_list ap, pmtrs_t *prmtr);
int print_S0S(va_list ap, pmtrs_t *prmtr);
int (*specifier_get(char *s))(va_list ap, pmtrs_t *prmtr);
int func_get_pr(char *s, va_list ap, pmtrs_t *prmtr);
int flg_get(char *s, pmtrs_t *prmtr);
int modif_get(char *s, pmtrs_t *prmtr);
char *width_get(char *s, pmtrs_t *prmtr, va_list ap);
int hexa_print(va_list ap, pmtrs_t *prmtr);
int HEXA_print(va_list ap, pmtrs_t *prmtr);
int binary_out(va_list ap, pmtrs_t *prmtr);
int octal_out(va_list ap, pmtrs_t *prmtr);
void init_prmtr(pmtrs_t *prmtr, va_list ap);
char *precision_get(char *p, pmtrs_t *prmtr, va_list ap);
int _puts(char *str);
int _putchar(int c);
int _Adigit(int c);
int _strlen(char *s);
int print_num(char *str, pmtrs_t *prmtr);
int print_shift(char *s, pmtrs_t *prmtr);
int print_left_shift(char *s, pmtrs_t *prmtr);
int _printf(const char *format, ...);
int print_w(char *begin, char *end, char *except);
int rev_str(va_list ap, pmtrs_t *prmtr);
int print_root13(va_list ap, pmtrs_t *prmtr);
char *transform(long int num, int base, int flags, pmtrs_t *prmtr);
int unsigned_print(va_list ap, pmtrs_t *prmtr);
int print_locate(va_list ap, pmtrs_t *prmtr);

#endif
