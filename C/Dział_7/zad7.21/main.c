#include <stdio.h>
#include <math.h>
#define SIZE 100



float average(const int tab[], int size){
    if(tab == NULL || size <= 0){
        return -1;
    }
    float sum = 0;
    for(int i = 0; i< size; i++){
        sum += (float)tab[i];
    }
    return sum / (float)size;
    }

float stdDev(const int tab[], int size){
    if(tab == NULL || size <= 0){
        return -1;
    }
    float avg = average(tab, size);
    float sum_of_squares = 0;
    for(int i = 0; i < size; i++){
        float diff = (float)tab[i] - avg;
        sum_of_squares += diff * diff;
    }
    return sqrt(sum_of_squares / size);
}

int main(){
    printf("Podaj wektor:\n");
    int ilosc = 0;
    int liczba;
    int tab[SIZE];
    while(1){
        if(scanf("%d", &liczba) != 1){
            printf("Incorrect input");
            return 1;
        }
        if(liczba == 0 || ilosc >= SIZE){
            break;
        }
        tab[ilosc++] = liczba;
    }
    if(ilosc <= 0){
        printf("not enough data available");
        return 2;
    }
    float ave_result = average(tab, ilosc);
    float stddev_result = stdDev(tab, ilosc);
    if(ave_result != -1 && stddev_result != -1){
        printf("%.2lf\n", ave_result);
        printf("%.2lf\n", stddev_result);
    }
    return 0;
}
