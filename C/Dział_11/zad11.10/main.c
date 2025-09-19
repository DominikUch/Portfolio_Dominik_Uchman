#include <stdio.h>
#define SIZE 1000

char* space_changer(char* text) {
    if (text == NULL) {
        return NULL;
    }
    for (char* ptr = text; *ptr != '\0'; ptr++) {
        if (*ptr == ' ') {
            *ptr = '_';
        }
    }
    return text;
}

int main() {
    char tablica[SIZE + 1];
    int ilosc = 0;
    printf("Podaj tekst:\n");
    char *wskaznik = tablica;
    while (1) {
        int znak = getchar();
        if (ilosc >= SIZE || znak == '\n' || znak == EOF) {
            break;
        }
        *wskaznik = (char)znak;
        wskaznik++;
        ilosc++;
    }
    *wskaznik = '\0';
    space_changer(tablica);
    printf("%s\n", tablica);
    return 0;
}
