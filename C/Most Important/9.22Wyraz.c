#include <stdio.h>
#include <ctype.h>
#define SIZE 30

void display(char tab[], int size){
    for(int i = 0; i < size; i++){
        printf("%c", tab[i]);
    }
    printf("\n");
}

int read_vector2(char tab[], int size){
    if(tab == NULL || size <= 0){
        return -1;
    }
    int count = 0;
    int znak;
    while(count < size){
        znak = getchar();
        if(znak == '\n' || znak == EOF || count >= SIZE){
            break;
        }
        tab[count] = (char)znak;
        count++;
    }
    tab[count] = '\0';
    return count;
}

int sort_lowercase(char tab[]) {
    if (tab == NULL) {
        return 1;
    }
    int size = 0;
    while (tab[size] != '\0') {
        size++;
    }
    int swapped = 0;
    for(int i =0; i < size-1; i++){
        for(int j = 0; j < size - 1-i; j++){
            if(tolower(tab[j]) > tolower(tab[j+1])){
                char temp = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = temp;
                swapped = 1;
            }
        }
        if(!swapped){
            break;
        }
    }
    return 0;
}

int main() {
    printf("Wprowadz tekst:\n");
    char tab[SIZE + 1];
    int count = read_vector2(tab, SIZE);
    printf("Before sorting:\n");
    display(tab, count);
    printf("After sorting:\n");
    sort_lowercase(tab);
    display(tab,count);
    return 0;
}