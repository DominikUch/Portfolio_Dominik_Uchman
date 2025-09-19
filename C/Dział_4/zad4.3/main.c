#include <stdio.h>

int main(){
#define wielkosc_tablicy 11
    int liczby[wielkosc_tablicy];
    for(int i = 0; i < wielkosc_tablicy; i++){
        liczby[i] = i;
    }
    for(int i = 0; i < wielkosc_tablicy; i++){
        printf("%d ", liczby[i]);
    }
    printf("\n");
    return 0;
}