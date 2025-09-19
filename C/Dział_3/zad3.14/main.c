
#include <stdio.h>

int main() {
    float num1;
    float suma = 0.0;
    float max = 0.0;
    float min = 0.0;
    printf("Podaj liczbe:\n");
    for (int i = 0; i < 100; i++) {
        int user_input = scanf("%f", &num1);
        if (user_input != 1) {
            printf("Incorrect input");
            return 1;
        }
        if (i == 0) {
            min = num1;
            max = num1;
        } else {
            //minimum
            if (num1 < min) {
                min = num1;
            }
            //maksimum
            if (num1 > max) {
                max = num1;
            }
        }
        //suma
        suma = suma + num1;
    }
    //srednia
    float srednia;
    srednia = suma / 100;

    //wyswietlanie
    printf("%f\n", min);
    printf("%f\n", max);
    printf("%.2f\n", srednia);
    return 0;
}




