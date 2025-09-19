#include <stdio.h>

#define wielkosc_tablicy 11

int main(){
    int liczby[wielkosc_tablicy];
    int odpowiedz;
    for (int i = 0; i < 5; i++){
        printf("Podaj 2 liczby calkowite:");
        odpowiedz = scanf("%d %d", &liczby[2*i+1], &liczby[2*i+2]);
        if (odpowiedz != 2){
            printf("Input data type error\n");
            return 1;
        }
    }
    for(int i = 1; i <= 10; i++){
        if(liczby[i] % 2 == 0){
            printf("%d even\n", liczby[i]);
        }
        else{
            printf("%d odd\n", liczby[i]);
        }
    }
    return 0;
}