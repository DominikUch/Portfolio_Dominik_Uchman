#include <stdio.h>

float poly(float num_1){
    float rownanie = 5*(num_1 * num_1) + (12.55 * num_1) + 0.75;
    return rownanie;
}
int main(){
    float liczba;
    printf("Podaj x:\n");
    if(scanf("%f", &liczba) != 1){
        printf("Incorrect input");
        return 1;
    }
    float wynik = poly(liczba);
    printf("Wynik: %f",wynik);
    return 0;
}
