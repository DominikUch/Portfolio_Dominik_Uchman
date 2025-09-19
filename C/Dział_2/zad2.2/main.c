#include <stdio.h>

int main(){
    //nr1 odpowiada pierwszej czesci numeru.nr2 drugiej czesci numeru. nr3 trzeciej czesci numeru.
    int kierunkowy,nr1,nr2,nr3;

    printf("Podaj numer telefonu:\n");
    if(scanf("(%d) %d-%d-%d", &kierunkowy, &nr1,&nr2,&nr3) != 4){
        printf("Incorrect input\n");
        return 1;
    }
    else{
        printf("Numer kierunkowy: %02d\n", kierunkowy);
        printf("Numer telefonu: %03d-%02d-%02d\n", nr1,nr2,nr3);
        return 0;
    }
}
