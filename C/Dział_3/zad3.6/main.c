
#include <stdio.h>

int main() {
    double potegi;
    for (potegi = 1; potegi < 10e+19; potegi = potegi * 10)
        printf("%.0lf ", potegi);
    return 0;
}