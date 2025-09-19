#include <stdio.h>

int main(){
    int dzien,miesiac,rok;

    printf("Podaj date(w formacie dd-mm-yyyy):\n");
    scanf("%d-%d-%d", &dzien, &miesiac, &rok);

    printf("Day:%8.02d\n"
           "Month:%6.02d\n"
           "Year:%7.04d", dzien,miesiac,rok);

    return 0;
}