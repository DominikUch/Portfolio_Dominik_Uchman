#include <stdio.h>


int power_of_3(int number_len){
    if(number_len == 0){
        return 1;
    }
    else{
        return 3 * power_of_3(number_len - 1);
    }
}


int sum_of_digits_times_3(int number, int i){
    int temp = number / 10;
    int digit = number - (temp * 10);
    if (number / 10 == 0) {
        return number * power_of_3(i);
    }
    else{
        return (digit * power_of_3(i)) + sum_of_digits_times_3(number / 10, i + 1);
    }
}

int loop(int sum){
    if(sum / 10 == 0){
        return sum;
    }
    else{
        return loop(sum_of_digits_times_3(sum, 0));
    }
}

int is_divisible_by_7(int number){
    int result = loop(number);
    if(result == -7 || result == 0 || result == 7){
        return 1;
    }
    else{
        return 0;
    }
}


int main() {
    printf("Podaj liczbe:\n");
    int liczba;
    if(scanf("%d", &liczba) != 1){
        printf("Incorrect input");
        return 1;
    }
    int result = is_divisible_by_7(liczba);
    if(result == 1){
        printf("YES");
    }
    else {
        printf("NO\n");
    }
    return 0;
}
