#include <stdio.h>

int main() {
    int day;
    int month;
    int year;
    printf("Podaj date w formacie dd-mm-yyyy:");
    int user_input = scanf("%d-%d-%d", &day, &month, &year);
    if (user_input != 3) {
        printf("Incorrect input");
        return 1;
    }
    //ujemna data + niemożliwe miesiące
    if (day <= 0 || month <= 0 || month > 12 || year <= 0) {
        printf("Incorrect");
    }
        //dłuższe miesiace
    else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        if (day > 31) {
            printf("Incorrect");
        } else {
            printf("Correct");
        }
    }
        //krótsze miesiące
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30) {
            printf("Incorrect");
        } else {
            printf("Correct");
        }
    }
        // rok przestepny
    else if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        if (month == 2 && day > 29) {
            printf("Incorrect");
        }
        else{
            printf("Correct");
        }
    }
        // luty w roku nieprzestępnym
    else if (month == 2 && day > 28) {
        printf("Incorrect");
    }
    else {
        printf("Correct");
    }
    return 0;
}