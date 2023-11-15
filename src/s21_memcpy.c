#include "s21_string.h"

//Копирует n символов из src в dest.
void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  for (s21_size_t i = 0; i < n; i++) {
    *(((char *)dest) + i) = *(((char *)src) + i);
  }
  return dest;
}

// void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
//   char *char_dest = (char *)dest;
//   const char *char_src = (const char *)src;

//   for (s21_size_t i = 0; i < n; i++) {
//     char_dest[i] = char_src[i];
//   }

//   return dest;
// }

// #include <stdio.h>

// int main() {
//   char source[] = "Hello, World!";
//   char destination[20];

//   s21_memcpy(destination, source, 13); 

//   // Выводим результат
//   printf("Source: %s\n", source);
//   printf("Destination: %s\n", destination);

//   return 0;
// }
