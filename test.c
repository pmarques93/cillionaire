#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>


typedef struct _node {
   char text[128];
   char answer[4][128];
   enum {easy, medium, hard} difficulty;
   struct _node * next;
} node;

int main()
{
   char Option_List[4] = {'A','B','C','D'};
   char line[512];
   node * head = NULL;
   node * tail = NULL;
   node * new;
   node * aux;
   int i;
   srand(time(0));
   int r = rand() % 4;
   char player_choice;
   
   FILE *in_file = fopen("questions.txt", "r");
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
      else if(strcmp(line, "DIFFICULTY=medium\n") == 0)
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


   for (aux = head, i= 0; aux != NULL; aux = aux -> next, i++)
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
               printf("*** Question: %s",aux->text);
               printf("*** %c: %s",Option_List[0],aux->answer[1]);
               printf("*** %c: %s",Option_List[1],aux->answer[2]);
               printf("*** %c: %s",Option_List[2],aux->answer[0]);
               printf("*** %c: %s",Option_List[3],aux->answer[3]);
               break;
            }

            else
            {
               
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

   return 0;
}