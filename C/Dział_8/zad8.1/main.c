#include <stdio.h>

unsigned long factorial_rec(int n);

int main() {
    int n;
    printf("Podaj n: ");
    if (scanf("%d", &n) != 1) {
        printf("Incorrect input\n");
        return 1;
    }
    unsigned long wynik = factorial_rec(n);
    if (wynik == 0) {
        printf("Incorrect input data\n");
        return 2;
    }
    printf("Wynik: %lu", wynik);
    return 0;
}
unsigned long factorial_rec(int n) {
    if (n < 0 || n > 20) {
        return 0;
    } else if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial_rec(n - 1);
    }
}