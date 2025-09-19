#include "letter_changer.h"
#include <stdio.h>

char to_lower(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }
    return c;
}

char to_upper(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - ('a' - 'A');
    }
    return c;
}

char* change_letter_size(char *txt, enum letter_changer_t c) {
    if (txt == NULL) {
        return NULL;
    }

    char *ptr = txt;
    while (*ptr != '\0') {
        if (c == TO_UPPER) {
            *ptr = to_upper(*ptr);
        } else if (c == TO_LOWER) {
            *ptr = to_lower(*ptr);
        } else {
            return NULL;
        }
        ptr++;
    }
    return txt;
}