
#include <stdio.h>
int main(){
    int tablica_liczb[1000];
    int liczba;
    int ilosc = 0;
    int suma = 0;

    printf("Podaj liczby (nie wiecej niz 1000):\n");
    while (1) {
        if (scanf("%d", &liczba) != 1) {
            printf("Incorrect input");
            return 1;
        }
        if (liczba == 0) {
            break;
        }
        if (ilosc >= 1000) {
            break;
        }
        tablica_liczb[ilosc] = liczba;
        suma += liczba;
        ilosc++;
    }
    if(ilosc == 0){
        printf("Brak danych\n");
        return 0;
    }
    double srednia = (double)suma/ilosc;
    int suma_wiekszych = 0;
    int suma_mniejszych = 0;

    for(int i = 0; i < ilosc; i++) {
        if (tablica_liczb[i] > srednia) {
            suma_wiekszych += tablica_liczb[i];
        } else if (tablica_liczb[i] < srednia) {
            suma_mniejszych += tablica_liczb[i];
        }
    }
    printf("%.2lf\n",srednia);
    printf("%d\n",suma_wiekszych);
    printf("%d\n",suma_mniejszych);
    return 0;
}

