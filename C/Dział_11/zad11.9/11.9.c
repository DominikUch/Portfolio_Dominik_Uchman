#include <stdio.h>

#define SIZE 1000

int my_strlen(char *txt){
    int i =0;
    while(*(txt+i) != '\0'){
        i++;
    }
    return i;
}

int connect(const char* t1, const char* t2, const char* t3, char* t4, int size){
    if(t1 == NULL || t2 == NULL || t3 == NULL || t4 == NULL || my_strlen((char*)t1) <0 || my_strlen((char*)t2) <0
       || my_strlen((char*)t3) <0 || size <0){
        return 1;
    }
    if( ((my_strlen((char*)t1) + my_strlen((char*)t2) + my_strlen((char*)t3) +3) > size)){
        return 1;
    }
    int i=0;
    while(*(t1 + i) != '\0'){
        *(t4+i) = *(t1 + i);
        i++;
    }
    *(t4+i) = ' ';
    int start2 =i+1;
    i =0;
    while(*(t2 + i) != '\0'){
        *(t4+start2) = *(t2 + i);
        start2++;
        i++;
    }
    *(t4+start2) = ' ';
    int start3 = start2 + 1;
    i=0;
    while(*(t3 + i) != '\0'){
        *(t4+start3) = *(t3 + i);
        start3++;
        i++;
    }
    *(t4+start3) = '\0';
    return 0;
}


int main() {
    printf("Podaj tekscik\n");
    char tab1[SIZE+1];
    fgets(tab1, SIZE+1, stdin);
    int i1 =0;
    int new_line1 =0;
    while(*(tab1+i1)!= '\0'){
        if(*(tab1+i1) == '\n'){
            *(tab1+i1) ='\0';
            new_line1++;
        }
        i1++;
    }
    if(!new_line1){
        int c;
        while( (c = getchar()) != '\n' && c != EOF ){}
    }
    printf("Podaj tekscik\n");
    char tab2[SIZE+1];
    fgets(tab2, SIZE+1, stdin);
    int i2 =0;
    int new_line2 =0;
    while(*(tab2+i2)!= '\0'){
        if(*(tab2+i2) == '\n'){
            *(tab2+i2) ='\0';
            new_line2++;
        }
        i2++;
    }
    if(!new_line2){
        int c;
        while( (c = getchar()) != '\n' && c != EOF ){}
    }
    printf("Podaj tekscik\n");
    char tab3[SIZE+1];
    fgets(tab3, SIZE+1, stdin);
    int i3 =0;
    int new_line3 =0;
    while(*(tab3+i3)!= '\0'){
        if(*(tab3+i3) == '\n'){
            *(tab3+i3) ='\0';
            new_line3++;
        }
        i3++;
    }
    if(!new_line3){
        int c;
        while( (c = getchar()) != '\n' && c != EOF ){}
    }

    char tab_result[3*SIZE+3];
    int result = connect(tab1,tab2,tab3,tab_result, 3*SIZE+3);
    if(result == 1){
        printf("Incorrect input");
        return -1;
    }
    else{
        printf("%s", tab_result);
    }
    return 0;
}
