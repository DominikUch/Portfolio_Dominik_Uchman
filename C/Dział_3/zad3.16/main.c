#include <stdio.h>

int main() {
    float liczba;
    float iloczyn = 1.0;
    while (1) {
        printf("Podaj liczbe:");
        int user_input = scanf("%f", &liczba);
        if (user_input != 1) {
            printf("Incorrect input");
            return 0;

        }
        iloczyn = iloczyn * liczba;
        printf("Wynik = %.2f\n", iloczyn);
    }
}