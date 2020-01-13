#include "game.h"

void joker(node*head)
{
    node * aux;
    char Option_List[4] = {'A','B','C','D'};
    int i = 0;
    srand(time(0));
    int r = rand() % 4;
    for (aux = head; aux != NULL; aux = aux -> next, i++)
    {
        if (r == 0)
        {  
            int j = rand() % 3;
            printf("*** Question: %s",aux->text);
            printf("*** %c: %s",Option_List[0],aux->answer[0]);
            printf("*** %c: %s",Option_List[j],aux->answer[j]);  
            break;
        }
        else if (r == 1)
        {  
            int j = rand() % 3;
            printf("*** Question: %s",aux->text);
            printf("*** %c: %s",Option_List[j],aux->answer[j]);
            printf("*** %c: %s",Option_List[1],aux->answer[0]);
            break;
        }
        else if (r == 2)
        {  
            int j = rand() % 3;
            printf("*** Question: %s",aux->text);
            printf("*** %c: %s",Option_List[2],aux->answer[0]);
            printf("*** %c: %s",Option_List[j],aux->answer[j]);
            break;
        }
         else if (r == 2)
        {  
            int j = rand() % 3;
            printf("*** Question: %s",aux->text);
            printf("*** %c: %s",Option_List[3],aux->answer[0]);
            printf("*** %c: %s",Option_List[j],aux->answer[j]);
            break;
        }
    }
}