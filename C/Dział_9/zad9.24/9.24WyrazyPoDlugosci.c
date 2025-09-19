#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 1000

int sort_by_length(char tab[]) {
    if(tab == NULL){
        return 1;
    }
    for (int i = 0; tab[i] != '\0'; i++) {
        if (!isalpha(tab[i]) && tab[i] != ' ') {
            return 1;
        }
    }

    char words[SIZE][SIZE]; // Array to store words
    int word_count = 0;

    // Tokenize input text into words
    char *token = strtok(tab, " ");
    while (token != NULL) {
        strcpy(words[word_count], token);
        word_count++;
        token = strtok(NULL, " ");
    }
    // Bubble sort to sort words alphabetically
    for (int i = 0; i < word_count - 1; i++) {
        for (int j = 0; j < word_count - i - 1; j++) {
            if ((strlen(words[j]) > strlen(words[j + 1])) > 0) {
                char temp[SIZE];
                strcpy(temp, words[j]);
                strcpy(words[j], words[j + 1]);
                strcpy(words[j + 1], temp);
            }
            else if (strlen(words[j]) == strlen(words[j + 1])){
                if(strcmp(words[j],words[j+1]) > 0){
                    char temp[SIZE];
                    strcpy(temp, words[j]);
                    strcpy(words[j], words[j + 1]);
                    strcpy(words[j + 1], temp);
                }
            }
        }
    }
    // Reconstructing the sorted text
    int index = 0;
    for (int i = 0; i < word_count; i++) {
        strcpy(&tab[index], words[i]);
        index += strlen(words[i]);
        tab[index++] = ' ';
    }
    tab[index - 1] = '\0'; // Removing the extra space at the end
    return 0;
}

int main() {
    printf("Enter:");
    char tab[SIZE];
    int size=0;
    do{
        int input = scanf("%c", &tab[size]);
        if (input == 0){
            printf("Incorrect input data");
            return 2;
        }
        size += 1;
    }
    while(tab[size-1] != '\n' && size < SIZE);
    if(tab[size-1] == '\n'){
        tab[size-1] = '\0';
    }
    int result = sort_by_length(tab);
    if(result == 1){
        printf("Incorrect input data");
        return 2;
    }
    printf("%s", tab);
    return 0;
}
