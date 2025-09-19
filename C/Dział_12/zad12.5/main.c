#include <stdio.h>
#define MAX_SIZE 20
void draw_windmill(int n) {

    if (n > 0){
        int matrix[MAX_SIZE][MAX_SIZE];
        for (int i = 0; i < 2*n; i++) {
            for (int j = 0; j < 2*n; j++) {
                matrix[i][j] = ' ';
            }
        }
        for (int i = 0; i < 2 * n; i++) {
            matrix[i][i] = 'X';
            matrix[i][2 * n - i - 1] = 'X';
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                matrix[i][j] = 'X';
                matrix[j][2 * n - i - 1] = 'X';
                matrix[(2 * n) - 1 - i][(2 * n) - 1 - j] = 'X';
                matrix[(2 * n) - 1 - j][i] = 'X';
            }
        }

        for (int i = 0; i < 2 * n; i++) {
            for (int j = 0; j < 2 * n; j++) {
                printf("%c", matrix[i][j]);
            }
            printf("\n");
        }
    }
    else{
        n *= -1;
        int matrix[MAX_SIZE][MAX_SIZE];
        for (int i = 0; i < 2 * n; i++) {
            for (int j = 0; j < 2 * n; j++) {
                matrix[i][j] = ' ';
            }
        }
        for (int i = 0; i < 2 * n; i++) {
            matrix[i][i] = 'X';
            matrix[i][2 * n - i - 1] = 'X';
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                matrix[j][i] = 'X';
                matrix[i][2 * n - j - 1] = 'X';
                matrix[(2 * n) - 1 - j][(2 * n) - 1 - i] = 'X';
                matrix[(2 * n) - 1 - i][j] = 'X';
            }
        }
        for (int i = 0; i < 2 * n; i++) {
            for (int j = 0; j < 2 * n; j++) {
                printf("%c", matrix[i][j]);
            }
            printf("\n");
        }
    }
}


int main() {
    int n;
    int ilosc = 0;
    int tablica_wiatraczkow[11];
    while (1) {
        printf("Podaj liczbe:");
        if(scanf("%d", &n) != 1){
            printf("Incorrect input");
            return 1;
        }
        if (n == 0) {
            break;
        }
        tablica_wiatraczkow[ilosc] = n;
        ilosc++;
    }
    for(int i = 0; i< ilosc; i++){
        draw_windmill(tablica_wiatraczkow[i]);
        printf("\n");
    }
    return 0;
}