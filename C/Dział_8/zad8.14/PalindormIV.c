#include <stdio.h>
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


int is_palindrom_rec(const int tab[], int start_index, int end_index){
    if(tab == NULL || start_index < 0 || end_index < 0){
        return -1;
    }
    if(start_index >= end_index){
        return 1;
    }
    else{
        if(tab[start_index] == tab[end_index] ){
            return is_palindrom_rec(tab, start_index+1, end_index -1);
        }
        else{
            return 0;
        }
    }
}

int main() {
    printf("Podaj liczby:\n");
    int tab[SIZE];
    int size = read_vector(tab, SIZE, -1);
    if(size == -1){
        printf("Incorrect input");
        return 1;
    }

    if(size <= 0){
        printf("Not enough data available");
        return 2;
    }
    int result = is_palindrom_rec(tab, 0, size-1);
    if(result == 1){
        printf("YES");
    }
    else{
        printf("NO");
    }
    return 0;
}
