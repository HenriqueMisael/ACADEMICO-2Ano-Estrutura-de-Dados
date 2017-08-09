/******************************************************************************/
#include "Standart.h"
/******************************************************************************/
int NoEsquerda( i )
{
   return (2*i)+1;
}
/******************************************************************************/
int NoDireita( i )
{
   return (2*i)+2;
}
/******************************************************************************/
void maxHeapify( TLista *Lista, int i, int n )
{
   int Esquerda, Direita, Maior, Temp;
   
   Esquerda = NoEsquerda( i );
   Direita  = NoDireita( i );
   if( Esquerda >= 1 && Esquerda <= n && Lista->Elemento[ Esquerda ].Chave > Lista->Elemento[ i ].Chave )
      Maior = Esquerda;
   else
      Maior = i;
      
   if( Direita >= 1 && Direita <= n && Lista->Elemento[ Direita ].Chave > Lista->Elemento[ Maior ].Chave )
      Maior = Direita;

   if( Maior != i )
   {
      Temp = Lista->Elemento[ i ].Chave;
      Lista->Elemento[ i ].Chave = Lista->Elemento[ Maior ].Chave;
      Lista->Elemento[ Maior ].Chave = Temp;
      maxHeapify( Lista, Maior, n );
   }
}
/******************************************************************************/
void buildMaxHeap( TLista *Lista )
{
   int i;

   for( i = (Lista->numeroElementos-1)/2; i >= 0; i-- )
      maxHeapify( Lista, i, Lista->numeroElementos-1 );
}
/******************************************************************************/
void heapSort( TLista *Lista )
{
   int i, Temp;

   buildMaxHeap( Lista );
   for( i = Lista->numeroElementos-1; i >= 1; i-- )
   {
      Temp = Lista->Elemento[ 0 ].Chave;
      Lista->Elemento[ 0 ].Chave = Lista->Elemento[ i ].Chave;
      Lista->Elemento[ i ].Chave = Temp;
      maxHeapify( Lista, 0, i-1 );
   }
}
/******************************************************************************/
