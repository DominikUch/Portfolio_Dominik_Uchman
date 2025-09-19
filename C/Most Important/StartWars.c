#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DICTIONARY_SIZE 12
#define MAX_WORD_LENGTH 10
#define MAX_SENTENCE_LENGTH 10 * 10

char dictionary[DICTIONARY_SIZE][MAX_WORD_LENGTH] = {"Moc", "Jedi", "Sith", "Imperium", "Rebelia",
                                                     "Gwiezdny", "Wojny", "Miecz", "Mroczny",
                                                     "Swiatlo", "Mistrz", "Mocarz"};

void generate_solo_sentence(char sentence[], int words_in_sentance_count) {
    strcpy(sentence, "");
    for (int i = 0; i < words_in_sentance_count; i++) {
        strcat(sentence, dictionary[rand() % DICTIONARY_SIZE]);
        strcat(sentence, " ");
    }
}

void bubble_sort(int tab[], int size) {
    for (int i = 0; i < size-1; i++) {
        for (int j = 0; j < size-i-1; j++) {
            if (tab[j] < tab[j+1]) {
                int temp = tab[j+1];
                tab[j+1] = tab[j];
                tab[j] = temp;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    char sentence[MAX_SENTENCE_LENGTH];
    int statistics[DICTIONARY_SIZE] = {0};
    printf("Wygenerowane zdania:\n");

    //WSZYTKO DLA KAŻDEGO ZDANIA OSOBNO
    for (int sentence_num = 0; sentence_num < 10; sentence_num++) {
        int word_count = (rand() % (10 - 3 + 1) + 3); // od 3 do 10 słów
        generate_solo_sentence(sentence, word_count);
        printf("%d. %s\n", sentence_num+1, sentence);

        // Aktualizacja statystyk
        char *word = strtok(sentence, " ");
        while (word != NULL) {
            for (int j = 0; j < DICTIONARY_SIZE; j++) {
                if (strcmp(word, dictionary[j]) == 0) {
                    statistics[j]++;
                    break;
                }
            }
            word = strtok(NULL, " ");
        }
    }
    bubble_sort(statistics, DICTIONARY_SIZE);
    printf("Statystyka ilosci wystepowania slow:\n");
    for (int i = 0; i < DICTIONARY_SIZE; i++) {
        printf("%s: %d\n", dictionary[i], statistics[i]);
    }
    return 0;
}