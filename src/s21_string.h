#ifndef S21_STRING_H
#define S21_STRING_H
#define ON 1
#define OFF 0
#define BUFF_SIZE 1024

#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define S21_NULL ((void *)0)
typedef unsigned long s21_size_t;

// Основные функции
char *s21_strchr(const char *str, int c);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memmove(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strcpy(char *dest, const char *src);
char *s21_strncpy(char *dest, const char *src, size_t n);
char *s21_strstr(const char *haystack, const char *needle);
void *s21_memchr(const void *str, int c, s21_size_t n);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strerror(int errnum);
s21_size_t s21_strlen(const char *str);
char *s21_strchr(const char *str, int c);
char *s21_strtok(char *str, const char *delim);

typedef struct {
  int minus;  // к левому краю
  int plus;   // знак
  int space;  //+символ под знак
  int hash;  // вывод 16 и 8ричных чисел в формате 0х и 0 соответсвенно
  int full_zero;  // заполнить нулями а не пробелами
  int width;      // ширина после точки
  int accuracy;   // точность
  char length;    // тип переменной ld,lf, Lf и тд
  int number_system;  // система начисления
  int flag_size;  // если число отрицательное или есть + или space
  int dot;         // наличие точки, говорит про  accuracy
  int upper_case;  // если спецификатор - буква в верхнем
  int g;           // спецификатор g
  int e;  // если необходимо запиать число в научной
} Spec;

// sprintf
int s21_sprintf(char *str, const char *format, ...);
const char *get_specs(const char *format, Spec *specs);
const char *get_width(const char *format, int *width, va_list arguments);
const char *set_specs(Spec *specs, const char *format, va_list arguments);
char *read_spec(char *str, char *src, const char *format, Spec specs,
                va_list arguments);

char *print_char(char *str, Spec specs, int symbol);
char *print_s(char *str, Spec specs, va_list arguments);
char *print_p(char *str, Spec *specs, va_list arguments);

s21_size_t get_size_decimal(Spec *specs, long int num);
char *spec_print_u(char *str, Spec specs, char format, va_list arguments);
int decimal_string(Spec specs, long int num, char *str_num,
                   s21_size_t size_decimal);
s21_size_t size_unsigned_decimal(Spec *specs, unsigned long int num);
Spec place_number_system(Spec specs, char format);
char *print_decimal(char *str, Spec specs, va_list arguments);
int decimal_string_helper(Spec specs, long int num, char *str_num,
                          s21_size_t size_decimal, int i);
int decimal_string_zeros(Spec specs, long int num, char *str_num,
                         s21_size_t size_decimal, int i, long int copy_num,
                         int flag);
char get_num_char(int num, int upper_case);
s21_size_t get_size_decimal(Spec *specs, long int num);
s21_size_t get_size_double(Spec *specs, long double num);
Spec cutter(Spec specs, long double num);
long double normalize(long double *number, Spec *specs);
s21_size_t get_size_e_g(Spec *specs, long double number);
char *print_e_g_double(char *str, Spec specs, char format, va_list arguments);
char *print_double(char *str, Spec specs, char format, va_list arguments);
int unsigned_decimal_string(char *buf_str, Spec specs, unsigned long int num,
                            s21_size_t size_num);
int double_string(char *str_num, Spec specs, long double number,
                  s21_size_t size_double);
char *nan_or_inf(char *str, long double number, Spec specs, s21_size_t size);

// Функции тестирования
int s21_strchr_test(const char *str, int symbol);
int s21_strncpy_test(char *dest, const char *src, s21_size_t n);
int s21_memset_test(void *str, int c, s21_size_t n);
int s21_memmove_test(void *dest, const void *src, s21_size_t n);
int s21_memcpy_test(void *dest, const void *src, s21_size_t n);
int s21_strrchr_test(const char *str, int c);
int s21_strpbrk_test(const char *str1, const char *str2);
int s21_memchr_test(const void *str, int c, s21_size_t n);
int s21_strstr_test(const char *haystack, const char *needle);
int s21_strcspn_test(const char *str1, const char *str2);
int s21_strncmp_test(const char *str1, const char *str2, size_t n);
int s21_strncat_test(char *dest, const char *src, s21_size_t n);
int s21_memcmp_test(const void *str1, const void *str2, s21_size_t n);
int s21_strlen_test(const char *str);
int s21_strerror_test(int errornum);

// Функции в стиле C#
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

#endif
