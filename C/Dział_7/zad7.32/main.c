#include <stdio.h>

double km2nm (double distance) {
    if (distance < 0) {
        return -1;
    } else {
        return distance / 1.851852;
    }
}
double km2lm (double distance){
    if (distance < 0) {
        return -1;
    } else {
        return distance / 1.609344;
    }
}
int main(){
    double odleglosc;
    printf("wprowadz odleglosc (w km):\n");
    if(scanf("%lf",&odleglosc) != 1){
        printf("Incorrect input");
        return 1;
    }
    if(odleglosc < 0){
        printf("Incorrect input data");
        return 2;
    }
    else{
        double mile_morskie = km2nm(odleglosc);
        if(mile_morskie != -1){
            printf("%.3lf mile morskie\n", mile_morskie);
        }
        double mile_ladowe = km2lm(odleglosc);
        if(mile_ladowe != -1){
            printf("%.3lf mile ladowe\n",mile_ladowe);
        }
    }
    return 0;
}
