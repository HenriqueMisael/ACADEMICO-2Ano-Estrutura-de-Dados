/******************************************************************************/
#include <string.h>
#include <malloc.h>
#include <stdio.h>
/******************************************************************************/
#define TRUE  1
#define FALSE 0
/******************************************************************************/
typedef char info[15];
typedef struct estrutura{
   int prioridade;
   info dado;
   struct estrutura *prox;
} TNo;
/******************************************************************************/
typedef struct{
   TNo *inicio, *fim;
} TFila;
/******************************************************************************/