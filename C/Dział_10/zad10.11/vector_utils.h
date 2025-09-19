#ifndef VECTOR_UTILS_H
#define VECTOR_UTILS_H
#define SIZE 150
enum direction {
    ROTATE_RIGHT = 1,
    ROTATE_LEFT = 2
};
int read_vector(int *vec, int size, int stop_value);
void display_vector(const int* tab, int size);
int shift(int *array, int array_size, int positions_to_shift, enum direction dir);
#endif