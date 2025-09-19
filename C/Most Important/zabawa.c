#include <stdio.h>
#include <string.h>

////////////////////////////// ZADANIE 1 //////////////////////////////

int lenght(int n){
    if(n < 10){
        return 1;
    }
    return 1 + lenght(n/10);
}

int main(){
    printf("------------Zadanie 1------------\n");
    printf("Podaj liczbe\n");
    int num;
    if(scanf("%d", &num)!= 1){
        printf("Incorrect input");
        return 1;
    }
    if(num < 1000 || num > 9999){
        int len = lenght(num);
        printf("Incorrect len - %d", len);
        return 2;
    }
    return 0;
}
