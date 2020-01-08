#include "keyPress.h"

void pressKey(void);
void printMenu(void);
void printCredits(void);
void jokerBonus(void);

node* readFile();
void game(node*, char*);
int seed;

int main(int argc, char** argv)
{	

	if (argc > 1)
	{
		seed = atoi(argv[1]);
	}
	else
	{
		seed = time(NULL);
	}

	printMenu();

	keyPress();
   return 0;	
}









