#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100

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

void shuffle(int tab[], int size) {
    for (int i = 0; i < size; i++) {
        int swap_index = rand() % size;
        int temp = tab[i];
        tab[i] = tab[swap_index];
        tab[swap_index] = temp;
    }
}
int main() {
    int array[SIZE];
    printf("Podaj liczby:\n");
    int ilosc = read_vector(array, SIZE, 0);
    if(ilosc == -1){
        printf("incorrect input");
        return 1;
    }
    if(ilosc < 1){
        printf("Not enough data available");
        return 2;
    }
    srand(time(NULL));
    shuffle(array, ilosc);
    display_vector(array,ilosc);
    return 0;
}