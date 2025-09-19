#include <stdio.h>
#include <string.h>
#define SIZE 1000

int is_palindrom(const char *text) {
    if (text == NULL) {
        return -1;
    }
    int length=0;
    while(*(text+length)!='\0') {
        length++;
    }
    if (length <= 1) {
        return 0;
    }
    const char *start = text;
    const char *end = text + length - 1;
    while (start < end) {
        if (*start != *end) {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

char *find_palindrom(char *text, int len) {
    if (text == NULL || len <= 0) {
        return NULL;
    }
    int text_len = strlen(text);
    if (len > text_len) {
        return NULL;
    }
    for (char *i = text; i <= text + text_len - len; i++) {
        int is_palindrome = 1;
        for (int j = 0; j < len / 2; j++) {
            if (*(i + j) != *(i + len - 1 - j)) {
                is_palindrome = 0;
                break;
            }
        }
        if (is_palindrome) {
            *(i + len) = '\0';
            return i;
        }
    }
    return NULL;
}

int create_palindrom(const char *text, char *out, int size) {
    if (text == NULL || out == NULL) {
        return 1;
    }
    if (size <= 0) {
        return 1;
    }
    int text_len = strlen(text);
    if (size < 2 * text_len + 1) {
        return 2;
    }
    const char *src = text;
    char *dest = out;
    while (*src != '\0') {
        *dest++ = *src++;
    }
    src--;
    while (src >= text) {
        *dest++ = *src--;
    }
    *dest = '\0';
    return 0;
}

int main() {
    char text[SIZE + 1];
    printf("Podaj tekst:\n");
    fgets(text, SIZE + 1, stdin);

    int i=0;
    int newline = 0;
    while(*(text+i) != '\0'){
        if(*(text+i) == '\n') {
            *(text+i) = '\0';
            newline++;
        }
        i++;
    }
    if(newline == 0){
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    }

    int result = is_palindrom(text);
    if(result == 1){
        printf("YES");
        return 0;
    }
    printf("NO\n");
    printf("Co dalej?\n");
    char choice;
    scanf("%c", &choice);
    if(choice == 'c' || choice == 'C'){
        char createdtab[(2*SIZE) + 2];

        int created = create_palindrom(text,createdtab, (2*SIZE) + 2);
        if(created == 0){
            printf("%s", createdtab);
        }
    }
    else if(choice == 'f' || choice == 'F'){
        int dlugosc_palindromu;
        printf("Podaj dlugosc palindromu:\n");
        if(scanf("%d", &dlugosc_palindromu) != 1){
            printf("Incorrect input");
            return 1;
        }
        if(dlugosc_palindromu <= 0) {
            printf("Incorrect input data");
            return 2;
        }
        char *found = find_palindrom(text, dlugosc_palindromu);
        if(found != NULL){
            printf("%s", found);
        }
        else{
            printf("Couldn't find");
        }
    }
    else{
        printf("Incorrect input data");
        return 2;
    }

    return 0;
}