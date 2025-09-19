#include <stdio.h>
#define MAX_DATES 150

int is_valid_date(int day, int month, int year) {
    if (day < 0 || month < 1 || month > 12 || year < 0) {
        return 0;
    }
    return 1;
}

void swap_dates(int *day1, int *month1, int *year1, int *day2, int *month2, int *year2) {
    int temp = *day1;
    *day1 = *day2;
    *day2 = temp;

    temp = *month1;
    *month1 = *month2;
    *month2 = temp;

    temp = *year1;
    *year1 = *year2;
    *year2 = temp;
}

int sort_dates(int day[], int month[], int year[], int size) {
    if (size <= 0) {
        return 1;
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (year[j] > year[j + 1] || (year[j] == year[j + 1] && month[j] > month[j + 1]) ||
                (year[j] == year[j + 1] && month[j] == month[j + 1] && day[j] > day[j + 1])) {
                swap_dates(&day[j], &month[j], &year[j], &day[j + 1], &month[j + 1], &year[j + 1]);
            }
        }
    }

    for (int i = 0; i < size; i++) {
        if (!is_valid_date(day[i], month[i], year[i])) {
            return 1;
        }
    }

    return 0;
}

int main() {
    int day[MAX_DATES], month[MAX_DATES], year[MAX_DATES];
    int size = 0;

    printf("Enter dates in the format dd-mm-yyyy:\n");

    while (size < MAX_DATES) {
        int d, m, y;

        if (scanf("%d", &d) != 1) {
            printf("Incorrect input\n");
            return 1;
        }

        if (d == 0) {
            break;
        }

        if (scanf("-%d-%d", &m, &y) != 2 || !is_valid_date(d, m, y)) {
            printf("Incorrect input\n");
            return 1;
        }

        day[size] = d;
        month[size] = m;
        year[size] = y;
        size++;
    }

    if (size == 1 && is_valid_date(day[0], month[0], year[0])) {
        printf("%02d-%02d-%04d\n", day[0], month[0], year[0]);
        return 0;
    }

    if (size == 0) {
        printf("Not enough data available\n");
        return 3;
    }

    sort_dates(day, month, year, size);

    for (int i = 0; i < size; i++) {
        printf("%02d-%02d-%04d\n", day[i], month[i], year[i]);
    }

    return 0;
}