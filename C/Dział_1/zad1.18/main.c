#include <stdio.h>


int main(){

    float num1,num2,num3,num4,num5;
    float srednia;
    printf("Podaj piec liczb: \n");
    scanf("%f %f %f %f %f",&num1,&num2,&num3,&num4,&num5);

    srednia = (num1+num2+num3+num4+num5)/5.0;

    printf("Wynik = %.4f", srednia);
    return 0;
}
