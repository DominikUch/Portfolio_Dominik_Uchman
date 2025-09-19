#include <stdio.h>

int main(){
#define wielkosc_tablicy 11
    int liczby[wielkosc_tablicy] = {0,1,2,3,4,5,6,7,8,9,10};
    printf("%d %d %d %d %d %d %d %d %d %d %d\n",liczby[0],liczby[1],liczby[2],liczby[3],liczby[4],
           liczby[5],liczby[6],liczby[7],liczby[8],liczby[9],liczby[10]);

    for (int i=0; i < 11; i++){
        printf("%d\n", liczby[i]);
    }
    return 0;
}