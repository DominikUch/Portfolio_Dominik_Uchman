#include <stdio.h>

int add(const int *first, const int *second, int* result){
    if(first == NULL || second == NULL || result == NULL) {
        return 1;
    }
    *result = *first + *second;
    return 0;
}

int subtract(const int *first, const int *second, int* result){
    if(first == NULL || second == NULL || result == NULL) {
        return 1;
    }
    *result = *first - *second;
    return 0;
}

int multiply(const int *first, const int *second, int* result){
    if(first == NULL || second == NULL || result == NULL) {
        return 1;
    }
    *result = *first * *second;
    return 0;
}
int divide(const int *first, const int *second, float* result){
    if(first == NULL || second == NULL || *second == 0 || result == NULL ) {
        return 1;
    }
    *result = (float)*first / (float)*second;
    return 0;
}


int main() {
    printf("Podaj liczby:\n");
    int num1;
    int *pt1 = &num1;
    int num2;
    int *pt2 = &num2;
    char operation;
    if(scanf("%d %c %d", &num1, &operation ,&num2) != 3){
        printf("Incorrect input\n");
        return 1;
    }
    if(operation != '+' && operation != '-' && operation != '/' && operation != '*' ){
        printf("Incorrect input\n");
        return 1;
    }
    if(operation == '/' && num2 == 0){
        printf("Operation not permitted\n");
        return 4;
    }

    if(operation == '+'){
        int result;
        int fun_result = add(pt1, pt2, &result);
        if(fun_result == 1){
            printf("Incorrect input");
            return 1;
        }
        printf("%d", result);

    }
    if(operation == '-'){
        int result;
        int fun_result = subtract(pt1, pt2, &result);
        if(fun_result == 1){
            printf("Incorrect input");
            return 1;
        }
        printf("%d", result);

    }
    if(operation == '*'){
        int result;
        int fun_result = multiply(pt1, pt2, &result);
        if(fun_result == 1){
            printf("Incorrect input");
            return 1;
        }
        printf("%d", result);
    }
    if(operation == '/'){
        float result;
        int fun_result = divide(pt1, pt2, &result);
        if(fun_result == 1){
            printf("Incorrect input");
            return 1;
        }
        printf("%f", result);
    }
    
    return 0;
}