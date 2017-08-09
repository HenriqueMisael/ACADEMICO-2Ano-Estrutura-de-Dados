/******************************************************************************/
#include <stdio.h>
#include "ShellSort.h"
/******************************************************************************/
void mostraVetor( const int Vetor[]
                 ,const int Tamanho
                )
{
   int i;

   printf( "\n Vetor[%d]: ", Tamanho );
   for( i = 0; i < Tamanho; i++ )
      printf( "%d ", Vetor[ i ] );

}
/******************************************************************************/
int troca( int Vetor[],
           int i      ,
           int j      )
{
   int Temporario, troca;

   troca = Vetor[ i ] > Vetor[ j ];
   if( troca )
   {
      Temporario = Vetor[ i ];
      Vetor[ i ] = Vetor[ j ];
      Vetor[ j ] = Temporario;
   }
   return troca;
}
/******************************************************************************/
int ShellSort( int Vetor[] )
{
   int valorTrocado;
   int i, j, h;
   
   for( h = 1; h < TAMANHO; h = h*FATOR_LARGURA+1 );
   
   while( h >= 1 )
   {
      h /= FATOR_LARGURA;
      for( i = h; i < TAMANHO; i++ )
      {
         valorTrocado = Vetor[ i ];
         j = i-h;
         while( j >= 0 && valorTrocado < Vetor[ j ] )
         {
            Vetor[ j+h ] = Vetor[ j ];
            j -= h;
         }
         Vetor[ j+h ] = valorTrocado;
      }
   }
}
/******************************************************************************/
int main()
{
   int Vetor[ TAMANHO ] = { 3,4,2,1,5,9,6,8,7,0 };
   
   mostraVetor( Vetor, TAMANHO );
   ShellSort( Vetor );
   mostraVetor( Vetor, TAMANHO );

   return 0;
}
/******************************************************************************/
