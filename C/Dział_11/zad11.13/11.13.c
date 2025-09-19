#include <stdio.h>
#include <string.h>


#define SIZE 100
int starts_with(const char* txt, const char* find){
    if(txt == NULL || find == NULL){
        return -1;
    }
    if(strcmp(txt, find) == 0){
        return 1;
    }
    if(strncmp(txt, find, strlen(find)) == 0){
        return 1;
    }
    return 0;
}

int ends_with(const char* txt, const char* find){
    if(txt == NULL || find == NULL){
        return -1;
    }
    int len1 = strlen(txt);
    int len2 = strlen(find);
    if(strcmp(txt, find) == 0){
        return 1;
    }
    if(strncmp(txt+(len1-len2), find, len2) == 0 ){
        return 1;
    }
    return 0;
}

void clear_input_buffer() {
    scanf("%*[^\n]");
    scanf("%*c");
}

int main() {
    printf("Podaj tekscik\n");
    char tab1[SIZE + 1];
    fgets(tab1, SIZE + 1, stdin);
    int len1 = strlen(tab1);
    if (len1 > 0 && *(tab1 +(len1 - 1)) == '\n') {
        *(tab1 +(len1 - 1)) = '\0';
    } else if (len1 == SIZE && *(tab1 +(len1 - 1)) != '\n') {
        clear_input_buffer();
    }

    printf("Podaj 2 tekscik\n");
    char tab2[SIZE + 1];
    fgets(tab2, SIZE + 1, stdin);
    int len2 = strlen(tab2);
    if (len2 > 0 && *(tab2 +(len2 - 1)) == '\n') {
        *(tab2 +(len2 - 1)) = '\0';
    } else if (len2 == SIZE && *(tab2 +(len2 - 1)) != '\n') {
        clear_input_buffer();
    }
    printf("%d\n", starts_with(tab1,tab2));
    printf("%d\n", ends_with(tab1,tab2));


    return 0;
}
