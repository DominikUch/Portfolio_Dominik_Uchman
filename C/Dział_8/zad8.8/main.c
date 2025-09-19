#include <stdio.h>
int even_odd(int s, int n) {
    if (n < 0){
        return 0;
    }
    if (n == 0) {
        return s;
    }
    if (s % 2 == 0) {
        return even_odd(s/2, n-1);
    } else {
        return even_odd(3*s+1,n-1);
    }
}
int main() {
    int s;
    printf("Podaj wartosc pierwszego wyrazu:\n");
    if (scanf("%d", &s) != 1) {
        printf("Incorrect input");
        return 1;
    }
    int n;
    printf("Podaj numer wyrazu, ktorego wartosc chcesz wyznaczyc:\n");
    if (scanf("%d", &n) != 1) {
        printf("Incorrect input");
        return 1;
    }
    int result = even_odd(s, n);
    if (result == 0){
        printf("Incorrect input data");
        return 2;
    }
    else{
        printf("Wynik: %d", result);
    }
}


