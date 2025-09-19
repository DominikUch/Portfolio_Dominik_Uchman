#include <stdio.h>

int main() {
    float a;
    float b;
    printf("Podaj a:");
    if (scanf("%f", &a) != 1){
        printf("Incorrect input");
        return 1;
    }
    printf("Podaj b:");
    if (scanf("%f", &b) != 1){
        printf("Incorrect input");
        return 1;
    }
    float lewa_strona;
    lewa_strona = (a+b) *(a-(b));

    float prawa_strona;
    prawa_strona = (a*a) + (b*b);

    if(lewa_strona == prawa_strona){
        printf("tozsamosc jest prawdziwa");
    }
    else{
        printf("tozsamosc nie jest prawdziwa");
    }
    return 0;
}