#include <stdio.h>
#include <stdlib.h>
#include "vector_utils.h"
#define SIZE 150

int sort_by_length(int tab[], int size) {
    if (tab == NULL || size <= 0) {
        return 1;
    }
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            int len1 = 0;
            int num1 = abs(tab[j]), num2 = abs(tab[j + 1]);

            if (tab[j] < 0) {
                len1++;
            }
            do {
                len1++;
                num1 /= 10;
            } while (num1 != 0);

            int len2 = 0;
            if (tab[j + 1] < 0) {
                len2++;
            }
            do {
                len2++;
                num2 /= 10;
            } while (num2 != 0);

            if (len1 > len2 || (len1 == len2 && tab[j] < tab[j + 1])) {
                int temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
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
    if (ilosc == 0) {
        printf("Not enough data available\n");
        return 3;
    }
    if (ilosc == 1) {
        printf("%d", vec[0]);
        return 0;
    }
    int result = sort_by_length(vec,ilosc);
    if(result == 1){
        printf("Not enough data available");
        return 3;
    }
    display_vector(vec, ilosc);
    return 0;
}