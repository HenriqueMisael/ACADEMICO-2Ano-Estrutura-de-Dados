/******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
/******************************************************************************/
#define TRUE 1
#define FALSE 0
/******************************************************************************/
typedef int chave;
typedef struct TNode{
   chave chave;
   int info;
   struct TNode *next, *prev;
} TNode;

typedef struct{
   TNode* head;
} TList;

