#include <stdio.h>

int main() {
    int printed_chars, scanned_chars;
    char str[20];

    // Пример с выводом
    printed_chars = printf("HI %n", &printed_chars);
    printf("Количество напечатанных символов: %d\n", printed_chars);

    // Пример с вводом
    printf("Введите строку: ");
    scanned_chars = scanf("%s%n", str, &scanned_chars);
    printf("Вы ввели: %s\n", str);
    printf(": %d\n", scanned_chars);

    return 0;
}