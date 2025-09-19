#include <stdio.h>

int main() {
    float kwota_poczatkowa;
    float liczba_mies;
    float rata = 0.01;

    printf("Podaj kwote poczatkowa:\n");
    int odp1 = scanf("%f", &kwota_poczatkowa);
    if (odp1 != 1 || kwota_poczatkowa < 0) {
        printf("Incorrect input");
        return 1;
    }
    printf("podaj liczbe miesiecy:\n");
    int odp2 = scanf("%f", &liczba_mies);
    if (odp2 != 1 || liczba_mies < 0) {
        printf("Incorrect input");
        return 1;
    }
    for (int i = 0; i < liczba_mies; i++){
        kwota_poczatkowa = kwota_poczatkowa + kwota_poczatkowa * rata;
    }
    printf("%.2f", kwota_poczatkowa);
    return 0;
}