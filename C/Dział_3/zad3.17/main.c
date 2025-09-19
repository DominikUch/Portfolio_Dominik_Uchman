
#include <stdio.h>
#include <math.h>

int main() {
    double liczba;
    int user_input;
    double suma = 0.0;
    printf("Podaj 10 liczb:\n");
    for(int i = 0; i < 10; i++){
    user_input = scanf("%lf", &liczba);
    if(user_input != 1){
        printf("Incorrect input");
        return 1;
    }
    suma = suma + fabs(liczba);
    }
    printf("%.2lf", suma);
    return 0;
}




