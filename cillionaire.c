#include "cillionaire.h"
#include "classes.h"
#include "readFile.h"
#include "game.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>







void keyPress(int *seed)
{
   
   char *file_name[100];
   node* head;
	head = readFile(file_name[100]);
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
            game(head, aux_nome, seed);
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
   int seed = 0;
   char file_name[100];
	if (argc < 1)
	{
    
	   seed = atoi(argv[1]);
	}
   else if (argc == 3)
   {
      
      char new_str1 = strcmp(argv[1],"-s");
      char new_str2 = strcmp(argv[1],"-f");
      if (new_str1 == 0)
      {
         seed = *argv[2];
      }
      if (new_str2 == 0)
      {
         strcpy(file_name,argv[2]);
         puts(file_name);
      }





   }
	else
	{
		seed = time(NULL);
	}

	printMenu();

	keyPress(&seed);
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

void printScore(char *aux_nome)
{
   printf("********************************************\n");
   printf("*** Name:  %-32s*\n", aux_nome);
   printf("*** Level: %-32s*\n", "temporario lvl");
   printf("*** j50:   %-32s*\n", "temporario joker 50");
   printf("*** j25:   %-32s*\n", "temporario joker 25");
   printf("********************************************\n");
}






