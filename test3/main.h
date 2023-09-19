#ifndef _PRINTF_H_
#define _PRINTF_H_

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define LOWER_CASE	1
#define CONVERT_UNSIGNED	2

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

int print_char(va_list ap, pmtrs_t *prmtr);
int print_int(va_list ap, pmtrs_t *prmtr);
int print_string(va_list ap, pmtrs_t *prmtr);
int print_percent(va_list ap, pmtrs_t *prmtr);
int print_S(va_list ap, pmtrs_t *prmtr);
int (*get_specifier(char *s))(va_list ap, pmtrs_t *prmtr);
int get_print_func(char *s, va_list ap, pmtrs_t *prmtr);
int get_flag(char *s, pmtrs_t *prmtr);
int get_modifier(char *s, pmtrs_t *prmtr);
char *get_width(char *s, pmtrs_t *prmtr, va_list ap);
int print_hex(va_list ap, pmtrs_t *prmtr);
int print_HEX(va_list ap, pmtrs_t *prmtr);
int print_binary(va_list ap, pmtrs_t *prmtr);
int print_octal(va_list ap, pmtrs_t *prmtr);
void init_params(pmtrs_t *prmtr, va_list ap);
char *get_precision(char *p, pmtrs_t *prmtr, va_list ap);
int _puts(char *str);
int _putchar(int c);
int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, pmtrs_t *prmtr);
int print_number_right_shift(char *str, pmtrs_t *prmtr);
int print_number_left_shift(char *str, pmtrs_t *prmtr);
int _printf(const char *format, ...);
int print_from_to(char *start, char *stop, char *except);
int print_rev(va_list ap, pmtrs_t *prmtr);
int print_rot13(va_list ap, pmtrs_t *prmtr);
char *convert(long int num, int base, int flags, pmtrs_t *prmtr);
int print_unsigned(va_list ap, pmtrs_t *prmtr);
int print_address(va_list ap, pmtrs_t *prmtr);

#endif
