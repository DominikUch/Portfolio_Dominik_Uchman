#include <stdio.h>

int main(){
    int odp;
    printf("Podaj cyfe dnia:\n");
    scanf("%d",&odp);

    switch(odp){
        case 1:
            printf("dzien roboczy");
            break;
        case 2:
            printf("dzien roboczy");
            break;
        case 3:
            printf("dzien roboczy");
            break;
        case 4:
            printf("dzien roboczy");
            break;
        case 5:
            printf("dzien roboczy");
            break;
        case 6:
            printf("weekend");
            break;
        case 7:
            printf("weekend");
            break;
        default:
            printf("Incorrect input");
            return 1;
    }
    return 0;
}



