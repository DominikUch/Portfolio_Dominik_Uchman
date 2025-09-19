#include <stdio.h>
#include "vector_utils.h"
#define SIZE 100

int reverse_vector(int *tab, int size) {
    if (tab == NULL || size <= 0) {
        return 1;
    }
    int middle = size / 2;
    int *start = tab;
    int *end = tab + size - 1;

    for (int i = 0; i < middle; i++) {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
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
    display_vector(vec, ilosc);
    int result = reverse_vector(vec,ilosc);
    if(result == 1){
        printf("Not enough data available");
        return 3;
    }
    display_vector(vec, ilosc);
    return 0;
}