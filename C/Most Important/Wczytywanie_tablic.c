#include <stdio.h>
#include <string.h>


//////////////////////////////////////// WCZYTANIE ZDANIA ////////////////////////////////////////
#define SIZE 6

//int main(){
//    char tab[SIZE+1];
//    printf("Podaj zdanie");
//    fgets(tab, SIZE, stdin);
//    int i =0;
//    int new_line =0;
//    while(*(tab+i) != '\0'){
//        if(*(tab+i) == '\n'){
//            *(tab+i) = '\0';
//            new_line++;
//        }
//        i++;
//    }
//    if(!new_line){
//        int c;
//        while( (c=getchar()) != '\n' && c != EOF ){}
//    }
//    printf("Twoje zdanie to:\n%s", tab);
//    return 0;
//}


//////////////////////////////////////// WCZYTANIE WIELU ZDAŃ ////////////////////////////////////////

#define WORDS_COUNT 10
//int main(){
//    char tab[WORDS_COUNT][SIZE+1];
//    printf("Podaj jakis tekst wariacie");
//    int words_count =0;
//    for(; words_count < WORDS_COUNT; words_count++){
//        fgets( *(tab+words_count), SIZE, stdin);
//        if(  *(*(tab+words_count)+0) == '\n'){
//            break;
//        }
//        int i =0;
//        int new_line = 0;
//        while( *(*(tab+words_count)+i) != '\0'){
//            if(*(*(tab+words_count)+i) == '\n'){
//                *(*(tab+words_count)+i) = '\0';
//                new_line++;
//            }
//            i++;
//        }
//        if(!new_line){
//            int c;
//            while( (c=getchar())!='\n' && c != EOF ){}
//        }
//    }
//    printf("Twoje zdania to:\n");
//    for(int i =0; i < words_count; i++){
//        printf("%s\n", *(tab+i));
//    }
//    return 0;
//}

//////////////////////////////////////// WCZYTANIE tablicy liczb ////////////////////////////////////////
//
//int main(){
//    int tab[SIZE];
//    int count =0;
//    printf("Podaj liczby\n");
//    for(; count  < SIZE; count ++){
//        if(scanf("%d", &*(tab+count )) != 1){
//            printf("Incorrect input\n");
//            return 1;
//        }
//        if(*(tab+count) == -1){
//            break;
//        }
//    }
//    while(getchar() != '\n'){}
//    return 0;
//}