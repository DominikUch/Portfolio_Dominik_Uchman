#include <stdio.h>

int compare(int num_1,int num_2, int num_3){
    if (num_1 == num_2 && num_1 == num_3){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    int liczba_1;
    int liczba_2;
    int liczba_3;
    printf("Podaj trzy liczby:\n");
    if(scanf("%d-%d-%d", &liczba_1, &liczba_2, &liczba_3) != 3){
        printf("Incorrect input");
        return 1;
    }
    int wynik = compare(liczba_1,liczba_2,liczba_3);
    if (wynik == 1){
        printf("EQUAL");
    }
    else{
        printf("NOT EQUAL");
    }
    return 0;
}
