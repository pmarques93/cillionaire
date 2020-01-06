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
		
		else if (c == 'n')
		{
			takeName();
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
	puts("********************************************");
	puts("***            CILLIONAIRE                 *");
	puts("********************************************");
	puts("*** n <name>     - new game                *");
	puts("*** q            - quit                    *");
	puts("*** h            - show this menu          *");
	puts("*** r <filename> - resume game             *");
	puts("*** s <filename> - save progress and quit  *");
	puts("*** j 50         - play 50:50 joker        *");
	puts("*** j 25         - play 25:75 joker        *");
	puts("*** c            - show credits            *");
	puts("********************************************");

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


/* Takes name from player else assigns name 'Newbie' */
void takeName(char argc)
{
	if (argc < 1);
		char name = 'Newbie';


}