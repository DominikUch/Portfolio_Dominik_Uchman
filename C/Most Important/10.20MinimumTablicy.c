#include <stdio.h>
#include "vector_utils.h"

int find(const int *tab, int size, int to_find) {
    static const int *ptr;
    static int i_;
    static int size_;

    if(tab == NULL && ptr == NULL) {
        return -2;
    }

    if((size <= 0) && (tab != NULL)) {
        return -2;
    }

    int i =0;
    // Zamiana danych
    if(tab == NULL && ptr != NULL) {
        tab = ptr;
        i = i_;
        size = size_;
    }

    if(i >= size) {
        return -1;
    }

    //pierwsze przejście ptr == NULL, potem tab == NULL i ptr != NULL
    for(; i < size; i++) {
        if (*(tab + i) == to_find) {
            ptr = tab;
            i_ = i + 1;
            size_ = size;
            return i;
        }
    }
    return -1;
}


int main() {
    printf("Podaj liczby:\n");
    int tab[SIZE];
    int size = read_vector(tab, SIZE, 0);
    if(size == -1){
        printf("Not enough data available\n");
        return 3;
    }
    if(size == -2){
        printf("Incorrect input\n");
        return 1;
    }
    if(size == 0){
        printf("Not enough data available\n");
        return 3;
    }
    int wanted;
    printf("Podaj szukana wartosc:\n");
    if(!scanf("%d", &wanted)) {
        printf("Incorrect input\n");
        return 1;
    }
    int found = 0;
    int result = find(tab, size, wanted);
    //analogia to 9.23WyrazyAlfabetycznie
    while(result != -1){
        found++;
        printf("%d ", result);
        //ustawiawsz tab na NULL
        result = find(NULL, size , wanted);
    }
    if(!found){
        printf("Nothing to show\n");
    }
    return 0;
}