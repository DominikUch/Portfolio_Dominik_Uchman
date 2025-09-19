#include <stdio.h>
int swap(int *wda, int *wdb) {
    if (wda == NULL || wdb == NULL) {
        return 1;
    }
    int temp = *wda;
    *wda = *wdb;
    *wdb = temp;
    return 0;
}
    int main() {
    int number_1;
    int number_2;
    printf("Podaj 2 liczby oddzielone spacja;\n");
    if(scanf("%d %d", &number_1, &number_2)!= 2){
        printf("Incorrect input");
        return 1;
    }
    swap(&number_1, &number_2);
    printf("a: %d, b: %d", number_1, number_2);
    return 0;
}