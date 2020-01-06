#include <stdio.h>
#include <stdlib.h>


void readFile(void);

typedef struct 
	{
		char question[128];
		char answer[4][128];
		int difficulty;
	} pergunta;

int main()
{
   readFile();
}



void readFile()
{
   char ch;
   FILE *fp;
   fp = fopen("abc.txt", "r"); // read mode

   if (fp == NULL)
   {
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   }

   puts("The contents of file are:\n");

   while((ch = fgetc(fp)) != EOF)
      printf("%c", ch);

   fclose(fp);
}