#include <stdio.h>

int main() {
    int T[10];
    int *ptr = T;
    for (int i = 0; i < 10; i++) {
        *ptr = i;
        ptr++;
    }

    ptr = T;
    for (int i = 0; i < 10; i++) {
        printf("%d ", *ptr);
        ptr++;
    }

    return 0;
}