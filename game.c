#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

void joker(node*, int *);
char player_choice [100];
char aux_char;
int aux_type;

void game(node*head, char * aux_nome)
{	
    node * aux;
    
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

fgets(player_choice, 100, stdin);
sscanf(player_choice,"%c%d", &aux_char, &aux_type);

if (r == 0)
{
   
    if(toupper(aux_char) == Option_List[0])
    {
        puts("*** Hooray!");
        printScore(aux_nome);
    }
    else if(toupper(aux_char) == Option_List[4])
    {
        if (aux_type == 50)
        {
            joker(head, &r);
            fgets(player_choice, 100, stdin);
            sscanf(player_choice,"%c%d", &aux_char, &aux_type);
            
            if(toupper(aux_char) == Option_List[0])
            {
                puts("*** Hooray!");
                printScore(aux_nome);
            }
            else
            {
                puts("*** Woops... That's not correct.");
                printf("*** The correct answer was %c: %s", Option_List[0],aux->answer[0]);
            }
            
        }    
    }
    else
    {
        puts("*** Woops... That's not correct.");
        printf("*** The correct answer was %c: %s", Option_List[0],aux->answer[0]);
    }
    
}

else if (r == 1)
{
    if(toupper(aux_char) == Option_List[1])
    {
        puts("*** Hooray!");
        printScore(aux_nome);
    }
    
    else if(toupper(aux_char) == Option_List[4])
    {
        if (aux_type == 50)
        {
            joker(head, &r);
            fgets(player_choice, 100, stdin);
            sscanf(player_choice,"%c%d", &aux_char, &aux_type);
            
            if(toupper(aux_char) == Option_List[1])
            {
                puts("*** Hooray!");
                printScore(aux_nome);
            }
            else
            {
                puts("*** Woops... That's not correct.");
                printf("*** The correct answer was %c: %s", Option_List[1],aux->answer[0]);
            }
            
        }        
    }

    else
    {
        puts("*** Woops... That's not correct.");
        printf("*** The correct answer was %c: %s", Option_List[1],aux->answer[0]);
    }
}

else if (r == 2)
{
    if(toupper(aux_char) == Option_List[2])
        puts("*** Hooray!");

    else if(toupper(aux_char) == Option_List[4])
    {
        if (aux_type == 50)
        {
            joker(head, &r);
            fgets(player_choice, 100, stdin);
            sscanf(player_choice,"%c%d", &aux_char, &aux_type);
            
            if(toupper(aux_char) == Option_List[2])
            {
                puts("*** Hooray!");
                printScore(aux_nome);
            }
            else
            {
                puts("*** Woops... That's not correct.");
                printf("*** The correct answer was %c: %s", Option_List[2],aux->answer[0]);
            }
            
        }    
    }

    else
    {
        puts("*** Woops... That's not correct.");
        printf("*** The correct answer was %c: %s", Option_List[2],aux->answer[0]);
    }
}

else if (r == 3)
{
    if(toupper(aux_char) == Option_List[3])
    {    
        puts("*** Hooray!");
        printScore(aux_nome);
    }
    else if(toupper(aux_char) == Option_List[4])
    {
        if (aux_type == 50)
        {
            joker(head, &r);
            fgets(player_choice, 100, stdin);
            sscanf(player_choice,"%c%d", &aux_char, &aux_type);
            
            if(toupper(aux_char) == Option_List[3])
            {
                puts("*** Hooray!");
                printScore(aux_nome);
            }
            else
            {
                puts("*** Woops... That's not correct.");
                printf("*** The correct answer was %c: %s", Option_List[3],aux->answer[0]);
            }
            
        }
    }

    else
    {
        puts("*** Woops... That's not correct.");
        printf("*** The correct answer was %c: %s", Option_List[3],aux->answer[0]);
        printScore(aux_nome); 

    } 
}


}


void joker(node*head, int *r)
{
    node * aux;
    char Option_List[4] = {'A','B','C','D'};
    int i = 0;
    srand(time(0));
    //  (upper - lower + 1)) + lower; 
    int j = rand() % (3 - 1 + 1) + 1;
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
            if(j > 1)
            {
                printf("*** Question: %s",aux->text);
                printf("*** %c: %s",Option_List[1],aux->answer[0]);
                printf("*** %c: %s",Option_List[j],aux->answer[j]);
                break;
            }

            if(j < 1)
            {
                printf("*** Question: %s",aux->text);
                printf("*** %c: %s",Option_List[j],aux->answer[j]);
                printf("*** %c: %s",Option_List[1],aux->answer[0]);
                break;
            }

            if(j == 1)
            {
                int lista[4] = {0,2,3};
                int rand_num = (rand() % 2); 
                j = lista[rand_num];
                printf("j = %d\n", j);
            }
            
            printf("*** Question: %s",aux->text);
            printf("*** %c: %s",Option_List[1],aux->answer[0]);
            printf("*** %c: %s",Option_List[j],aux->answer[j]);
            break;
        }

    }
}
