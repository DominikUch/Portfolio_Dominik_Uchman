#include <stdio.h>

int main() {
    double num_1;
    double num_2;
    printf("Podaj pierwsza liczbe:\n");
    if (scanf("%lf", &num_1) != 1){
        printf("Incorrect input");
        return 1;
    }
    printf("Podaj druga liczbe:\n");
    if (scanf("%lf", &num_2) != 1){
        printf("Incorrect input");
        return 1;
    }
    double suma = num_1 + num_2;
    double roznica = num_1 - (num_2);
    double iloczyn = num_1 * num_2;

    if (num_2 != 0){
        double iloraz = num_1 / num_2;
        printf("suma = %lf\n", suma);
        printf("roznica = %lf\n", roznica);
        printf("iloczyn = %lf\n", iloczyn);
        printf("iloraz = %lf\n", iloraz);
    }
    else{
        printf("suma = %lf\n", suma);
        printf("roznica = %lf\n", roznica);
        printf("iloczyn = %lf\n", iloczyn);
        printf("Operation not permitted");
    }
    return 0;
}