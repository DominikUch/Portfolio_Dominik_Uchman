
#include <stdio.h>

int main() {
    int tablica[10];
    int min;
    int max;
    int suma = 0;
    printf("Podaj liczbe:\n");
    for (int i = 0; i < 10; i = i + 2) {
        if (scanf("%d %d", &tablica[i], &tablica[i + 1]) != 2) {
            printf("Input data type error");
            return 1;
        }
        if (i == 0){
            min = max = tablica[i];
        }
        //maximum
        if (tablica[i] > max){
            max = tablica[i];
        }
        if(tablica[i+1] > max){
            max = tablica[i+1];
        }
        //minimum
        if (tablica[i] < min){
            min = tablica[i];
        }
        if(tablica[i+1] < min){
            min = tablica[i+1];
        }
        suma = suma + tablica[i] + tablica[i + 1];
    }
        float srednia;
        srednia = suma / 10.0;

        printf("srednia = %.4lf\n", srednia);
        printf("wartosc maksymalna = %d\n", max);
        printf("wartosc minimalna = %d\n", min);
        return 0;
}
