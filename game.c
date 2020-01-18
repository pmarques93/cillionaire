#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

void joker50(node*, int *);
void joker25(node*, int *);
unsigned int level_check (node* ,int );
char player_choice [100];
char aux_char;
int aux_type;
int joker_50_50 = 1;
int joker_25_75 = 1;
int level = 0;
node* game(node*head, char * aux_nome)
{	
    node * aux;
   
    char Option_List[6] = {'A','B','C','D','J','Q'};
    int i = 0;
    int r = rand() % 4;
    
    printScore(aux_nome, level);
    for (aux = head; aux != NULL; aux = aux -> next, i++)
    {       
            //Variavel que ve em que nivel o jogador esta
            
            if(aux->difficulty == level_check (aux,level)) //falta so fazer com o nivel suba se o jogador acertaruma pergunta
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
        
        
    if(toupper(aux_char) == Option_List[5])
        {
            puts(">*** Sad to see you go...");
            exit(0);
        }
    if (r == 0)
    {
        
        if(toupper(aux_char) == Option_List[0])
        {
            puts("*** Hooray!");
            printScore(aux_nome, level);
            level += 1;
            

        
        }
        else if(toupper(aux_char) == Option_List[4])
        {
            if (aux_type == 50)
            {
                joker50(head, &r);
                fgets(player_choice, 100, stdin);
                sscanf(player_choice,"%c%d", &aux_char, &aux_type);
                joker_50_50 = 0;
                if(toupper(aux_char) == Option_List[5])
                {
                    puts(">*** Sad to see you go...");
                    exit(0);
                }
                else if(toupper(aux_char) == Option_List[0])
                {
                    puts("*** Hooray!");
                   printScore(aux_nome, level);
                    level += 1;
                    
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
            printScore(aux_nome, level);
            level += 1;
            
        }
        
        else if(toupper(aux_char) == Option_List[4])
        {
            if (aux_type == 50)
            {
                joker_50_50 = 0;
                joker50(head, &r);
                fgets(player_choice, 100, stdin);
                sscanf(player_choice,"%c%d", &aux_char, &aux_type);
                
                if(toupper(aux_char) == Option_List[5])
                {
                    puts(">*** Sad to see you go...");
                    exit(0);
                }
                else if(toupper(aux_char) == Option_List[1])
                {
                    puts("*** Hooray!");
                    printScore(aux_nome, level);
                    level += 1;
                }
                else
                {
                    puts("*** Woops... That's not correct.");
                    printf("*** The correct answer was %c: %s", Option_List[1],aux->answer[0]);
                    level -= 1;
                }
                
            }        
        }

        else
        {
            puts("*** Woops... That's not correct.");
            printf("*** The correct answer was %c: %s", Option_List[1],aux->answer[0]);
            level -= 1;
        }
    }

    else if (r == 2)
    {   
        
        if(toupper(aux_char) == Option_List[2])
        {
            puts("*** Hooray!");
            printScore(aux_nome, level);
            level += 1;
        }
        else if(toupper(aux_char) == Option_List[4])
        {
            if (aux_type == 50)
            {
                joker_50_50 = 0;
                joker50(head, &r);
                fgets(player_choice, 100, stdin);
                sscanf(player_choice,"%c%d", &aux_char, &aux_type);
                
                if(toupper(aux_char) == Option_List[5])
                {
                    puts(">*** Sad to see you go...");
                    exit(0);
                }
                if(toupper(aux_char) == Option_List[2])
                {
                    puts("*** Hooray!");
                    printScore(aux_nome, level);
                    level += 1;
                }
                else
                {
                    puts("*** Woops... That's not correct.");
                    printf("*** The correct answer was %c: %s", Option_List[2],aux->answer[0]);
                    level -= 1;
                }
                
            }    
        }

        else
        {
            puts("*** Woops... That's not correct.");
            printf("*** The correct answer was %c: %s", Option_List[2],aux->answer[0]);
            level -= 1;
        }
    }

    else if (r == 3)
    {
        if(toupper(aux_char) == Option_List[3])
        {    
            puts("*** Hooray!");
            printScore(aux_nome, level);
            level += 1;
        }
        else if(toupper(aux_char) == Option_List[4])
        {
            if (aux_type == 50)
            {
                joker_50_50 = 0;
                joker50(head, &r);
                fgets(player_choice, 100, stdin);
                sscanf(player_choice,"%c%d", &aux_char, &aux_type);
                if(toupper(aux_char) == Option_List[5])
                {
                    puts(">*** Sad to see you go...");
                    exit(0);
                }
                else if(toupper(aux_char) == Option_List[3])
                {
                    puts("*** Hooray!");
                    printScore(aux_nome, level);
                    level += 1;
                }
                else
                {
                    puts("*** Woops... That's not correct.");
                    printf("*** The correct answer was %c: %s", Option_List[3],aux->answer[0]);
                    level -= 1;
                    printScore(aux_nome, level); 
                }
                
            }
        }

        else
        {
            puts("*** Woops... That's not correct.");
            printf("*** The correct answer was %c: %s", Option_List[3],aux->answer[0]);
            level -= 1;
            

        } 
    }
    
    if (aux == NULL)
    {

        exit(0); 
    }
    else
    {
        aux = head -> next;
        head -> next = aux -> next;
        free(aux);
         aux -> next = game(head->next, aux_nome);
        return head;
        
    }
        
}


void joker50(node*head, int *r)
{
    node * aux;
    char Option_List[4] = {'A','B','C','D'};
    int i = 0;
   
    
    int j = rand() % (3 - 1 + 1) + 1;
    for (aux = head; aux != NULL; aux = aux -> next, i++)
    {
       if(aux->difficulty == 0)
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
                if(j >= 1)
                {
                    printf("*** Question: %s",aux->text);
                    printf("*** %c: %s",Option_List[1],aux->answer[0]);
                    printf("*** %c: %s",Option_List[j],aux->answer[j]);
                    break;
                }

                else if(j < 1)
                {
                    printf("*** Question: %s",aux->text);
                    printf("*** %c: %s",Option_List[j],aux->answer[j]);
                    printf("*** %c: %s",Option_List[1],aux->answer[0]);
                    break;
                }
            }
            else if (*r == 2)
            {
                if(j > 2)
                {
                    printf("*** Question: %s",aux->text);
                    printf("*** %c: %s",Option_List[2],aux->answer[0]);
                    printf("*** %c: %s",Option_List[j],aux->answer[j]);
                    break;
                }

                else if(j < 2)
                {
                    printf("*** Question: %s",aux->text);
                    printf("*** %c: %s",Option_List[j],aux->answer[j]);
                    printf("*** %c: %s",Option_List[2],aux->answer[0]);
                    break;
                }

                
                
            }
            else if (*r == 3)
            {
                if(j == 3)
                {
                    j = rand() % 3;
                    printf("*** Question: %s",aux->text);
                    printf("*** %c: %s",Option_List[j],aux->answer[j]);
                    printf("*** %c: %s",Option_List[3],aux->answer[0]);
                    break;
                }

                else if(j < 3)
                {
                    printf("*** Question: %s",aux->text);
                    printf("*** %c: %s",Option_List[j],aux->answer[j]);
                    printf("*** %c: %s",Option_List[3],aux->answer[0]);
                    break;
                }
                        
            }
        }
    }
}

//void joker25(node*head, int *r)
//{
    
    //Inserirn codigo do joker 25 75 aqui
    //ja ta definido no resto dos ficheiros
//}


//funcao que verifica o patamar do jogador
//recebe os nodes e o nivel atual
//retorna um valor entre 0 e 2 para a dificuldade
unsigned int level_check (node* aux,int level)
{
    unsigned int difficulty;
    if (level < 3)
    {
        difficulty = 0;
        aux->difficulty = 0;
    }
        
    else if ( level > 3 && level < 5)
    {
        aux ->difficulty = 1;
        difficulty = 1;
    }
        
    else
    {
        aux->difficulty = 2;
        difficulty = 2;
    }
        
    return difficulty;
}

void printScore(char *aux_nome, int level)
{

    int level_title;
    if (level == 0)
    {
        
        level_title = 0;

    }
        
    else if ( level == 1)
    {
        level_title = 500;
    }
        
    else if ( level == 2)
    {
        level_title = 1000;
    }
    else if ( level == 3)
    {
        level_title  = 2000;
    }
    else if ( level == 4)
    {
        level_title  = 5000;
    }
    else if ( level == 5)
    {
        level_title  = 10000;
    }
    else if ( level == 6)
    {
        level_title  = 200000;
    }
    else if ( level == 7)
    {
        level_title  = 500000;
    }
    else
    {
        level_title  = 100000;
    }
    printf("********************************************\n");
    printf("*** Name:  %-32s*\n", aux_nome);
    printf("*** Level: %d\n", level_title);
    printf("*** j50:   %-32s*\n", "YES");
    printf("*** j25:   %-32s*\n", "YES");
    printf("********************************************\n");
}