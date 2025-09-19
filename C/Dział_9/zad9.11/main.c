#include <stdio.h>
#include <stdlib.h>
#include "vector_utils.h"
#define SIZE 150

int sort_by_abs(int tab[], int size) {
    if (tab == NULL || size <= 0) {
        return 1;
    }
    int swapped = 0;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < (size - 1 - i); j++) {
            if (abs(tab[j]) > abs(tab[j + 1])) {
                int temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped) {
            break;
        }
    }
    return 0;
}

int main() {
    int vec[SIZE];
    printf("Podaj liczby:\n");
    int ilosc = read_vector(vec, SIZE, 0);
    if (ilosc == -1) {
        printf("Incorrect input\n");
        return 1;
    }
    if (ilosc == 0) {
        printf("Not enough data available\n");
        return 3;
    }
    if (ilosc == 1) {
        printf("%d", vec[0]);
        return 0;
    }
    int result = sort_by_abs(vec, ilosc);
    if (result == 1) {
        printf("Not enough data available\n");
        return 3;
    }
    display_vector(vec, ilosc);
    return 0;
}