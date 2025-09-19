#include <stdio.h>
#include "bmp_io.h"
#define ROWS 1000
#define COLS 1000


unsigned char find_min(unsigned char *tab, int size){
    if(size == 1){
        return *(tab+size - 1);
    }
    unsigned char min = find_min(tab+1, size-1);
    if(*(tab+0) < min){
        return *(tab+0);
    }
    else{
        return min;
    }
}

void make_path(unsigned char *photo, int row, int col, int points_count){
    if(points_count <=0 ){
        return;
    }
    unsigned char up = *(photo + ((row - 1) * COLS) + col);
    unsigned char down = *(photo + ((row + 1 ) * COLS) + col);
    unsigned char left = *(photo + (row * COLS) + (col -1));
    unsigned char right = *(photo + (row * COLS) + (col+1));
    unsigned char tab[4] = {up,down,left,right};
    unsigned char min = find_min(tab, 4);

    if(min == up){
        *(photo + ((row - 1) * COLS) + col) = 255;
        return make_path(photo, row -1, col, points_count -1);
    }
    if(min == down){
        *(photo + ((row + 1 )* COLS) + col) = 255;
        return make_path(photo, row +1, col, points_count -1);
    }
    if(min == left){
        *(photo + (row * COLS) + (col -1)) = 255;
        return make_path(photo, row, col-1, points_count -1);
    }
    if(min == right){
        *(photo + (row * COLS) + (col+1)) = 255;
        return make_path(photo, row, col+1, points_count -1);
    }
}

int main() {
    unsigned char image[ROWS][COLS];
    read_bmp("../pp1_path.bmp", *image, ROWS, COLS);
    make_path(*image, 304,58,5280);
    write_bmp("../done.bmp", *image, ROWS, COLS);
    return 0;
}
