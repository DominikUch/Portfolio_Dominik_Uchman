#include <stdio.h>
#define SIZE 50

int read_vector(int vec[], int size, int stop_value) {
    int ilosc = 0;
    while (1) {
        int liczba;
        if (scanf("%d", &liczba) != 1) {
            return -1;
        }
        if (liczba == stop_value || ilosc >= size) {
            break;
        }
        vec[ilosc] = liczba;
        ilosc++;
    }
    while (getchar() != '\n');
    return ilosc;
}

void display_vector(const int vec[], int size) {
    if (vec == NULL || size <= 0) {
        return;
    }
    for (int i = 0; i < size; i++) {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

void swap_vector(int first[], int size, int second[], int size2){
    int temp;
    if(size >= size2){
        for (int i = 0; i < size; i++) {
            temp = first[i];
            first[i] = second[i];
            second[i] = temp;
        }
    }
    else{
        for (int i = 0; i < size2; i++) {
            temp= first[i];
            first[i] = second[i];
            second[i] = temp;
        }
    }
}

int main(){
    int tab1[SIZE];
    printf("Podaj wektor:\n");
    int ilosc1 =read_vector(tab1,SIZE, 0);
    if(ilosc1 == -1){
        printf("incorrect input");
        return 1;
    }
    else if(ilosc1 <=0 ){
        printf("not enough data available");
        return 2;
    }
    int tab2[SIZE];
    printf("Podaj drugi wektor:\n");
    int ilosc2 = read_vector(tab2,SIZE, 0);
    if(ilosc2 == -1){
        printf("incorrect input");
        return 1;
    }
    else if(ilosc2 <=0 ){
        printf("not enough data available");
        return 2;
    }
    swap_vector(tab1, ilosc1, tab2, ilosc2);
    display_vector(tab1,ilosc2);
    display_vector(tab2,ilosc1);
    return 0;
}
