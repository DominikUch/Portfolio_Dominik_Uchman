#ifndef SORT_H
#define SORT_H
#define SIZE 50

enum direction {
    ASCENDING = 1,
    DESCENDING = 2
};

int bubble_sort(int tab[], int size, enum direction dir);
int bubble_sort_desc(int tab[], int size);
int bubble_sort_asc(int tab[], int size);

#endif