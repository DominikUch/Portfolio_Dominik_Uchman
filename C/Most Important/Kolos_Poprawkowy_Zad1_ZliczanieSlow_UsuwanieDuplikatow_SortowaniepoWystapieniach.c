#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LENGTH 100


void generateRandomString(char *str, int length){
    srand(time(NULL));
    for(int i =0; i < length; i++){
        *(str+i) = 'A' + (rand()%26);
    }
    *(str+length) = '\0';
}

void findAndDisplayStats(char *str){
    ///usuwanie duplikatów || Nowa tablica
    char new_str[MAX_LENGTH];
    int new_str_len = 0;
    for(int i = 0; i < strlen(str)-1;i++){
        int unique = 1;
        for(int j =0; j < new_str_len; j++){
            if(*(str + i) == *(new_str + j)){
                unique = 0;
                break;
            }
        }
        if(unique == 1){
            *(new_str + new_str_len) = *(str+i);
            new_str_len++;
        }
    }
    *(new_str + new_str_len) = '\0';

    //zliczanie
    int count[MAX_LENGTH] = {0};
    for(int i=0; i < new_str_len; i++){
        for(int j =0; j < strlen(str); j++){
            if(*(new_str + i) == *(str+j)){
                *(count+i) += 1;
            }
        }
    }
    //sortowanie new_sort i wydruk
    for(int i=0; i < strlen(new_str)-1; i++){
        for(int j =0; j < strlen(new_str)-1-i; j++){
            if(*(new_str + j) > *(new_str + j+1)){
                char temp;
                temp = *(new_str + j+1);
                *(new_str + j+1) = *(new_str + j);
                *(new_str + j) = temp;
                int temp_int;
                temp_int = *(count + j+1);
                *(count + j+1) = *(count + j);
                *(count + j) = temp_int;
            }
        }
    }
    //filtr - usuwanie parzystych ilości
    char last_tab[MAX_LENGTH];
    int last_len = 0;
    for(int i =0; i < new_str_len; i++){
        if((*(count+i) / 2) == 0){
            *(last_tab +last_len) = *(new_str+i);
            last_len++;
        }
    }
    *(last_tab +last_len) = '\0';
    for(int i =0; i < strlen(new_str)-1; i++){
        printf("znak %c moc %d MandoPower\n", *(new_str+i), *(count + i));
    }
    printf("Tajemniczy kod mocy: %s", last_tab);
}

void delete_odds(char *str);
int main() {
    printf("Podaj dlugosc\n");
    int len;
    if(scanf("%d", &len) != 1){
        return 1;
    }
    if(len < 0 || len > MAX_LENGTH){
        return 1;
    }
    //generowanie liczb
    srand(time(NULL));
    char napis[MAX_LENGTH];
    generateRandomString(napis, len);
    printf("%s\n", napis);
    findAndDisplayStats(napis);
    return 0;
}
