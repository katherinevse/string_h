#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define S21_NULL ((void*)0)
typedef unsigned long s21_size_t;



// Копирует n символов из src в dest.

void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memmove(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strcpy(char *dest, const char *src);
char *s21_strncpy(char *dest, const char *src, size_t n);

s21_size_t s21_strlen(const char *str);
char *s21_strchr(const char *str, int c);


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



//sprintf
const char *get_specs(const char *format, Spec *specs);
const char *get_width(const char *format, int *width, va_list *arguments);
const char *set_specs(Spec *specs, const char *format, va_list *arguments);
const char* print_char(char *str,Spec specs,int symbol);
char *print_s(char *str, Spec specs, va_list *arguments);


char *read_spec(char *str, char *src, const char *format, Spec specs, va_list *arguments);

#endif  // SRC_S21_STRING_H_