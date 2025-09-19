#include <stdio.h>
#define SIZE 1000
char* trim(char* text) {
    if (text == NULL)
        return NULL;

    char* result = text;
    char* write = text;
    int is_space = 0;

    while (*text == ' ')
        text++;

    while (*text) {
        if (*text != ' ') {
            *write++ = *text++;
            is_space = 0;
        } else {
            if (!is_space) {
                *write++ = *text++;
                is_space = 1;
            } else {
                text++;
            }
        }
    }
    if (write > result && *(write - 1) == ' ')
        write--;
    *write = '\0';
    return result;
}

char *remove_non_letters(char* text) {
    if (text == NULL)
        return NULL;

    char* result = text;
    while (*text) {
        if ((*text >= 'a' && *text <= 'z') || (*text >= 'A' && *text <= 'Z')) {
            text++;
        } else {
            *text = ' ';
            text++;
        }
    }
    return result;
}

char* reverse(char* text) {
    if (text == NULL){
        return NULL;
    }

    char* start = text;
    char* end = text;
    while (*end != '\0')
        end++;
    end--;
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
    return text;
}

int main() {
    char text1[SIZE+1];
    printf("Wprowadz tekst 1:\n");
    fgets(text1, sizeof(text1), stdin);

    int count = 0;
    char *ptr1 = text1;
    while (*ptr1 != '\0' && *ptr1 != '\n') {
        if ((*ptr1 >= 'a' && *ptr1 <= 'z') || (*ptr1 >= 'A' && *ptr1 <= 'Z')) {
            count++;
        }
        ptr1++;
    }
    if (*ptr1 == '\n') {
        *ptr1 = '\0';
    } else {
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    }
    if(count == 0){
        printf("wohs ot gnihtoN");
    }
    reverse(text1);
    remove_non_letters(text1);
    trim(text1);
    printf("%s", text1);

    return 0;
}

