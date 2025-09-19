#include <stdio.h>
#include "vector_utils.h"
#define SIZE 150

int sort_odd_desc(int tab[], int size){
    if (tab == NULL || size <= 0) {
        return 1;
    }
    int swapped = 0;
    for (int i = 1; i < size - 1; i+=2) {
        for (int j = 1; j < (size - i - 1); j+=2) {
            if (tab[j] < tab[j + 2]) {
                int temp = tab[j];
                tab[j] = tab[j + 2];
                tab[j + 2] = temp;
                swapped = 1;
            }
        }
        if (!swapped) {
            break;
        }
    }
    return 0;

}
int sort_even_asc(int tab[], int size){
    if (tab == NULL || size <= 0) {
        return 1;
    }
    int swapped = 0;
    for (int i = 0; i < size - 1; i+=2) {
        for (int j = 0; j < (size - 2 - i); j+=2) {
            if (tab[j] > tab[j + 2]) {
                int temp = tab[j];
                tab[j] = tab[j + 2];
                tab[j + 2] = temp;
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

    int result1 = sort_odd_desc(vec,ilosc);
    if (result1 == 1) {
        printf("Not enough data available\n");
        return 3;
    }
    int result2 = sort_even_asc(vec,ilosc);
    if (result2 == 1) {
        printf("Not enough data available\n");
        return 3;
    }
    display_vector(vec, ilosc);
    return 0;
}