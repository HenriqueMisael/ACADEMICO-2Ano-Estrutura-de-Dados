/******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
/******************************************************************************/
#define MAX 6
#define FIM -1

#define FALSE 0
#define TRUE  1
/******************************************************************************/
typedef struct{
   int dado;
   int prox;
}TNo;
typedef struct{
   TNo No[MAX];
   int inicio, disp;
}TDeque;
/******************************************************************************/
void TDeque_Inicializa( TDeque *Deque ){

   int i;

   Deque->inicio = FIM;
   Deque->disp   = 0;
   
   for( i = 0; i < MAX-1; i++ )
      Deque->No[i].prox = i+1;
   Deque->No[i].prox = FIM;
}
/******************************************************************************/
int TDeque_PegaDisponivel( TDeque *Deque ){
   
   int Disponivel;
   
   Disponivel = Deque->disp;
   if( !( Disponivel - FIM ) )
      return FIM;
      
   Deque->disp = Deque->No[ Disponivel ].prox;

   return Disponivel;
}
/******************************************************************************/
int TDeque_IndiceFim( TDeque Deque ){
   
   int i;
   
   i = Deque.inicio;
   while( i != FIM )
      if( Deque.No[i].prox == FIM )
         return i;
      else
         i = Deque.No[i].prox;

   return FIM;
}
/******************************************************************************/
int TDeque_Insere( TDeque *Deque, int info, int inicio ){

   int Indice, Fim;

   Indice = TDeque_PegaDisponivel( Deque );

   if( !( Indice - FIM ) ) //disp-FIM = 0 significa que não há mais espaço disponivel
      return FALSE;

   if( inicio ){
      Deque->No[Indice].prox = Deque->inicio;
      Deque->inicio = Indice;
   }else{
      Fim = TDeque_IndiceFim( *Deque );
      Deque->No[ Fim ].prox = Indice;
      Deque->No[ Indice ].prox = FIM;
   }
   Deque->No[ Indice ].dado = info;
   
   return TRUE;
}
/******************************************************************************/
void TDeque_Show( TDeque Deque ){
   
   int i;
   
   i = Deque.inicio;
   if( i != FIM )
      do{
         printf( "%d ", Deque.No[i].dado );
         i = Deque.No[i].prox;
      }while( i != FIM );
}
/******************************************************************************/
int main(){
   
   TDeque Baralho;
   
   TDeque_Inicializa( &Baralho );
   TDeque_Insere( &Baralho, 10, 0 );
   TDeque_Show( Baralho );
   TDeque_Insere( &Baralho, 10, 0 );
   TDeque_Show( Baralho );
   TDeque_Insere( &Baralho, 10, 0 );
   TDeque_Show( Baralho );

   return 0;
}

