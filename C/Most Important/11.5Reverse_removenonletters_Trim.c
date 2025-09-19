#include <stdio.h>
#define SIZE 1000

int strlen(char *text){
    int i =0;
    int size =0;
    while(*(text+i) != '\0'){
        size++;
        i++;
    }
    return size;
}
int is_alpha(char a){
    if(a >= 'A' && a <= 'Z' || a >= 'a' && a <= 'z'){
        return 1;
    }
    return 0;
}
int between_words(char *text, int index){
    if (index > 0 && *(text + index) == ' ' && is_alpha(*(text + (index - 1)))){
        return 1;
    }
    return 0;
}

char* trim(char* text){
    if(text == NULL){
        return NULL;
    }
    //początek i koniec
    int temp_start = 0;
    while(!is_alpha(*(text + temp_start))){
        temp_start++;
    }
    int start = temp_start;

    int temp_end = strlen(text) - 1;
    while(!is_alpha(*(text+temp_end))){
        temp_end--;
    }
    int end = temp_end;
    *(text + (temp_end +1)) = '\0';

    //przepisanie z usunięciem spacji
    int i=0;
    while(*(text+start) != *(text+(end + 1))){
        if(is_alpha(*(text+start)) == 1 || between_words(text,start) == 1){
            *(text+i) = *(text+start);
            i++;
        }
        start++;
    }
    *(text + i) = '\0';
    return text;
}

char* remove_non_letters(char* text){
    if(text == NULL){
        return NULL;
    }
    int i =0;
    while(*(text +i) != '\0'){
        if(is_alpha(*(text +i)) == 0){
            *(text+i) = ' ';
        }
        i++;
    }
    return text;
}

char* reverse(char* text){
    if(text == NULL){
        return NULL;
    }
    int end = strlen(text) -1;
    int start = 0;
    while(end > start){
        char temp;
        temp = *(text + start);
        *(text + start) = *(text + end);
        *(text + end) =temp;
        start++;
        end--;
    }
    return text;
}



int main() {
    printf("Dej jakis tekst\n");
    char tab[SIZE];
    fgets(tab, SIZE, stdin);
    int i =0;
    int new_line = 0;
    while(*(tab+i) != '\0'){
        if(*(tab+i) == '\n'){
            *(tab+i) = '\0';
            new_line++;
        }
        i++;
    }
    if(!new_line){
        int c;
        while( (c=getchar()) != '\n' && c != EOF ){}
    }
    remove_non_letters(tab);
    trim(tab);
    reverse(tab);
    int j =0;
    int letter = 0;
    while(*(tab+j) == '\0'){
        if(is_alpha(*(tab+j)) == 1){
            letter = 1;
        }
        j++;
    }
    if(!letter){
        printf("wohs ot gnihtoN\n");
    }
    else{
        printf("%s", tab);
    }
    return 0;
}
