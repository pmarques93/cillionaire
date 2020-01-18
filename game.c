#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

void joker50(node*, int *);
void joker25(node*, int *);
unsigned int level_check (node* ,int );
char player_choice [100];
char aux_char;
int aux_type;
int joker_50_50 = 1;
int joker_25_75 = 1;
int level = 0;
int dif_up = 0;
int level_title;
int fail = 0;
node* game(node*head, char * aux_nome)
{	
    node * aux;
    if (level < 0)
        level = 0;
    
    if (fail == 2)
    {
        puts("youlost");
        exit(0);
    }
    printf("%d", fail);  
    char Option_List[6] = {'A','B','C','D','J','Q'};
    int i = 0;
    int r = rand() % 4;
    
    printScore(aux_nome, level, joker_50_50);


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
                puts(">*** Hooray!");
                 fail = 0;
                level += 1;
                

            
            }
            else if(toupper(aux_char) == Option_List[4])
            {
                if (aux_type == 50)
                {
                    joker50(head, &r);
                    fgets(player_choice, 100, stdin);
                    sscanf(player_choice,"%c%d", &aux_char, &aux_type);
                    
                    if(toupper(aux_char) == Option_List[5])
                    {
                        puts(">*** Sad to see you go...");
                        exit(0);
                    }
                    else if(toupper(aux_char) == Option_List[0])
                    {
                        puts(">*** Hooray!");
                        fail = 0;
                        level += 1;
                        
                    }
                    else
                    {
                        puts(">*** Woops... That's not correct.");
                        printf("*** The correct answer was %c: %s", Option_List[0],aux->answer[0]);
                        fail +=1;
                    }
                    
                }    
            }
            
            else
            {
                puts(">*** Woops... That's not correct.");
                printf("*** The correct answer was %c: %s", Option_List[0],aux->answer[0]);
                fail +=1;
            }
            
        }

        else if (r == 1)
        {   
            if(toupper(aux_char) == Option_List[1])
            {
                puts(">*** Hooray!");
                 fail = 0;
                
                level += 1;
                
            }
            
            else if(toupper(aux_char) == Option_List[4])
            {
                if (aux_type == 50)
                {
                    
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
                    puts(">*** Hooray!");
                        fail = 0;
                        level += 1;
                    }
                    else
                    {
                        puts(">*** Woops... That's not correct.");
                        printf("*** The correct answer was %c: %s", Option_List[1],aux->answer[0]);
                        fail +=1;
                        level -= 1;
                    }
                    
                }        
            }

            else
            {
                puts(">*** Woops... That's not correct.");
                printf("*** The correct answer was %c: %s", Option_List[1],aux->answer[0]);
                level -= 1;
                fail +=1;
            }
        }

        else if (r == 2)
        {   
            
            if(toupper(aux_char) == Option_List[2])
            {
                puts(">*** Hooray!");
                 fail = 0;
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
                        puts(">*** Hooray!");
                         fail = 0;
                        level += 1;
                    }
                    else
                    {
                        puts(">*** Woops... That's not correct.");
                        printf("*** The correct answer was %c: %s", Option_List[2],aux->answer[0]);
                        level -= 1;
                        fail +=1;
                    }
                    
                }    
            }

            else
            {
                puts(">*** Woops... That's not correct.");
                printf("*** The correct answer was %c: %s", Option_List[2],aux->answer[0]);
                level -= 1;
                fail +=1;
            }
        }

        else if (r == 3)
        {
            if(toupper(aux_char) == Option_List[3])
            {    
                puts(">*** Hooray!");
                 fail = 0;
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
                        puts(">*** Hooray!");
                         fail = 0;
                        level += 1;
                    }
                    else
                    {
                    puts(">*** Woops... That's not correct.");
                        printf("*** The correct answer was %c: %s", Option_List[3],aux->answer[0]);
                        level -= 1;
                        fail +=1;
                        
                    }
                    
                }
            }

        else
        {
            puts(">*** Woops... That's not correct.");
            printf("*** The correct answer was %c: %s", Option_List[3],aux->answer[0]);
            level -= 1;
            fail +=1;
            

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


void joker50(node*aux, int *r)
{
    aux = aux->next;
    char Option_List[4] = {'A','B','C','D'};
    
    
    
    int j = rand() % (3 - 1 + 1) + 1;
    
    
       if(aux->difficulty == 0)
       {
        
            if (*r == 0)
            {  

                printf("*** Question: %s",aux->text);
                printf("*** %c: %s",Option_List[0],aux->answer[0]);
                printf("*** %c: %s",Option_List[j],aux->answer[j]);  
                
            }
            else if (*r == 1)
            {
               
                if(j >= 1)
                {
                    printf("*** Question: %s",aux->text);
                    printf("*** %c: %s",Option_List[1],aux->answer[0]);
                    printf("*** %c: %s",Option_List[j],aux->answer[j]);
                   
                }
                else if(j < 1)
                {
                    printf("*** Question: %s",aux->text);
                    printf("*** %c: %s",Option_List[j],aux->answer[j]);
                    printf("*** %c: %s",Option_List[1],aux->answer[0]);
                    
                }
            }
            else if (*r == 2)
            {
                if(j > 2)
                {
                    printf("*** Question: %s",aux->text);
                    printf("*** %c: %s",Option_List[2],aux->answer[0]);
                    printf("*** %c: %s",Option_List[j],aux->answer[j]);
                    
                }

                else if(j < 2)
                {
                    printf("*** Question: %s",aux->text);
                    printf("*** %c: %s",Option_List[j],aux->answer[j]);
                    printf("*** %c: %s",Option_List[2],aux->answer[0]);
                    
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
                    
                }

                else if(j < 3)
                {
                    printf("*** Question: %s",aux->text);
                    printf("*** %c: %s",Option_List[j],aux->answer[j]);
                    printf("*** %c: %s",Option_List[3],aux->answer[0]);
                    
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
        aux->difficulty = 0;
        difficulty = 0;

    }
        
<<<<<<< HEAD
    else if ( level >= 3 && level < 5)
=======
    else if ( level > 2 && level < 5)
>>>>>>> 9fb8635d08b9787a7bc0bf48d176cc1f57a0e0e2
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

void printScore(char *aux_nome, int level, int joker_50_50)
{
    
    
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
        level_title  = 20000;
    }
    else if ( level == 7)
    {
        level_title  = 50000;
    }
    else if ( level == 8)
    {
        level_title  = 100000;
    }
    char joker50_text[1000];
    if (joker_50_50 == 1 )
    {
      strcpy(joker50_text, "YES");
    }
    else
    {
        strcpy(joker50_text, "NO");
    }
    char joker25_text[1000];
    if (joker_25_75 == 1 )
    {
      strcpy(joker25_text, "YES");
    }
    else
    {
        strcpy(joker25_text, "NO");
    }
    printf("********************************************\n");
    printf("*** Name:  %-32s*\n", aux_nome);
    printf("*** Level: %-32d*\n", level_title);
    printf("*** j50:   %-32s*\n", joker50_text);
    printf("*** j25:   %-32s*\n", joker25_text);
    printf("********************************************\n");
    if (level == 8)     // quando chega ao lvl 8 faz print do menu e da exit
    {
        puts("*** This is incredible! You have won!");
        printf("*** Congratulations %s!\n", aux_nome);
        exit(0);
    }
}