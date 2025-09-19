
#include <stdio.h>
#define SIZE 100
    int main(){
        int tablica_liczb[SIZE];
        int liczba;
        int ilosc = 0;
        printf("Podaj liczby(nie wiecej niz 100):\n");
        while (1) {
            if(ilosc >= SIZE){
                break;
            }
            if(scanf("%d", &liczba) != 1){
                printf("Incorrect input");
                return 1;
            }
            if(liczba == 0){
                if(ilosc < 1){
                    printf("not enough data available");
                    return 2;
                }
                else {
                    break;
                }
            }

            tablica_liczb[ilosc] = liczba;
            ilosc++;
        }
        while(getchar() != '\n');

        for(int i = 0; i < ilosc; i++){
            int powtorzenie = 0;

            for (int j = 0; j<i; j++){
                if(tablica_liczb[i] == tablica_liczb[j]){
                    powtorzenie = 1;
                    break;
                }
            }
            if (powtorzenie == 0){
                printf("%d ", tablica_liczb[i]);
                continue;
            }
        }
    return 0;
}
