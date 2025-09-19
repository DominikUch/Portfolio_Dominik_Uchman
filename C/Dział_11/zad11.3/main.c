#include <stdio.h>
#define SIZE 1000

int marks_counter(const char *text, int *uppercase, int *lowercase, int *whitespace) {
    if (text == NULL || uppercase == NULL || lowercase == NULL || whitespace == NULL) {
        return 1;
    }
    *uppercase = 0;
    *lowercase = 0;
    *whitespace = 0;

    while (*text != '\0') {
        if (*text >= 'A' && *text <= 'Z') {
            (*uppercase)++;
        } else if (*text >= 'a' && *text <= 'z') {
            (*lowercase)++;
        } else if (*text == ' ' || *text == '\n' || *text == '\t') {
            (*whitespace)++;
        }
        text++;
    }
    return 0;
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
    int uppercase_count, lowercase_count, whitespace_count;
    int result = marks_counter(tablica, &uppercase_count, &lowercase_count, &whitespace_count);
    if (result == 0) {
        printf("%d\n", uppercase_count);
        printf("%d\n", lowercase_count);
        printf("%d\n", whitespace_count);
    }
    return 0;
}