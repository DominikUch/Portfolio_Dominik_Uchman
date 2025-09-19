#include <stdio.h>

int number_len(int number){
    if(number / 10 == 0){
        return 1;
    }
    return 1+ number_len(number/ 10);
}

int sum1(int number){
    int temp = number / 10;
    int digit = number - (temp*10);
    if(number / 10 == 0){
        return number;
    }
    else{
        return digit + sum1(number / 100);
    }
}

int is_divisible_by_11(int liczba){
    int len = number_len(liczba);
    int even_sum;
    int odd_sum;
    if(len == 1 || len == 3 || len == 5){
        even_sum = sum1(liczba);
        odd_sum = sum1(liczba / 10);
    }
    else{
        odd_sum=sum1(liczba);
        even_sum = sum1(liczba/ 10);
    }

    int sums_diff = even_sum - odd_sum;
    if(sums_diff < 0){
        sums_diff *= -1;
    }
    if(sums_diff == 0 || sums_diff == 11 || sums_diff == -1){
        return 1;
    }
    else{
        return 0;
    }
}


int main() {
    printf("Podaj liczbe:\n");
    double liczba;
    if(scanf("%lf", &liczba)!= 1){
        printf("Incorrect input");
        return 1;
    }
    int result = is_divisible_by_11(liczba);
    if(result == 1){
        printf("YES");
    }
    else{
        printf("NO");
    }
    return 0;
}
