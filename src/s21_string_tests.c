#include "s21_string.h"
#include <stdio.h>

int s21_strchr_test(const char *str, int symbol);
int s21_strncpy_test(char *dest, const char *src, size_t n);
int s21_memset_test(void *str, int c, s21_size_t n);
int s21_memmove_test(void *dest, const void *src, s21_size_t n);
int s21_memcpy_test(void *dest, const void *src, s21_size_t n);
int s21_strrchr_test(const char *str, int c);
int s21_strpbrk_test(const char *str1, const char *str2);
int s21_memchr_test(const void *str, int c, s21_size_t n);
int s21_strstr_test(const char *haystack, const char *needle);
int s21_strcspn_test(const char *str1, const char *str2);
int s21_strncmp_test(const char *str1, const char *str2, size_t n);
int s21_strcat_test(char *dest, const char *src);

int main(){
    char test[] = "PEPEGA";

    // Вызов тестовых функций для strchr
    if (s21_strchr_test("PEPEGA", 'E') == 1){
        printf("s21_strchr TEST 1 - SUCCESS\n");
    } else {
        printf("s21_strchr TEST 1 - FAIL\n");
    }

    if (s21_strchr_test("PEPEGA", 'e') == 1){
        printf("s21_strchr TEST 2 - SUCCESS\n");
    } else {
        printf("s21_strchr TEST 2 - FAIL\n");
    }

    if (s21_strchr_test("PEPEGA", 'L') == 1){
        printf("s21_strchr TEST 3 - SUCCESS\n");
    } else {
        printf("s21_strchr TEST 3 - FAIL\n");
    }

    if (s21_strchr_test("PEPEGA", '2') == 1){
        printf("s21_strchr TEST 4 - SUCCESS\n");
    } else {
        printf("s21_strchr TEST 4 - FAIL\n");
    }

    if (s21_strchr_test("PEPEGA", '%') == 1){
        printf("s21_strchr TEST 5 - SUCCESS\n");
    } else {
        printf("s21_strchr TEST 5 - FAIL\n");
    }

    printf("\n");

    //Вызов тестовых функция для strcpy
    if (s21_strncpy_test(test, "STAREGA", 3) == 1){
        printf("s21_strncpy TEST 1 - SUCCESS\n");
    } else {
        printf("s21_strncpy TEST 1 - FAIL\n");
    }

    if (s21_strncpy_test(test, "STAREGA", 4) == 1){
        printf("s21_strncpy TEST 2 - SUCCESS\n");
    } else {
        printf("s21_strncpy TEST 2 - FAIL\n");
    }

    if (s21_strncpy_test(test, "STAREGA", 1) == 1){
        printf("s21_strncpy TEST 3 - SUCCESS\n");
    } else {
        printf("s21_strncpy TEST 3 - FAIL\n");
    }

    if (s21_strncpy_test(test, "STAREGA", 10) == 1){
        printf("s21_strncpy TEST 4 - SUCCESS\n");
    } else {
        printf("s21_strncpy TEST 4 - FAIL\n");
    }

   if (s21_strncpy_test(test, "STAREGA", 0) == 1){
        printf("s21_strncpy TEST 5 - SUCCESS\n");
    } else {
        printf("s21_strncpy TEST 5 - FAIL\n");
   }

   printf("\n");

    //Вызов тестовых функций для memset
    if(s21_memset_test(test, 83, 3) == 1){
        printf("s21_memset TEST 1 - SUCCESS\n");
    } else {
        printf("s21_memset TEST 1 - FAIL\n");
    }
    if(s21_memset_test(test, 83, 3) == 1){
        printf("s21_memset TEST 2 - SUCCESS\n");
    } else {
        printf("s21_memset TEST 2 - FAIL");
    }
    if(s21_memset_test(test, 83, 3) == 1){
        printf("s21_memset TEST 3 - SUCCESS\n");
    } else {
        printf("s21_memset TEST 3 - FAIL\n");
    }
    if(s21_memset_test(test, 83, 3) == 1){
        printf("s21_memset TEST 4 - SUCCESS\n");
    } else {
        printf("s21_memset TESt 4 - FAIL\n");
    }
    if(s21_memset_test(test, 83, 3) == 1){
        printf("s21_memset TEST 5 - SUCCESS\n");
    } else {
        printf("s21_memset TEST 5 - FAIL\n");
    }

    printf("\n");

    //Вызов тестовых функций для memmove
    if(s21_memmove_test(test, "STAREGA", 1) == 1){
        printf("s21_memmove TEST 1 - SUCCESS\n");
    } else {
        printf("s21_memmove TEST 1 - FAIL\n");
    }
    if(s21_memmove_test(test, "STAREGA", 5) == 1){
        printf("s21_memmove TEST 2 - SUCCESS\n");
    } else {
        printf("s21_memmove TEST 2 - FAIL\n");
    }
    if(s21_memmove_test(test, ",№:$%^#&#&", 1) == 1){
        printf("s21_memmove TEST 3 - SUCCESS\n");
    } else {
        printf("s21_memmove TEST 3 - FAIL\n");
    }
    if(s21_memmove_test(test, "F", 5) == 1){
        printf("s21_memmove TEST 4 - SUCCESS\n");
    } else {
        printf("s21_memmove TEST 4 - FAIL\n");
    }

    printf("\n");

    //Вызов тестовых функций для memcpy
    if(s21_memcpy_test(test, "STAREGA", 1) == 1){
        printf("s21_memcpy TEST 1 - SUCCESS\n");
    } else {
        printf("s21_memcpy TEST 1 - FAIL\n");
    }
    if(s21_memcpy_test(test, "STAREGA", 5) == 1){
        printf("s21_memcpy TEST 2 - SUCCESS\n");
    } else {
        printf("s21_memcpy TEST 2 - FAIL\n");
    }
    if(s21_memcpy_test(test, "пепега", 4) == 1){
        printf("s21_memcpy TEST 3 - SUCCESS\n");
    } else {
        printf("s21_memcpy TEST 3 - FAIL\n");
    }
    if(s21_memcpy_test(test, ",№:$%^#&#&", 1) == 1){
        printf("s21_memcpy TEST 4 - SUCCESS\n");
    } else {
        printf("s21_memcpy TEST 4 - FAIL\n");
    }
    if(s21_memcpy_test(test, "F", 5) == 1){
        printf("s21_memcpy TEST 5 - SUCCESS\n");
    } else {
        printf("s21_memcpy TEST 5 - FAIL\n");
    }

    printf("\n");

    //Вызов тестовых функции для strrchr
    if (s21_strrchr_test(test, 80) == 1){
        printf("s21_strrchr TEST 1 - SUCCESS\n");
    } else {
        printf("s21_strrchr TEST 1 - FAIL\n");
    }

    if (s21_strrchr_test(test, 83) == 1){
        printf("s21_strrchr TEST 2 - SUCCESS\n");
    } else {
        printf("s21_strrchr TEST 2 - FAIL\n");
    }

    if (s21_strrchr_test(test, 112) == 1){
        printf("s21_strrchr TEST 3 - SUCCESS\n");
    } else {
        printf("s21_strrchr TEST 3 - FAIL\n");
    }

    if (s21_strrchr_test(test, 69) == 1){
        printf("s21_strrchr TEST 4 - SUCCESS\n");
    } else {
        printf("s21_strrchr TEST 4 - FAIL\n");
    }

    if (s21_strrchr_test(test, 128) == 1){
        printf("s21_strrchr TEST 5 - SUCCESS\n");
    } else {
        printf("s21_strrchr TEST 5 - FAIL\n");
    }

    printf("\n");
    // Вызов тестовых функции для strpbrk
    if (s21_strpbrk_test("EGA", "PEPEGA") == 1){
        printf("s21_strpbrk TEST 1 - SUCCESS\n");
    } else {
        printf("s21_strpbrk TEST 1 - FAIL\n");
    }

    if (s21_strpbrk_test("A", "PEPEGA") == 1){
        printf("s21_strpbrk TEST 2 - SUCCESS\n");
    } else {
        printf("s21_strpbrk TEST 2 - FAIL\n");
    }

    if (s21_strpbrk_test("STAREGA", "PEPEGA") == 1){
        printf("s21_strpbrk TEST 3 - SUCCESS\n");
    } else {
        printf("s21_strpbrk TEST 3 - FAIL\n");
    }

    if (s21_strpbrk_test("PEPE", "PEPEGA") == 1){
        printf("s21_strpbrk TEST 4 - SUCCESS\n");
    } else {
        printf("s21_strpbrk TEST 4 - FAIL\n");
    }

    if (s21_strpbrk_test("PEPEGA", "PEPEGA") == 1){
        printf("s21_strpbrk TEST 5 - SUCCESS\n");
    } else {
        printf("s21_strpbrk TEST 5 - FAIL\n");
    }

    printf("\n");

    // Вызов тестовых функций для memchr
    if (s21_memchr_test("PEPEGA", 'P', 3) == 1){
        printf("s21_memchr TEST 1 - SUCCESS\n");
    } else {
        printf("s21_memchr TEST 1 - FAIL\n");
    }
    if (s21_memchr_test("PEPEGA", 'P', 1) == 1){
        printf("s21_memchr TEST 2 - SUCCESS\n");
    } else {
        printf("s21_memchr TEST 2 - FAIL\n");
    }

    printf("\n");

    //Вызов тестовых функций для strstr
    if(s21_strstr_test("PEPEGA", "PEGA") == 1){
        printf("s21_strstr TEST 1 - SUCCESS\n");
    } else {
        printf("s21_strstr TEST 1 - FAIL\n");
    }

    printf("\n");

    // Вызов тестовых функций для strcspn
    if(s21_strcspn_test("PEPEGA", "EGA") == 1){
        printf("s21_strcspn TEST 1 - SUCCESS\n");
    } else {
        printf("s21_strcspn TEST 1 - FAIL\n");
    }

    printf("\n");

    // Вызов тестовых функций для strncmp
    if(s21_strncmp_test("PEPEGA", "EGA", 3) == 1){
        printf("s21_strcmp TEST 1 - SUCCESS\n");
    } else {
        printf("s21_strcmp TEST 1 - FAIL\n");
    }

    printf("\n");
    //const char test1[] = "STAREGA";
    // Вызов тестовых функция для strcat
    if(s21_strcat_test(test, "STAR") == 1){
        printf("s21_strcat TEST 1 - SUCCESS\n");
    } else {
        printf("s21_strcat TEST 1 - FAIL\n");
    }

    return 0;
}

