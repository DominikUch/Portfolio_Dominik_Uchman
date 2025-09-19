#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void fillArray(char (*arr)[COLS], int row, int col) {
    if (row >= ROWS) {
        return;
    }
    //doszedłem do końca wiersza, przechodze do kolejnego
    if (col >= COLS) {
        fillArray(arr, row + 1, 0);
        return;
    }
    int small_or_big = rand() % 2;
    if (small_or_big == 1) {
        *(*(arr+row)+col) = 'a' + (rand() % 26);
    } else {
        *(*(arr+row)+col) = 'A' + (rand() % 26);
    }
    fillArray(arr, row, col + 1);
}

void sort_array_helper(char (*arr)[COLS], int row, int start, int end){
    if(start >= end-1){
        return;
    }
    if(*(*(arr+row)+start) < *(*(arr+row)+start+1)){
        char temp;
        temp = *(*(arr+row)+start+1);
        *(*(arr+row)+start+1) = *(*(arr+row)+start);
        *(*(arr+row)+start) = temp;
    }
    return sort_array_helper(arr, row, start+1, end);
}

void recursiveSortArray(char (*arr)[COLS], int row, int start, int end){
    if(row >= end){
        return;
    }
    sort_array_helper(arr, 0,0,10);
    recursiveSortArray(arr, row+1, start, end);
}


int main() {
    char matrix[ROWS][COLS];
    srand(time(NULL));
    // Fill the matrix with random letters
    fillArray(matrix, 0, 0);
    // Print the filled matrix
    printf("Filled Array:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c\t", matrix[i][j]);
        }
        printf("\n");
    }
    recursiveSortArray(matrix, 0,0,10);
    printf("After Sort:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c\t", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}