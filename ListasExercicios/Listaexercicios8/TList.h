/******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/******************************************************************************/
#define TRUE 1
#define FALSE 0
/******************************************************************************/
typedef char Palavra[30];
typedef struct{
	Palavra nome, endereco;
	int idade;	
} Pessoa;
typedef struct TNode{
   Pessoa* info;
   struct TNode *next;
} TNode;

typedef struct{
   TNode* head;
} TList;

