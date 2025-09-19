#include <stdio.h>
#include "vector_utils.h"


int product_left(const long long *input, int input_size, long long *output, int output_size){
    if(input == NULL || input_size <=1 || output == NULL || output_size <= 1){
        return 1;
    }
    *(output + 0) = 1;
    for(int i =1; i < input_size; i++){
        long long current_mult = 1;
        for(int j = 0; j < i; j++){
            current_mult *= *(input+j);
        }
        *(output+i) = current_mult;
    }
    return 0;
}

int product_right(const long long *input, int input_size, long long *output, int output_size){
    if(input == NULL || input_size <=1 || output == NULL || output_size <= 1){
        return 1;
    }
    *(output + (input_size-1)) = 1;
    for(int i = 0; i < input_size-1; i++){
        long long current_mult = 1;
        for(int j = i+1; j < input_size; j++){
            current_mult *= *(input+j);
        }
        *(output+i) = current_mult;
    }
    return 0;
}

int main() {
    long long tab[SIZE];
    printf("Podaj liczbvy:\n");
    int size = read_vector_ll(tab, SIZE, -1);
    if(size == -2){
        printf("Incorrect input");
        return 1;
    }
    if(size == -1){
        printf("Not enough data available");
        return 3;
    }
    long long results_right[SIZE];
    int wynik1 = product_right(tab, size, results_right, size);
    if(wynik1 == 1){
        printf("Not enough data available\n");
        return 3;
    }
    long long results_left[SIZE];
    int wynik2 =product_left(tab, size, results_left, size);
    if(wynik2 == 1){
        printf("Not enough data available\n");
        return 3;
    }
    long long results[SIZE];
    for(int i=0; i < size; i++){
        *(results + i) = *(results_left+i) * *(results_right+i);
    }
    display_vector_ll(results, size);
    return 0;
}