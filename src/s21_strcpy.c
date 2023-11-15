#include "s21_string.h"

//не видит strlen

// Копирует строку, на которую указывает src, в dest, включая '\0'
char *s21_strcpy(char *dest, const char *src) {
    s21_size_t i = 0;
    for (; i < s21_strlen(src); i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}


// int main(void){
//     char source[] = "Hello worldsss";
//     char source_2[100];


//     s21_strcpy(source_2, source);
//     printf("%s\n", source);
//     printf("%s\n", source_2);

//     return 0;

// }