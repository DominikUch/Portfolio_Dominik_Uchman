#include <stdio.h>
#define SIZE 17
int horner(const char binary[]) {
    int result = 0;
    for (int i = 0; binary[i] != '\0'; ++i) {
        if (binary[i] == '0' || binary[i] == '1') {
            result = result * 2 + (binary[i] - '0');
        } else {
            return -1;
        }
    }
    return result;
}
int main() {
    char binary[SIZE];
    printf("Wprowadz liczbe binarna:\n");
    if (scanf("%16s", binary) != 1) {
        printf("Incorrect input\n");
        return 1;
    }
    int decimal = horner(binary);
    if (decimal != -1) {
        printf("%d\n", decimal);
    } else {
        printf("Incorrect input\n");
        return 1;
    }
    return 0;
}