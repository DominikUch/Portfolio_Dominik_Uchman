#include "vector_utils.h"
#include <stdio.h>


int read_vector(int vec[], int size, int stop_value) {
    int ilosc = 0;
    while (1) {
        int liczba;
        if (scanf("%d", &liczba) != 1) {
            return -1;
        }
        if (liczba == stop_value || ilosc >= size) {
            break;
        }
        vec[ilosc] = liczba;
        ilosc++;
    }
    while (getchar() != '\n');
    return ilosc;
}

void display_vector(const int vec[], int size) {
    if (vec == NULL || size <= 0) {
        return;
    }
    for (int i = 0; i < size; i++) {
        printf("%d ", vec[i]);
    }
    printf("\n");
}