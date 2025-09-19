
#include <stdio.h>

int main() {
    float min;
    float max;

    printf("Podaj min:\n");
    if (scanf("%f", &min) != 1) {
        printf("Incorrect input");
        return 1;
    }
    printf("Podaj max:\n");
    if (scanf("%f", &max) != 1) {
        printf("Incorrect input");
        return 1;
    }
    if (min > max) {
        printf("Incorrect range");
        return 2;
    }
    for (float i = min; i <= max; i = i + 0.25) {
        printf("%f ", i);
    }
    return 0;
}




