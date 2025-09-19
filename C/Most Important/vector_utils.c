#include <stdio.h>
#include "vector_utils.h"


int read_vector_ll(long long* tab, int size, int stop_value){
    if(tab == NULL || size <= 0 || size > SIZE){
        return -1;
    }
    int count =0;
    for(; count < size; count++){
        if(scanf("%lld", &(*(tab+count))) != 1){
            return -2;
        }
        if(*(tab+count) == stop_value){
            break;
        }
    }
    while (getchar() != '\n');
    return count;
}

void display_vector_ll(const long long *tab, int size){
    if(tab == NULL || size <= 0) return;
    for(int i = 0; i < size; i++){
        printf("%lld ", *(tab+i));
    }
    printf("\n");
}


