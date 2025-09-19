#include <stdio.h>
#include "vector_utils.h"


int reverse_vector(int* tab, int size){
    if(tab == NULL || size <= 0){
        return 1;
    }
    for(int i = 0; i <= size/2; i++){
        int temp = *(tab + i);
        *(tab + i) = *(tab +(size - i -1));
        *(tab +(size - i -1)) = temp;
    }
    return 0;
}


int main() {
    int tab[SIZE];
    printf("Podaj liczby:\n");
    int size = read_vector(tab, SIZE ,0);
    if(size == -2){
        printf("Incorrect input\n");
        return 1;
    }
    if(size == -1){
        printf("Not enough data available\n");
        return 3;
    }
    display_vector(tab, size);
    int result = reverse_vector(tab, size);
    if(result == 1){
        printf("Not enough data available\n");
        return 3;
    }
    display_vector(tab, size);
    return 0;
}