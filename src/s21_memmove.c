#include "s21_string.h"

//	Еще одна функция для копирования n символов из src в dest.
void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  char *str_dest = (char *)dest;
  char *str_src = (char *)src;
  char str_temp[100] = {0};
  
    s21_memcpy(str_temp, src, n);
    s21_memcpy(dest, str_temp, n);
    return dest;
}
