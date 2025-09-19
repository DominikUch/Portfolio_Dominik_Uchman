#include <stdio.h>
#include "vector_utils.h"
#define SIZE 150

int complex_sort(int tab[], int size) {
    if (tab == NULL || size <= 0 || size % 2 != 0) {
        return 1;
    }
    for (int i = 0; i < size - 2; i += 2) {
        for (int j = 0; j < size - i - 2; j += 2) {
            if (tab[j] > tab[j + 2] || (tab[j] == tab[j + 2] && tab[j + 1] < tab[j + 3])) {
                int temp_real = tab[j];
                int temp_imag = tab[j + 1];

                tab[j] = tab[j + 2];
                tab[j + 1] = tab[j + 3];

                tab[j + 2] = temp_real;
                tab[j + 3] = temp_imag;
            }
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
    if (ilosc % 2 != 0) {
        printf("Incorrect input data\n");
        return 2;
    }
    if (ilosc == 0) {
        printf("Not enough data available\n");
        return 3;
    }
    if (ilosc == 1) {
        printf("%d", vec[0]);
        return 0;
    }
    int result = complex_sort(vec,ilosc);
    if(result == 1){
        printf("Incorrect input data");
        return 3;
    }
    display_vector(vec, ilosc);
    return 0;
}