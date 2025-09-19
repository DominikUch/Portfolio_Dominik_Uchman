#include <stdio.h>

float add(float num_1, float num_2){
    float wynik = num_1 + num_2;
    return wynik;
}
int main(){
    float liczba_1;
    printf("Podaj pierwsza liczbe:\n");
    if(scanf("%f", &liczba_1) != 1){
        printf("Incorrect input");
        return 1;
    }
    float liczba_2;
    printf("Podaj druga liczbe:\n");
    if(scanf("%f", &liczba_2) != 1){
        printf("Incorrect input");
        return 1;
    }
    float suma = add(liczba_1, liczba_2);
    printf("Wynik: %f", suma);
    return 0;
}
