#include <stdio.h>

int is_prime(int a) {
    if (a >= 2) {
        for (int i = 2; i < a; i++) {
            if (a % i == 0) {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}
int is_twin(int a, int b){
    if((a - b) == 2 || (b-a) == 2){
        if(is_prime(a) && is_prime(b)) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int x1;
    printf("Podaj x1:\n");
    if (scanf("%d", &x1) != 1) {
        printf("Incorrect input");
        return 1;
    }
    int x2;
    printf("Podaj x2:\n");
    if (scanf("%d", &x2) != 1) {
        printf("Incorrect input");
        return 1;
    }
    if (x1 > x2) {
        printf("Incorrect input");
        return 1;
    }
    int pierwsze = 0;
    for(int i = x1; i <= x2 -2; i++) {
        if (is_twin(i, i + 2) == 1) {
            pierwsze = 1;
            printf("%d %d\n", i, i + 2);
        } else {
            continue;
        }
    }
    if(pierwsze == 0){
        printf("Nothing to show");
    }
    return 0;
}