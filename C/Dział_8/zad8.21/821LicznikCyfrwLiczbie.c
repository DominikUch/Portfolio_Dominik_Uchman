#include <stdio.h>


int digits_in_number(unsigned long long number, unsigned int digit){

    if(number < 10){
        if(digit == number){
            return 1;
        }
        else{
            return 0;
        }
    }
    if(digit == number % 10){
        return 1 + digits_in_number(number / 10, digit);
    }
    else {
        return digits_in_number(number / 10, digit);
    }
}

int main() {


    printf("Podaj liczbe:\n");
    unsigned long long liczba;
    if(scanf("%llu", &liczba) != 1){
        printf("Incorrect input");
        return 1;
    }
    printf("Podaj 2 liczbe:\n");
    unsigned int liczba2;
    if(scanf("%u", &liczba2) != 1){
        printf("Incorrect input");
        return 1;
    }
    if(liczba2 > 9) {
        printf("Incorrect input data");
        return 2;
    }
    int result = digits_in_number(liczba, liczba2);
    printf("%d", result);
}
