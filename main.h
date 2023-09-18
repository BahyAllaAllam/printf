#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define NULL_STRING "(null)"

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED  2

/**
 * struct flag_parameters - struct parameters
 * @unsign: unsign
 * @plus_flag: plus_flag
 * @space_flag: space_flag
 * @hashtag_flag: hashtag_flag
 * @zero_flag: zero_flag
 * @minus_flag: minus_flag
 * @width: width
 * @precision: precision
 * @h_modifier: h_modifier
 * @l_modifier: l_modifier
*/
typedef struct flag_parameters
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
} flags_t;

/**
 * struct specifier - struct specifier
 * @specifier: specifier
 * @f: f
*/
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, flags_t *);
} spec_t;

int _puts(char *str);
int _putchar(int t);

int print_char(va_list list, flags_t *flags);
int print_int(va_list list, flags_t *flags);
int print_string(va_list list, flags_t *flags);
int print_percent(va_list list, flags_t *flags);
int print_S(va_list list, flags_t *flags);

char *convert(long int n, int b, int f, flags_t *flags);
int print_unsigned(va_list list, flags_t *flags);
int print_address(va_list list, flags_t *flags);

int (*get_specifier(char *ptr))(va_list list, flags_t *flags);
int get_print_func(char *str, va_list list, flags_t *flags);
int get_flag(char *str, flags_t *flags);
int get_modifier(char *str, flags_t *flags);
char *get_width(char *str, flags_t *flags, va_list list);

int print_hex(va_list list, flags_t *flags);
int print_HEX(va_list list, flags_t *flags);
int print_binary(va_list list, flags_t *flags);
int print_octal(va_list list, flags_t *flags);

int print_from_to(char *st, char *stp, char *exc);
int print_rev(va_list list, flags_t *flags);
int print_rot13(va_list list, flags_t *flags);

int _isdigit(int x);
int _strlen(char *s);
int print_number(char *s, flags_t *flags);
int print_number_right_shift(char *s, flags_t *flags);
int print_number_left_shift(char *s, flags_t *flags);

void init_params(flags_t *flags, va_list list);

char *get_precision(char *ptr, flags_t *flags, va_list list);

int _printf(const char *format, ...);

#endif
