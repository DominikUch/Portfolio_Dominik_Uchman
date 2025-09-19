#include <stdio.h>
long long binary_exponentiation(long long x, unsigned int n){
    if (n == 0){
        return 1;
    }
    else if (n % 2  == 1){
        return x * binary_exponentiation(x * x, (n - 1) / 2);
    }
    else{
        return binary_exponentiation(x * x, n / 2);
    }
}
int main() {
    long long podstawa;
    printf("Podaj podstawe:\n");
    if(scanf("%lld", &podstawa) != 1){
        printf("Incorrect input");
        return 1;
    }
    unsigned int wykladnik;
    printf("Podaj wykladnik:\n");
    if(scanf("%u", &wykladnik) != 1){
        printf("Incorrect input");
        return 1;
    }
    long long wynik = binary_exponentiation(podstawa,wykladnik);
    printf("Wynik: %lld", wynik);
    return 0;
}
