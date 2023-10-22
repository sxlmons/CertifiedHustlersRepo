#define _CRT_SECURE_NO_WARNINGS  
#include "player.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COURSE_COUNT 12

// A method that creates a new player object with the specified level
PLAYER CreateNewPlayer(int level)
{
	PLAYER p;
	p.level = level;
	for (int i = 0; i < 3; i++) 
	{
		p.courses[i].highscore = 0;
	}
	return p;
}

// A method that adds one level to the specified player object
void AddLevelToPlayer(PLAYER* player)
{
	player->level++;
}

// A method that saves the specified player data into a file called "player.txt"
void SavePlayerData(PLAYER player)
{
	FILE* fp = fopen("player.txt", "w");
	
	int i = COURSE_COUNT - 1;
	fprintf(fp, "%d\n%d\n%d",
		player.courses[i--].highscore,
		player.courses[i--].highscore,
		player.courses[i--].highscore);

	fclose(fp);
}

// A safe method that loads player data from the file "player.txt" and outputs it
bool LoadPlayerData(PLAYER* player) {
	if (player == NULL)
	{
		return false;
	}
	
	FILE* fp = fopen("player.txt", "r");
	if (fp == NULL)
	{
		return false;
	}
	char highscoreString[COURSE_COUNT];
	int i = 0;

	while (fgets(highscoreString, COURSE_COUNT, fp) != NULL)
	{
		int score = atoi(highscoreString); 
		if (score < 0)
		{
			score = 0; 
		}
		player->courses[i++].highscore = score;
	}

	fclose(fp);
	return true;
}

// A method to check if the specified file exists
bool FileExists(const char* filename)
{
	FILE* fp = fopen(filename, "r");
	bool is_exist = false;
	if (fp != NULL)
	{
		is_exist = true;
		fclose(fp);
	}
	return is_exist;
}