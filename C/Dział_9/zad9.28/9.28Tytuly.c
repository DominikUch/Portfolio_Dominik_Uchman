#include <stdio.h>
#include <string.h>

#define SIZE 20
#define LEN 101

int sort_titles_alphabetically(char tab[SIZE][LEN], int size){
    if(tab == NULL || size <= 0 || size > SIZE){
        return 1;
    }
    for(int i =0; i < size -1; i ++){
        for(int j = 0 ; j < size - 1 - i; j++){
            if(strcasecmp(tab[j],tab[j+1]) > 0){
                char temp[LEN];
                strcpy(temp, tab[j+1]);
                strcpy(tab[j+1], tab[j]);
                strcpy(tab[j], temp);
            }
            else if(strcasecmp(tab[j],tab[j+1]) == 0){
                if(strcmp(tab[j],tab[j+1]) > 0){
                    char temp[LEN];
                    strcpy(temp, tab[j+1]);
                    strcpy(tab[j+1], tab[j]);
                    strcpy(tab[j], temp);
                }
            }
        }
    }
    return 0;
}


int main() {
    printf("Podaj tytuly:\n");
    char titles[SIZE][LEN];
    int titles_count=0;
    for(; titles_count < SIZE; titles_count++){
        fgets(titles[titles_count], LEN, stdin);
        if(titles[titles_count][0] == '\n'){
            break;
        }
        int new_line = 0;
        int k=0;
        while(titles[titles_count][k] != '\0'){
            if(titles[titles_count][k] == '\n'){
                titles[titles_count][k] = '\0';
                new_line++;
            }
            k++;
        }
        if(!new_line){
            int c;
            while( (c=getchar()) != '\n' && c != EOF);
        }
    }
    int result = sort_titles_alphabetically(titles, titles_count);
    if(result == 1){
        printf("Incorrect input data");
        return 2;
    }
    else{
        for(int i = 0 ; i < titles_count; i++){
            printf("%s\n", titles[i]);
        }
    }
    return 0;
}
