#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_
#include <stdio.h>
#include <stdlib.h>

#define s21_NULL ((void*)0)
typedef unsigned long s21_size_t;


// Копирует n символов из src в dest.
s21_size_t s21_strlen(const char *str);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);

#endif  // SRC_S21_STRING_H_