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

int binary_search(const int arr[], int l, int r, int x){
    if(arr == NULL || l > r || l < 0 || r < 0){
        return -1;
    }
    if(l == r){
        if(arr[l] == x){
            return l;
        }
        return -1;
    }
    int middle = (l + r)/2;
    if(arr[middle] == x){
        return middle;
    }
    else{
        if(x > arr[middle]){
            return binary_search(arr,middle+1,r, x);
        }
        else{
         return binary_search(arr, l, middle -1, x);
        }
    }
}

int is_sorted(const int arr[], int size, int index) {
    if(arr == NULL || size <= 0 || index < 0){
        return 2;
    }
    if (index == size - 1) {
        return 1;
    }
    if (arr[index] > arr[index + 1]) {
        return 0;
    }
    return is_sorted(arr, size, index + 1);
}
int main() {
    printf("Podaj wektor:\n");
    int tab1[SIZE];
    int ilosc1 = read_vector(tab1,SIZE,0);
    if(ilosc1 == -1){
        printf("Incorrect input");
        return 1;
    }
    else if(ilosc1 < 1){
        printf("Not enough data available");
        return 3;
    }
    int szukana_liczba;
    printf("Podaj szukana liczbe:\n");
    if(scanf("%d", &szukana_liczba)!= 1){
        printf("Incorrect input");
        return 1;
    }
    int sorted = is_sorted(tab1, ilosc1, 0);
    if(sorted == 0){
        printf("Incorrect input data");
        return 2;
    }
    int wynik = binary_search(tab1,0,ilosc1,szukana_liczba);
    printf("%d", wynik);
    return 0;
}