/******************************************************************************/
#include "Standart.h"
/******************************************************************************/
void insereResto( TLista *Lista,
                  int resto[],
                  int tResto ,
                  int iResto ,
                  int iVetor )
{
   int Erro;
   
   while( iResto < tResto )
   {
      Lista->Elemento[iVetor++].Chave = resto[iResto++];
   }
}
/******************************************************************************/
void intercala( TLista *Lista,
                int inicio ,
                int meio   ,
                int fim    )
{
   int *v1, *v2;
   int tamanho1, tamanho2, Erro;
   int i, j, k;
   
   tamanho1 = (meio-inicio+1);
   tamanho2 = (fim-meio);
   v1 = (int*)malloc( sizeof( int )*tamanho1 );
   v2 = (int*)malloc( sizeof( int )*tamanho2 );
   
   k = inicio;
   for( i = 0; i < tamanho1; i++, k++ )
      v1[i] = Lista->Elemento[k].Chave;
   for( i = 0; i < tamanho2; i++, k++ )
      v2[i] = Lista->Elemento[k].Chave;

   //Intercalar enquanto os dois tiverem o mesmo tamanho
   i = j = 0;
   k = inicio;
   while( i < tamanho1 && j < tamanho2 )
   {
      if( v1[i] > v2[j] )
      {
         Lista->Elemento[k].Chave = v2[j++];
      }
      else
      {
         Lista->Elemento[k].Chave = v1[i++];
      }
      k++;
   }
   
   //Insere o resto do vetor maior
   insereResto( Lista, v1, tamanho1, i, k );
   insereResto( Lista, v2, tamanho2, j, k );
}
/******************************************************************************/
void mergeSort( TLista *Lista,
                int inicio ,
                int final  )
{
   int meio;
   if( inicio < final )
   {
      meio = (inicio+final)/2;
      mergeSort( Lista, inicio, meio );
      mergeSort( Lista, meio+1, final );
      intercala( Lista, inicio, meio, final );
   }
}
/******************************************************************************/
void MergeSort( TLista *Lista )
{
   mergeSort( Lista, 0, Lista->numeroElementos-1 );
}
