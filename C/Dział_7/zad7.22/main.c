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

int concat_begin(const int first[], int size, const int second[], int size2, int dest[], int size3) {
    if (first == NULL || second == NULL || dest == NULL || size <= 0 || size2 <= 0 || size3 <= 0) {
        return -1;
    }
    if (size + size2 > size3) {
        return -2;
    }
    int i;
    for (i = 0; i < size; i++) {
        dest[i] = first[i];
    }
    for (int j = 0; j < size2; j++, i++) {
        dest[i] = second[j];
    }
    return i;
}
int concat_end(const int first[], int size, const int second[], int size2, int dest[], int size3){
    if (first == NULL || second == NULL || dest == NULL || size <= 0 || size2 <= 0 || size3 <= 0) {
        return -1;
    }
    if (size + size2 > size3) {
        return -2;
    }
    int i;
    for(i =0; i< size2; i++){
        dest[i] = second[i];
    }
    for(int j=0; j<size; j++, i++){
        dest[i] = first[j];
    }
    return i;
}
int concat_zip(const int first[], int size, const int second[], int size2, int dest[], int size3) {
    if (first == NULL || second == NULL || dest == NULL || size <= 0 || size2 <= 0 || size3 <= 0) {
        return -1;
    }
    int i = 0, j = 0, k = 0;
    while (i < size && j < size2 && k < size3) {
        dest[k++] = first[i++];
        dest[k++] = second[j++];
    }
    while (i < size && k < size3) {
        dest[k++] = first[i++];
    }
    while (j < size2 && k < size3) {
        dest[k++] = second[j++];
    }
    if (i < size || j < size2) {
        return -2;
    }
    return k;
}
int main(){
    printf("Podaj wektor:\n");
    int tab1[SIZE];
    int ilosc1 = read_vector(tab1,SIZE,0);
    if(ilosc1 == -1){
        printf("Incorrect input");
        return 1;
    }
    else if(ilosc1 == 0){
        printf("Not enough data available");
        return 2;
    }
    printf("Podaj drugi wektor:\n");
    int tab2[SIZE];
    int ilosc2 = read_vector(tab2,SIZE,0);
    if(ilosc2 == -1){
        printf("Incorrect input");
        return 1;
    }
    else if(ilosc2 == 0){
        printf("Not enough data available");
        return 2;
    }

    int tab_begin[SIZE];
    int result_begin = concat_begin(tab1, ilosc1, tab2, ilosc2, tab_begin,SIZE);
    int tab_end[SIZE];
    int result_end = concat_end(tab1, ilosc1, tab2, ilosc2, tab_end, SIZE);
    int tab_zip[SIZE];
    int result_zip = concat_zip(tab1, ilosc1, tab2, ilosc2, tab_zip, SIZE);

    display_vector(tab1, ilosc1);
    printf("\n");
    display_vector(tab2, ilosc2);

    if(ilosc1+ilosc2 > SIZE){
        printf("Output buffer is too small");
        return 0;
    }
    display_vector(tab_begin, result_begin);
    display_vector(tab_end, result_end);
    display_vector(tab_zip, result_zip);
    return 0;
}
