#include "s21_string.h"

//void *str - указатель на блок памяти, который мы хотим заполнить

void *s21_memset(void *str, int c, s21_size_t n) {
    for (s21_size_t i = 0; i < n; i++) {
        ((char *)str)[i] = (char)c;
    }
    return str;
}




