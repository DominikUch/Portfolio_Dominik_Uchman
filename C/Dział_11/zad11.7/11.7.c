#include <stdio.h>
#define SIZE 1000

int my_strlen(char *text){
    if(text == NULL){
        return -1;
    }
    int i =0;
    while(*(text+i) != '\0'){
        i++;
    }
    return i;
}

int is_alpha(char a){
    if((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z')){
        return 1;
    }
    else{
        return 0;
    }
}

char* swap_order_words(char* txt){
    if(txt == NULL){
        return NULL;
    }
    if(*txt == '\0'){
        return txt;
    }

    //testy
    int TESTY = my_strlen(txt) -1;
    while(is_alpha(*(txt+TESTY)) != 1){
        *(txt+TESTY) = '\0';
        TESTY--;
    }
    TESTY++;
    // Cleared text from non-alphabetic letters and extra spaces
    int i = 0;
    int j = 0; // Additional variable for tracking the position after clearing characters
    while(*(txt+i) != '\0'){
        if(!((*(txt+i) >= 'A' && *(txt+i) <= 'Z') || (*(txt+i) >= 'a' && *(txt+i) <= 'z'))){
            *(txt+i) = ' ';
        }
        if (*(txt+i) == ' ' && (is_alpha(*(txt+(i-1))) == 0)) {
            // Skip consecutive spaces
            i++;
            continue;
        }
        // Copy character to the new position after clearing
        *(txt+j) = *(txt+i);
        i++;
        j++; // Increment j only if a character is copied
    }
    *(txt+j) = '\0'; // Terminate the modified string

    // Reverse text
    int end = my_strlen(txt) - 1;
    int start = 0;
    while(end > start){
        char temp = *(txt+start);
        *(txt+start) = *(txt+end);
        *(txt+end) = temp;
        start++;
        end--;
    }

    // Reverse each word in the text without last one
    i = 0;
    int word_start = 0;
    while(*(txt + i) != '\0'){
        if(*(txt + i) == ' '){
            int word_end = i - 1;
            while(word_end > word_start){
                char temp = *(txt + word_start);
                *(txt + word_start) = *(txt + word_end);
                *(txt + word_end) = temp;
                word_start++;
                word_end--;
            }
            word_start = i + 1;
        }
        i++;
    }

    // Reverse last word directly
    int last_start = j - 1; // Start position of the last word
    while(*(txt + last_start) != ' ' && last_start >= 0){
        last_start--;
    }
    last_start++; // Adjust to the beginning of the last word
    end = j - 1; // End position of the last word
    for(; end > last_start; last_start++, end--){
        char temp = *(txt + last_start);
        *(txt + last_start) = *(txt + end);
        *(txt + end) = temp;
    }
    return txt;
}

int main() {
    printf("Podaj tekscik\n");
    char tab[SIZE+1];
    fgets(tab, SIZE+1, stdin);
    int i = 0;
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
        while( (c = getchar()) != '\n' && c != EOF ){}
    }
    swap_order_words(tab);
    if(my_strlen(tab) == 0){
        printf("show to Nothing");
    }
    printf("%s", tab);
    return 0;
}

