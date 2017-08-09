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
   struct TNode *next;
} TNode;

typedef struct{
   TNode* first;
   TNode* sentinel;
} TList;

