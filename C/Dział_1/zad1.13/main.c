#include <stdio.h>

int main() {

    int num_1, num_2,suma,roznica,iloczyn,iloraz;

    printf("Podaj pierwsza liczbe:\n");
    scanf("%d", &num_1);
    printf("Podaj druga liczbe:\n");
    scanf("%d", &num_2);

    suma = num_1 + num_2;
    roznica = num_1 - (num_2);
    iloczyn = num_1 * num_2;
    iloraz = num_1 / num_2;

    printf("suma = %d\n", suma);
    printf("roznica = %d\n", roznica);
    printf("iloczyn = %d\n", iloczyn);
    printf("iloraz = %d\n", iloraz);

    return 0;
}
