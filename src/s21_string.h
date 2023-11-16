#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define s21_NULL ((void*)0)
typedef unsigned long s21_size_t;


// Копирует n символов из src в dest.

void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memmove(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strcpy(char *dest, const char *src);
char *s21_strncpy(char *dest, const char *src, size_t n);

s21_size_t s21_strlen(const char *str);
char *s21_strchr(const char *str, int c);

#endif  // SRC_S21_STRING_H_