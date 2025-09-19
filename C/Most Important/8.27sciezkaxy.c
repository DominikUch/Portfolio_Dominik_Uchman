#include <stdio.h>


int is_destination_reachable(int sx, int sy, int dx, int dy) {
    if (sx == dx && sy == dy) { // Jeśli aktualne współrzędne są równe docelowym
        return 1;
    }
    if (sx > dx || sy > dy) { // Jeśli przekroczono docelowe współrzędne
        return 0;
    }
    // Sprawdzamy możliwość dotarcia do docelowych współrzędnych, poruszając się wzdłuż osi X lub Y
    if ((sx + sy <= dx && is_destination_reachable(sx + sy, sy, dx, dy)) || (sx + sy <= dy && is_destination_reachable(sx, sx + sy, dx, dy))) {
        return 1; // Jeśli możemy osiągnąć docelowe współrzędne, zwracamy 1
    }
    return 0; // W przeciwnym razie zwracamy 0
}


int main(){

    int sx,sy;
    printf("Podaj wspolrzedne poczatkowe:\n");
    if(scanf("%d %d", &sx, &sy) != 2){
        printf("Incorrect input");
        return 1;
    }
    int dx, dy;
    printf("Podaj wspolrzedne koncowe:\n");
    if(scanf("%d %d", &dx, &dy) != 2){
        printf("Incorrect input\n");
        return 1;
    }
    int result = is_destination_reachable(sx,sy,dx,dy);
    if(result == 1){
        printf("YES");
    }
    else{
        printf("NO");
    }
    return 0;
}
