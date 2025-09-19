#include <stdio.h>

int main() {
    int ocena;
    printf("Podaj ocene:");
    scanf("%d", &ocena);
    switch (ocena) {
        case 1:
            printf("brak promocji do nastepnej klasy");
            break;
        case 2:
            printf("promocja do nastepnej klasy");
            break;
        case 3:
            printf("promocja do nastepnej klasy");
            break;
        case 4:
            printf("promocja do nastepnej klasy");
            break;
        case 5:
            printf("promocja do nastepnej klasy");
            break;
        case 6:
            printf("promocja z ocena celujaca");
            break;
        default:
            printf("wprowadzona ocena jest niepoprawna");
    }
}