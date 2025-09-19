#include <stdio.h>
#define SIZE 50

int read(int tab[], int size, int stop_value){
    if(tab == NULL){
        return -1;
    }
    int ilosc = 0;
    while(1){
        int liczba;
        if(scanf("%d", &liczba) != 1){
            printf("Incorrect input");
            return -1;
        }
        if(liczba == stop_value || ilosc >=size){
            break;
        }
        tab[ilosc] = liczba;
        ilosc++;
    }
    return ilosc;
}

int display(int tab[], int size){
    for(int i = 0; i < size; i++){
        printf("%d ", tab[i]);
    }
    printf("\n");
}

void bubble_rec_helper(int tab[], int size, int i) {
    if (i >= size - 1)
        return;
    if (tab[i] > tab[i + 1]) {
        int temp = tab[i + 1];
        tab[i + 1] = tab[i];
        tab[i] = temp;
    }
    bubble_rec_helper(tab, size, i + 1);
}
int bubble_sort_asc_rec(int tab[], int size) {
    if (tab == NULL || size < 0)
        return -1;
    if(size == 0){
        return 0;
    }
    display(tab ,size);
    bubble_rec_helper(tab, size, 0);
    bubble_sort_asc_rec(tab, size - 1);
}

void bubble_rec_helper2(int tab[], int size, int i) {
    if (i >= size - 1) {
        return;
    }
    if (tab[i] < tab[i + 1]){
        int temp = tab[i + 1];
        tab[i + 1] = tab[i];
        tab[i] = temp;
    }
    bubble_rec_helper2(tab, size, i + 1);
}

int bubble_sort_desc_rec(int tab[], int size) {
    if (tab == NULL || size < 0)
        return -1;
    if(size == 0){
        return 0;
    }
    display(tab ,size);
    bubble_rec_helper2(tab, size, 0);
    bubble_sort_desc_rec(tab, size - 1);
}

int main() {
    printf("podaj talbice:\n");
    int tab[SIZE];
    int ilosc = read(tab, SIZE, 0);
    if(ilosc == -1){
        printf("Incorrect input data");
        return 2;
    }
    printf("Sortowanie rosnace -> 1 ; Sortowanie malejace -> 2:\n");
    int kierunek;
    if(scanf("%d", &kierunek) != 1 || (kierunek !=1 && kierunek != 2)){
        printf("Incorrect input");
        return -1;
    }
    if(kierunek == 1){
        bubble_sort_asc_rec(tab, ilosc);
    }
    else if(kierunek == 2){
        bubble_sort_desc_rec(tab, ilosc);
    }
    else{
        printf("Inocrrect input data\n");
        return 2;
    }
    display(tab, ilosc);
    return 0;
}
