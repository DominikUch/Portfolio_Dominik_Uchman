#include <stdio.h>

int clamp(int x, int lo, int hi){
    if (lo > hi) {
        int temp = lo;
        lo = hi;
        hi = temp;
    }
    if (x >= hi){
        return hi;
    }
    else if (x <= lo){
        return lo;
    }
    else{
        return x;
    }
}
int main(){
    int liczba;
    printf("Podaj liczbe:\n");
    if(scanf("%d",&liczba) != 1){
        printf("Incorrect input");
        return 1;
    }
    int granica_min;
    printf("Podaj pierwsza granice:\n");
    if(scanf("%d",&granica_min) != 1){
        printf("Incorrect input");
        return 1;
    }
    int granica_max;
    printf("Podaj druga granice:\n");
    if(scanf("%d",&granica_max) != 1){
        printf("Incorrect input");
        return 1;
    }
    int wynik = clamp(liczba,granica_min,granica_max);
    printf("%d", wynik);
    return 0;
}
