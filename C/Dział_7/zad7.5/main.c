#include <stdio.h>

int add(int num_1, int num_2){
    int wynik = num_1 + num_2;
    return wynik;
}
int main(){
    int liczba_1;
    printf("Podaj pierwsza liczbe:\n");
    if(scanf("%d", &liczba_1) != 1){
        printf("Incorrect input");
        return 1;
    }
    int liczba_2;
    printf("Podaj druga liczbe:\n");
    if(scanf("%d", &liczba_2) != 1){
        printf("Incorrect input");
        return 1;
    }
    int suma = add(liczba_1, liczba_2);
    printf("Wynik: %d", suma);
    return 0;
}
