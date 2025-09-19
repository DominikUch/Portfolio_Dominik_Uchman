#include <stdio.h>
#include "vector_utils.h"


int sort_all(int tab[], int size){
    if(tab == NULL || size <=0 ){
        return 1;
    }
    int swapped = 0;
    for(int i =0; i < size - 1; i ++){
        for(int j =0; j < size - i - 1; j++){
            if(tab[j] > tab[j+1]){
                int temp = tab[j+1];
                tab[j+1] = tab[j];
                tab[j] = temp;
                swapped = 1;
            }
        }
        if(!swapped){
            break;
        }
    }
    return 0;
}

int sort_negative_asc_positive_desc(int tab[], int size){
    if(tab == NULL || size <=0 ){
        return 1;
    }
    sort_all(tab, size);
    for(int i =0; i < size - 1; i ++){
        for(int j =0; j < size - i - 1; j++){
            if(tab[j] < 0 && tab[j+1] < 0){
                if(tab[j] > tab[j+1]){
                    int temp = tab[j+1];
                    tab[j+1] = tab[j];
                    tab[j] = temp;
                }
            }
            else if(tab[j] >= 0 && tab[j + 1]>=0){
                if(tab[j] < tab[j+1]){
                    int temp = tab[j+1];
                    tab[j+1] = tab[j];
                    tab[j] = temp;
                }
            }
        }
    }
    return 0;
}




int main() {
    printf("Podaj liczby:\n");
    int tab[SIZE];
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
        sort_negative_asc_positive_desc(tab, ilosc);
        display_vector(tab, ilosc);
    }
    return 0;
}
