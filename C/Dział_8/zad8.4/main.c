#include <stdio.h>

unsigned long sum_rec(int n){
    if (n <= 0){
        return 0;
    }
//    else if(n == 0){
//        return 0;
//    }
    else{
        return n + sum_rec(n - 1);
    }
}
int main(){
    int liczba;
    printf("Podaj liczbe, dla ktorej chcesz policzyc sume:\n");
    if(scanf("%d", &liczba) != 1){
        printf("Incorrect input");
        return 1;
    }
    unsigned long wynik = sum_rec(liczba);
    if (wynik == 0){
        printf("Incorrect input data");
        return 2;
    }
    else{
        printf("Wynik: %lu", wynik);
    }
    return 0;
}



