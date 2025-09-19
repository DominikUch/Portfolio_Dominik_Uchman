#include <stdio.h>
#include <math.h>

int main() {
    int a;
    printf("Podaj poczatek:\n");
    if(scanf("%d", &a) != 1){
        printf("Incorrect input");
        return 1;
    }
    int b;
    printf("Podaj koniec:\n");
    if(scanf("%d", &b) != 1){
        printf("Incorrect input");
        return 1;
    }
    if(b < a){
        printf("Incorrect input data");
        return 2;
    }

    int temp = a;
    int ilosc_znaczaca = 0;
    while(temp <= b){
        int ilosc_dziel = 0;
        int suma_dziel = 0;
        for(int i = 1; i < temp; i++){
            if(temp % i == 0){
                ilosc_dziel += 1;
                suma_dziel += i;
            }
        }

        double srednia = ((double)suma_dziel/ilosc_dziel);
        if(srednia < sqrt(temp)){
            ilosc_znaczaca++;
        }
        temp += 1;
    }
    printf("%d", ilosc_znaczaca);
    return 0;
}
