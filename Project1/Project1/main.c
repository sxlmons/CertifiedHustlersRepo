#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "player.h"
#include "async.h"
#include "course.h"

#define TO_PERCENTAGE 10

//MATH TEST PROGRAM - Hackathon fall 2023 - Team 2 - Joshua-Harris-Garreth-Balyo

int main(void) 
{
	//call player struct
	PLAYER player;

	//call FileExists function, check if player.txt exists
	if (FileExists("player.txt"))
	{
		//call LoadPlayerData function, if none exist else:
		LoadPlayerData(&player);
	}
	else
	{
		//create new player struct
		player = CreateNewPlayer(1);

		//save to player.txt
		SavePlayerData(player);
	}
	
	//print UI for main, math course
	do
	{
		//"playtext" delays printing of each character, giving illusion of cpu typing
		PlayText("|--MATH COURSE--|", 0.1f);
		WaitForSeconds(0.5f);

		//print menu selection, print current saved highscore in a percentage for each course
		printf("|  1. Addition       |\tHighest Grade: %d%%\n", player.courses[0].highscore * TO_PERCENTAGE);
		printf("|  2. Subraction     |\tHighest Grade: %d%%\n", player.courses[1].highscore * TO_PERCENTAGE);
		printf("|  3. Multiplication |\tHighest Grade: %d%%\n", player.courses[2].highscore * TO_PERCENTAGE);

		//enetering 4 will quit program
		printf("|  4. Quit           |\n");
		
		//declare int "choice", for menu selection
		int choice;
		 
		//take user input, and store in "choice"
		scanf_s("%d", &choice);
		
		//take choice and implement in switch statement, depending on the integer of choice will select the case
		//if user enters a number not within range of 1-4, or is alphabetical, return reprompt user.
		switch (choice)
		{
		case 1:
			//call addition function, with "player" struct referenced
			printf("|--Addition--|\n");
			CourseOneMaterial(&player);
			break;
		case 2:
			//call subtraction function, with "player" struct referenced
			printf("|--Subraction--|\n");
			CourseTwoMaterial(&player);
			break;
		case 3:
			//call multiplication function, with "player" struct referenced
			printf("|--Multiplication--|\n");
			CourseThreeMaterial(&player);
			break;
		case 4:
			//if user selects "4" program will exit successfully 
			PlayText("Goodbye!", 0.1f);
			exit(EXIT_SUCCESS);
			break;
		//else, prompt user again
		default: 
			printf("Please select a valid menu selection.");
			break;
		}

		//save player data to "player.txt"
		SavePlayerData(player);

		//pause before reprinting menu
		WaitForSeconds(2);
		
		//clear console, with system function
		system("cls");
	} while (true);

	return 0;
}