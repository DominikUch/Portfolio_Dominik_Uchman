
#include <stdio.h>

int main() {
    double liczba;
    int user_input;
    double max = 0.0;
    double min = -0.0;
    double suma = 0.0;
    double srednia = 0.0;
    int ilosc = 0;

    printf("Podaj liczbe:\n");
    while (1) {
        user_input = scanf("%lf", &liczba);
        if (user_input != 1) {
            printf("Incorrect input");
            return 1;
        }
        if (liczba == -1) {
            break;
        } else {
            //minimum
            if (ilosc == 0 || liczba < min) {
                min = liczba;
            }
            //maximum
            if (ilosc == 0 || liczba > max) {
                max = liczba;
            }
            suma = suma + liczba;
            ilosc = ilosc + 1;
        }
        srednia = suma / ilosc;
    }
    //wyswietlanie
    printf("%lf\n", min);
    printf("%lf\n", max);
    printf("%.2lf\n", srednia);

    return 0;
}




