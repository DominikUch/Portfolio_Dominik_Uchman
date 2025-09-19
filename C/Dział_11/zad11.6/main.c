#include <stdio.h>
#define SIZE 1000

int my_strlen(const char *str){
    if(str == NULL){
        return -1;
    }
    int ilosc = 0;

    while(*str++ != '\0'){
        ilosc++;
    }
    return ilosc;
}

char* my_strcpy(char* dest, const char* src) {
    if (dest == NULL || src == NULL) {
        return NULL;
    }
    char* ptr = dest;
    while (*src) {
        *dest++ = *src++;
    }
    *dest = '\0';
    return ptr;
}
char* my_strcat(char* dest, const char* src) {
    if (dest == NULL || src == NULL) {
        return NULL;
    }
    char* ptr = dest;
    while (*ptr) {
        ptr++;
    }
    while (*src) {
        *ptr++ = *src++;
    }
    *ptr = '\0';
    return dest;
}


int main() {
    char text1[SIZE+1];
    printf("Wprowadz tekst 1:\n");
    fgets(text1, sizeof(text1), stdin);
    char *ptr1 = text1;
    while (*ptr1 != '\0' && *ptr1 != '\n') {
        ptr1++;
    }
    if (*ptr1 == '\n') {
        *ptr1 = '\0';
    } else {
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    }

    char text2[SIZE+1];
    printf("Wprowadz tekst 2:\n");
    fgets(text2, sizeof(text2), stdin);
    char *ptr2 = text2;
    while (*ptr2 != '\0' && *ptr2 != '\n') {
        ptr2++;
    }
    if (*ptr2 == '\n') {
        *ptr2 = '\0';
    } else {
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    }
    int strlen1 = my_strlen(text1);
    int strlen2 = my_strlen(text2);
    if(strlen1 == -1 || strlen2 == -1){
        printf("Incorrect input");
        return 1;
    }
    printf("%d %d\n", strlen1, strlen2);

    char connected[(SIZE * 2) + 1];
    my_strcpy(connected, text2);
    my_strcat(connected, text1);
    printf("%s\n", connected);

    char copied[(SIZE * 2) + 1];
    my_strcpy(copied, text2);
    my_strcpy(copied, text1);
    printf("%s\n", copied);

    return 0;
}