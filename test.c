#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//estrutura cria vector para PERGUNTA, 4 RESPOSTAS, DIFICULDADE
typedef struct _node {
   char text[128];
   char answer[4][128];
   enum {easy, medium, hard} difficulty;
   struct _node * next;
} node;

int main()
{
   char line[512];
   node * head = NULL;// sempre primeiro node
   node * tail = NULL;// tail ai ser sempre o último node (última pergunta)
   node * new;
   node * aux;
   int i;
   int r = rand() % 4;
   
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
         tail->next = new;//se o TAIL não for o último, cria um novo node
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
               printf("*** A: %s",aux->answer[0]);
               printf("*** B: %s",aux->answer[1]);
               printf("*** C: %s",aux->answer[2]);
               printf("*** D: %s",aux->answer[3]);
               break;
            }

            else if (r == 1)
            {
               printf("*** Question: %s",aux->text);
               printf("*** A: %s",new->answer[1]);
               printf("*** B: %s",new->answer[0]);
               printf("*** C: %s",new->answer[2]);
               printf("*** D: %s",new->answer[3]);
               break;
            }

            else if (r == 2)
            {
               printf("*** Question: %s",aux->text);
               printf("*** A: %s",new->answer[1]);
               printf("*** B: %s",new->answer[2]);
               printf("*** C: %s",new->answer[0]);
               printf("*** D: %s",new->answer[3]);
               break;
            }

            else
            {
               printf("%d", r);
               printf("*** Question: %s",aux->text);
               printf("*** A: %s",new->answer[1]);
               printf("*** B: %s",new->answer[2]);
               printf("*** C: %s",new->answer[3]);
               printf("*** D: %s",new->answer[0]);
               break;
            }
         }
   }

   return 0;
}