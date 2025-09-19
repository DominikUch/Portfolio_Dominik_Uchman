#include <stdio.h>

float add(float num_1, float num_2){
    float wynik_dodawania = num_1 + num_2;
    return wynik_dodawania;
}
float subtract(float num_1, float num_2){
    float wynik_odejmowania = num_1 - num_2;
    return wynik_odejmowania;
}
float multiply(float num_1, float num_2){
    float wynik_mnozenia = num_1 * num_2;
    return wynik_mnozenia;
}
float divide(float num_1, float num_2){
    if(num_2 == 0){
        printf("Operation not permitted");
        return -1;
    }
    else{
        float wynik_dzielenia = num_1 / num_2;
        return wynik_dzielenia;
    }
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
    printf("Suma: %.1f\n", suma);

    float roznica = subtract(liczba_1,liczba_2);
    printf("Roznica: %.1f\n", roznica);

    float iloczyn = multiply(liczba_1,liczba_2);
    printf("Iloczyn: %.1f\n", iloczyn);

    float iloraz = divide(liczba_1,liczba_2);
    if (liczba_2 != 0) {
        printf("Iloraz: %.6f\n", iloraz);
    }
    return 0;
}
