#include <stdio.h>
#include "vector_utils.h"
#define SIZE 150

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
        *vec++ = liczba;
        ilosc++;
    }
    while (getchar() != '\n');
    return ilosc;
}
int find_min(const int *tab, int size, int *min) {
    if (tab == NULL || size <= 0 || min == NULL) {
        return 1;
    }
    const int *ptr = tab;
    int minimum = *ptr;
    for (int i = 1; i < size; i++) {
        ptr++;
        if (*ptr < minimum) {
            minimum = *ptr;
        }
    }

    *min = minimum;
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
    int min_val;
    int result = find_min(vec, ilosc, &min_val);
    if (result == 0) {
        printf("Min: %d\n", min_val);
    } else {
        printf("Not enough data available\n");
        return 3;
    }
    return 0;
}