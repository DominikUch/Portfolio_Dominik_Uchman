#include <stdio.h>

int main(){
    float num;
    printf("Podaj swoja liczbe:\n");
    if(scanf("%f", &num) != 1){
        printf("Incorrect input");
        return 1;
    }
    if (num > 0){
        printf("dodatnia");}
    else if(num == 0){
        printf("zerowa");}
    else{
        printf("ujemna");}
    return 0;
}