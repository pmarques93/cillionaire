#include "classes.h"

#ifndef __game_h__
#define __game_h__

node* game(node*head, char * aux_nome);
void joker50(node*head, int*);
void joker25(node*head, int*);
unsigned int level_check (node* aux,int level);
void printScore(char * aux_nome, int level, int joker_50_50);
#endif

