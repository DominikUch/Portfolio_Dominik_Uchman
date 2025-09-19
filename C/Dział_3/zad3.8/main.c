
#include <stdio.h>

int main() {
    int num_1, num_2;
    for (num_1 = 0; num_1 <= 10; num_1++) {
        for (num_2 = 0; num_2 <= 10; num_2++)
            printf("%2d * %2d = %2d\n", num_1,num_2,num_1 * num_2);
    }
    return 0;
}
