#include  <stdio.h>
int main() {
    int tablica_liczb_A[100];
    int liczba_A;
    int ilosc_A = 0;
    printf("Podaj ciag liczb:\n");
    while (1) {
        if (scanf("%d", &liczba_A) != 1) {
            printf("incorrect input");
            return 1;
        }
        if (liczba_A == 0 || ilosc_A >= 100) {
            break;
        }
        tablica_liczb_A[ilosc_A] = liczba_A;
        ilosc_A++;
    }
    while (getchar() != '\n');
    int tablica_liczb_B[100];
    int liczba_B;
    int ilosc_B = 0;
printf("Podaj drugi ciag liczb:\n");
    while (1) {
        if (scanf("%d", &liczba_B) != 1) {
            printf("incorrect input");
            return 1;
        }
        if (liczba_B == 0 || ilosc_B >= 100) {
            break;
        }
        tablica_liczb_B[ilosc_B] = liczba_B;
        ilosc_B++;
    }
    while (getchar() != '\n');
    if (ilosc_A < 1 || ilosc_B < 1) {
        printf("not enough data available");
        return 2;
    }
    int tablica_roznicy[100];
    if (ilosc_A == ilosc_B || ilosc_A < ilosc_B) {
        for (int i = 0; i < ilosc_A; i++) {
            tablica_roznicy[i] = tablica_liczb_A[i] - (tablica_liczb_B[i]);
            printf("%d ", tablica_roznicy[i]);
        }
    }
    else if(ilosc_A > ilosc_B){
        for (int i = 0; i < ilosc_B; i++) {
            tablica_roznicy[i] = tablica_liczb_A[i] - (tablica_liczb_B[i]);
            printf("%d ", tablica_roznicy[i]);
        }
    }
    return 0;
}