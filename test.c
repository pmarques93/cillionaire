#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct _node {
   char text[128];
   char answer[4][128];
   enum {easy, medium, hard} difficulty;
   struct _node * next;
} node;

int main()
{
   char line[512];
   node * head = NULL;
   node * tail = NULL;
   node * new;
   node * aux;
   int i;

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
            printf("*** question: %s",aux->text);
            printf("%d\n", aux->difficulty);
            break;
         }
   }

   return 0;
}