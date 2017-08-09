/******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
/******************************************************************************/
#define TRUE 1
#define FALSE 0
/******************************************************************************/
typedef struct TNode{
   int info, key;
   struct TNode *next;
} TNode;

typedef struct{
   TNode* top;
} TStack;

