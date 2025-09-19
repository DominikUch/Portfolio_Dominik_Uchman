#include <stdio.h>
#include "bmp_io.h"
#define WIDTH 200
#define HEIGHT 200
#define OKNO 10

int minimum(unsigned char *image, int size, int start_x, int start_y) {
    int min = *(image + (start_y * WIDTH) + start_x);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (*(image + ((start_y + i) * WIDTH) + (start_x + j))< min) {
                min = *(image + ((start_y + i) * WIDTH) + (start_x + j));
            }
        }
    }
    return min;
}

int maximum(unsigned char *image, int size, int start_x, int start_y) {
    int max = *(image + (start_y * WIDTH) + start_x);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if ( *(image + ((start_y + i) * WIDTH) + (start_x + j))> max) {
                max = *(image + ((start_y + i) * WIDTH) + (start_x + j));
            }
        }
    }
    return max;
}

void draw_main(unsigned char *image, int x, int y, int edge) {
    if (edge <= 0 || x >= WIDTH || y >= HEIGHT) {
        return;
    }
    //rozmiar - 1- i
    *(image + (y * WIDTH) + x) = 255;
    draw_main(image ,x+1,y+1,edge-1);
}

void draw_second(unsigned char *image, int x, int y, int edge) {
    if (edge <= 0 || x >= WIDTH || y >= HEIGHT) {
        return;
    }
    //rozmiar - 1- i
    *(image + ((y+OKNO - 1) * WIDTH) + x) = 255;
    draw_second(image ,x+1,y-1,edge-1);
}

void draw_X(unsigned char *image, int x, int y, int edge) {
    if (edge <= 0 || x >= WIDTH || y >= HEIGHT) {
        return;
    }
    //rozmiar - 1- i
    draw_main(image ,x,y,edge);
    draw_second(image ,x,y,edge);
}

void process(unsigned char *image, int x, int y) {
    if (y >= HEIGHT) {
        return;
    }

    int max = maximum(image, OKNO, x, y);
    int min = minimum(image, OKNO, x, y);
    if (max - min < 100) {
        draw_X(image, x, y, OKNO);
    }
    if(x + OKNO <= WIDTH - OKNO){
        process(image, x + OKNO, y);
    }
    else{
        process(image, 0, y+OKNO);
    }
}

int main() {
    unsigned char photo[WIDTH * HEIGHT];
    read_bmp("../kwiatek.bmp", photo, WIDTH, HEIGHT);
    process(photo, 0, 0);
    write_bmp("../kwiatek_DONE.bmp", photo, WIDTH, HEIGHT);
    return 0;
}


//#include <stdio.h>
//#include "bmp_io.h"
//#define ROZMIAR1 10
//#define ROZMIAR2 200
//void rekurencja(unsigned char* data, int row, int column){
//    if(row==200){
//        return;
//    }
//    int max = *(data+row*ROZMIAR2 + column);
//    int min = *(data+row*ROZMIAR2 + column);
//    for(int i=0;i<ROZMIAR1;i++){
//        for(int j=0;j<ROZMIAR1;j++){
//            if(*(data+(row+i)*ROZMIAR2+column+j)>max){
//                max = *(data+(row+i)*ROZMIAR2+column+j);
//            }
//            if(*(data+(row+i)*ROZMIAR2+column+j)<min){
//                min = *(data+(row+i)*ROZMIAR2+column+j);
//            }
//        }
//    }
//    if(max-min<100){
//        for(int i=0;i<ROZMIAR1;i++){
//            *(data+(row+i)*ROZMIAR2+column+i) = 255;
//        }
//        for(int i=0;i<ROZMIAR1;i++){
//            *(data+(row+i)*ROZMIAR2+column+ROZMIAR1-1-i) = 255;
//        }
//
//    }
//    if(column==190){
//        return rekurencja(data,row+10,column-190);
//    }
//    else {
//        return rekurencja(data, row, column + 10);
//    }
//}
//
//int main(){
//    unsigned char data[ROZMIAR2][ROZMIAR2];
//    read_bmp("../kwiatek.bmp",(unsigned char *)data,ROZMIAR2,ROZMIAR2);
//    rekurencja((unsigned char*)data,0,0);
//    write_bmp("../kwiatek_DONE.bmp",(unsigned char *)data,ROZMIAR2,ROZMIAR2);
//
//    return 0;
//}
