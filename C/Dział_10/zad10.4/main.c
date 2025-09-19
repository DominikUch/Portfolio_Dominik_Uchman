#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 20

int main() {
    int array[SIZE];
    int *wdt = array;

    srand(time(NULL));

    for (int i = 0; i < SIZE; i++) {
        *wdt = rand() % 20;
        wdt++;
    }
    wdt = array;
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", *wdt);
        wdt++;
    }
    printf("\n");
    wdt = array;
    for (int i = 0; i < SIZE; i += 2) {
        printf("%d ", *wdt);
        wdt += 2;
    }
    printf("\n");
    return 0;
}