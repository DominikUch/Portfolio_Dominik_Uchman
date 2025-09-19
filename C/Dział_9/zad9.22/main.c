#include <stdio.h>
#define MAX_LENGTH 31
int is_lowercase(char ch) {
    return (ch >= 'a' && ch <= 'z');
}

int is_valid_input(char tab[]) {
    for (int i = 0; tab[i] != '\0'; i++) {
        if (!is_lowercase(tab[i])) {
            return 0;
        }
    }
    return 1;
}

void swap_chars(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}
int sort_lowercase(char tab[]) {
    if (tab == NULL || !is_valid_input(tab)) {
        return 1;
    }
    for (int i = 0; tab[i] != '\0'; i++) {
        for (int j = 0; tab[j] != '\0'; j++) {
            if (tab[i] < tab[j]) {
                swap_chars(&tab[i], &tab[j]);
            }
        }
    }
    return 0;
}

int main() {
    char word[MAX_LENGTH];
    printf("Wprowadz tekst:\n");
    int i = 0;
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF && i < MAX_LENGTH - 1) {
        if (!is_lowercase(ch)) {
            printf("Incorrect input data\n");
            return 2;
        }
        word[i++] = ch;
    }
    word[i] = '\0';
    int result = sort_lowercase(word);
    if (result == 0) {
        printf("%s\n", word);
    } else {
        printf("Incorrect input data\n");
    }
    return 0;
}