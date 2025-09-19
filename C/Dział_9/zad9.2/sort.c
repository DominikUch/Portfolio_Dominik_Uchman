#include <stdio.h>
#include "sort.h"
#include "vector_utils.h"

int bubble_sort_asc(int tab[], int size) {
    if (tab == NULL || size <= 0) {
        return 1;
    }
    int swapped;
    for (int i = 0; i < size - 1; i++) {
        swapped = 0;
        for (int j = 0; j < size - i - 1; j++) {
            if (tab[j] > tab[j + 1]) {
                int temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped) {
            break;
        }
        display_vector(tab, size);
    }

    return 0;
}

int bubble_sort_desc(int tab[], int size) {
    if (tab == NULL || size <= 0) {
        return 1;
    }
    int swapped;
    for (int i = 0; i < size - 1; i++) {
        swapped = 0;
        for (int j = 0; j < size - i - 1; j++) {
            if (tab[j] < tab[j + 1]) {
                int temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped) {
            break;
        }
        display_vector(tab, size);
    }
    return 0;
}
int bubble_sort(int tab[], int size, enum direction dir) {
    if (tab == NULL || size <= 0) {
        return 1;
    }
    if (dir == ASCENDING) {
        return bubble_sort_asc(tab, size);
    } else if (dir == DESCENDING) {
        return bubble_sort_desc(tab, size);
    } else {
        return 1;
    }
}