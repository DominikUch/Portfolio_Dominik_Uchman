#include <stdio.h>
#include <math.h>

int main(){

    double a,b,c,alfa,beta,PI;
    PI = 3.14159265358979323846;
    printf("Podaj pierwsza przyprostokatna:\n");
    scanf("%lf", &a);

    printf("Podaj druga przyprostokatna:\n");
    scanf("%lf",&b);

    c = sqrt(a*a + b*b);
    printf("Przeciwprostokatna: %.2lf\n",c);

    alfa = atan2(a,b) * 180.0 / PI;
    beta = 90.0 - alfa;

    printf("%.2lf\n", alfa);
    printf("%.2lf\n", beta);
    return 0;
}