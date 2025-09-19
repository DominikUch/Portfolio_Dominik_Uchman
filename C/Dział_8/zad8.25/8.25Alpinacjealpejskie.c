//#include <stdio.h>
//
//void display_vector(const int vec[], int size) {
//    if (vec == NULL || size <= 0) {
//        return;
//    }
//    for (int i = 0; i < size; i++) {
//        printf("%d ", vec[i]);
//    }
//    printf("\n");
//}
//
//int print_combination(int arr[], int start, int N, int start_number, int end_number) {
//    if(arr == NULL || N < 0 || N > 10 || start_number < 0 || end_number < 0 || start < 0){
//        return -1;
//    }
//    int count = 0;
//    if(N == 0){
//        display_vector(arr, start);
//        return 1;
//    }
//    for(int i = start_number; i <= end_number; i++){
//        arr[start] = i;
//        count += print_combination(arr, start + 1, N - 1, i + 1, end_number);
//    }
//    return count;
//}
//
//
//int main() {
//    printf("Podaj poczatek zakresu liczb:\n");
//    int start_number;
//    if (scanf("%d", &start_number) != 1) {
//        printf("Incorrect input");
//        return 1;
//    }
//    printf("Podaj koniec zakresu liczb:\n");
//    int end;
//    if (scanf("%d", &end) != 1) {
//        printf("Incorrect input");
//        return 1;
//    }
//
//    printf("Podaj ilu elementowe maja byc kombinacje:\n");
//    int elements_count;
//    if (scanf("%d", &elements_count) != 1) {
//        printf("Incorrect input");
//        return 1;
//    }
//
//    if (start_number >= end) {
//        printf("Incorrect input");
//        return 1;
//    }
//
//    if (elements_count > end - start_number + 1) {
//        printf("Incorrect input data");
//        return 2;
//    }
//    int tab[10];
//    int result = print_combination(tab, 0, elements_count, start_number, end);
//    printf("%d\n", result);
//
//    return 0;
//}


#include <stdio.h>

void display_vector(const int vec[], int size) {
    if (vec == NULL || size <= 0) {
        return;
    }
    for (int i = 0; i < size; i++) {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

int print_combination(int arr[], int start, int N, int start_number, int end_number) {
    if (arr == NULL || N <= 0 || N > 10 || start < 0) {
        return -1;
    }
    int count = 0;
    for (int i = start_number; i <= end_number; i++) {
        arr[start] = i;
        if (N == 1) {
            display_vector(arr, start + 1);
            count++;
        } else {
            count += print_combination(arr, start + 1, N - 1, i + 1, end_number);
        }
    }
    return count;
}

int main() {
    printf("Podaj poczatek zakresu liczb:\n");
    int start_number;
    if (scanf("%d", &start_number) != 1) {
        printf("Incorrect input");
        return 1;
    }
    printf("Podaj koniec zakresu liczb:\n");
    int end;
    if (scanf("%d", &end) != 1) {
        printf("Incorrect input");
        return 1;
    }

    printf("Podaj ilu elementowe maja byc kombinacje:\n");
    int elements_count;
    if (scanf("%d", &elements_count) != 1) {
        printf("Incorrect input");
        return 1;
    }

    if (start_number >= end) {
        printf("Incorrect input data");
        return 2;
    }

    if (elements_count > end - start_number + 1) {
        printf("Incorrect input data");
        return 2;
    }

    int tab[10];
    int result = print_combination(tab, 0, elements_count, start_number, end);
    if(result == -1){
        printf("Incorrect input data");
        return 2;
    }
    else{
        printf("%d\n", result);
    }
    return 0;
}