// Joshua Lim
// Dr. Steinberg
// COP3223C Section 4
// Large Program 1

#define ROUNDS 3
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void greeting(); // display welcome message to user
int playRound(int round); // play one round
int humanPick(); // retrieve the user's pick
int computerPick(int choice, int leftover); // computer makes its pick
int leftOnTable(int toothpicks, int taken); // calculate number of toothpicks left
void winnerAnnouncement(int user); // overall winner of round announcement

int main() {

    // greet the user
    greeting();

	for(int x = 0; x < ROUNDS; ++x) {

		int result = playRound(x + 1); // call playRound and assign result the value function returns
		
		// some code here that will determine the winner
        winnerAnnouncement(result);

	}
	
	printf("********************************************************\n");
	printf("Thank you for playing!\n");
	return 0;

}

// greets user at beginning of game
void greeting() {
    
    printf("********************************************************\n");
    printf("Welcome to Toothpick Game!\n");
    printf("Here are the rules.\n");
    printf("There are currently 31 toothpicks on the table.\n");
    printf("You and I will each get a turn to pick either 1, 2, or 3 toothpicks off the table.\n");
    printf("The player that gets to pick the last toothpicks loses the game.\n");
    printf("Sounds easy right? Well let's see if you can beat me!\n");
    printf("Ready to play?...Here we go!\n");
    printf("********************************************************\n");

}

// play round loops until all toothpicks are gone, as well as processes which round it is
int playRound(int round) {
    
    printf("Welcome to round %d!\n", round);
	printf("You may go first!\n");
	printf("********************************************************\n");
	int toothpicks = 31; // number of toothpicks to start with
	
	while(toothpicks != 0) // loop that keeps track of toothpicks until respective no more toothpicks left. we will learn about conditional loops soon :)
	{
		// insert code here that simulate the round properly based on assignment directions
		printf("There are %d toothpick(s) left on the table.\n", toothpicks);
        printf("How many toothpicks are you going to take off the table? ");
        int humanChoice = humanPick();
        if (humanChoice == 0) {
            
            printf("********************************************************\n"); // because user inputted invalid number, let loop pass through

        } else if (humanChoice == toothpicks) {

            // lose game
            printf("Ok... you took %d off the table.\n", humanChoice);
            return 0; // return 0 and breaks loop if computer wins

        } else {

            // chose less than what is left, valid choice
            toothpicks = leftOnTable(toothpicks, humanChoice);
            printf("Ok... you took %d off the table.\n", humanChoice);
            int computerChoice = computerPick(humanChoice, toothpicks);
            toothpicks = leftOnTable(toothpicks, computerChoice);

        }

        // don't need line once program is finished
		// return 0; //terminates loop HOWEVER YOU WILL NEED TO CHANGE THIS WHEN BUILDING YOUR PROGRAM. THIS WAS PUT IN THE SKELETON SO THAT THE INITIAL RUN ISN'T STUCK IN AN INFINITE LOOP
	
    }

    return 1; // returns 1 if user wins
	// return 0; //returns 0 HOWEVER YOU WILL NEED TO CHANGE THIS PART OF THE CODE TO MAKE THE PROGRAM WORK PROPERLY! YOU DON'T WANT THE SAME VALUE RETURNED ALWAYS

}

// retrieve the user's pick
int humanPick() {

    int pick;
    scanf("%d", &pick);
    if (pick < 1 || pick > 3) {

        printf("Oh no no, you can't do that in this game! Try again.\n");
        printf("********************************************************\n");
        return 0; // returns 0 if invalid number

    } else {

        return pick;

    }

}

// computer logic to make strategic pick based on user's pick
int computerPick(int choice, int leftover) {

    printf("I'm making my decision now.\n");
    int pick;
    if (leftover > 4) {
        
        pick = 4 - choice;
        printf("I am taking %d toothpick(s) off the table.\n", pick);
        printf("********************************************************\n");
        printf("********************************************************\n");

    } else if (leftover >= 2 && leftover <=4) {

        pick = leftover - 1;
        printf("I am taking %d toothpick(s) off the table.\n", pick);
        printf("********************************************************\n");
        printf("********************************************************\n");

    } else if (leftover == 1) {

        pick = 1;
        printf("I am taking %d toothpick(s) off the table.\n", pick);

    }
    return pick;

}

// subtract 1, 2, or 3 from toothpicks from the table
int leftOnTable(int toothpicks, int taken) {

    return toothpicks - taken;

}

// process the winner of the round
void winnerAnnouncement(int user) {

    if (user == 0) {
        printf("I won! Haha better luck next time!\n");
    } else {
        printf("You won! I'll let you have this one.\n");
    }

}