#include <stdio.h>

int main() {
    int num_1;
    int num_2;
    printf("Podaj pierwsza liczbe:\n");
    if (scanf("%d", &num_1) != 1){
        printf("Incorrect input");
        return 1;
    }
    printf("Podaj druga liczbe:\n");
    if (scanf("%d", &num_2) != 1){
        printf("Incorrect input");
        return 1;
    }
    
    int suma = num_1 + num_2;
    int roznica = num_1 - (num_2);
    int iloczyn = num_1 * num_2;

    if (num_2 != 0){
        int iloraz = num_1 / num_2;
        printf("suma = %d\n", suma);
        printf("roznica = %d\n", roznica);
        printf("iloczyn = %d\n", iloczyn);
        printf("iloraz = %d\n", iloraz);
    }
    else{
        printf("suma = %d\n", suma);
        printf("roznica = %d\n", roznica);
        printf("iloczyn = %d\n", iloczyn);
        printf("Operation not permitted");
    }
    return 0;
}