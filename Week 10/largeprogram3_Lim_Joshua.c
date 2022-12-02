// Joshua Lim
// Dr. Steinberg
// COP3223 Section 4
// Large Program 3

// define macro constants
#define MAX_WORD_SIZE 20
#define MAX_GUESSES 6

// include libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// function prototypes (professor provided)
void rules(void); // displays rules of the game
void maskWord(char starword[], int size); // mask the word with stars (asterisks) to display
int playRound(char starword[], char answer[]); // play a round of hangman
int occurancesInWord(char userguess, char answer[]); // number of times letter occurs in the word
void updateStarWord(char starword[], char answer[], char userguess); // update the starword with the userguess
void playAgain(int *play); // ask user if to play again. 1 is yes, 2 is no

int main() {

    // declare variables
    int play = 1; // 1 is yes, 2 is no
    int round = 1; // round number
    int wordsize = 0; // size of word
    int i = 0; // loop counter
    char wordbank[8][MAX_WORD_SIZE]; // word bank
    char answer[MAX_WORD_SIZE]; // answer word
    char starword[MAX_WORD_SIZE]; // star word
    char userguess; // user guess
    FILE *fp; // file pointer
    
    // open file
    fp = fopen("words.txt", "r");
    
    // check if file is empty
    if (fp == NULL) {
        printf("Error: File is empty.");
        return 0;
    }

    // read file into word bank
    while (fscanf(fp, "%s", wordbank[i]) != EOF) {
        i++;
    }

    // close file
    fclose(fp);

    // play game
    while (play == 1) {

        // display rules if first round
        if (round == 1) {
            rules();
        }
        
        // create random int between 0 and 7, then select word from word bank
        srand(time(0));
        int random = (rand() % (7 - 0 + 1));
        strcpy(answer, wordbank[random]);
        
        // get word size
        wordsize = strlen(answer);
        
        // mask word
        maskWord(starword, wordsize);
        
        // play round
        int win = playRound(starword, answer);
        
        // display results
        if (win == 0) {
            printf("Sorry you did not win the round. The word was %s.\n", answer);
        } else {
            printf("Congratulations! You won! The word was %s.\n", answer);
        }

        // ask to play again
        playAgain(&play);
        
        if (play == 1) {
            round++;
        } else {
            printf("\n************************************************************************\n");
            printf("Thank you for playing today!");
        }

    }

    return 0;

}

// rules function
void rules(void) {

    // display rules
    printf("Welcome to the Hangman Game!\n");
    printf("************************************************************************\n");
    printf("Here are the rules.\n");
    printf("I will provide you with a word and you will have to guess the word.\n");
    printf("Each * represents a letter in the English Alphabet.\n");
    printf("You must figure out each letter of the missing word.\n");
    printf("For every correct letter guessed, I will reveal its place in the word.\n");
    printf("Each mistake will result in a strike.\n");
    printf("6 strikes will result in a loss that round.\n");
    printf("Are you ready? Here we go!\n");
    
}

// maskWord function
void maskWord(char starword[], int size) {

    // declare variables
    int i = 0; // loop counter

    // mask word with stars
    for (i = 0; i < size; i++) {
        starword[i] = '*';
    }

    // add null terminator
    starword[i] = '\0';

}

// playRound function
int playRound(char starword[], char answer[]) { // return 1 if win, 0 if lose // calls playAgain, maskWord & rules

    printf("\n************************************************************************\n");
    printf("Welcome to the Round!\n");
    printf("The size of the word has %lu letters.\n", strlen(answer));

    // declare variables
    int strikes = 0; // number of strikes
    int win = 2; // 0 is lose, 1 is win, 2 is continue
    char userguess; // user guess
    char lettersGuessed[26] = {'\0'};

    // play round
    do {

        // while use guess is not a letter a-z or A-Z (convert to lowercase)
        do {
            // display strikes
            printf("\nYou currently have %d strike(s).\n", strikes);
            // display letters guessed
            printf("Letter(s) you have guessed: %s\n\n", lettersGuessed);
            // display star word
            printf("%s\n\n", starword);
            // get user guess
            printf("Enter your guess: ");
            scanf(" %c", &userguess);
            // convert to lowercase
            userguess = tolower(userguess);
            // check if user guess is a letter
            if (!isalpha(userguess)) {
                printf("You did not guess a letter from the alphabet.\n");
            }
        } while (!isalpha(userguess));

        // check if user guess has already been guessed
        if (strchr(lettersGuessed, userguess) != NULL) {
            printf("You have already guessed that letter.\n");
        } else {
            // add user guess to letters guessed
            lettersGuessed[strlen(lettersGuessed)] = userguess;
            // check if user guess is in answer
            if (occurancesInWord(userguess, answer) == 0) { // if not in answer
                // check to see if it is users last strike
                if (strikes == MAX_GUESSES - 1) {
                    // set win to 0
                    win = 0;
                } else {
                    // append letter to end of letters guessed
                    printf("\nThe letter %c is not in the word.\n", userguess);
                    // increment strikes
                    strikes++;
                }
            } else { // if in answer
                // update star word
                updateStarWord(starword, answer, userguess);
                // check if user has won
                if (strcmp(starword, answer) == 0) {
                    // set win to 1
                    win = 1;
                } else {
                    printf("\nThe letter %c is in the word.\n", userguess);
                }
            }
        }

    } while (strikes < MAX_GUESSES && win == 2);

    return win;

}

// occurancesInWord function
int occurancesInWord(char userguess, char answer[]) { // return positive number of times letter occurs in the word, otherwise return 0

    // declare variables
    int i = 0; // loop counter
    int count = 0; // number of times letter occurs in word

    // loop through word
    for (i = 0; i < strlen(answer); i++) {
        if (userguess == answer[i]) {
            count++;
        }
    }

    // return number of times letter occurs in word
    return count;

}

// updateStarWord function
void updateStarWord(char starword[], char answer[], char userguess) {

    // declare variables
    int i = 0; // loop counter

    // loop through word
    for (i = 0; i < strlen(answer); i++) {
        if (userguess == answer[i]) {
            starword[i] = userguess;
        }
    }

}

// playAgain function
void playAgain(int *play) {

    // declare variables
    char userinput; // user input

    // ask user if to play again
    printf("************************************************************************\n");
    printf("Would you like to play another round?\n");
    printf("1: Yes\n");
    printf("2: No\n");
    printf("Choice: ");
    // get user input and make program wait for valid input
    do {
        scanf(" %c", &userinput);
    } while (userinput != '1' && userinput != '2');

    // set play to int casted user input
    *play = (int)userinput - 48;

}