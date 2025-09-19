#include <stdio.h>
#define SIZE 150



int max(const int arr[], int size){
    if(arr == NULL || size <= 0){
        return -1;
    }
    if(size == 1) {
        return arr[size - 1];
    }
    int maximum = max(arr+1, size-1);
    if(arr[0] > maximum){
        return arr[0];
    }
    else{
        return maximum;
    }
}


int main() {
    printf("Podaj liczby:\n");
    int tab[SIZE];
    int liczba;
    int size = 0;
    while(1){
        if(scanf("%d", &liczba)!= 1){
            printf("Incorrect input");
            return 1;
        }
        if(liczba == -1 || size == SIZE){
            break;
        }
        tab[size] = liczba;
        size++;
    }
    while(getchar() != '\n');
    int max_value = max(tab, size);
    printf("%d\n", max_value);
    return 0;
}
