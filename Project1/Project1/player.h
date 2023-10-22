#pragma once
#include <stdbool.h>

#define COURSE_COUNT 3

typedef struct playerCourseData
{
	int highscore;
	
} PLAYERCOURSEDATA;

typedef struct player
{
	int level;
	PLAYERCOURSEDATA courses[COURSE_COUNT];
} PLAYER;

PLAYER CreateNewPlayer(int level);
void AddLevelToPlayer(PLAYER* player); 
void SavePlayerData(PLAYER player);
bool LoadPlayerData(PLAYER* player);
bool FileExists(const char* filename);