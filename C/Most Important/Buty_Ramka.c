#include "bmp_io.h"
#define WIDTH 1000
#define HEIGHT 1000
#define WINDOW_SIZE 250

int check_window(unsigned char* photo, int start_x, int start_y) {
    int count = 0;
    for(int i = 0; i < WINDOW_SIZE; i++) {
        for(int j = 0; j < WINDOW_SIZE; j++) {
            if(*(photo + ((start_y + i) * WIDTH) + (start_x + j)) >= 200) {
                count++;
            }
        }
    }
    if(count > (WINDOW_SIZE * WINDOW_SIZE / 2)){
        return 1;
    }
    return 0;
}
void draw_vertical(unsigned char* photo, int start_x, int start_y, int edge) {
    if(edge <= 0){
        return;
    }
    // Pionowe boki || x stały || Y zmienny
    //Ograniczasz X bo do niego dodajesz 250, dlatego if
    if(start_x < WIDTH - 250 && start_y < HEIGHT){
        *(photo+(start_y*WIDTH)+start_x) = 250;
        *(photo+(start_y*WIDTH)+(start_x+WINDOW_SIZE)) = 250;
    }
    draw_vertical(photo, start_x,start_y+1,edge -1);
}
void draw_horizontal(unsigned char* photo, int start_x, int start_y, int edge) {
    if(edge <= 0){
        return;
    }
    // Poziome bokli|| x zmienny || y stały
    //Ograniczasz Y bo do niego dodajesz 250, dlatego if
    if(start_x < WIDTH && start_y < HEIGHT-250){
        *(photo+(start_y*WIDTH)+start_x) = 250;
        *(photo+((start_y+WINDOW_SIZE)*WIDTH)+start_x) = 250;
    }
    draw_horizontal(photo, start_x + 1, start_y, edge - 1);
}

void draw_inner_frame(unsigned char* photo, int start_x, int start_y, int edge) {
    if(edge == 0){
        return;
    }
    draw_vertical(photo, start_x, start_y,edge);
    draw_horizontal(photo, start_x, start_y,edge);
}

void process_image(unsigned char* photo, int start_x, int start_y, int cols, int rows){
    if(start_x >= cols || start_y >= rows){
        return ;
    }
    if(check_window(photo, start_x, start_y) == 1){
        draw_inner_frame(photo ,start_x, start_y, WINDOW_SIZE);
    }

    if(start_x+WINDOW_SIZE <= cols - WINDOW_SIZE){
        process_image(photo, start_x+WINDOW_SIZE, start_y, cols, rows);
    }
    //doszedłem do konca X
    else{
        //zeruje X i powtarzam
        if(start_y+WINDOW_SIZE <= rows - WINDOW_SIZE){
            process_image(photo,0, start_y+WINDOW_SIZE, cols, rows);
        }
    }
}

int main() {
    unsigned char image[HEIGHT][WIDTH];
    read_bmp("../buty_kwadraty.bmp", (unsigned char *) image, HEIGHT, WIDTH);
    process_image((unsigned char*)image, 0, 0, WIDTH, HEIGHT);
    write_bmp("../buty_kwadraty_modified.bmp", (unsigned char *) image, HEIGHT, WIDTH);
    return 0;
}

