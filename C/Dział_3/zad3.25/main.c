
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int max = 40;
    int min = 30;
    srand(time(0));
    int number = rand() % (max - min + 1) + min;
    printf("%d", number);
    return 0;
}