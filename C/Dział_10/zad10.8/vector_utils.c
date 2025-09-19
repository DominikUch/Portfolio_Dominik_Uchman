#include <stdio.h>
#include "vector_utils.h"

int read_vector(int *vec, int size, int stop_value) {
    int ilosc = 0;
    while (1) {
        int liczba;
        if (scanf("%d", &liczba) != 1) {
            return -1;
        }
        if (liczba == stop_value || ilosc >= size) {
            break;
        }
        *vec = liczba;
        vec++;
        ilosc++;
    }
    while (getchar() != '\n');
    return ilosc;
}
void display_vector(const int* tab, int size) {
    if (tab == NULL || size <= 0) {
        return;
    }
    for (const int *ptr = tab; ptr < tab + size; ++ptr) {
        printf("%d ", *ptr);
    }
    printf("\n");
}