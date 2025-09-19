#include <stdio.h>

int main() {

    float num_1,num_2,suma,roznica,iloczyn,iloraz;

    printf("Podaj pierwsza liczbe:\n");
    scanf("%f", &num_1);
    printf("Podaj druga liczbe:\n");
    scanf("%f", &num_2);

    suma = num_1 + num_2;
    roznica = num_1 - (num_2);
    iloczyn = num_1 * num_2;
    iloraz = num_1 / num_2;

    printf("suma = %f\n", suma);
    printf("roznica = %f\n", roznica);
    printf("iloczyn = %f\n", iloczyn);
    printf("iloraz = %f\n", iloraz);

    return 0;
}
