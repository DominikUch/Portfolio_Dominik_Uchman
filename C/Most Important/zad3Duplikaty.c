//#include <stdio.h>
//#include <string.h>
//#define SIZE 100
//
//void print_sequence(int *tab, int size){
//    for(int i =0; i < size; i++ ){
//        printf("%d ", *(tab+i));
//    }
//    printf("\n");
//}
//
//void recalculate_sequence(int *tab, int size) {
//    if (size <= 2) {
//        return;
//    }
//    int temp[SIZE] = {0};
//    int index = 0;
//    int mid = size / 2;
//
//    for (int i = 0; i < mid; i++) {
//        int start = *(tab + i);
//        int end = *(tab + (size - i - 1));
//        int suma = start + end;
//        if (suma > 9) {
//            int digit = suma % 10;
//            *(temp+(index)) = suma / 10;
//            *(temp+(index+1)) = digit;
//            index+=2;
//        } else {
//            *(temp+(index)) = suma;
//            index++;
//        }
//    }
//    // Obsługa elementu środkowego dla nieparzystych rozmiarów
//    if (size % 2 != 0) {
//        temp[index++] = tab[mid];
//    }
//    print_sequence(temp, index);
//    recalculate_sequence(temp, index);
//}
//int * count_first_sequence(char * text, int frequences[SIZE], int *end_size){
//    if(text == NULL || frequences == NULL){
//        return NULL;
//    }
//    int text_len = strlen(text) - 1;
//    if(text_len <= 0){
//        return NULL;
//    }
//    for(int i = 0; i < SIZE; i++) {
//        *(frequences+i) = 0;
//    }
//    //usuniecie duplikatow i stworznie nowej tablica
//    char signs[SIZE];
//    int unique_len = 0;
//
//    for(int i =0; i < text_len; i++){
//        int is_unique = 1;
//        for(int j =0; j < text_len; j++){
//            if(*(text+i) == *(signs+j)){
//                is_unique = 0;
//                break;
//            }
//        }
//        if(is_unique == 1){
//            *(signs + unique_len) = *(text+i);
//            unique_len++;
//        }
//    }
//    for(int i =0; i <text_len; i++){
//        for(int j=0;j < unique_len; j++){
//            if(*(text + i) == *(signs + j)){
//                *(frequences + j) += 1;
//                break;
//            }
//        }
//    }
//    *end_size = unique_len;
//    return frequences;
//}
//int main() {
//    printf("Podaj slowo\n");
//    char word[SIZE];
//    fgets(word, SIZE, stdin);
//    printf("%s", word);
//    int zlicznia[SIZE] = {0};
//    int size;
//    count_first_sequence(word, zlicznia, &size);
//    printf("poczatkowy ciag liczb\n");
//    print_sequence(zlicznia, size);
//    recalculate_sequence(zlicznia, size);
//    return 0;
//}


#include <stdio.h>
#define SIZE 10
int main(){
    printf("Podaj liczby:\n");
    int tab[SIZE];
    int count =0;
    for(; count < SIZE; count++){
        if(scanf("%d", &*(tab+count)) != 1){
            return -1;
        }
        if(*(tab + count) == -1){
            break;
        }
    }
    while (getchar() != '\n');

    printf("Tablica przed sortowaniem to:\n");
    for(int i=0; i < count; i++){
        printf("%d ", *(tab + i));
    }
    printf("\n");
    for(int i=0; i < count - 1; i++){
        for(int j=0; j < count -1-i; j++){
            if(*(tab + j+1) < *(tab + j)){
                int temp = *(tab + j);
                *(tab + j) = *(tab + j+1);
                *(tab + j+1) = temp;
            }
            printf("\nTablica po przejsciu %d to:\n", j);
            for(int k=0; k < count; k++){
                printf("%d ", *(tab + k));
            }
        }
    }
    return 0;
}
