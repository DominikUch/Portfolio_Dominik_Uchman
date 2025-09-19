#include <stdio.h>
#include "vector_utils.h"


int number_dividers(int n){
    int dividers = 0;
    if(n == 0){
        return 0;
    }
    if(n < 0){
         n *= -1;
    }
    for(int i = 1; i <= n; i++){
        if(n % i == 0){
            dividers++;
        }
    }
    return dividers;
}

int sort_by_dividers(int tab[], int size){
    if(tab == NULL || size <= 0){
        return 1;
    }
    int swapped = 0;
    for(int i =0; i < size - 1; i++){
        for(int j = 0; j < size - 1 -i; j++){
            if(number_dividers(tab[j]) > number_dividers(tab[j+1])){
                int temp = tab[j];
                tab[j] =  tab[j+1];
                tab[j+1] = temp;
                swapped = 1;
            }
            else if(number_dividers(tab[j]) == number_dividers(tab[j+1])){
                if(tab[j] > tab[j+1]){
                    int temp = tab[j];
                    tab[j] = tab[j+1];
                    tab[j+1] = temp;
                    swapped = 1;
                }
            }
        }
        if(!swapped){
            break;
        }
    }
    return 0;
}


int main() {
    printf("Podaj wektor:\n");
    int tab[SIZE];
    int ilosc = read_vector(tab, SIZE , 0);
    if(ilosc == -1){
        printf("Incorrect input");
        return 1;
    }
    int result = sort_by_dividers(tab,ilosc);
    if(result == 1){
        printf("Not enough data available");
        return 3;
    }
    display_vector(tab, ilosc);

    return 0;
}
