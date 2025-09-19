#include <stdio.h>
#define SIZE 31
int main() {
    char imie[SIZE];
    printf("Podaj swoje imie:\n");
    scanf("%30s", imie);
    printf("Witaj %s!", imie);
    return 0;
}
