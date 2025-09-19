
#include <stdio.h>

int main(){
#define wielkosc_tablicy 16
    float tab[wielkosc_tablicy]={10, 11, 4, 5, 6, 12, 16, 1, 2, 3, 13, 14, 15, 7, 8, 9};
    for(int i = 0; i < wielkosc_tablicy; i += 2){
        printf("%.0f\n", tab[i]);
    }
    return 0;
}