int s21_strchr_test(const char *str, int symbol){
    int result;
    if (s21_strchr(str, symbol) == strchr(str, symbol)){
        result = 1;
    } else {
        result = 0;
    }
    return result;
}

int s21_strncpy_test(char *dest, const char *src, size_t n){
    int result;
    char *s21_func = s21_strncpy(dest, src, n);
    char *orig_func = strncpy(dest, src, n);
    for (size_t i = 0; i < n; i++){
        if (s21_func[i] != orig_func[i]){
            result = 0;
            break;
        }
    }
    result = 1;

    return result;
}

int s21_memset_test(void *str, int c, s21_size_t n){
    int result;
    char *s21_func = s21_memset(str, c, n);
    char *orig_func = memset(str, c, n);
    if(strcmp(s21_func, orig_func) == 0){
        result = 1;
    } else {
        result = 0;
    }
    return result;
}

int s21_memmove_test(void *dest, const void *src, s21_size_t n){
    int result;
    char *s21_func = s21_memmove(dest, src, n);
    char *orig_func = memmove(dest, src, n);
    if(strcmp(s21_func, orig_func) == 0){
        result = 1;
    } else {
        result = 0;
    }
    return result;
}

int s21_memcpy_test(void *dest, const void *src, s21_size_t n){
    int result;
    char *s21_func = s21_memcpy(dest, src, n);
    char *orig_func = memcpy(dest, src, n);
    if (strcmp(s21_func, orig_func) == 0){
        result = 1;
    } else {
        result = 0;
    }
    return result;
}

