#include "readFile.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

node* readFile(char * file_name)
{  
   
   char line[512];
   node * head = NULL;
   node * tail = NULL;
   node * new;
   
   FILE *in_file;
   
   
   in_file = fopen(file_name, "r");
   
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
      if (strcmp(line, "DIFFICULTY=easy\n") == 0)
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