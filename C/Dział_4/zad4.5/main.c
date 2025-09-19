
#include <stdio.h>
int main(){
    float liczby[11];
    float odpowiedz;
    for (int i = 0; i < 5; i++){
       printf("Podaj 2 liczby zmiennoprzecinkowe:");
       odpowiedz = scanf("%f %f", &liczby[2*i+1], &liczby[2*i+2]);
       if (odpowiedz != 2){
           printf("Input data type error\n");
           return 1;
       }
    }
    for(int i = 1; i <= 10; i++){
        printf("Indeks %d = %f\n", i-1, liczby[i]);
    }
    return 0;
}
