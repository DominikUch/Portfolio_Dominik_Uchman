#include <stdio.h>
#define PI 3.14159
float circumference(float b){
    if(b <= 0){
        return -1;
    }
    float wynik = PI * b;
    return wynik;
}
int main(){
    float srednica;
    printf("Podaj srednice kola:\n");
    if (scanf("%f",&srednica) != 1){
        printf("Incorrect input");
        return 1;
    }
    float obwod = circumference(srednica);
    if(obwod != -1){
        printf("Obwod kola to %f", obwod);
    }
    else{
        printf("Incorrect input");
        return 1;
    }
    return 0;
}
