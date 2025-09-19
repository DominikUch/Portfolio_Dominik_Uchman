#include <stdio.h>
#include <math.h>

int main(){

    float x,y;
    printf("Podaj wartosc x:\n");
    scanf("%f", &x);

    y= 2*pow(x,3)-4*pow(x,2)+3*x-7;

    printf("wartosc funkcji y= %f",y);
    return 0;
}
