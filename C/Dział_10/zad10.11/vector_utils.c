#include "vector_utils.h"
#include <stdio.h>

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

int shift(int *array, int array_size, int positions_to_shift, enum direction dir) {
    if (array == NULL || array_size <= 0 || positions_to_shift < 0) {
        return 1;
    }
    positions_to_shift = positions_to_shift % array_size;

    if (dir == ROTATE_RIGHT) {
        while (positions_to_shift > 0) {
            int temp = *(array + array_size - 1);
            for (int i = array_size - 1; i > 0; --i) {
                *(array + i) = *(array + i - 1);
            }
            *array = temp;
            positions_to_shift--;
        }
    } else if (dir == ROTATE_LEFT) {
        while (positions_to_shift > 0) {
            int temp = *array;
            for (int i = 0; i < array_size - 1; ++i) {
                *(array + i) = *(array + i + 1);
            }
            *(array + array_size - 1) = temp;
            positions_to_shift--;
        }
    } else {
        return 1;
    }
    return 0;
}