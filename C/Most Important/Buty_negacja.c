#include <stdio.h>
#include "bmp_io.h"

#define WIDTH 1000
#define HEIGHT 1000


void thresholding(unsigned char *image_ptr, int thresh1, int thresh2){
    for(int i = 0; i < WIDTH*HEIGHT; i++){
        if(*(image_ptr + i) >= thresh1 && *(image_ptr + i) <= thresh2){
            *(image_ptr + i) = 255;
        }
        else{
            *(image_ptr + i) =0;
        }
    }
}

int main() {
    unsigned char tab[WIDTH][HEIGHT];
    read_bmp("../BUTY.bmp", *tab ,WIDTH, HEIGHT);
    thresholding(*tab, 30, 230);
    write_bmp("../ButyNegacja.bmp", *tab, WIDTH, HEIGHT);
    return 0;
}