#include <stdio.h>

unsigned long long is_prime(unsigned long long number){
    if(number < 2){
        return 0;
    }
    for(unsigned long long i = 2; i * i <= number; i++){
        if(number % i == 0){
            return 0;
        }
    }
    return number;
}
unsigned long long find_largest_prime_number(unsigned long long number) {
    unsigned long long largest_prime = 0;
    unsigned long long temp = number;

    if(number < 2){
        return 0;
    }

    while (temp > 0) {
        unsigned long long divisor = 1;
        unsigned long long sub_number = 0;
        unsigned long long n = temp;
        while (n > 0) {
            unsigned long long digit = n % 10;
            sub_number += (digit * divisor);
            divisor *= 10;
            n /= 10;
            unsigned long long prime = is_prime(sub_number);
            if (prime != 0 && prime > largest_prime) {
                largest_prime = prime;
            }
        }
        temp /= 10;
    }
    if(largest_prime != 0){
        return largest_prime;
    }
    else{
        return 0;
    }
}

int main() {
    unsigned long long number;
    printf("Podaj liczbe:\n");
    if (scanf("%llu", &number) != 1) {
        printf("Incorrect input\n");
        return 1;
    }

    unsigned long long result = find_largest_prime_number(number);
//    if(result != 0){
        printf("%llu", result);
    //}

    return 0;
}