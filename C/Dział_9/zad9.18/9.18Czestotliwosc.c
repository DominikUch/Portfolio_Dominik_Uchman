#include <stdio.h>
#include "vector_utils.h"


int histogram(int tab[],int size, int num){
    int count = 0;
    for(int i = 0; i< size; i++){
        if(tab[i] == num){
            count++;
        }
    }
    return count;
}

int freq_sort(int tab[], int size){
    if(tab == NULL || size <= 0){
        return 1;
    }
    int swapped = 0;
    for(int i =0; i < size -1 ; i++){
        for(int j =0; j < size -1 -i; j++){
            if(histogram(tab,size,tab[j]) < histogram(tab,size,tab[j+1])){
                int temp = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = temp;
                swapped = 1;
            }
            else if(histogram(tab,size,tab[j]) == histogram(tab,size,tab[j+1])){
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
    int ilosc = read_vector(tab, SIZE ,-1);
    if(ilosc == -1){
        printf("Incorrect input");
        return 1;
    }
    int result = freq_sort(tab, ilosc);
    if(result == 1){
        printf("Not enough data available");
        return 3;
    }
    display_vector(tab, ilosc);
    return 0;
}
