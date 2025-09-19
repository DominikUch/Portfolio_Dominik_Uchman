#include <stdio.h>
#include "vector_utils.h"
#define SIZE 150

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
    int move;
    printf("Podaj przesuniecie:\n");
    if(scanf("%d", &move) != 1){
        printf("Incorrect input");
        return 1;
    }
    int direction;
    printf("Podaj kierunek przesuniecia:\n");
    if(scanf("%d", &direction) != 1){
        printf("Incorrect input\n");
        return 1;
    }
    if (direction != 1 && direction != 2) {
        printf("Incorrect input data\n");
        return 2;
    }
    if (shift(vec, ilosc, move, (enum direction)direction) == 1) {
        printf("Incorrect input data\n");
        return 1;
    }
    display_vector(vec, ilosc);
    return 0;
}