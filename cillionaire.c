#include "cillionaire.h"
#include "classes.h"
#include "readFile.h"
#include "game.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void keyPress(char * file_name)
{
   
   node* head;
	char line [100];
	char aux_nome [100] = "newbie";
	char aux_2;

   while (line[0] != 'q')
   {
      
      fgets(line, 100, stdin);
      switch(line [0])
      {
         case 'n' :  // n, starts game

            head = readFile(file_name);
            sscanf(line,"%c%s", &aux_2, aux_nome);
            printf("*** Hi %s, let's get started!\n", aux_nome);
            printScore(aux_nome);
            game(head, aux_nome);   
            break;

         case 'h' :
            printMenu();
            break;

         case 'c' :
            printCredits();
            break;

         case 'q' :
            // q, quits the program
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
   int seed;
   char * file_name;
   int i;
   if (argc == 3)
   {
      
      char new_str1 = strcmp(argv[1],"-s");
      char new_str2 = strcmp(argv[1],"-f");
      
      if (new_str1 == 0 )
      {
         seed = *argv[2];
      }

      else if (new_str2 == 0)
      {
         seed = time(0);
         int str_len = strlen(argv[2]);
         file_name = malloc(str_len);
         for (i=2; i<3; i++) 
         {
            strcat(file_name, argv[i]);
            if (3 > i+1)
               strcat(file_name, " ");
         }
      }
   }
   else if (argc == 5)
   {
      char new_str1 = strcmp(argv[1],"-s");
      char new_str2 = strcmp(argv[1],"-f");
      char new_str4 = strcmp(argv[3],"-f");
      if (new_str1 == 0)
      {
         seed = *argv[2];

         if(new_str4 == 0)
         {
            int str_len = strlen(argv[4]);
            file_name = malloc(str_len);
            for (i=4; i<5; i++) 
            {
               strcat(file_name, argv[i]);
               if (5 > i+1)
                  strcat(file_name, " ");
            }

         }

      }

      else if (new_str2 == 0)
      {
         seed = *argv[4];

         int str_len = strlen(argv[2]);
         file_name = malloc(str_len);
         for (i=2; i<3; i++) 
         {
            strcat(file_name, argv[i]);
            if (3 > i+1)
               strcat(file_name, " ");
         }
      }
   }

   srand(seed);
	printMenu();
	keyPress(file_name);
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
   printf(">");
}

void printScore(char *aux_nome)
{
   printf("********************************************\n");
   printf("*** Name:  %-32s*\n", aux_nome);
   printf("*** Level: %-32s*\n", "0");
   printf("*** j50:   %-32s*\n", "YES");
   printf("*** j25:   %-32s*\n", "YES");
   printf("********************************************\n");
}






