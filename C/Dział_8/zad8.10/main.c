#include <stdio.h>

int sum_of_digits(long long number) {
    if (number < 0) {
        number = -number;
    }
    if (number == 0) {
        return 0;
    } else {
        return number % 10 + sum_of_digits(number / 10);
    }
}
int main() {
    long long input;
    printf("Podaj liczbe:\n");
    if (scanf("%lld", &input) != 1) {
        printf("Incorrect input\n");
        return 1;
    }
    int result = sum_of_digits(input);
    printf("Wynik: %d\n", result);
    return 0;
}