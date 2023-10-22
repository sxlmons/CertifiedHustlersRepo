#define _CRT_SECURE_NO_WARNINGS
#include "course.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "async.h"
#include "player.h"

#define QUESTION_COUNT 10
#define QUESTION_MESSAGE_LENGTH 99
#define MAX_NUMBER 10

/*
 * Course IDs:
 * 0 = Addition
 * 1 = Subtraction
 * 2 = Multiplication
*/

// A method that creates a question with the specified question prompt and answer
QUESTION CreateQuestion(char question[], int answer)
{
	QUESTION q;
	strncpy(q.question, question, QUESTION_MESSAGE_LENGTH);
	q.answer = answer;
	return q;
}

// Method that runs course 1 (Addition)
void CourseOneMaterial(PLAYER* player)
{
    // seed the random number generator 
    srand(time(0));

	// Generate random questions and answers
    QUESTION quests[QUESTION_COUNT];
    for (int i = 0; i < QUESTION_COUNT; i++)
	{
        int a = rand() % MAX_NUMBER;
        int b = rand() % MAX_NUMBER;
        char message[QUESTION_MESSAGE_LENGTH];
        sprintf(message, "What is %d + %d?\n", a, b);
        quests[i] = CreateQuestion(message, a + b); 
    }

	// I don't know exactly what this does but it makes scanf work in a loop so it's here
	while (getchar() != '\n');

	// Loop through each question and let the user answer them
    int answeredCorrectly = 0;
    for (int i = 0; i < QUESTION_COUNT; i++)
	{
        printf("%s", quests[i].question);

        int input;
        scanf_s("%d", &input); 
		while (getchar() != '\n');

        if (input == quests[i].answer)
		{
            printf("You answered correctly!\n\n");
            answeredCorrectly++;
        }
		else
		{
            printf("You answered incorrectly!\n\n");
             
        }
     
        WaitForSeconds(0.5f);
    }
    
    printf("You answered %d/%d correctly!\n", answeredCorrectly, QUESTION_COUNT);

	// Check and assign the player's score if it's a highscore
	if (player->courses[0].highscore < answeredCorrectly)
	{ 
		player->courses[0].highscore = answeredCorrectly; 
	}
}

// Method for course 2 (Subtraction)
void CourseTwoMaterial(PLAYER* player)
{
	// seed the random number generator 
	srand(time(0));

	// Generate questions and answers
	QUESTION quests[QUESTION_COUNT];
	for (int i = 0; i < QUESTION_COUNT; i++)
	{
		int a = rand() % MAX_NUMBER;
		int b = rand() % MAX_NUMBER;
		char message[QUESTION_MESSAGE_LENGTH];
		sprintf(message, "What is %d - %d?\n", a, b);
		quests[i] = CreateQuestion(message, a - b);
	}

	while (getchar() != '\n');

	// Loop through each question and let the user answer them
	int answeredCorrectly = 0;
	for (int i = 0; i < QUESTION_COUNT; i++)
	{
		printf("%s", quests[i].question);

		int input;
		scanf_s("%d", &input);
		while (getchar() != '\n');

		if (input == quests[i].answer)
		{
			printf("You answered correctly!\n\n");
			answeredCorrectly++;
		}
		else {
			printf("You answered incorrectly!\n\n");

		}

		WaitForSeconds(0.5f);
	}

	printf("You answered %d/%d correctly!\n", answeredCorrectly, QUESTION_COUNT);
	if (player->courses[1].highscore < answeredCorrectly)
	{
		player->courses[1].highscore = answeredCorrectly;
	}
}

void CourseThreeMaterial(PLAYER* player)
{
	// seed the random number generator 
	srand(time(0));

	// Generate all the questions and answers
	QUESTION quests[QUESTION_COUNT];
	for (int i = 0; i < QUESTION_COUNT; i++)
	{
		int a = rand() % MAX_NUMBER;
		int b = rand() % MAX_NUMBER;
		char message[QUESTION_MESSAGE_LENGTH];
		sprintf(message, "What is %d x %d?\n", a, b);
		quests[i] = CreateQuestion(message, a * b);
	}

	while (getchar() != '\n');

	// Let the user answer the questions
	int answeredCorrectly = 0;
	for (int i = 0; i < QUESTION_COUNT; i++)
	{
		printf("%s", quests[i].question);

		int input;
		scanf_s("%d", &input);
		while (getchar() != '\n');

		if (input == quests[i].answer) {
			printf("You answered correctly!\n\n");
			answeredCorrectly++;
		}
		else {
			printf("You answered incorrectly!\n\n");

		}

		WaitForSeconds(0.5f);
	}

	printf("You answered %d/%d correctly!\n", answeredCorrectly, QUESTION_COUNT);

	if (player->courses[2].highscore < answeredCorrectly)
	{
		player->courses[2].highscore = answeredCorrectly;
	}
}