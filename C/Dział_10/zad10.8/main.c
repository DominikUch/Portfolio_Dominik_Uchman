#include <stdio.h>
#include "vector_utils.h"
#define SIZE 100

int sort(int* tab, int size) {
    if (tab == NULL || size <= 0) {
        return 1;
    }
    for (int* i = tab; i < tab + size - 1; ++i) {
        for (int* j = tab; j < tab + size - (i - tab) - 1; ++j) {
            if (*j > *(j + 1)) {
                int temp = *j;
                *j = *(j + 1);
                *(j + 1) = temp;
            }
        }
    }
    return 0;
}

int main() {
    int vec[SIZE];
    printf("Podaj liczby:\n");
    int ilosc = read_vector(vec, SIZE, -1);
    if (ilosc == -1) {
        printf("Incorrect input\n");
        return 1;
    }
    if (ilosc == 0) {
        printf("Not enough data available\n");
        return 3;
    }
    sort(vec, ilosc);
    display_vector(vec, ilosc);

    return 0;
}