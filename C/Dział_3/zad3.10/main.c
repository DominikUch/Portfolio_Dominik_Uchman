#include <stdio.h>
int main(){
    double suma = 0.0;
    double odpowiedz;

    for(int i = 1; i<= 10; i++){
        printf("Podaj %d liczbe:\n", i);
        if (scanf("%lf", &odpowiedz) != 1)
        {
            printf("Incorrect input");
            return 1;
        }
        suma += odpowiedz;
    }
    printf("Suma podanych liczb to %lf", suma);
    return 0;
}