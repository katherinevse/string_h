#include "s21_string.h"


char *s21_strchr(const char *str, int c) {
    while (*str != (char)c) {
        if (*str++ == '\0') {
            return 0;
        }
    }
    return (char *)str;
}

//Вычисляет длину строки str, не включая завершающий нулевой символ.
s21_size_t s21_strlen(const char *str) {
  s21_size_t i = 0;
  while (str[i] != '\0') {
    i++;
  }
  return i;
}

//Копирует до n символов из строки, на которую указывает src, в dest.
char *s21_strncpy(char *dest, const char *src, size_t n){
    for (s21_size_t i = 0; i < n; i++)
    {
        dest[i] = src[i];
    }
    return dest;
}

//Копирует символ c (беззнаковый тип) в первые n символов строки, на которую указывает аргумент str.
void *s21_memset(void *str, int c, s21_size_t n) {
    for (s21_size_t i = 0; i < n; i++) {
        ((char *)str)[i] = (char)c;
    }
    return str;
}

//	Еще одна функция для копирования n символов из src в dest.
void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  char *str_dest = (char *)dest;
  char *str_src = (char *)src;
  char str_temp[100] = {0};
  
    s21_memcpy(str_temp, src, n);
    s21_memcpy(dest, str_temp, n);
    return dest;
}

//Копирует n символов из src в dest.
void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  for (s21_size_t i = 0; i < n; i++) {
    *(((char *)dest) + i) = *(((char *)src) + i);
  }
  return dest;
}

// Выполняет поиск последнего вхождения символа c (беззнаковый тип) в строке, на которую указывает аргумент str.
char* s21_strrchr(const char* str, int c) {
  const char* p = str;
  const char* last_occurrence = 0;
  while (*p != '\0') {
    if (*p == c) {
      last_occurrence = p;
    }
    p++;
  }
  return (char*)last_occurrence;
}

// Находит первый символ в строке str1, который соответствует любому символу, указанному в str2.
char *s21_strpbrk(const char *str1, const char *str2) {
  int str1_len = s21_strlen(str1);
  int str2_len = s21_strlen(str2);

  for (int i = 0; i < str1_len; i++) {
    for (int j = 0; j < str2_len; j++) {
      if (str1[i] == str2[j]) {
        return (char *)&str1[i];
      }
    }
  }
  return NULL;
}

// Выполняет поиск первого вхождения символа c (беззнаковый тип) в первых n байтах строки, на которую указывает аргумент str.
void *s21_memchr(const void *str, int c, s21_size_t n) {
  const unsigned char *p = str;
  unsigned char pc = c;
  for (s21_size_t i = 0; i < n; i++) {
    if (p[i] == pc) {
      return (void *)(p + i);
    }
  }
  return NULL;
}

// Находит первое вхождение всей строки needle (не включая завершающий нулевой символ), которая появляется в строке haystack.
char *s21_strstr(const char *haystack, const char *needle) {
  int haystack_len = s21_strlen(haystack);
  int needle_len = s21_strlen(needle);

  for (int i = 0; i <= haystack_len - needle_len; i++) {
    int j;
    for (j = 0; j < needle_len; j++) {
      if (haystack[i + j] != needle[j]) {
        break;
      }
    }
    if (j == needle_len) {
      return (char *)&haystack[i];
    }
  }
  return NULL;
}

//Сравнивает первые n байтов str1 и str2.
int memcmp(const void *str1, const void *str2, s21_size_t n) {
  unsigned char *str_1 = (unsigned char *)str1;
  unsigned char *str_2 = (unsigned char *)str2;
  int result = 0;
  for (int i = 0; result == 0 && str_1[i] != '\0' && i < n; i += 1)
    result = str_1[i] - str_2[i];
  return result;
}

// Вычисляет длину начального сегмента str1, который полностью состоит из символов, не входящих в str2.
s21_size_t s21_strcspn(const char *str1, const char *str2) {
  int len1, len2, i = 0, j = 0;
  s21_size_t result = 0;
  len1 = strlen(str1);
  len2 = strlen(str2);
  while (i < len1) {
    j = 0;
    while (j < len2) {
      if (str1[i] == str2[j]) break;
      j++;
    }
    if (j == len2)
    result++;
    i++;
    break;
  }
  return result;
}

// Сравнивает не более первых n байтов str1 и str2.
int s21_strncmp(const char *str1, const char *str2, size_t n) {
  int i = 0, result = 0, length;
  length = strlen(str1);
  if (strlen(str2) < length) length = strlen(str2);
  while (i < length && i < n) {
    result = str1[i] - str2[i];
    if (result != 0) break;
    i++;
  }
  return result;
}

// Добавляет строку, на которую указывает src, в конец строки, на которую указывает dest, длиной до n символов.
// ФУНКЦИЯ НЕ СООТВЕТСВУЮЕТ ОРИГИНАЛУ!!!!!!
char *s21_strcat(char *dest, const char *src) {
    int dest_len = s21_strlen(dest);
    int i = 0;

    for (; src[i]; i++) {
        dest[dest_len + i] = src[i];
    }

    dest[dest_len + i] = '\0';

    return dest;
}
