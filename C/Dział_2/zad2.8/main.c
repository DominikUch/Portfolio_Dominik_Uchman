#include <stdio.h>

int main() {
    char kolumna;
    char wiersz;
    printf("Podaj pole:\n");
    if (scanf("%c%c", &kolumna, &wiersz) != 2){
        printf("incorrect input");
        return 1;
    }
    if (kolumna >= 'a' && kolumna <= 'h' && wiersz >= '1' && wiersz <= '8'){
        if (kolumna == 'a' || kolumna == 'c' || kolumna == 'e' || kolumna == 'g' ){
            if(wiersz == '1' || wiersz == '3' || wiersz == '5' || wiersz == '7'){
                printf("black");
            }
            else{
                printf("white");
            }
        }
        else if(kolumna == 'b' || kolumna == 'd' || kolumna == 'f' || kolumna == 'h' ){
            if(wiersz == '2' || wiersz == '4' || wiersz == '6' || wiersz == '8'){
                printf("black");
            }
            else{
                printf("white");
            }
        }
    }
    else{
        printf("Incorrect input");
        return 1;
    }
}