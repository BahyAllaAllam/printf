#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define NULL_STRING "(null)"

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED  2

/**
 * struct parameters - struct parameters
 * @unsign: unsign
 * @plus_flag: plus_flag
 * @space_flag: space_flag
 * @hashtag_flag: hashtag_flag
 * @zero_flag: zero_flag
 * @minus_flag: minus_flag
 * @width: width
 * @percision: percision
 * @h_modifier: h_modifier
 * @l_modifier: l_modifier
*/
typedef struct parameters
{
	unsigned int unsign         :1;
	unsigned int plus_flag      :1;
	unsigned int space_flag     :1;
	unsigned int hashtag_flag   :1;
	unsigned int zero_flag      :1;
	unsigned int minus_flag     :1;

	unsigned int width;
	unsigned int precision;

	unsigned int h_modifier     :1;
	unsigned int l_modifier     :1;
} params_t;

/**
 * struct specifier - struct specifier
 * @specifier: specifier
 * @f: f
*/
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, params_t *);
} specifier_t;

int _puts(char *str);
int _putchar(int c);

int print_char(va_list ap, params_t *params);
int print_int(va_list ap, params_t *params);
int print_string(va_list ap, params_t *params);
int print_percent(va_list ap, params_t *params);
int print_S(va_list ap, params_t *params);

char *convert(long int n, int b, int f, params_t *params);
int print_unsigned(va_list list, params_t *params);
int print_address(va_list list, params_t *params);

int (*get_specifier(char *s))(va_list ap, params_t *params);
int get_print_func(char *s, va_list ap, params_t *params);
int get_flag(char *s, params_t *params);
int get_modifier(char *s, params_t *params);
int *get_width(char *s, params_t *params, va_list ap);

int print_hex(va_list ap, params_t *params);
int print_HEX(va_list ap, params_t *params);
int print_binary(va_list ap, params_t *params);
int print_octal(va_list ap, params_t *params);

int print_from_to(char *st, char *stp, char *exc);
int print_rev(va_list list, params_t *params);
int print_rot13(va_list list, params_t *params);

int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, params_t *params);
int print_number_right_shift(char *str, params_t *params);
int print_number_left_shift(char *str, params_t *params);

void init_params(params_t *params, va_list ap);

char *get_precision(char *ptr, params_t *params, va_list list);

int _printf(const char *format, ...);

#endif
