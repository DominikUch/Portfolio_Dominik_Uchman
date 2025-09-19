#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100

void display_vector(const int vec[], int size) {
    if (vec == NULL || size <= 0) {
        return;
    }
    for (int i = 0; i < size; i++) {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

int generate(int lotto[], int N, int start, int end) {
    if (start > end || lotto == NULL || N <= 0 || (end - start + 1) < N) {
        return -1;
    }
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        int num;
        do {
            num = (rand() % (end - start + 1)) + start;
            int is_duplicate = 0;
            for (int j = 0; j < i; j++) {
                if (lotto[j] == num) {
                    is_duplicate = 1;
                    break;
                }
            }
            if (!is_duplicate) {
                lotto[i] = num;
                break;
            }
        } while (1);
    }
    return 0;
}

int vector_max_norm(const int tab[], int size){
    if(tab == NULL || size <= 0){
        return 0;
    }
    int max_module = abs(tab[0]);
    for(int i = 0; i<size; i++){
        if(abs(tab[i]) > max_module){
            max_module = abs(tab[i]);
        }
    }
    return max_module;
}

int vector_sum(const int tab[], int size){
    if(tab == NULL || size <= 0){
        return 0;
    }
    int suma = 0;
    for(int i = 0; i<size; i++){
        suma += tab[i];
    }
    return suma;
}

int main() {
    int a;
    printf("Podaj a:\n");
    if(scanf("%d", &a) != 1){
        printf("Incorrect input");
        return 1;
    }
    int b;
    printf("Podaj b:\n");
    if(scanf("%d", &b) != 1){
        printf("Incorrect input");
        return 1;
    }
    int ilosc_losowan;
    printf("Podaj liczbe elementow do wylosowania:\n");
    if(scanf("%d", &ilosc_losowan) != 1){
        printf("Incorrect input");
        return 1;
    }
     if(a == b & ilosc_losowan != 1){
         printf("Incorrect input data");
         return 2;
     }
     if(a > b){
         printf("Incorrect input data");
         return 2;
     }
    if(ilosc_losowan <= 0 ){
        printf("Incorrect input data");
        return 2;
    }
    if((abs(a) + abs(b)) < ilosc_losowan){
        printf("Incorrect input data");
        return 2;
    }
    if(ilosc_losowan > SIZE){
        printf("Incorrect input data");
        return 2;
    }
    int tab[SIZE];
    generate(tab,ilosc_losowan,a,b);
    display_vector(tab, ilosc_losowan);
    int wynik_max_normy = vector_max_norm(tab, ilosc_losowan);
    printf("norma max wynosi %d\n", wynik_max_normy);
    int wynik_sumy = vector_sum(tab,ilosc_losowan);
    printf("suma wynosi %d", wynik_sumy);
    return 0;
}