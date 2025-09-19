#include <stdio.h>

int main() {
    int num1, num2, suma;

    printf("Podaj dwie liczby calkowite:\n");

    if(scanf("%d %d", &num1, &num2) == 2){
        suma = num1 + num2;
        printf("Suma liczb = %d\n", suma);
        return 0;
    }
    else{
        printf("Incorrect input\n");
        return 1;
    }
}