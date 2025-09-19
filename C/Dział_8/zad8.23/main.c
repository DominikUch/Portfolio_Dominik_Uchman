#include <stdio.h>
#define SIZE 150

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

int max(const int arr[], int size){
    if(arr == NULL || size < 1){
        return -1;
    }
    if(size == 1){
        return arr[0];
    }
    int maximum = max(arr + 1, size -1);
        if(arr[0] > maximum){
            return arr[0];
        }
        return maximum;
    }

int main() {
    printf("Podaj wektor:\n");
    int tab1[SIZE];
    int ilosc1 = read_vector(tab1,SIZE,-1);
    if(ilosc1 == -1){
        printf("Incorrect input");
        return 1;
    }
    else if(ilosc1 == 0){
        printf("Not enough data available");
        return 2;
    }
    int wynik = max(tab1, ilosc1);
    printf("%d", wynik);
    return 0;
}