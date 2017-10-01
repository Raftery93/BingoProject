/*
Title: Bingo Project
Name: Conor Raftery
Student No.: G00274094
Aim: Create a bingo programme using the C language, which creates a random player card, which calls random numbers and compares
them to the players card. The programme should be able to save a game, and load a previous game. 
It should also be able to output the current games status.
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <time.h>
main(void) {

	//Gives me different random numbers every time program is ran
	srand(time(NULL));

	//Declare Variables
	int bingo[3][9];
	int bingoNumber[99];
	int row;
	int col;
	int num = 0;
	int noOfPlayers = 0;
	int i = 0;
	int j = 0;
	int starterOption = 0;
	int option = 0;
	int counter = 0;
	int fileBingo;
	int calledNumbers = 0;

	//Declares file pointer
	FILE* filep;
	//---------------------------------------------------------------//

	//Prompt for option
	printf("Please Select Option:\n 1) Start New Game\n "
		"2) Load Previous Game\n");
	scanf("%d", &option);
	//---------------------------------------------------------------//

	//Option 1 - Start new game
	if (option == 1) {

		//Request number of players - only works with 1 player
		printf("\nPlease Enter Number of Players: ");
		scanf("%d", &noOfPlayers);

		for (i = 0; i < noOfPlayers; i++) {
			//Code for extra players
			//Should have created 3D array - bingo[i][j][k];
		}

		printf("\nPlayer %d Bingo Card: \n", i);

		//Place random number for each index
		bingo[0][0] = (rand() % 10) + 1;//Top left corner
		bingo[0][1] = (rand() % 10) + 11;
		bingo[0][2] = (rand() % 10) + 21;
		bingo[0][3] = (rand() % 10) + 31;
		bingo[0][4] = (rand() % 10) + 41;
		bingo[0][5] = (rand() % 10) + 51;
		bingo[0][6] = (rand() % 10) + 61;
		bingo[0][7] = (rand() % 10) + 71;
		bingo[0][8] = (rand() % 10) + 81;//Bottom left corner
		bingo[1][0] = (rand() % 10) + 1;
		bingo[1][1] = (rand() % 10) + 11;
		bingo[1][2] = (rand() % 10) + 21;
		bingo[1][3] = (rand() % 10) + 31;
		bingo[1][4] = (rand() % 10) + 41;
		bingo[1][5] = (rand() % 10) + 51;
		bingo[1][6] = (rand() % 10) + 61;
		bingo[1][7] = (rand() % 10) + 71;
		bingo[1][8] = (rand() % 10) + 81;
		bingo[2][0] = (rand() % 10) + 1;//Top right corner
		bingo[2][1] = (rand() % 10) + 11;
		bingo[2][2] = (rand() % 10) + 21;
		bingo[2][3] = (rand() % 10) + 31;
		bingo[2][4] = (rand() % 10) + 41;
		bingo[2][5] = (rand() % 10) + 51;
		bingo[2][6] = (rand() % 10) + 61;
		bingo[2][7] = (rand() % 10) + 71;
		bingo[2][8] = (rand() % 10) + 81;//Bottom right corner

		//Output bingoCard array
		for (row = 0; row < 3; row++)
		{
			for (col = 0; col < 9; col++)
			{
				printf("%d\t", bingo[row][col]);
			}
			printf("\n");
		}


		//While loop for exiting programme
		while (option != 4) {

			//2nd option list
			printf("\nPlease Select an option:\n "
				"1) Draw Number\n"
				"2) Save Game\n"
				"3) Output current games status\n"
				"4) Exit Program\n");
			scanf("%d", &option);

//___________________________________________________________________________________________//
			//option 1 - draw number
			if (option == 1) {
				bingoNumber[j] = (rand() % 90) + 1; //Draws random number between 1-90
				printf("\nBingo Number: %d \n", bingoNumber[j]); //Outputs number drawn
				counter++; //Counter for ammount of drawn numbers
				j++;//Counter for BingoNumber

				i = 0;
				//Loops through each completed iteration
				while (i < counter) {

					//Compares numbers drawn with numbers in card
					if (bingoNumber[i] == bingo[0][0] || bingoNumber[i] == bingo[0][1] || bingoNumber[i] == bingo[0][2] || bingoNumber[i] == bingo[0][3] || bingoNumber[i] == bingo[0][4] || bingoNumber[i] == bingo[0][5] || bingoNumber[i] == bingo[0][6] || bingoNumber[i] == bingo[0][7] || bingoNumber[i] == bingo[0][8]
						|| bingoNumber[i] == bingo[1][0] || bingoNumber[i] == bingo[1][1] || bingoNumber[i] == bingo[1][2] || bingoNumber[i] == bingo[1][3] || bingoNumber[i] == bingo[1][4] || bingoNumber[i] == bingo[1][5] || bingoNumber[i] == bingo[1][6] || bingoNumber[i] == bingo[1][7] || bingoNumber[i] == bingo[1][8]
						|| bingoNumber[i] == bingo[2][0] || bingoNumber[i] == bingo[2][1] || bingoNumber[i] == bingo[2][2] || bingoNumber[i] == bingo[2][3] || bingoNumber[i] == bingo[2][4] || bingoNumber[i] == bingo[2][5] || bingoNumber[i] == bingo[2][6] || bingoNumber[i] == bingo[2][7] || bingoNumber[i] == bingo[2][8]) {
						printf("\nBingo Number %d marked on card\n", bingoNumber[i]);// if number in card has been found, output to screen
					}
					else {
						printf("\nNumber %d not marked on card\n", bingoNumber[i]);//if number has not been found, output to screen
					}
					i++;
				}//while
			}//option1

//___________________________________________________________________________________________//
			//Option2 - To save game
			if (option == 2) {
				printf("\nGame Saved! See 'Bingo.txt'\n");

				//Outputs total of drawn numbers
				printf("\nThe total of numbers drawn are %d,\n Please take note of this if you wish to load the game!\n", counter);

				//Create/open file
				filep = fopen("Bingo.txt", "w");

				//Output bingoCard to file
				for (row = 0; row < 3; row++)
				{
					for (col = 0; col < 9; col++)
					{
						fprintf(filep, "%d\t", bingo[row][col]);
					}
					fprintf(filep, "\n");
				}
				for (i = 0; i < counter; i++) {
					fprintf(filep, "%d \n", bingoNumber[i]);
				}
				//close file
				fclose(filep);
			}//Option2

//___________________________________________________________________________________________//
			//Option3 - Outputs numbers that have been drawn
			if (option == 3) {
				printf("\nNumbers Drawn: \n");
				//loops through every number which has been drawn and outputs
				for (i = 0; i < counter; i++) {
					printf("%d \n", bingoNumber[i]);
				}
			}//Option 3
		}//end while
	}//End starter option 1
//========================================================================================================//

	else if (option == 2) {

		//Prompt user for count for 1D array
		printf("\nPlease enter the amount of numbers called in previous game: \n");
		scanf("%d", &calledNumbers);

		//opens file for reading
		filep = fopen("Bingo.txt", "r");

		//first if reads unil file is null via while loop
		if (filep != NULL) {
			while (!feof(filep)) {

				//reads file data into variables
				for (row = 0; row < 3; row++) {
					for (col = 0; col < 9; col++) {
						fileBingo = fscanf(filep, "%d", &bingo[row][col]);
					}
				}

				for (i = 0; i < calledNumbers; i++) {
					fileBingo = fscanf(filep, "%d", &bingoNumber[i]);
				}

				printf("\nGame Loaded!\n");
				//when reaches end of file, outputs to screen
				if (fileBingo > 0) {
					printf("\nBingo Card: \n");
					for (row = 0; row < 3; row++) {
						for (col = 0; col < 9; col++) {
							printf("%d\t", bingo[row][col]);
						}
						printf("\n");
					}

					for (i = 0; i < calledNumbers; i++) {
						fileBingo = printf("%d\n", bingoNumber[i]);
					}
				}

			}//while

			 //close file
			fclose(filep);
		}//first if

		 //if file is empty, print out file is empty to screen
		else
		{
			printf("File is empty\n");
		}

		//close file
		fclose(filep);
//----------------------------------------------------------------------//

		while (option != 4) {
			printf("\nPlease Select an option:\n "
				"1) Draw Number\n"
				"2) Save Game\n"
				"3) Output current games status\n"
				"4) Exit Program\n");
			scanf("%d", &option);

//___________________________________________________________________________________________//
			//option 1 - draw number
			if (option == 1) {
				bingoNumber[j] = (rand() % 90) + 1; //Draws random number between 1-90
				printf("\nBingo Number: %d \n", bingoNumber[j]); //Outputs number drawn
				counter++; //Counter for ammount of drawn numbers
				j++;//Counter for BingoNumber

				i = 0;
				//Loops through each completed iteration
				while (i < counter) {

					//Compares numbers drawn with numbers in card
					if (bingoNumber[i] == bingo[0][0] || bingoNumber[i] == bingo[0][1] || bingoNumber[i] == bingo[0][2] || bingoNumber[i] == bingo[0][3] || bingoNumber[i] == bingo[0][4] || bingoNumber[i] == bingo[0][5] || bingoNumber[i] == bingo[0][6] || bingoNumber[i] == bingo[0][7] || bingoNumber[i] == bingo[0][8]
						|| bingoNumber[i] == bingo[1][0] || bingoNumber[i] == bingo[1][1] || bingoNumber[i] == bingo[1][2] || bingoNumber[i] == bingo[1][3] || bingoNumber[i] == bingo[1][4] || bingoNumber[i] == bingo[1][5] || bingoNumber[i] == bingo[1][6] || bingoNumber[i] == bingo[1][7] || bingoNumber[i] == bingo[1][8]
						|| bingoNumber[i] == bingo[2][0] || bingoNumber[i] == bingo[2][1] || bingoNumber[i] == bingo[2][2] || bingoNumber[i] == bingo[2][3] || bingoNumber[i] == bingo[2][4] || bingoNumber[i] == bingo[2][5] || bingoNumber[i] == bingo[2][6] || bingoNumber[i] == bingo[2][7] || bingoNumber[i] == bingo[2][8]) {
						printf("\nBingo Number %d marked on card\n", bingoNumber[i]);// if number in card has been found, output to screen
					}
					else {
						printf("\nNumber %d not marked on card\n", bingoNumber[i]);//if number has not been found, output to screen
					}
					i++;
				}//while
			}//option1

//___________________________________________________________________________________________//
			 //Option2 - To save game
			if (option == 2) {
				printf("Game Saved! See 'Bingo.txt'");

				//Outputs total of drawn numbers
				printf("\nThe total of numbers drawn are %d,\n Please take note of this if you wish to load the game!\n", counter);

				//Create/open file
				filep = fopen("Bingo.txt", "w");

				//Output bingoCard to file
				for (row = 0; row < 3; row++)
				{
					for (col = 0; col < 9; col++)
					{
						fprintf(filep, "%d\t", bingo[row][col]);
					}
					fprintf(filep, "\n");
				}
				for (i = 0; i < counter; i++) {
					fprintf(filep, "%d \n", bingoNumber[i]);
				}
				//close file
				fclose(filep);
			}//Option2

//___________________________________________________________________________________________//
			 //Option3 - Outputs numbers that have been drawn
			if (option == 3) {
				printf("\nNumbers Drawn: \n");
				//loops through every number which has been drawn and outputs
				for (i = 0; i < counter; i++) {
					printf("%d \n", bingoNumber[i]);
				}
			}//Option 3
		}//First while
	}//End Starter option 2
	getch();
}//end main