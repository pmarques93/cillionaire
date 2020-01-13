#include "cillionaire.h"
#include "classes.h"
#include "readFile.h"
#include "game.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int seed;




void keyPress()
{
   node* head;
	head = readFile();
	char line [100];
	char aux_nome [100] = "newbie";
	char aux_2;


   while (line[0] != 'q')
   {
      fgets(line, 100, stdin);
      switch(line [0])
      {
         case 'n' :  // n, starts game
            sscanf(line,"%c%s", &aux_2, aux_nome);
            printf("*** Hi %s, let's get started!\n", aux_nome);
            game(head, aux_nome);
            break;

         case 'h' :
            printMenu();
            break;

         case 'c' :
            printCredits();
            break;

         case 'q' :  // q, quits the program
            break;

         case '\n' :
            break;
         

         default: // if none of the cases above, print unknown option
            puts(MSG_UNKNOWN);
      }
   }
   puts(MSG_BYE);
}


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








void printCredits(void)
{
   puts("*********************");
	puts("*** GAME CREATORS ***");
   puts("***   MR. Green   ***");
   puts("***  Jund Master  ***");
   puts("***    Pedro M    ***");
   puts("*********************");
}




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








