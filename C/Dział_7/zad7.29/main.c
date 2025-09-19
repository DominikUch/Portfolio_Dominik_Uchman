#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 6

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

int main() {
    int wyniki[SIZE];
    int start = 1;
    int end = 49;
    int N = 6;
    int wynik = generate(wyniki, N, start, end);

    if (wynik == 0) {
        display_vector(wyniki, 6);
    } else {
        printf("incorrect input\n");
    }
    return 0;
}