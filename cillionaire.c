#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MSG_BYE "*** Sad to see you go..."
#define MSG_UNKNOWN "*** Unknown option..."

void pressKey(void);
void printMenu(void);
void printCredits(void);
void jokerBonus(void);




typedef struct _node {
   char text[128];
   char answer[4][128];
   enum {easy, medium, hard} difficulty;
   struct _node * next;
   } node;

   node* readFile(void);
   void game(node*);

   int seed;

int main(int argc, char** argv)
{	
	
	node* head;
	head = readFile();
	char nome[100] = "newbie";
	char line [100];
	char aux_nome [100];
	char aux_2;
   
	if (argc > 1)
   

	{
		seed = atoi(argv[1]);
	}
	else
	{
      
		seed = time(NULL);
	}

	printMenu();
	fgets(line, 100, stdin);
	
	switch(line [0])
	{
		case 'n' :
			if (sscanf(line,"%c%s", &aux_2, aux_nome) == 2)
				{
					strcpy(nome, aux_nome);
					
				}
			
			printf("*** Hi %s, let's get started!\n", nome);
			game(head);
         break;

			
			
	}
   return 0;	
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





node* readFile()
{  
   
   
   char line[512];
   node * head = NULL;
   node * tail = NULL;
   node * new;
   
   
   
   FILE *in_file;
   in_file = fopen("questions.txt", "r");
   
   
   if (in_file == NULL)
   {
      puts("*** Error opening file");
      exit(0);
   }
   while(fgets(line, 512, in_file) != NULL) // ler QUESTION=...
   {
      if (line[0] == ';')
         continue;

      new = (node *) malloc(sizeof(node));
      new->next = NULL;

      strcpy(new->text, &line[9]);

      fgets(line, 512, in_file); // ler OPTION0
      strcpy(new->answer[0], &line[8]);

      fgets(line, 512, in_file); // ler OPTION1
      strcpy(new->answer[1], &line[8]);

      fgets(line, 512, in_file); // ler OPTION2
      strcpy(new->answer[2], &line[8]);

      fgets(line, 512, in_file); // ler OPTION3
      strcpy(new->answer[3], &line[8]);

      fgets(line, 512, in_file); // ler CATEGORY

      fgets(line, 512, in_file); // ler DIFFICULTY
      if (strcmp(line, "DIFFICULTY=easy\n")== 0)
         new->difficulty = easy;
      else if(strcmp(line, "DIFFICULTY=medium\n") == 1)
         new->difficulty = medium;
      else
        new->difficulty = hard;


      if (head == NULL)
      {
         head = new;
      }

      if (tail != NULL)
      {
         tail->next = new;
      }
      tail = new;

   }
   fclose(in_file);
   return head;
}

void game(node*head)
{	
   node * aux;
	char player_choice;
	char Option_List[4] = {'A','B','C','D'};
   int i = 0;
   srand(time(0));
   int r = rand() % 4;
	for (aux = head; aux != NULL; aux = aux -> next, i++)
   {  
      
      if(aux->difficulty == 0)         
      {
         if (r == 0)
         {  
            
            printf("*** Question: %s",aux->text);
            printf("*** %c: %s",Option_List[0],aux->answer[0]);
            printf("*** %c: %s",Option_List[1],aux->answer[1]);
            printf("*** %c: %s",Option_List[2],aux->answer[2]);
            printf("*** %c: %s",Option_List[3],aux->answer[3]);
            
            break;
         }

         else if (r == 1)
         {
            
            printf("*** Question: %s",aux->text);
            printf("*** %c: %s",Option_List[0],aux->answer[1]);
            printf("*** %c: %s",Option_List[1],aux->answer[0]);
            printf("*** %c: %s",Option_List[2],aux->answer[2]);
            printf("*** %c: %s",Option_List[3],aux->answer[3]);
            break;
         }

         else if (r == 2)
         {
            puts("not");
            printf("*** Question: %s",aux->text);
            printf("*** %c: %s",Option_List[0],aux->answer[1]);
            printf("*** %c: %s",Option_List[1],aux->answer[2]);
            printf("*** %c: %s",Option_List[2],aux->answer[0]);
            printf("*** %c: %s",Option_List[3],aux->answer[3]);
            break;
         }

         else
         {
            puts("working");
            printf("*** Question: %s",aux->text);
            printf("*** %c: %s",Option_List[0],aux->answer[1]);
            printf("*** %c: %s",Option_List[1],aux->answer[2]);
            printf("*** %c: %s",Option_List[2],aux->answer[3]);
            printf("*** %c: %s",Option_List[3],aux->answer[0]);
            
            break;
         }
      
      }
   }  
   
   player_choice = getc(stdin);
   if (r == 0)
   {
      if(toupper(player_choice) == Option_List[0])
		   puts("*** Hooray!");
         else
      {
         puts("*** Woops... That's not correct.");
         printf("*** The correct answer was %c: %s", Option_List[0],aux->answer[0]);
      }
   }
   
   else if (r == 1)
   {
      if(toupper(player_choice) == Option_List[1])
		   puts("*** Hooray!");
      else
      {
         puts("*** Woops... That's not correct.");
         printf("*** The correct answer was %c: %s", Option_List[1],aux->answer[0]);
      }
   }

   else if (r == 2)
   {
      if(toupper(player_choice) == Option_List[2])
		   puts("*** Hooray!");
      else
      {
         puts("*** Woops... That's not correct.");
         printf("*** The correct answer was %c: %s", Option_List[2],aux->answer[0]);
      }
   }

   else if (r == 3)
   {
      if(toupper(player_choice) == Option_List[3])
		   puts("*** Hooray!");
      else
      {
         puts("*** Woops... That's not correct.");
         printf("*** The correct answer was %c: %s", Option_List[3],aux->answer[0]);

         
      }
         
   }
}




