
#include <stdio.h>
int main() {
    for( int i = -10; i <= 10; i++){
        for (int j = -10; j <= 10; j++){
            int lewa_str = (i + j) * (i - (j));
            int prawa_str = (i * i) + (j * j);
            if (lewa_str == prawa_str){
                printf("%d %d\n", i,j);
            }
        }
    }
    return 0;
}




