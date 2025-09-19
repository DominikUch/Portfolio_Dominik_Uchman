#include <stdio.h>


int main(){

    int num1,num2,num3,num4,num5,num6,num7,num8,num9,num10;
    float srednia;
    printf("Podaj dziesiec liczb: \n");
    scanf("%d %d %d %d %d %d %d %d %d %d",&num1,&num2,&num3,&num4,&num5,&num6,&num7,&num8,&num9,&num10);

    srednia = (num1+num2+num3+num4+num5+num6+num7+num8+num9+num10)/10.0;

    printf("Srednia arytmetyczna = %.4f", srednia);
    return 0;
}
