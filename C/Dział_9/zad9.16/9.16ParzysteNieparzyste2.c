#include <stdio.h>
#include "vector_utils.h"

int is_even(int number){
    if(number % 2 == 0){
        return 1;
    }
    else{
        return 0;
    }
}

void sort_helper(int tab[], int size){
    int swapped = 0;
    for(int i = 0 ; i < size-1 ; i++){
        for(int j = 0; j < size-1-i; j++){
            if(is_even(tab[j]) == 1){
                int temp = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = temp;
                swapped =1;
            }
        }
        if(!swapped){
            break;
        }
    }
}

int sort_odd_asc_even_desc(int tab[], int size){
    if(tab == NULL || size <= 0){
        return 1;
    }
    sort_helper(tab, size);
    for(int i = 0 ; i < size-1 ; i++){
        for(int j = 0; j < size-1-i; j++){
            //nieparzyste
            if((is_even(tab[j]) == 0 && is_even(tab[j+1]) == 0) && tab[j] > tab[j+1]){
                int temp = tab[j+1];
                tab[j+1] = tab[j];
                tab[j] = temp;
            }
            //parzyste
            else if((is_even(tab[j]) == 1 && is_even(tab[j+1]) == 1) && tab[j] <= tab[j+1]){
                int temp2 = tab[j+1];
                tab[j+1] = tab[j];
                tab[j] = temp2;
            }
        }
    }
    return 0;
}



int main() {
    printf("Podaj liczby:\n");
    int tab[SIZE];
    int ilosc = read_vector(tab,SIZE, 0);
    if(ilosc == -1){
        printf("Incorrect input");
        return 1;
    }
    int result = sort_odd_asc_even_desc(tab ,ilosc);
    if(result == 1){
        printf("Not enough data available");
        return 3;
    }
    display_vector(tab,ilosc);
    return 0;
}
