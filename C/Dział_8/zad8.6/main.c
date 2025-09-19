#include <stdio.h>

long int fibonacci(int n){
    if(n < 0){
        return -1;
    }
    else if (n==0){
        return 1;
    }
    else if (n == 1) {
        return 2;
    }
    else{
        return fibonacci(n - 1) + fibonacci(n - 2) + n;
    }
}

int main() {
    int liczba;
    printf("ktory wyrfaz ciagu Fibonacciego chcesz wyznaczyc?:\n");
    if(scanf("%d", &liczba) != 1){
        printf("Incorrect input");
        return 1;
    }
    long int wynik = fibonacci(liczba);
    if(wynik != -1){
        printf("Wynik: %ld",wynik);
    }
    else{
        printf("Incorrect input data");
        return 2;
    }
    return 0;
}