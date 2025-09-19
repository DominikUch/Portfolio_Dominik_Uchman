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
int is_divisible_by_3(int number) {
    if (number < 0) {
        number = -number;
    }
    if (number == 0 || number == 3 || number == 6 || number == 9) {
        return 1;
    } else if (number < 10) {
        return 0;
    } else {
        return is_divisible_by_3(sum_of_digits(number));
    }
}
int main() {
    long long input;
    printf("Podaj liczbe:\n");
    if (scanf("%lld", &input) != 1) {
        printf("Incorrect input\n");
        return 1;
    }
    int digit_sum = sum_of_digits(input);
    int divisible_by_3 = is_divisible_by_3(digit_sum);

    if (divisible_by_3) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}