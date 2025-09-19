#include <stdio.h>
long power_rec(int a, int n);

int main() {
    int a, n;
    printf("Podaj a: ");
    if (scanf("%d", &a) != 1) {
        printf("Incorrect input");
        return 1;
    }
    printf("Podaj wykladnik n: ");
    if (scanf("%d", &n) != 1) {
        printf("Incorrect input");
        return 1;
    }
    long wynik = power_rec(a, n);
    if (n < 0) {
        printf("Incorrect input data\n");
        return 2;
    }
    printf("Wynik: %ld\n", wynik);
    return 0;
}
long power_rec(int a, int n) {
    if (n < 0) {
        return 0;
    }
    if (n == 0) {
        return 1;
    } else {
        return a * power_rec(a, n - 1);
    }
}