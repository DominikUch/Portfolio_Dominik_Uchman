
#include <stdio.h>

int main() {
    int min;
    int max;

    printf("Podaj min:\n");
    if (scanf("%d", &min) != 1) {
        printf("Incorrect input");
        return 1;
    }
    printf("Podaj max:\n");
    if (scanf("%d", &max) != 1) {
        printf("Incorrect input");
        return 1;
    }
    if (min > max) {
        printf("Incorrect range");
        return 2;
    }
    for (int i = min; i <= max; i++) {
        printf("%d ", i);
    }
    return 0;
}




