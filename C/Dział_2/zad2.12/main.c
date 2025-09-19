
#include <stdio.h>
#include <math.h>
int main(){
    float a,b,c;
    printf("Program rozwiazujący rownanie kwadratowe postaci 0 = ax^2 + bx + c\n");
    printf("Podaj a:\n");
    scanf("%f", &a);
    printf("Podaj b:\n");
    scanf("%f", &b);
    printf("Podaj c:\n");
    scanf("%f", &c);

    float delta = (b * b) + ((-4)*a*c);
    if((a == 0) && (b != 0)){
        float pier_a0 = (-c) / b;
        printf("jeden pierwiastek: %f\n", pier_a0);
    }
    else if((a == 0) && (b == 0) && (c == 0)){
        printf("nieskonczonosc\n");
    }
    else if ((a == 0) && (b == 0)){
        printf("brak\n");
    }
    else if((a != 0) && (b != 0)){
        float pier_a_1 = ((-b) - (sqrtf(delta)))/(2*a);
        float pier_a_2 = ((-b) + (sqrtf(delta)))/(2*a);
        if (pier_a_1 == pier_a_2){
            printf("jeden pierwiastek: %f\n", pier_a_1);
        }
        else if (delta < 0){
            printf("brak");
        }
        else{
            printf("Dwa pierwiastki: %f %f\n", pier_a_1, pier_a_2);
        }
    }
    return 0;
}