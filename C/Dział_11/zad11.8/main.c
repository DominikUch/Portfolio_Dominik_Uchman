#include <stdio.h>
#define SIZE 1000

char* change_letter_size(char *dest, const char *src) {
    if (dest == NULL || src == NULL) {
        return NULL;
    }
    char *result = dest;
    while (*src != '\0') {
        if (*src >= 'a' && *src <= 'z') {
            *dest = *src - ('a' - 'A');
        } else if (*src >= 'A' && *src <= 'Z') {
            *dest = *src + ('a' - 'A');
        } else {
            *dest = *src;
        }
        src++;
        dest++;
    }
    *dest = '\0';
    return result;
}

int main() {
    char array[SIZE + 1];
    int amount = 0;
    printf("Podaj tekst:\n");
    char* wskaznik = array;
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
    change_letter_size(array, array);
    printf("%s\n", array);
    return 0;
}