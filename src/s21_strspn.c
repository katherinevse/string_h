#include <stdio.h>
#include <string.h>

int main() {
    const char *str = "abcdV123";
    const char *valid_chars = "abcefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    size_t length = strspn(str, valid_chars);
    
    printf("Длина начального сегмента, состоящего: %zu\n", length);

    return 0;
}


