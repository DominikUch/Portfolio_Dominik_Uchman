#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 1000

int sort_alphabetically(char tab[]){
    if(tab == NULL){
        return 1;
    }
    for (int i = 0; tab[i] != '\0'; i++) {
        if (!isalpha(tab[i]) && !isblank(tab[i])) {
            return 1;
        }
    }
    //token
    char words[SIZE][SIZE];
    int words_count = 0;
    char *token = strtok(tab, " ");
    while(token != NULL){
        strcpy(words[words_count++], token);
        token = strtok(NULL, " ");
    }
    //bubble sorcik
    for(int i =0; i < words_count-1; i++){
        for(int j =0; j < words_count -1- i; j++){
            if(strcasecmp(words[j], words[j+1]) > 0){
                char temp[SIZE];
                strcpy(temp, words[j]);
                strcpy(words[j], words[j+1]);
                strcpy(words[j+1], temp);
            }
            else if(strcasecmp(words[j], words[j+1]) == 0){
                if(strcmp(words[j], words[j+1]) > 0) {
                    char temp[SIZE];
                    strcpy(temp, words[j]);
                    strcpy(words[j], words[j + 1]);
                    strcpy(words[j + 1], temp);
                }
            }
        }
    }
    //from 2d to 1d
    int index = 0;
    for(int i =0; i < words_count; i++){
        strcpy(&tab[index], words[i]);
        index += strlen(words[i]);
        tab[index++] = ' ';
    }
    tab[index -1] = '\0';
    return 0;
}

int main(){
    char tab[SIZE];
    int size = 0;
    printf("Podaj jakis tekscik wariacie:\n");
    do{
        if(scanf("%c", &tab[size]) != 1){
            printf("Incorrect input data\n");
            return 2;
        }
        size++;
    }
    while(tab[size - 1] != '\n' && (size+1) < SIZE);
    if(tab[size - 1] == '\n'){
        tab[size - 1] = '\0';
    }

    int result = sort_alphabetically(tab);
    if(result == 1){
        printf("Incorrect input data\n");
        return 2;
    }
    else{
        printf("%s", tab);
    }
    return 0;
}