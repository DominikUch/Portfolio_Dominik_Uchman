#include <stdio.h>
#include <ctype.h>

#define SIZE 1000

int main() {
    char text[SIZE + 1];

    printf("Podaj tekst:\n");
    fgets(text, sizeof(text), stdin);
    char *ptr = text;
    int count = 0;
    int is_word = 0;

    while (*ptr != '\n' && *ptr != '\0') {
        if ((*ptr >= 'A' && *ptr <= 'Z') || (*ptr >= 'a' && *ptr <= 'z')) {
            if (!is_word) {
                printf("%c", toupper(*ptr));
                is_word = 1;
            } else {
                printf("%c", tolower(*ptr));
            }
            count++;
        } else {
            is_word = 0;
        }
        ptr++;
    }

    if (count == 0) {
        printf("NothingToShow\n");
    }

    return 0;
}