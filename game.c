#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

void joker(node*, int *);

void game(node*head, char * aux_nome)
{	
    node * aux;
    char player_choice;
    char Option_List[5] = {'A','B','C','D','J'};
    int i = 0;
    srand(time(0));
    int r = rand() % 4;
    for (aux = head; aux != NULL; aux = aux -> next, i++)
{  
    
    if(aux->difficulty >= 0 && aux->difficulty < 3)       
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
    
    else if(toupper(player_choice) == Option_List[4])
        joker(head, &r);    
    
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
    
    else if(toupper(player_choice) == Option_List[4])
        joker(head, &r);   
    
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

    else if(toupper(player_choice) == Option_List[4])
        joker(head, &r);

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

    else if(toupper(player_choice) == Option_List[4])
        joker(head, &r);

    else
    {
        puts("*** Woops... That's not correct.");
        printf("*** The correct answer was %c: %s", Option_List[3],aux->answer[0]);
    } 
}
// print score and jokers after answer
printf("********************************************\n");
printf("*** Name:  %-32s*\n", aux_nome);
printf("*** Level: %-32s*\n", "temporario lvl");
printf("*** j50:   %-32s*\n", "temporario joker 50");
printf("*** j25:   %-32s*\n", "temporario joker 25");
printf("********************************************\n");
}


void joker(node*head, int *r)
{
    node * aux;
    char Option_List[4] = {'A','B','C','D'};
    int i = 0;
    srand(time(0));
    int j = rand() % (3 + 1 - 1) + 1;
    
    for (aux = head; aux != NULL; aux = aux -> next, i++)
    {
        if (*r == 0)
        {  
            
            printf("*** Question: %s",aux->text);
            printf("*** %c: %s",Option_List[0],aux->answer[0]);
            printf("*** %c: %s",Option_List[j],aux->answer[j]);  
            break;
        }
        else if (*r == 1)
        {  
            
            printf("*** Question: %s",aux->text);
            printf("*** %c: %s",Option_List[j],aux->answer[j]);
            printf("*** %c: %s",Option_List[1],aux->answer[0]);
            break;
        }
        else if (*r == 2)
        {  
           
            printf("*** Question: %s",aux->text);
            printf("*** %c: %s",Option_List[2],aux->answer[0]);
            printf("*** %c: %s",Option_List[j],aux->answer[j]);
            break;
        }
         else if (*r == 3)
        {  
            printf("*** Question: %s",aux->text);
            printf("*** %c: %s",Option_List[3],aux->answer[0]);
            printf("*** %c: %s",Option_List[j],aux->answer[j]);
            break;
        }
    }
}
