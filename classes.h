#ifndef __classes_h__
#define __classes_h__

typedef struct _node {
   char text[128];
   char answer[4][128];
   enum {easy, medium, hard} difficulty;
   struct _node * next;
} node;

#endif


