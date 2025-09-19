#include <stdio.h>
#include <stdlib.h>

int user_hint, punkty;

int main() {
    printf("Podaj liczbe uzyskanych punktow:\n");
    user_hint = scanf("%d", &punkty);
    if (user_hint != 1) {
        printf("Incorrect input\n");
        return 1;
    }
    else if (punkty >= 0 && punkty <= 10){
        printf("Ocena 2\n");
    }
    else if (punkty >= 11 && punkty <= 13) {
        printf("Ocena 3\n");
    }
    else if (punkty >= 14 && punkty <= 16) {
        printf("ocena 4\n");
    }
    else if (punkty >= 17 && punkty <= 20) {
        printf("ocean 5\n");
    }
    else{
        printf("Incorrect input\n");
        return 1;
    }
    return 0;
}
