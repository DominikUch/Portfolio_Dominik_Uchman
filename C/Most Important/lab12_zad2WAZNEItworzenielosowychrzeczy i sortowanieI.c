#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define STUDENTS_COUNT 15


void bs(int *indeksy, int * points, int*runs, int size){
    for(int i=0; i < size-1;i++){
        for(int j =0; j < size - 1- i; j++){
            if(*(points + j) < *(points + j + 1)){
                int temp = *(points + j+1);
                *(points + j+1) = *(points + j);
                *(points + j) = temp;
                int temp2 = *(indeksy + j+1);
                *(indeksy + j+1) = *(indeksy + j);
                *(indeksy + j) = temp2;
                int temp3 = *(runs + j+1);
                *(runs + j+1) = *(runs + j);
                *(runs + j) = temp3;
            }
            if((*(points + j) == *(points + j + 1))  && *(runs + j) > *(runs + j+1)){
                int temp = *(points + j+1);
                *(points + j+1) = *(points + j);
                *(points + j) = temp;
                int temp2 = *(indeksy + j+1);
                *(indeksy + j+1) = *(indeksy + j);
                *(indeksy + j) = temp2;
                int temp3 = *(runs + j+1);
                *(runs + j+1) = *(runs + j);
                *(runs + j) = temp3;
            }
        }
    }
}

int main() {
    int students_idx[STUDENTS_COUNT];
    srand(time(NULL));
    //indexy
    int count =0;
    while(count < STUDENTS_COUNT){
        int index = (rand() % (120 - 101 +1) +101);
        int new = 1;
        for(int j =0; j < count; j++){
            if(*(students_idx + j) == index){
                new = 0;
                break;
            }
        }
        if(new == 1){
            *(students_idx + count) = index;
            count++;
        }
    }

    //punkty
    int points_tab[STUDENTS_COUNT];
    count =0;
    while(count < STUDENTS_COUNT){
        int points = (rand() % (11 - 1 + 1) + 1) * 5;
        *(points_tab+ count) = points;
        count++;
    }
    //runs
    int runs_tab[STUDENTS_COUNT];
    count =0;
    while(count < STUDENTS_COUNT){
        int runs = (rand() % (5 - 1 + 1) + 1);
        *(runs_tab+ count) = runs;
        count++;
    }
    for(int i =0; i < STUDENTS_COUNT; i++){
        printf("%3d ", *(students_idx + i));
    }
    printf("\n");
    for(int i =0; i < STUDENTS_COUNT; i++){
        printf("%3d ", *(points_tab + i));
    }
    printf("\n");
    for(int i =0; i < STUDENTS_COUNT; i++){
        printf("%3d ", *(runs_tab + i));
    }
    printf("\n");
    printf("After sort:\n");
    bs(students_idx, points_tab, runs_tab, STUDENTS_COUNT);
    for(int i =0; i < STUDENTS_COUNT; i++){
        printf("%3d ", *(students_idx + i));
    }
    printf("\n");
    for(int i =0; i < STUDENTS_COUNT; i++){
        printf("%3d ", *(points_tab + i));
    }
    printf("\n");
    for(int i =0; i < STUDENTS_COUNT; i++){
        printf("%3d ", *(runs_tab + i));
    }
    return 0;
}
