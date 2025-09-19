#include <stdio.h>

#define SIZE 1000

int my_strlen(const char *str) {
    if (str == NULL) {
        return -1;
    }
    int i = 0;
    while (*(str + i) != '\0') {
        i++;
    }
    return i;
}


char *my_strcpy(char *dest, const char *src) {
    if (dest == NULL || src == NULL) {
        return NULL;
    }
    int j = 0;
    while (*(dest + j) != '\0') {
        *(dest + j) = '\0';
        j++;
    }
    int i = 0;
    while (*(src + i) != '\0') {
        *(dest + i) = *(src + i);
        i++;
    }
    return dest;
}

char *my_strcat(char *dest, const char *src) {
    if (dest == NULL || src == NULL) {
        return NULL;
    }
    int start_second = my_strlen(dest);
    int i = 0;
    while (*(src + i) != '\0') {
        *(dest + start_second) = *(src + i);
        i++;
        start_second++;
    }
    *(dest + start_second) = '\0';
    return dest;
}

int main() {
    char tab[SIZE];
    printf("podaj tekscik wariacei\n");
    fgets(tab, SIZE, stdin);
    int i = 0;
    int new_line = 0;
    while (*(tab + i) != '\0') {
        if (*(tab + i) == '\n') {
            *(tab + i) = '\0';
            new_line++;
        }
        i++;
    }
    if (!new_line) {
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    }

    char tab2[SIZE];
    printf("podaj 2 tekscik wariacei\n");
    fgets(tab2, SIZE, stdin);
    int i2 = 0;
    int new_line2 = 0;
    while (*(tab2 + i2) != '\0') {
        if (*(tab2 + i2) == '\n') {
            *(tab2 + i2) = '\0';
            new_line2++;
        }
        i2++;
    }
    if (!new_line2) {
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    }
    int len1 = my_strlen(tab);
    int len2 = my_strlen(tab2);
    printf("%d %d\n", len1, len2);
    my_strcat(tab2, tab);
    printf("%s\n", tab2);
    my_strcpy(tab2, tab);
    printf("%s", tab2);
    return 0;
}