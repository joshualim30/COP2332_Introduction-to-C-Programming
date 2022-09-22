//Name: 
//Dr. Steinberg
//COP3223C 
//Large Program 1 Skeleton

#define ROUNDS 3
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

//void greeting(); //display welcome message to user
int playRound(int round); //play one round
//int humanPick(); //retrieve the user's guess
//int computerPick(int choice, int leftover); //computer makes its pick
//int leftOnTable(int toothpicks, int taken); //calculate number of toothpicks left
//void winnerAnnouncment(int user); //overall winner of round announcement

int main()
{
	//insert some code here that will greet the user
	
	for(int x = 0; x < ROUNDS; ++x)
	{
		int result = playRound(x + 1); //call playRound and assign result the value function returns
		
		//insert some code here that will determine the winner
	}
	
	printf("********************************************************\n");
	printf("Thank you for playing!\n");
	return 0;
}

int playRound(int round)
{
	printf("Welcome to a new round %d!\n", round);
	printf("You may go first!\n");
	
	int toothpicks = 31; //number of toothpicks to start with
	
	//you can insert code here
	
	//loop that keeps track of toothpicks until respective no more toothpicks left. we will learn about conditional loops soon :)
	
	while(toothpicks != 0)
	{
		//insert code here that simulate the round properly based on assignment directions
		
		return 0; //terminates loop HOWEVER YOU WILL NEED TO CHANGE THIS WHEN BUILDING YOUR PROGRAM. THIS WAS PUT IN THE SKELETON SO THAT THE INITIAL RUN ISN'T STUCK IN AN INFINITE LOOP
	}
	
	return 0; //returns 0 HOWEVER YOU WILL NEED TO CHANGE THIS PART OF THE CODE TO MAKE THE PROGRAM WORK PROPERLY! YOU DON'T WANT THE SAME VALUE RETURNED ALWAYS
}