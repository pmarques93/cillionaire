#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct _node {
   char text[128];
   char answer[4][128];
   enum {easy, medium, hard} difficulty;
   struct _node * next;
} node;



