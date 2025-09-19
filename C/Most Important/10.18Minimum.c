#include <stdio.h>
#include "vector_utils.h"


int find_min(const int* tab, int size, int *min){
    if(tab == NULL || min == NULL || size <= 1){
        return 1;
    }
    int minimum = *(tab+0);
    for(int i=0 ; i < size; i++){
        if(*(tab+i) < minimum){
            minimum = *(tab+i);
        }
    }
    *min = minimum;
    return 0;
}


int main() {
    int tab[SIZE];
    printf("Podaj liczby:\n");
    int size = read_vector(tab, SIZE, -1);
    if(size == -1){
        printf("Not enough data available");
        return 3;
    }
    else if(size == -2){
        printf("Incorrect input");
        return 1;
    }
    int minimum;
    int result = find_min(tab, size, &minimum);
    if(result == 1){
        printf("Not enough data availalble");
        return 3;
    }
    printf("Min: %d", minimum);
    return 0;
}