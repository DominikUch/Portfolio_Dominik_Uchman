#include <stdio.h>

int main() {
    int num1,num2;
    char op;
    printf("Podaj pierwsza liczbe:");
    if (scanf("%d", &num1) != 1) {
        printf("Incorrect input");
        return 1;
    }
    printf("Podaj druga liczbe: ");
    if (scanf("%d", &num2) != 1) {
        printf("Incorrect input\n");
        return 1;
    }
    printf("Podaj symbol operacji ( + , * , - , / ): ");
    if (scanf(" %c", &op) != 1) {
        printf("Incorrect input");
        return 1;
    }
    if (op == '+') {
        printf("%d", num1 + num2);
    }
    else if (op == '-') {
        printf("%d", num1 - (num2));
    }
    else if (op == '*') {
        printf("%d", num1 * num2);
    }
    else if (op == '/'){
        if(num2 == 0){
            printf("Operation not permitted");
            return 2;
        }
        else{
            double dzielenie = (double)num1 / num2;
            printf("%.2lf\n", dzielenie);
        }
    }
    else{
        printf("Incorrect input");
        return 1;
    }
    return 0;
}




