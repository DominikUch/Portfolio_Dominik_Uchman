#include <stdio.h>

int is_balanced(unsigned long long a) {
    int even_divisors = 0;
    int odd_divisors = 0;

    for (unsigned long long i = 1; i <= a; i++) {
        if (a % i == 0) {
            if (i % 2 == 0)
                even_divisors++;
            else
                odd_divisors++;
        }
    }
    if(even_divisors == odd_divisors){
        return 1;
    }
    else{
        return 0;
    }
}

int main() {
    unsigned long long N;
    printf("Podaj liczbe:\n");
    if (scanf("%llu", &N) != 1 || N == 0) {
        printf("Incorrect input\n");
        return 1;
    }
    unsigned long long candidate = N + 1;
    while (1) {
        if (is_balanced(candidate) == 1) {
            printf("%llu\n", candidate);
            break;
        }
        candidate++;
    }
    return 0;
}