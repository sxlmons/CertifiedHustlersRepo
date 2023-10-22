#pragma once
#include "player.h"
#include <string.h>

typedef struct question {
	char question[99];
	int answer;
} QUESTION;

QUESTION CreateQuestion(char question[], int answer);
void CourseOneMaterial(PLAYER* player);
void CourseTwoMaterial(PLAYER* player);
void CourseThreeMaterial(PLAYER* player);