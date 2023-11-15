#include "s21_string.h"

//Копирует до n символов из строки, на которую указывает src, в dest.
char *s21_strncpy(char *dest, const char *src, size_t n){
    for (s21_size_t i = 0; i < n; i++)
    {
        dest[i] = src[i];
    }
    return dest;
}


// int main(void){
//     char h[] = "Hellooo";
//     char b[100];

//     s21_strncpy(b, h, 5);
//     printf("%s\n", b);
//     return 0;
// }