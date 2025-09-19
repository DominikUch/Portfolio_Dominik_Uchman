#include <stdio.h>

void print_stars(int n) {
    if (n <= 0) {
        return;
    }
    print_stars(n - 1);
    printf("* ");
}
void rectangular_triangle(int n) {
    if (n <= 0) {
        return;
    }
    rectangular_triangle(n - 1);
    print_stars(n);
    printf("\n");
}

int main() {
    int n;
    printf("Podaj dlugosc podstawy:\n");
    if(scanf("%d", &n) != 1){
        printf("Incorrect input");
        return 1;
    }
    if(n < 3){
        printf("Incorrect input data");
        return 2;
    }
    rectangular_triangle(n);
    return 0;
}