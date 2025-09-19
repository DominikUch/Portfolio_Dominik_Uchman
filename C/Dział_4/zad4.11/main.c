
#include <stdio.h>

int main(){
    int tablica_liczb[11] = {0};
    int liczba;

    printf("Podaj liczbe:");
    while (1){
        if(scanf("%d", &liczba) != 1){
            printf("Incorrect input");
            return 1;
        }
        if(liczba == -1){
            break;
        }
        if(liczba < 0 || liczba > 10){
            continue;
        }
        tablica_liczb[liczba] += 1 ;
    }
    for(int i = 0; i <= 10; i++){
        printf("%d - %d\n", i, tablica_liczb[i]);
        }
    return 0;
}
