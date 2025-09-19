#include <stdio.h>
#define SIZE 5


int column_statistics(const int *ptr, int width, int height, int column_id, int* max, int* min, float *avg){
    if(ptr == NULL || max == NULL || min == NULL || avg == NULL || width <1 || height < 1 ||column_id < 0 ||
    column_id >= width){
        return 1;
    }
    *min = *(ptr + (0*width) + column_id);
    *max = *(ptr + (0*width) + column_id);
    //max i min
    for(int i = 0; i < height; i++){
        int current = *(ptr + (i*width) + column_id);
        if(current > *max){
            *max = current;
        }
        if(current < *min){
            *min = current;
        }
    }
    //srednia
    float suma = 0.0;
    for(int i = 0; i < height; i++ ){
        suma += (float)*(ptr + (i*width) + column_id);
    }
    *avg = suma / (float)height;
    return 0;
}

int row_statistics(const int *ptr, int width, int height, int row_id, int* max, int* min, float *avg){
    if(ptr == NULL || max == NULL || min == NULL || avg == NULL || width < 1 || height < 1 || row_id < 0 || row_id
    >=height){
        return 1;
    }
    *min = *(ptr + (row_id*width) + 0);
    *max = *(ptr + (row_id*width) + 0);
    //max i min
    for(int i = 0; i < width; i++){
        int current = *(ptr + (row_id*width) + i);
        if(current > *max){
            *max = current;
        }
        if(current < *min){
            *min = current;
        }
    }
    //srednia
    float suma = 0.0;
    for(int i = 0; i < width; i++ ){
        suma += (float)*(ptr + (row_id*width) + i);
    }
    *avg = suma / (float)width;
    return 0;
}


int main() {
    int tab[SIZE][SIZE];
    printf("Podaj liczby:\n");
    for(int i =0; i < SIZE; i++){
        for(int j =0; j < SIZE; j++){
            if(scanf("%d", &*(*(tab+i)+j)) != 1){
                printf("Incorrect input");
                return 1;
            }
        }
    }
    int max_col;
    int min_col;
    float avg_col;
    for(int i =0; i < SIZE; i++){
        int result = column_statistics(*tab, SIZE, SIZE, i, &max_col, &min_col, &avg_col);
        if(result == 1){
            printf("Incorrect input");
            return 1;
        }
        printf("%d %d %.2f\n", min_col, max_col, avg_col);
    }
    int max_row;
    int min_row;
    float avg_row;
    for(int i =0; i < SIZE; i++){
        int result = row_statistics(*tab, SIZE, SIZE, i, &max_row, &min_row, &avg_row);
        if(result == 1){
            printf("Incorrect input");
            return 1;
        }
        printf("%d %d %.2f\n", min_row, max_row, avg_row);
    }

    return 0;
}