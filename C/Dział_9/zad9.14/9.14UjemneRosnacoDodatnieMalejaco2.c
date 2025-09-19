#include <stdio.h>
#include "vector_utils.h"



int sort_negative_asc_positive_desc(int tab[], int size) {
    if (tab == NULL || size < 1) {
        return 1;
    }
    // Sort negative numbers in ascending order
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (tab[i] < 0 && tab[j] < 0 && tab[i] > tab[j]) {
                int temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
        }
    }
    // Sort non-negative numbers in descending order
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (tab[i] >= 0 && tab[j] >= 0 && tab[i] < tab[j]) {
                int temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
        }
    }
    return 0;
}


int main(){
    int tab[SIZE];
    printf("Podaj liczby:\n");
    int ilosc = read_vector(tab, SIZE, 0);
    if(ilosc == -1){
        printf("Incorrect input");
        return 1;
    }
    int result = sort_negative_asc_positive_desc(tab, ilosc);
    if(result == 1){
        printf("Not enough data available");
        return 3;
    }
    else{
        sort_negative_asc_positive_desc(tab,ilosc);
        display_vector(tab, ilosc);
    }
    return 0;
}
