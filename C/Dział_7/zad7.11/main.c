#include <stdio.h>
int is_prime(int a) {
    if (a >= 2) {
        for (int i = 2; i < a; i++) {
            if (a % i == 0) {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}
int main(){
    int x1;
    printf("Podaj x1=");
    if(scanf("%d", &x1)!= 1){
        printf("Incorrect input");
        return 1;
    }
    int x2;
    printf("Podaj x2=");
    if(scanf("%d", &x2)!= 1){
        printf("Incorrect input");
        return 1;
    }
    if(x1 > x2){
        printf("Incorrect input");
        return 1;
    }

    int wystapienie = 0;
    for(int i = x1; i <= x2; i++){
        int wynik = is_prime(i);
        if(wynik == 1){
            printf("%d ", i);
            wystapienie = 1;
        }
    }
    if (wystapienie == 0){
        printf("Nothing to show");
    }
    return 0;
}
