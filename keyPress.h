#include "readFile.h"
#include "printMenu.h"
#include "printCredits.h"
#define MSG_BYE "*** Sad to see you go..."
#define MSG_UNKNOWN "*** Unknown option..."


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