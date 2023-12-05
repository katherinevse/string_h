#include <stdio.h>

#include "s21_string.h"

int main(){
    char str[80];
    char str_orig[80];

//    double b = 1;
//    s21_sprintf(str, "%.f", b);
//    sprintf(str_orig, "%.f", b);
    // int c_3, c_3_orig;
    // s21_sprintf(str, "%nqwerty", &c_3);
    // sprintf(str_orig, "%nqwerty", &c_3_orig);
    // printf("%s kek %d\n", str, c_3);
    // printf("%s %d\n", str_orig, c_3_orig);
    int c_2, c_2_orig;
    s21_sprintf(str, "12345%n678910%%", &c_2);
    sprintf(str_orig, "12345%n678910%%", &c_2_orig);
    printf("%s %d\n", str, c_2);
    printf("%s %d", str_orig, c_2_orig);
    return 0;
}