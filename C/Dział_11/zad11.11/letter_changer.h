#ifndef LETTER_CHANGER_H
#define LETTER_CHANGER_H

enum letter_changer_t {
    TO_UPPER,
    TO_LOWER
};
char to_lower(char c);
char to_upper(char c);
char* change_letter_size(char *txt, enum letter_changer_t c);
#endif