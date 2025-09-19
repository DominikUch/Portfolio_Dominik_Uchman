#include <stdio.h>
#include <string.h>

#define MAX_TITLES 10
#define MAX_TITLE_LENGTH 91

void swap(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

int strcmp_basic(const char *s1, const char *s2) {
    while (*s1 && *s2 && *s1 == *s2) {
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

int sort(char const *ptrs[], int size) {
    if (ptrs == NULL || size <= 0) {
        return 1;
    }
    for (char const **i = ptrs; i < ptrs + size - 1; i++) {
        for (char const **j = i + 1; j < ptrs + size; j++) {
            if (strcmp_basic(*i, *j) > 0) {
                swap((char **)i, (char **)j);
            }
        }
    }
    return 0;
}

int main() {
    char titles[MAX_TITLES+1][MAX_TITLE_LENGTH];
    char const *ptr_titles[MAX_TITLES];
    int title_count = 0;


    printf("Podaj tytuly:\n");
    while (title_count < MAX_TITLES) {
        if (fgets(*(titles + title_count), MAX_TITLE_LENGTH, stdin) == NULL) {
            printf("Not enough data available\n");
            return 3;
        }


        if (*(*(titles + title_count)) == '\n') {
            if (title_count == 0) {
                printf("Not enough data available\n");
                return 3;
            }
            break;
        }

        int i = 0;
        int new_line = 0;
        while(*(*(titles + title_count) + i) != '\0'){
            if(*(*(titles + title_count) + i) == '\n'){
                *(*(titles + title_count) + i) = '\0';
                new_line++;
            }
            i++;
        }
        if(new_line == 0){
            int c;
            while((c = getchar()) != '\n' && c != EOF){}
        }

        if (strlen(*(titles + title_count)) > 0 && *(*(titles + title_count) + strlen(*(titles + title_count)) - 1) == '\n') {
            *(*(titles + title_count) + strlen(*(titles + title_count)) - 1) = '\0';
        }
        *(ptr_titles + title_count) = *(titles + title_count);
        title_count++;
    }

    sort(ptr_titles, title_count);

    for (int i = 0; i < title_count; i++) {
        printf("%s\n", *(ptr_titles + i));
    }
    return 0;
}