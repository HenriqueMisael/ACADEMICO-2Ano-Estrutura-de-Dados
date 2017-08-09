/******************************************************************************/
#include "Standart.h"
/******************************************************************************/
void troca( volatile TLista *Lista
           ,const    int    i
           ,const    int    j
          )
{
   int Temp;
   Temp = Lista->Elemento[ j ].Chave;
   Lista->Elemento[ j ].Chave = Lista->Elemento[ i ].Chave;
   Lista->Elemento[ i ].Chave = Temp;
}
/******************************************************************************/
int gerarPivo( volatile TLista *Lista
              ,const    int    esquerda
              ,const    int    direita
             )
{
   int passos, IPO;
   IPO = esquerda;

   for( passos = esquerda+1; passos < direita + 1; passos++ )
   {
      if( Lista->Elemento[passos].Chave < Lista->Elemento[esquerda].Chave )
      {
         troca( Lista, ++IPO, passos );
      }
   }
   troca( Lista, IPO, esquerda );
   
   return IPO;
}
/******************************************************************************/
void q_sort( volatile TLista *Lista
            ,const    int    esquerda
            ,const    int    direita
           )
{
   int pivo;

   if( direita > esquerda )
   {
      pivo = gerarPivo( Lista, esquerda, direita );
      q_sort( Lista, esquerda, pivo-1 );
      q_sort( Lista, pivo+1, direita );
   }
}
/******************************************************************************/
void QuickSort( volatile TLista *Lista )
{
   q_sort( Lista, 0, TLista_GetTamanho( *Lista )-1 );
}
