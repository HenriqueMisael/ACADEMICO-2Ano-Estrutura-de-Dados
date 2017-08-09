/******************************************************************************/
#include "FilaDinamica.h"
/******************************************************************************/
void TFila_Inicializa( TFila *Fila ){
   Fila->inicio = NULL;
   Fila->fim = NULL;
}
/******************************************************************************/
void TFila_Insere( TFila *Fila, info dado, int priodidade ){

   TNo *NovoNo;

   NovoNo = (TNo*)malloc( sizeof( TNo ) );
   strcpy( NovoNo->dado, dado);
   NovoNo->prioridade = priodidade;
   NovoNo->prox = NULL;

   if( !Fila->inicio )
      Fila->inicio = NovoNo;
   else
      Fila->fim->prox = NovoNo;

   Fila->fim = NovoNo;
}
/******************************************************************************/
int TFila_ModificaPrioridade( TFila *Fila, info dado, int novaPriodidade ){

    TNo *p;

    p = Fila->inicio;
    while( p )
        if( p->dado == dado ){
            p->prioridade = novaPriodidade;
            return TRUE;
        }else
            p = p->prox;
    return FALSE;
}
/******************************************************************************/
TNo* TFila_BuscaMaiorPrioridade( TFila Fila, TNo **Anterior ){

    TNo *p, *Maior;

    Maior = Fila.inicio;
    if( !Maior )
        return NULL;
    *Anterior = NULL;
    p = Maior;
    while( p->prox ){
        if( Maior->prioridade < p->prox->prioridade ){
            Maior = p->prox;
            *Anterior = p;
        }
        p = p->prox;
    }
    return Maior;
}
/******************************************************************************/
void TFila_Show( TFila Fila ){

   TNo *p;

   for( p = Fila.inicio; p; p = p->prox ){
      printf( "\n %s, %d", p->dado, p->prioridade );
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

   TNo *Removido, *Anterior;
   info Dado;

   Anterior = NULL;
   if( !Fila->inicio )
      return NULL;
   else if( Fila->fim == Fila->inicio ){
      TFila_Inicializa( Fila );
      return NULL;
   }
   else{
      Removido = TFila_BuscaMaiorPrioridade( *Fila, &Anterior );
      if( Removido == Fila->inicio )
         TFila_Inicializa( Fila );
      else{
         if( Removido == Fila->fim )
            Fila->fim = Anterior;
         Anterior->prox = Removido->prox;
      }
      strcpy( Dado, Removido->dado );
      free( Removido );
   }

   return Dado;
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
