#include <stdio.h>
int main() {
#define DULUGOSC_TEKSTU_POCZ 1001
    char tekst[DULUGOSC_TEKSTU_POCZ];

    printf("Podaj tekst:");
    fgets(tekst, DULUGOSC_TEKSTU_POCZ, stdin);
    int dlugosc_tekstu_kon = 0;
    while(tekst[dlugosc_tekstu_kon] != '\0' && tekst[dlugosc_tekstu_kon] != '\n'){
        dlugosc_tekstu_kon++;
    }
    printf("%d", dlugosc_tekstu_kon);
    return 0;
}
