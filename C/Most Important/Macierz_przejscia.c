#include "bmp_io.h"
#define WIDTH 1000
#define HEIGHT 1000

void process_image(unsigned char *tab, int x, int y, int rows, int cols){
    for(int row =0;row < rows; row++){
        for(int col =0; col < cols; col++) {
            if (row == col) {
                *(tab + ((y + row) * WIDTH) + x + col) = 255;
                break;
            }
            *(tab + ((cols - 1 - col) * WIDTH) + x + col) = 255;
        }
    }
}


void left_to_right(unsigned char *tab, int x, int y, int rows, int cols) {
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            if (row <= col && (row + col >= (rows + cols) / 2)) {
                unsigned char temp = *(tab + ((y + row) * WIDTH) + x + col);
                *(tab + ((y + row) * WIDTH) + x + col)= *(tab + ((y + row) * WIDTH) + x + (cols - 1 - col));
                *(tab + ((y + row) * WIDTH) + x + (cols - 1 - col)) = temp;
            }
        }
    }
}

void upper_to_lower(unsigned char *tab, int x, int y, int rows, int cols){
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            if (row <= col && (row + col <= (rows + cols) / 2)) {
                unsigned char temp = *(tab + ((y + row) * WIDTH) + x + col);
                *(tab + ((y + row) * WIDTH) + x + col) = *(tab + ((cols - 1 - y - row) * WIDTH) + x + col);
                *(tab + ((cols - 1 - y - row) * WIDTH) + x + col) = temp;
            }
        }
    }
}

void move_by_main_diagonal_macierz(unsigned char *tab, int x, int y, int rows, int cols){
    for(int row = 0; row < rows; row++){
        for(int col = 0; col < cols; col++) {
            if (row >= col) {
                // Piksele z lewego dolnego trójkąta
                unsigned char temp = *(tab + ((y + row) * WIDTH) + x + col);
                *(tab + ((y + row) * WIDTH) + x + col) = *(tab + ((y + cols - 1 - row) * WIDTH) + x + (rows - 1 - col));
                *(tab + ((y + cols - 1 - row) * WIDTH) + x + (rows - 1 - col)) = temp;
            }
        }
    }
}

void move_by_main_diagonal(unsigned char *tab, int x, int y, int rows, int cols){
    for(int row = 0; row < rows; row++){
        for(int col = 0; col < cols; col++) {
            if (row >= col) {
                unsigned char temp = *(tab+ ((y + row) * WIDTH) + (x + col));
                *(tab+ ((y + row) * WIDTH) + (x + col)) = *(tab+ ((y + col) * WIDTH) + (x + row));
                *(tab+ ((y + col) * WIDTH) + (x + row)) = temp;
            }
        }
    }
}


int main(){
    unsigned char image[HEIGHT][WIDTH];
    read_bmp("../buty.bmp", (unsigned char *) image, HEIGHT, WIDTH);
    process_image((unsigned char*)image, 0, 0, WIDTH, HEIGHT);
    //left_to_right(*image, 0, 0, WIDTH, HEIGHT);
    upper_to_lower(*image, 0, 0, WIDTH, HEIGHT);
    //move_by_main_diagonal(*image, 0, 0, WIDTH, HEIGHT);
    //move_by_second_diagonal(*image, 0, 0, WIDTH, HEIGHT);
    write_bmp("../Matrix_triangles.bmp", (unsigned char *) image, HEIGHT, WIDTH);
}

