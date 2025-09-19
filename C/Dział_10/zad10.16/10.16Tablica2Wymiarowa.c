#include <stdio.h>
#define SIZE 10

int is_prime(int a){
    if(a < 2){
        return 0;
    }
    for(int i = 2; i * i <= a; i++){
        if(a % i == 0){
            return 0;
        }
    }
    return 1;
}

int main() {
    printf("Podaj liczby:\n");
    int tab[SIZE][SIZE];
    int k = 0;
    int l = 0;
    int zmienna;
    while (k < SIZE) {
        if (scanf("%d", &zmienna) != 1) {
            printf("Incorrect input");
            return 1;
        }
        if (is_prime(zmienna)) {
            *(*(tab+k)+l) = zmienna;
            l++;
            if (l == SIZE) {
                k++;
                l = 0;
            }
        }
    }
    for(int i = 0; i < SIZE; i += 3){
        for(int j = 0; j < SIZE; j += 3){
            printf("%d ", *(*(tab+i)+j));
        }
    }

    return 0;
}