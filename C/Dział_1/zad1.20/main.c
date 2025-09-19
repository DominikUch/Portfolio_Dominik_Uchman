#include <stdio.h>

int main(){
    float celsjusz, kelwin, farenheit;

    printf("Podaj temperature w stopniach celsjusza:\n");
    scanf("%f", &celsjusz);

    kelwin = celsjusz + 273.15;
    farenheit = celsjusz * 9/5 + 32;

    printf("%.2f\n", kelwin);
    printf("%.2f\n", farenheit);
    return 0;
}
