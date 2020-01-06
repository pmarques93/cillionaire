#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define MSG_BYE "*** Sad to see you go..."
#define MSG_UNKNOWN "*** Unknown option..."
FILE * abreFicheiro (char *, char *);
void pressKey(void);
void printMenu(void);
void printCredits(void);
void jokerBonus(void);
typedef struct 
	{
		char question[128];
		char answer[4][128];
		int difficulty;
	} pergunta;

int main(int argc, char** argv)
{	
	FILE * question;
	char player_command;
	int seed;
	char nome[100] = "newbie";
	char line [100];
	char aux_nome [00];
	char aux;

	if (argc > 1)
	{
		seed = atoi(argv[1]);
	}
	else
	{
		seed = time(NULL);
	}
	question = abreFicheiro(argv[1], "r");
	
	
	printMenu();
	fgets(line, 100, stdin);
	
	switch(line [0])
	{
		case 'n' :
			if (sscanf(line,"%c%s", &aux, aux_nome) == 2)
				{
					strcpy(nome, aux_nome);
					
				}
			
			printf("*** Hi %s, let's get started!\n", nome);
			break;

			
			
	}
	
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

FILE * abreFicheiro(char * nome, char * mode)
{
	FILE * r;
	printf("A abrir o ficheiro\n");
	r = fopen(nome, mode);
	if (r == NULL)
	{
		fprintf(stdout, "*** Não foi possivel abrir o ficheiro %s.\n", nome);
		exit(1);
	}
	return r;
}








