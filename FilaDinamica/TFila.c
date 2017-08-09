/******************************************************************************/
#include "FilaDinamica.h"
/******************************************************************************/
void TFila_Inicializa( TFila *Fila ){
   Fila->inicio = NULL;
   Fila->fim = NULL;
}
/******************************************************************************/
void TFila_Insere( TFila *Fila, info dado ){
   
   TNo *NovoNo;
   
   NovoNo = (TNo*)malloc( sizeof( TNo ) );
   strcpy( NovoNo->dado, dado);
   NovoNo->prox = NULL;

   if( !Fila->inicio )
      Fila->inicio = NovoNo;
   else
      Fila->fim->prox = NovoNo;
      
   Fila->fim = NovoNo;
}
/******************************************************************************/
void TFila_Show( TFila Fila ){
   
   TNo *p;
   
   for( p = Fila.inicio; p; p = p->prox ){
      printf( "%s\n", p->dado );
   }
}
/******************************************************************************/
TNo* TFila_PrimeiroNo( TFila Fila ){
   return Fila.inicio;
}
/******************************************************************************/
int TFila_Count( TFila Fila ){

   TNo *p;
   int n;

   for( n = 0, p = Fila.inicio; p; p = p->prox, n++ );

   return n;
}
/******************************************************************************/
int TFila_Remove( TFila *Fila ){

   TNo *Removido;

   if( !Fila->inicio )
      return FALSE;

   Removido = Fila->inicio;
   Fila->inicio = Fila->inicio->prox;
   
   if( !Fila->inicio )
      Fila->fim = NULL;

   free( Removido );

   return TRUE;
}
/******************************************************************************/
int TFila_isCrescente( TFila Fila ){
   
   TNo *p;
   
   if( Fila.inicio )
      for( p = Fila.inicio; p->prox; p = p->prox )
         if( strcmp( p->dado, p->prox->dado ) > 0 )
            return FALSE;

   return TRUE;
}
/******************************************************************************/
void TFila_Esvazia( TFila *Fila ){
   while( TFila_Remove( Fila ) );
}
/******************************************************************************/
void TFila_InverteDados( TFila *Fila ){

   TNo *pInicio, *pFim, *pAux;
   info DadoTemp;
   int Final, i;
   
   pInicio = Fila->inicio;
   pFim = Fila->fim;

   Final = TFila_Count( *Fila )/2;
   for( i = 0; i < Final; i++ ){

      strcpy( DadoTemp, pInicio->dado );
      strcpy( pInicio->dado, pFim->dado );
      strcpy( pFim->dado, DadoTemp );
      
      pAux = pInicio;
      while( pAux->prox != pFim ){
         pAux = pAux->prox;
      }
      pFim = pAux;
      pInicio = pInicio->prox;
   }
}
/******************************************************************************/
void TFila_InverteNos( TFila *Fila ){

   TNo *pAtual, *pProx, *pTemp;
   
   pAtual = Fila->inicio;
   pProx = pAtual->prox;
   while( pAtual->prox ){
      pTemp = pProx->prox;
      pProx->prox = pAtual;
      pAtual = pProx;
      pProx = pTemp;
   }

   Fila->inicio = Fila->fim;
   Fila->fim = pTemp;
}
/******************************************************************************/
