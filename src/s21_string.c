//void *memcpy(void *dest, const void *src, size_t n) -Копирует n символов из src в dest

//void *memmove(void *dest, const void *src, size_t n) Еще одна функция для копирования n символов из src в dest.

//void *memset(void *str, int c, size_t n) - 
//strcpy //strncpy

//char *strcat(char *dest, const char *src) -

//strtok //sterror //strcat //strncat
#include "s21_string.h"


s21_size_t s21_strlen(const char *str) {
  s21_size_t answer = 0;
  char *ptr = (char *)str;
  while (*ptr != '\0') {
    answer++;
    ptr++;
  }
  return answer;
}

