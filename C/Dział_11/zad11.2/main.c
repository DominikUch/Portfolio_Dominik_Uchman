#include <stdio.h>
#define SIZE 1000

char *my_strpbrk(const char *str, const char *seps) {
    while (*str) {
        const char *p = seps;
        while (*p) {
            if (*p == *str) {
                return (char *)str;
            }
            p++;
        }
        str++;
    }
    return NULL;
}

int main() {
    char array[SIZE + 1];
    int amount = 0;
    printf("Podaj tekst:\n");
    char *wskaznik = array;
    while (1) {
        int znak = getchar();
        if (znak == '\n' || amount >= SIZE || znak == EOF) {
            break;
        }
        *wskaznik = (char)znak;
        wskaznik++;
        amount++;
    }
    *wskaznik = '\0';
    const char *samogloski = "aeiouyAEIOUY";
    int count = 0;
    char *result = array;

    while ((result = my_strpbrk(result, samogloski)) != NULL) {
        count++;
        result++;
    }
    printf("%d\n", count);
    return 0;
}