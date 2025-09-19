#include <stdio.h>
float quadratic_equation(float a, float b, float c, float x){
    return (a*x*x)+(b*x)+c;
}
int main(){
    float a;
    float b;
    float c;
    printf("Podaj rowannie:\n");
    if(scanf("%fx^2%fx%f", &a,&b,&c) != 3){
        printf("Incorrect input");
        return 1;
    }
    float x;
    printf("Podaj x:\n");
    if(scanf("%f", &x) != 1){
        printf("Incorrect input");
        return 1;
    }
    float wynik = quadratic_equation(a,b,c,x);
    printf("Wynik: %f",wynik);
    return 0;
}
