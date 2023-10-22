#include <stdio.h>
#include <windows.h>
#include <string.h>

#define SECONDS_TO_MILLISECONDS 1000

// A method that pauses the entire program for 'x' amount of seconds
void WaitForSeconds(float seconds)
{
	//fflush(stdout);
	Sleep(seconds * SECONDS_TO_MILLISECONDS);
}

// A method that prints incrementing text
void PlayText(char text[], float timeBetweenChars)
{
	int count = 0;
	while (count < strlen(text))
	{
		printf("%c", text[count]);
		count++;
		WaitForSeconds(timeBetweenChars);
	}

	printf("\n");
}