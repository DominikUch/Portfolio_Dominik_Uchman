#include <stdio.h>
#include "vector_utils.h"
#define SIZE 150


int bubble_sort(int tab[], int size) {
    if (tab == NULL || size <= 0) {
        return 1;
    }
    int swapped;
    for (int i = 0; i < size - 1; i++) {
        swapped = 0;
        for (int j = 0; j < size - i - 1; j++) {
            if (tab[j] > tab[j + 1]) {
                int temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped) {
            break;
        }
        display_vector(tab, size);
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
    int result = bubble_sort(vec,ilosc);
    if(result == 1){
        printf("Not enough data available");
        return 3;
    }
    display_vector(vec, ilosc);
    return 0;
}