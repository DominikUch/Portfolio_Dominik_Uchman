#include <stdio.h>
#include <math.h>
float distance(int x1, int y1, int x2, int y2){
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));




}
float perimeter(float a, float b, float c){
    if(a <= 0 || b <= 0 || c <= 0){
        return -1;
    }
    else{
        if(a + b < c || a + c < b || b + c < a){
            return -1;
        }
        else{
            return a + b + c;
        }
    }
}
float area(float a, float b, float c){
    if(perimeter(a,b,c) != -1){
        float p = 0.5 * perimeter(a,b,c);
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
    else{
        return -1;
    }
}
int main(){
    int x_A;
    int y_A;
    printf("Podaj wspolrzedna pierwszego punktu:\n");
    if(scanf(" (%d,%d)", &x_A, &y_A) != 2){
        printf("Incorrect input");
        return 1;
    }
    int x_B;
    int y_B;
    printf("Podaj wspolrzedna drugiego punktu:\n");
    if(scanf(" (%d,%d)", &x_B, &y_B) != 2){
        printf("Incorrect input");
        return 1;
    }
    int x_C;
    int y_C;
    printf("Podaj wspolrzedna trzeciego punktu:\n");
    if(scanf(" (%d,%d)", &x_C, &y_C) != 2){
        printf("Incorrect input");
        return 1;
    }
    if(((x_A == x_B) && (y_A == y_B)) || ((x_A == x_C) && (y_A == y_C)) || ((x_B == x_C) && (y_B == y_C))){
        printf("Incorrect input");
        return 1;
    }
    float dlugosc_AB = distance(x_A,y_A,x_B,y_B);
    float dlugosc_AC = distance(x_A,y_A,x_C,y_C);
    float dlugosc_BC = distance(x_B,y_B,x_C,y_C);
    float pole = area(dlugosc_AB,dlugosc_AC,dlugosc_BC);
    printf("%f", pole);
    return 0;
}
