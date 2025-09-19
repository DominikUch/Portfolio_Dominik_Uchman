#include <stdio.h>

int main() {
    int zuzyta_energia;
    printf("Podaj ilosc zuzytej energi elektrycznej (w kWh):");
    if((scanf("%d",&zuzyta_energia) != 1) || zuzyta_energia < 0){
        printf("Incorrect input");
        return 1;
    }
    float koszt_brutto;
    if(zuzyta_energia <= 50){
        koszt_brutto = zuzyta_energia * 1.22 * 0.5;
        printf("Koszt brutto: %f", koszt_brutto);
    }
    else if(zuzyta_energia >= 50 && zuzyta_energia <= 150){
        koszt_brutto = (50 * 0.5 * 1.22) + ((zuzyta_energia - 50) * 0.75 * 1.22);
        printf("Koszt brutto: %f", koszt_brutto);
    }
    else if (zuzyta_energia >= 150 && zuzyta_energia <= 250){
         koszt_brutto = (50 * 0.5 * 1.22) + (100 * 0.75 * 1.22) + ((zuzyta_energia - 150) * 1.20 * 1.22);
         printf("Koszt brutto: %f", koszt_brutto);
    }
    else{
        koszt_brutto = (50 * 0.5 * 1.22) + (100 * 0.75 * 1.22) + ( 100 * 1.20 * 1.22) + ((zuzyta_energia - 250)*
                1.50*1.22 );
        printf("Koszt brutto: %f", koszt_brutto);
    }
    return 0;
}