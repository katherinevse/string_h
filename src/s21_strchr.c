// проверки наличия буквы в другом массиве
// strchr
#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  while (*str != (char)c) {
    if (*str++ == '\0') {
      return 0;
    }
  }
  return (char *)str;
}
// int main() {
//     const char *myString = "Hello, world!";
//     char myChar = 'e';

//     char *result = s21_strchr(myString, myChar);

//     if (result != NULL) {
//         printf("Символ найден: %c\n", *result);
//         printf("Он находится по адресу: %p\n", (void *)result);
//     } else {
//         printf("Символ не найден.\n");
//     }

//     return 0;
// }
