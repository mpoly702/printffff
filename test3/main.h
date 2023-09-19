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
 * @unsign: usg defined
 *
 * @space_flag: flg_sp defined
 * @plus_flag: flg_pls defined
 * @zero_flag: flg_z defined
 * @minus_flag: flg_ms defined
 * @hashtag_flag: htag_flg defined
 *
 * @width: field width defined
 * @precision: field defined
 *
 * @h_modifier: on if h_modifier is specified
 * @l_modifier: on if l_modifier is specified
 *
 */

typedef struct pmeter
{
	unsigned int usg			: 1;

	unsigned int plus_flag		: 1;
	unsigned int space_flag		: 1;
	unsigned int hashtag_flag	: 1;
	unsigned int zero_flag		: 1;
	unsigned int minus_flag		: 1;

	unsigned int width;
	unsigned int precision;

	unsigned int h_modifier		: 1;
	unsigned int l_modifier		: 1;
} params_t;

/**
 * struct specifier - Struct token
 *
 * @specifier: format token
 * @f: The function associated
 */
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, params_t *);
} specifier_t;

int print_char(va_list ap, params_t *params);
int print_int(va_list ap, params_t *params);
int print_string(va_list ap, params_t *params);
int print_percent(va_list ap, params_t *params);
int print_S(va_list ap, params_t *params);
int (*get_specifier(char *s))(va_list ap, params_t *params);
int get_print_func(char *s, va_list ap, params_t *params);
int get_flag(char *s, params_t *params);
int get_modifier(char *s, params_t *params);
char *get_width(char *s, params_t *params, va_list ap);
int print_hex(va_list ap, params_t *params);
int print_HEX(va_list ap, params_t *params);
int print_binary(va_list ap, params_t *params);
int print_octal(va_list ap, params_t *params);
void init_params(params_t *params, va_list ap);
char *get_precision(char *p, params_t *params, va_list ap);
int _puts(char *str);
int _putchar(int c);
int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, params_t *params);
int print_number_right_shift(char *str, params_t *params);
int print_number_left_shift(char *str, params_t *params);
int _printf(const char *format, ...);
int print_from_to(char *start, char *stop, char *except);
int print_rev(va_list ap, params_t *params);
int print_rot13(va_list ap, params_t *params);
char *convert(long int num, int base, int flags, params_t *params);
int print_unsigned(va_list ap, params_t *params);
int print_address(va_list ap, params_t *params);

#endif
