#include <stdio.h>

int main(){
    //C1 odpowiada pierwszej czesci numeru,C2 drugiej czesci numeru,C3 trzeciej czesci
    int numC1,numC2,numC3,kierunkowy;

    printf("podaj numer telefonu(ddd-dd-dd):");
    scanf("%03d-%02d-%02d",&numC1,&numC2,&numC3);

    printf("Podaj numer kierunkowy(dd):");
    scanf("%02d", &kierunkowy);

    printf("(%02d) %03d-%02d-%02d", kierunkowy, numC1,numC2,numC3);
    return 0;
}