#include <stdio.h>
#include <string.h>
#include <ctype.h>


#define LEN 31  // Maksymalna długość imienia

#define SIZE 20 // Maksymalna liczba imion (w tym pusta linia)

int sort_names_alphabetically(char names[SIZE][LEN], int size){
    if(names == NULL || size < 1 || size > SIZE){
        return 1;
    }

    for(int i =0 ; i < size; i++){
        int spr = strlen(names[i]);
        if(names[i][spr - 1] == '\n'){
            names[i][spr-1] = '\0';
            return 1;
        }
    }
    for(int i =0; i< size; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (strcasecmp(names[j], names[j + 1]) > 0) {
                char temp[LEN];
                strcpy(temp, names[j + 1]);
                strcpy(names[j + 1], names[j]);
                strcpy(names[j], temp);
            } else if (strcasecmp(names[j], names[j + 1]) == 0) {
                if (strcmp(names[j], names[j + 1]) > 0) {
                    char temp[LEN];
                    strcpy(temp, names[j + 1]);
                    strcpy(names[j + 1], names[j]);
                    strcpy(names[j], temp);
                }
            }
        }
    }
    return 0;
}


int main() {
    printf("Tell me their names:\n");
    char names[SIZE-1][LEN];
    int names_count = 0;
    for(; names_count < SIZE-1; names_count++){
        fgets(names[names_count], LEN, stdin);
        if(names[names_count][0] =='\n'){
            break;
        }
        int k =0;
        int new_line =0;
        while(names[names_count][k] != '\0'){
            if(names[names_count][k] == '\n'){
                names[names_count][k] = '\0';
                new_line++;
            }
            k++;
        }
        if(!new_line){
            int c;
            while( (c = getchar()) != '\n' && c != EOF){}
        }
    }
    for(int i= 0; i < names_count; i++){
        for(int j =0; j < (int)strlen(names[i]); j++){
            if( (names[i][j] >= '0' && names[i][j] <= '9') || names[i][j] == ' '){
                printf("Incorrect input data");
                return 2;
            }
        }
    }
    strcpy(names[names_count++], "Dominik");

    int result = sort_names_alphabetically(names, names_count);
    if(result == 1){
        printf("Incorrect input data");
        return 2;
    }
    for(int i= 0; i < names_count; i++){
        for(int j =0; j < (int)strlen(names[i]); j++){
            printf("%c", names[i][j]);
        }
        printf("\n");
    }
    return 0;
}

