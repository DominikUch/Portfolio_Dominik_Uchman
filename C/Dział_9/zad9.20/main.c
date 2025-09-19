#include <stdio.h>
#include <stdlib.h>
#include "vector_utils.h"
#define SIZE 150

int sort_by_sum(int tab[], int size) {
    if (tab == NULL || size <= 0) {
        return 1;
    }
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            int sum1 = 0;
            int num1 = abs(tab[j]);
            while (num1 != 0) {
                sum1 += num1 % 10;
                num1 /= 10;
            }
            int sum2 = 0;
            int num2 = abs(tab[j + 1]);
            while (num2 != 0) {
                sum2 += num2 % 10;
                num2 /= 10;
            }
            if (sum1 > sum2 || (sum1 == sum2 && tab[j] > tab[j + 1])) {
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
    int result = sort_by_sum(vec,ilosc);
    if(result == 1){
        printf("Not enough data available");
        return 3;
    }
    display_vector(vec, ilosc);
    return 0;
}