#include <stdio.h>



int swap(int* a, int* b){
    if(a == NULL || b == NULL){
        return 1;
    }
    int temp = *a;
    *a = *b;
    *b = temp;
    return 0;
}

int clamp(int *v, int lo, int hi){
    if(v == NULL){
        return 1;
    }
    if(lo > hi){
        swap(&lo,&hi);
    }

    if(*v < lo){
        *v = lo;
    }
    if(*v > hi){
        *v = hi;
    }
    return 0;
}


int main() {
    printf("Podaj liczbe:\n");
    int num1;
    if(scanf("%d", &num1) != 1 ){
        printf("Incorrect input");
        return 1;
    }
    int lo;
    printf("Podaj granice 1:\n");
    if(scanf("%d", &lo) != 1 ){
        printf("Incorrect input");
        return 1;
    }
    int hi;
    printf("Podaj granice 2:\n");
    if(scanf("%d", &hi) != 1 ){
        printf("Incorrect input");
        return 1;
    }
    int *pta = &num1;
    int result = clamp(pta, lo, hi);
    if(result == 1){
        printf("Incorrect input");
        return 1;
    }
    printf("%d", *pta);
    return 0;
}