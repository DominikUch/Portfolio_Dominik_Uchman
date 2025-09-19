#include <stdio.h>
#define SIZE 100
int sum(const float* tab, unsigned int size, float *result) {
    if (tab == NULL || result == NULL || size == 0) {
        return 1;
    }
    float suma = 0.0;
    for (unsigned int i = 0; i < size; ++i) {
        suma += *tab;
        tab++;
    }
    *result = suma;
    return 0;
}
int avg(const float* tab, unsigned int size, float *result) {
    if (tab == NULL || result == NULL || size == 0) {
        return 1;
    }
    float suma = 0.0;
    for (unsigned int i = 0; i < size; ++i) {
        suma += *tab;
        tab++;
    }
    *result = suma / size;
    return 0;
}
int read_vector_float(float *vec, int size, float stop_value) {
    int ilosc = 0;
    while (1) {
        float liczba;
        if (scanf("%f", &liczba) != 1) {
            return -1;
        }
        if (liczba == stop_value || ilosc >= size) {
            break;
        }
        *vec = liczba;
        vec++;
        ilosc++;
    }
    while (getchar() != '\n');
    return ilosc;
}
int main() {
    float vec[SIZE];
    printf("Podaj ciag liczb:\n");
    int ilosc = read_vector_float(vec,SIZE,0);
    if(ilosc == -1){
        printf("Incorrect input");
        return 1;
    }
    if (ilosc == 0) {
        printf("Not enough data available\n");
        return 3;
    }
    float sum_result;
    if (sum(vec, ilosc, &sum_result) == 0) {
        printf("Suma: %.2f\n", sum_result);
    } else {
        printf("Incorrect input\n");
        return 1;
    }
    float avg_result;
    if (avg(vec, ilosc, &avg_result) == 0) {
        printf("Srednia: %.2f\n", avg_result);
    } else {
        printf("Incorrect input\n");
        return 1;
    }
    return 0;
}