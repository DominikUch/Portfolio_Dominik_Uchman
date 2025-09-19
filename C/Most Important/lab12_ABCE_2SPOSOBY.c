#include <stdio.h>
#include <string.h>


/////////////////////////////// LITERKI ////////////////////////////////////////
int fun(char *current, int start, int start_len, int elements_count, int count) {
    char letter[] = {'a','b','c','d','e','f'};
    if(start_len == elements_count){
        printf("%s\n", current);
        count++;
    }
    for(int i = start; i < strlen(letter)-1; i++){
        *(current + start_len) = *(letter + i);
        *(current + start_len+1) = '\0';
        count = fun(current, i+1, start_len+1, elements_count, count);
    }
    return count;
}

//////////////////////////////////// CYFRY  ////////////////////////////////////////////////
void display_vector(const int vec[], int size) {
    if (vec == NULL || size <= 0) {
        return;
    }
    for (int i = 0; i < size; i++) {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

int print_combination(int arr[], int start, int elements_count, int start_number, int end_number) {
    int count = 0;
    for (int i = start_number; i <= end_number; i++) {
        arr[start] = i;
        if (elements_count == 1) {
            display_vector(arr, start + 1);
            count++;
        }
        else{
            count += print_combination(arr, start + 1, elements_count - 1, i + 1, end_number);
        }
    }
    return count;
}

int main(){
    printf("\n----------------LITERKI----------------\n");
    char tab_literki[7];
    int result = fun(tab_literki, 0,0,4,0);
    printf("%d", result);

    printf("\n----------------CYFRY----------------\n");
    int tab_cyfry[7];
    int result2 = print_combination(tab_cyfry, 0,3,1,5);
    printf("%d", result2);

    return 0;
}