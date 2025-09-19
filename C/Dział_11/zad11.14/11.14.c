#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "tested_declarations.h"
#include "rdebug.h"
#define SIZE 200

int validate(const char * number){
    if(number == NULL){
        return -1;
    }
    int i =0;
    while(*(number +i) != '\0'){
        if(strlen(number) == 1 && *(number+0) == '0'){
            return 1;
        }
        if(strlen(number) != 1 && *(number+0) == '0'){
            return 0;
        }
        if(isdigit(*(number+i)) != 0){
            i++;
        }
        else{
            return 0;
        }
    }
    return 1;
}


int add(const char* number1, const char* number2, char* result, int size){
    if(number1 == NULL || number2 == NULL || result == NULL || size <= 0){
        return 1;
    }
    if(validate(number1) != 1 || validate(number2) != 1){
        return 1;
    }
    int len1 = strlen(number1) -1;
    int len2 = strlen(number2) -1;
    int reszta =0;
    int pos =0;
    while(len1 >=0 || len2 >= 0 || reszta > 0) {
        if (pos >= size-1) {
            return 2;
        }
        int digit1 = 0;
        if (len1 >= 0) {
            digit1 = *(number1 + len1) - '0';
            len1--;
        }
        int digit2 = 0;
        if (len2 >= 0) {
            digit2 = *(number2 + len2) - '0';
            len2--;
        }
        int sum = digit1 + digit2 + reszta;
        *(result + pos) = (sum % 10) + '0';
        pos++;
        reszta = sum / 10;
    }
    *(result + pos) = '\0';

    for(int i=0; i < pos/2; i++){
        char temp = *(result + i);
        *(result + i) = *(result + (pos-i-1));
        *(result + (pos-i-1)) = temp;
    }
    return 0;
}

int main() {
    printf("Podaj liczbe\n");
    char liczba[SIZE+1];
    fgets(liczba, SIZE+1, stdin);
    int i =0;
    int new_line =0;
    while(*(liczba +i) != '\0'){
        if(*(liczba +i) == '\n'){
            *(liczba +i) = '\0';
            new_line++;
        }
        i++;
    }
    if(!new_line){
        int c;
        while( (c=getchar()) != '\n' && c != EOF ){}
    }

    int is_legit_1 = validate(liczba);
    if(is_legit_1 == -1){
        printf("Incorrect input");
        return -1;
    }
    printf("Podaj 2 liczbe\n");
    char liczba2[SIZE+1];
    fgets(liczba2, SIZE+1, stdin);
    int i2 =0;
    int new_line2 =0;
    while(*(liczba2 +i2) != '\0'){
        if(*(liczba2 +i2) == '\n'){
            *(liczba2 +i2) = '\0';
            new_line2++;
        }
        i2++;
    }
    if(!new_line2){
        int c;
        while( (c=getchar()) != '\n' && c != EOF ){}
    }
    int is_legit_2 = validate(liczba2);
    if(is_legit_2 == -1){
        printf("Incorrect input");
        return -1;
    }
    char sum_result[2*SIZE+1];
    int result = add(liczba,liczba2,sum_result, 2*SIZE+1);
    if(result != 0){
        printf("Incorrect input");
        return 1;
    }
    printf("%s", sum_result);
    return 0;
}

