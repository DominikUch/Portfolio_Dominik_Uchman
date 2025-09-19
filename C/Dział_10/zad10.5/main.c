

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 20
int main() {

    float array[SIZE];
    float *ptr = array;

    srand(time(NULL));
    for (int i = 0; i <SIZE; i++) {
        *ptr = (float)rand() / RAND_MAX;
        ptr++;
    }
    ptr = array;
    for (int i = 0; i < SIZE; i++) {
        printf("%f ", *ptr);
        ptr++;
    }
    printf("\n");
    ptr = array;
    for (int i = 0; i < SIZE; i += 2) {
        printf("%f ", *ptr);
        ptr += 2;
    }
    printf("\n");
    return 0;
}