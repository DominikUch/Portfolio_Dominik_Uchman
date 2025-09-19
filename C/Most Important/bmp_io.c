#include <stdio.h>

#define PALETTE_SIZE 1024

#pragma pack(push, 1)
typedef struct {
    unsigned short type;
    unsigned int size;
    unsigned short reserved1;
    unsigned short reserved2;
    unsigned int offset;
} bmp_file_header;

typedef struct {
    unsigned int size;
    int width;
    int height;
    unsigned short planes;
    unsigned short bits_per_pixel;
    unsigned int compression;
    unsigned int image_size;
    int x_pixels_per_meter;
    int y_pixels_per_meter;
    unsigned int colors_used;
    unsigned int colors_important;
} bmp_info_header;
#pragma pack(pop)

void read_bmp(char* filename, unsigned char* image_memory, int height, int width) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        printf("Cannot open file %s.\n", filename);
        return;
    }

    bmp_file_header file_header;
    bmp_info_header info_header;

    fread(&file_header, sizeof(bmp_file_header), 1, file);
    fread(&info_header, sizeof(bmp_info_header), 1, file);

    if (file_header.type != 0x4D42) {
        printf("File %s is not a proper BMP file.\n", filename);
        fclose(file);
        return;
    }

    if ((info_header.bits_per_pixel != 8 && info_header.bits_per_pixel != 24) || info_header.colors_used > 256) {
        printf("Only 8-bit and 24-bit bmp files with max 256 colors are supported. Given file has bits_per_pixel=%u and colors_used=%u\n",
               info_header.bits_per_pixel, info_header.colors_used);
        fclose(file);
        return;
    }

    if (info_header.height != height || info_header.width != width) {
        printf("Inappropriate memory size for image storage. Specified size: height=%d, width=%d. Bitmap size in the file: height=%d, width=%d.\n",
               height, width, info_header.height, info_header.width);
        fclose(file);
        return;
    }

    unsigned char palette[PALETTE_SIZE];
    fread(palette, PALETTE_SIZE, 1, file);

    int row_size = (width + 3) & (~3);
    unsigned char padding[3];
    for (int i = height - 1; i >= 0; i--) {
        fread(image_memory + i * width, sizeof(unsigned char), width, file);
        fread(padding, sizeof(unsigned char), row_size - width, file);
    }

    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            unsigned char* pixel = image_memory + row * width + col;
            unsigned char blue = palette[*pixel * 4];
            unsigned char green = palette[*pixel * 4 + 1];
            unsigned char red = palette[*pixel * 4 + 2];
            *pixel = (blue + green + red) / 3;
        }
    }

    fclose(file);
}

void write_bmp(char* filename, unsigned char* image_memory, int height, int width) {
    bmp_file_header file_header = { 0 };
    bmp_info_header info_header = { 0 };

    int row_size = (width + 3) & (~3);
    int pixel_array_size = row_size * height;
    int file_size = sizeof(bmp_file_header) + sizeof(bmp_info_header) + PALETTE_SIZE + pixel_array_size;

    file_header.type = 0x4D42;
    file_header.size = file_size;
    file_header.offset = sizeof(bmp_file_header) + sizeof(bmp_info_header) + PALETTE_SIZE;

    info_header.size = sizeof(bmp_info_header);
    info_header.width = width;
    info_header.height = height;
    info_header.planes = 1;
    info_header.bits_per_pixel = 8;
    info_header.compression = 0;
    info_header.image_size = pixel_array_size;
    info_header.x_pixels_per_meter = 0;
    info_header.y_pixels_per_meter = 0;
    info_header.colors_used = 256;
    info_header.colors_important = 0;

    FILE* file = fopen(filename, "wb");
    if (!file) {
        printf("Failed to open file %s\n", filename);
        return;
    }

    fwrite(&file_header, sizeof(bmp_file_header), 1, file);
    fwrite(&info_header, sizeof(bmp_info_header), 1, file);

    unsigned char palette[PALETTE_SIZE];
    for (int i = 0; i < PALETTE_SIZE/4; i++) {
        palette[i * 4] = i; //blue
        palette[i * 4 + 1] = i; //green
        palette[i * 4 + 2] = i; //red
        palette[i * 4 + 3] = 255; //alpha
    }
    fwrite(palette, sizeof(palette), 1, file);

    unsigned char padding[3] = { 0 };
    for (int row = height - 1; row >= 0; row--) {
        fwrite(image_memory + row * width, sizeof(unsigned char), width, file);
        fwrite(padding, sizeof(unsigned char), row_size - width, file);
    }

    fclose(file);
}
