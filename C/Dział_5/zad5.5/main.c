#include <stdio.h>
#define DLUGOSC 1001
#define DLUGOSC_SAMOGLOSEK 12
int main() {
    char tekst[DLUGOSC];

    printf("Podaj tekst:");
    fgets(tekst, DLUGOSC, stdin);

    int ilosc_samoglosek = 0;
    char samogloski[DLUGOSC_SAMOGLOSEK] = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U', 'y', 'Y'};
    int zliczone_samogloski[DLUGOSC_SAMOGLOSEK] = {0};
    for (int i = 0; i < DLUGOSC; i++) {
        if (tekst[i] == '\0') {
            break;
        }
        for (int j = 0; j < DLUGOSC_SAMOGLOSEK; j++) {
            if (tekst[i] == samogloski[j]) {
                if (zliczone_samogloski[j] == 0) {
                    zliczone_samogloski[j] = 1;
                    ilosc_samoglosek++;
                    break;
                }
                else{
                    continue;
                }
            }
        }
    }
    printf("Wynik: %d", ilosc_samoglosek);
    return 0;
}