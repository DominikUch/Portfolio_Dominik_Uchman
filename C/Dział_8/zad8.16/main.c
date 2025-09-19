#include <stdio.h>

int is_prime_rec(int n, int divisor) {
    if (n < 2) {
        return 0;
    } else if (divisor == 1) {
        return 1;
    } else if (n % divisor == 0) {
        return 0;
    } else {
        return is_prime_rec(n, divisor - 1);
    }
}
int print_primes_in_range_recursive(int x1, int x2) {
    int found_primes = 0;
    if (x1 <= x2) {
        if (is_prime_rec(x1, x1 / 2)) {
            printf("%d ", x1);
            found_primes = 1;
        }
        found_primes += print_primes_in_range_recursive(x1 + 1, x2);
    }
    return found_primes;
}
int main() {
    int x1, x2;
    printf("podaj x1:\n");
    if (scanf("%d", &x1) != 1) {
        printf("Incorrect input\n");
        return 1;
    }
    printf("podaj x2:\n");
    if (scanf("%d", &x2) != 1) {
        printf("Incorrect input\n");
        return 1;
    }
    if (x1 > x2) {
        printf("Incorrect input\n");
        return 1;
    }
    int found_primes = print_primes_in_range_recursive(x1, x2);
    if (found_primes == 0) {
        printf("Nothing to show\n");
        return 2;
    }
    printf("\n");
    return 0;
}