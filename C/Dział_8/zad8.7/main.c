#include <stdio.h>

int GCD(int a, int b) {
    if (b == 0) {
        if(a < 0){
            return -1*a;
        }
        else {
            return a;
        }
    } else{
        return GCD(b, a % b);
    }
}

int main() {
    int liczba_1;
    printf("Podaj pierwsza liczbe:\n");
    if (scanf("%d", &liczba_1) != 1) {
        printf("Incorrect input\n");
        return 1;
    }
    int liczba_2;
    printf("Podaj druga liczbe:\n");
    if (scanf("%d", &liczba_2) != 1) {
        printf("Incorrect input\n");
        return 1;
    }
    int wynik = GCD(liczba_1, liczba_2);
    printf("Najwiekszy wspolny dzielnik: %d\n", wynik);
    return 0;
}