#include <stdio.h>

unsigned long long product_of_digits(unsigned long long n){
    if(n < 10){
        return n;
    }
    else{
        return (n % 10) * product_of_digits(n/10);
    }
}
unsigned long long find_smallest_number(unsigned long long n, unsigned long long candidate) {
    if (product_of_digits(candidate) == n) {
        return candidate;
    }
    if(candidate > 255558){
        return 0;
    }
    return find_smallest_number(n, candidate + 1);
}
int main() {
    printf("podaj liczbe:\n");
    unsigned long long liczba;
    if(scanf("%llu", &liczba) != 1){
        printf("Incorrect input");
        return 1;
    }
    if(liczba > 10000) {
        printf("Incorrect input data");
        return 2;
    }
    unsigned long long result = find_smallest_number(liczba, 1);
    if(result != 0){
        printf("%llu", result);
    }
    else{
        printf("NIE");
    }

    return 0;
}