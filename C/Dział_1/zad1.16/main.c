#include <stdio.h>
#include <math.h>

int main() {

    int a,b,c;
    float dlugosc;

    printf("Podaj wartosc a: \n");
    scanf("%d", &a);

    printf("Podaj wartosc b: \n");
    scanf("%d", &b);

    printf("Podaj wartosc c: \n");
    scanf("%d", &c);

    dlugosc = sqrt((a*a)+(b*b)+(c*c));
    printf("dlugosc wektora(a,b,c) = %.2f", dlugosc);

    return 0;
}
