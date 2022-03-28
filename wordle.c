#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

int main (void) {
    bool playing = true;
    char wordOfTheDay[6] = "yacht";
    char guess[20];
    int results[5];
    int sum = 0;
    printf("\n");
    printf("Welcome to Wordle in C\n");
    printf("Written by Stevie Plant\n");
    printf("\n");
    printf("Start by guessing a word\n");
    printf("A corresponding number will be returned\n");
    printf("0 means the letter is incorrect\n");
    printf("1 means the letter is correct, and in the correct spot\n");
    printf("2 means the letter is correct, but in the wrong spot\n");
    printf("\n");

    do {
        // guessing loop
        printf("Please enter a 5 letter word: \n");
        fgets(guess, 20, stdin);

        if (guess[strlen(guess) - 1] == '\n') {
            guess[strlen(guess) - 1] = '\0';
        } 
    
        // check conditions
        for (int i = 0; i < 5; ++i) {
            if (wordOfTheDay[i] == guess[i]) {
                results[i] = 1;
                printf("%d", results[i]);
            } else if (strchr(wordOfTheDay, guess[i]) != NULL) {
                printf("2");
            } else {
                results[i] = 0;
                printf("%d", results[i]);
            }
        }
        printf("\n");
        for (int j = 0; j < 5; ++j) {
            sum += results[j];
        }
        
        if (strcmp(wordOfTheDay, guess) == 0) {
            playing = false;
        }
    } while (playing);
}