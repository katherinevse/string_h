#include "s21_string.h"

//Копирует символ c (беззнаковый тип) в первые n символов строки, на которую указывает аргумент str.
void *s21_memset(void *str, int c, s21_size_t n) {
    for (s21_size_t i = 0; i < n; i++) {
        ((char *)str)[i] = (char)c;
    }
    return str;
}

// void *s21_memset(void *str, int c, s21_size_t n){
//     char *str_str = (char*)str;
//     for (s21_size_t i = 0; i < n; i++)
//     {
//         str_str[i]= (char)c;
//     }
// }

// int main() {
//     char buffer[10]; 

//     s21_memset(buffer, 'A', 10); 

//     // Выводим результат
//     for (int i = 0; i < 10; i++) {
//         printf("%c ", buffer[i]);
//     }
//     printf("\n");

//     return 0;
// }
