#include <stdio.h>

unsigned long long decimal_to_octal(unsigned int number) {
    if (number == 0) {
        return 0;
    } else {
        return (number % 8) + 10 * decimal_to_octal(number / 8);
    }
}
int main() {
    unsigned int liczba_10;
    printf("Podaj liczbe: \n");
    if (scanf("%u", &liczba_10) != 1) {
        printf("Incorrect input\n");
        return 1;
    }
    unsigned long long liczba_8 = decimal_to_octal(liczba_10);
    printf("%llu\n", liczba_8);
    return 0;
}