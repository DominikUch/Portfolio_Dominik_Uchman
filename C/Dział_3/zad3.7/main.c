
#include <stdio.h>

int main() {
    int i = 0;
    double potegi;
        for (potegi = 1; potegi < 10e+19; potegi = potegi * 10) {
            printf("10 do potegi %2d = %22.0lf\n", i++, potegi);
        }
    return 0;
}
