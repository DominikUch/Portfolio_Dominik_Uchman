#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int dd_test(const int *ptr, int width, int height){
    if(ptr == NULL || width <= 0 ||  height <= 0 || width != height){
        return -1;
    }
    int row_sum;
    for(int i=0; i < height; i++){
        row_sum = 0;
        int current_element = *(ptr+(i*width)+i);
        for(int j =0; j < width; j++){
            if(  *(ptr+(i*width) + j) == current_element){
                continue;
            }
            row_sum += abs(*(ptr+(i*width) + j));
            if(row_sum >= abs(current_element)){
                return 0;
            }
        }
    }
    if(row_sum != 0){
        return 1;
    }
    else{
        return 0;
    }
}

int main() {
    int tab[SIZE][SIZE];
    printf("Podaj liczby:\n");
    for(int i =0; i < SIZE; i++){
        for(int j =0; j < SIZE; j++){
            if(scanf("%d", &*(*(tab+i)+j)) != 1){
                printf("Incorrect input");
                return 1;
            }
        }
    }
    int result = dd_test(*tab, SIZE, SIZE);
    if(result == 0){
        printf("NO");
    }
    else if(result == 1){
        printf("YES");
    }
    else{
        printf("Incorrect input");
        return 1;
    }
    return 0;
}

