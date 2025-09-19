#include <stdio.h>

int main() {
    int num1;
    int num2;
    printf("Podaj pierwsza liczbe calkowita:\n");
    if (scanf("%d", &num1) != 1) {
        printf("Incorrect input");
        return 1;
    }
    printf("Podaj druga liczbe calkowita:\n");
    if (scanf("%d", &num2) != 1) {
        printf("Incorrect input");
        return 1;
    }
    if (num2 == 0) {
        printf("Operation not permitted");
        return 1;
    } else if (num1 % num2 == 0) {
        printf("%d is divisible by %d", num1, num2);
    } else {
        printf("%d is not divisible by %d", num1, num2);
    }
    return 0;
}