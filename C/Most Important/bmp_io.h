#ifndef BMP_IO_H
#define BMP_IO_H

void read_bmp(char* filename, unsigned char* data, int height, int width);
void write_bmp(char* filename, unsigned char* data, int height, int width);

#endif //BMP_IO_H
