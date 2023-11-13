#include <s21_string.h>

char *s21_strcpy(char *dest, const char *src){
    size_t i = 0;
    while ((dest[i] = src[i]) != '\0') {
        ++i;
    }
    return dest;


}