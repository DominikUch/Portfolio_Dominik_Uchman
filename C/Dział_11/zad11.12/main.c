#include <stdio.h>
#define SIZE 1000

int message_compression(char* txt) {
    if (txt == NULL) {
        return -1;
    }
    int removal_count = 0;
    int is_first_letter = 1;

    while (*txt != '\0') {
        if (*txt < 'A' || (*txt > 'Z' && *txt < 'a') || *txt > 'z') {
            char *temp = txt;
            while (*temp != '\0') {
                *temp = *(temp + 1);
                temp++;
            }
            removal_count++;
            is_first_letter = 1;
        } else {
            if (is_first_letter) {
                if (*txt >= 'a' && *txt <= 'z') {
                    *txt = (char)(*txt - 'a' + 'A');
                }
                is_first_letter = 0;
            } else {
                if (*txt >= 'A' && *txt <= 'Z') {
                    *txt = (char)(*txt - 'A' + 'a');
                }
            }
            txt++;
        }
    }
    return removal_count;
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

    int result = message_compression(tablica);
    if (ilosc <= 0 || result == ilosc) {
        printf("NothingToShow");
    } else {
        printf("%s", tablica);
    }
    return 0;
}