#include <stdio.h>

int main() {
    const double PI = 3.1415926535897932;
    double promien;
    while (1){
        printf("Podaj promien kola\n");
        if((scanf("%lf", &promien) == 1) && promien > 0){
            break;
        }
        else{
            printf("Incorrect input\n");
            while (getchar() != '\n');
        }
    }
    double obwod = 2 * promien * PI;
    double pole = PI * promien * promien;
    printf("obwod kola: %.15f\n", obwod);
    printf("pole kola: %.15f\n", pole);
}