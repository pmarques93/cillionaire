#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MSG_BYE "*** Sad to see you go..."
#define MSG_UNKNOWN "*** Unknown option..."

void pressKey(void);
void printMenu(void);
void printCredits(void);
void jokerBonus(void);

int main(int argc, char** argv)
{
	/*
	if(argc == 1)
	else if(argc == 2)
	*/

	printMenu();
	pressKey();
	return 0;
}

/* press key to call a function */
void pressKey()
{
	
	/* variables */
	char c;
	
	while (c != 'q')
	{
		// verifica se as jogadas passam do limite //
	
		scanf(" %c", &c);
		/////////////////////////
		if (c == 'h')
		{
			printMenu();
		}
		/////////////////////////
		else if (c == 'c')
		{
			printCredits();
		}
		/////////////////////////
		else if (c == 'j')
		{
			jokerBonus();
		}
		/////////////////////////
		else if (c == 'q')
		{
			puts(MSG_BYE);
			break;
		}
		/////////////////////////
		else
		{
			puts(MSG_UNKNOWN);
		}
	}
}

/* print the option menu */
void printMenu(void)
{
	puts("****************************************");
	puts("*** menu ***");
	puts("****************************************");
}

/* print credits menu */
void printCredits(void)
{
	puts("*** GAME CREATORS ***");
}

/* gives joker Bonus */
void jokerBonus(void)
{
	puts("*** JOKER BONUS ***");
}
