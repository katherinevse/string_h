#include <stdio.h>
#include <string.h>


char *strcpy(char *dest, const char *src){

    char *original_dest = dest;

    while (dest != "\0")
    {
        
    }
    


}


int main(void){
    char source[] = "Hello world";
    char source_2[100];


    strcpy(source_2, source);
    printf("%s\n", source);
    printf("%s\n", source_2);

    return 0;

}