#include <stdio.h>
#define PI 3.14159

float toRadian(float a){
    return (a * 2 * PI ) / 360;
}
float toDegree(float a){
    return (a * 360)/ (2 * PI);
}
int main(){

    int wybor;
    printf("Wybierz rodzaj konwersji (1=stopnie na radiany, 2=radiany na stopnie):\n");
    if(scanf("%d", &wybor) != 1){
        printf("Incorrect input");
        return 1;
    }
    if(wybor == 1 || wybor == 2){
        float kat;
        printf("Podja miare kata:\n");
        if(scanf("%f", &kat) != 1){
            printf("Incorrect input");
            return 1;
        }
        if(wybor == 1){
            float wynik = toRadian(kat);
            printf("Wynik: %.2f", wynik);
        }
        else if(wybor == 2){
            float wynik = toDegree(kat);
            printf("Wynik: %.2f", wynik);
        }
    }
    else{
        printf("Incorrect input");
        return 1;
    }
    return 0;
}