int s21_strrchr_test(const char *str, int c){
    int result = 0;
    char *s21_func = s21_strrchr(str, c);
    char *orig_func = strrchr(str, c);
    if (s21_func == orig_func){
        result = 1;
    } else {
        result = 0;
    }
    return result;
}

int s21_strpbrk_test(const char *str1, const char *str2){
    int result = 0;
    char *s21_func = s21_strpbrk(str1, str2);
    char *orig_func = strpbrk(str1, str2);
    if (strcmp(s21_func, orig_func) == 0){
        result = 1;
    }
    return result;
}

int s21_memchr_test(const void *str, int c, s21_size_t n){
    int result = 0;
    char *s21_func = s21_memchr(str, c, n);
    char *orig_func = memchr(str, c, n);
    if (strcmp(s21_func, orig_func) == 0){
        result = 1;
    }
    return result;
}

int s21_strstr_test(const char *haystack, const char *needle){
    int result = 0;
    char *s21_func = s21_strstr(haystack, needle);
    char *orig_func = strstr(haystack, needle);
    if (strcmp(s21_func, orig_func) == 0){
        result = 1;
    }
    return result;
}

int s21_strcspn_test(const char *str1, const char *str2){
    int result = 0;
    s21_size_t s21_func = s21_strcspn(str1, str2);
    s21_size_t orig_func = strcspn(str1, str2);
    if (s21_func == orig_func){
        result = 1;
    }
    //printf("%lu %lu", s21_func, orig_func);
    return result;
}

int s21_strncmp_test(const char *str1, const char *str2, size_t n){
    int result = 0;
    int s21_func = s21_strncmp(str1, str2, n);
    int orig_func = strncmp(str1, str2, n);
    if (s21_func == orig_func){
        result = 1;
    }
    //printf("%d %d", s21_func, orig_func);
    return result;
}

int s21_strcat_test(char *dest, const char *src){
    int result = 0;
    char *s21_func = s21_strcat(dest, src);
    char *orig_func = strcat(dest, src);
    if (strcmp(s21_func, orig_func) == 0){
        result = 1;
    }
    //printf("%s %s", s21_func, orig_func);
    return result;
}