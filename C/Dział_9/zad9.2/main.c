#include <stdio.h>
#include "vector_utils.h"
#include "sort.h"
#define SIZE 50

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
    int kierunek;
    printf("Podaj kierunek sortowania:\n");
    if (scanf("%d", &kierunek) != 1) {
        printf("Incorrect input\n");
        return 1;
    }
    if (kierunek != 1 && kierunek != 2) {
        printf("Incorrect input data\n");
        return 2;
    }
    if (ilosc == 1) {
        printf("%d", vec[0]);
        return 0;
    }
    enum direction dir;
    if (kierunek == 1) {
        dir = ASCENDING;
    } else if (kierunek == 2) {
        dir = DESCENDING;
    } else {
        printf("Incorrect input data\n");
        return 2;
    }

    int result = bubble_sort(vec, ilosc, dir);
    if (result == 1) {
        printf("Incorrect data\n");
        return 1;
    } else if (result == 2) {
        printf("Incorrect input data\n");
        return 2;
    }
    display_vector(vec, ilosc);
    return 0;
}