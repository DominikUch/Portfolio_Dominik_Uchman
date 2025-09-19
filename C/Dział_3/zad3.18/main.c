
#include <stdio.h>

int main() {
    int liczba;
    int user_input;
    int suma_parzystych = 0;
    int suma_nieparzystych = 0;
    printf("podaj liczby:");
    while (1) {
        user_input = scanf("%d", &liczba);
        if (user_input != 1) {
            printf("Incorrect input");
            return 1;
        }
        if (liczba == -1) {
            break;
        }
        //suma parzystych
        if (liczba % 2 == 0) {
            suma_parzystych = suma_parzystych + liczba;
        }
            //suma nieparzystych
        else {
            suma_nieparzystych = suma_nieparzystych + liczba;
        }
    }
    //wyświetlanie
    printf("suma liczb parzystych: %d\n", suma_parzystych);
    printf("suma liczb nieparzystych: %d\n", suma_nieparzystych);
    return 0;
}




