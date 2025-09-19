#include <stdio.h>

int main(){
    int num;

    printf("Podaj liczbe z zakresu 1-10: \n");
    if(scanf("%d", &num) != 1){
        printf("Incorrect input");
        return 1;
    }
    else if(num == 0){
        printf("zero");}
    else if(num == 1){
        printf("jeden");}
    else if(num == 2){
        printf("dwa");}
    else if(num == 3){
        printf("trzy");}
    else if(num == 4){
        printf("cztery");}
    else if(num == 5){
        printf("piec");}
    else if(num == 6){
        printf("szesc");}
    else if(num == 7){
        printf("siedem");}
    else if(num == 8){
        printf("osiem");}
    else if(num == 9){
        printf("dziewiec");}
    else if(num == 10){
        printf("dziesiec");}
    else{
    printf("Incorrect input data");
    return 2;}
    return 0;
}