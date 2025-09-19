#include <stdio.h>
int main() {
    int n;
    printf("Podaj liczbe dodatnia mniejsza od 21:");
    int user_input = scanf("%d", &n);
    if (user_input != 1 || n > 21 || n < 0){
        printf("Incorrect input");
        return 1;
    }
    unsigned long long silnia = 1;
    for (int i = 1; i <= n; i++){
        silnia = silnia * i;
    }
    printf("%llu", silnia);
    return 0;
}