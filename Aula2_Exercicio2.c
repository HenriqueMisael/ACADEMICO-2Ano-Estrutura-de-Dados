#include <stdio.h>

#define TAMANHO 10

#define ORDENAR_DECRESCENTE 0
#define ORDENAR_CRESCENTE   1
/******************************************************************************/
void PegaLinha( int v[] ){

    int i;

    for( i = 0; i < TAMANHO; i++ )
        scanf( "%d", &v[i] );
}
/******************************************************************************/
void escreveLinha( int v[], int n ){

    int i;

    printf("\n" );
    for( i = 0; i < n; i++ ){
       printf( "\t%d", v[i] );
    }
}
/******************************************************************************/
/* FUNCOES PARA SEPARACAO *****************************************************/
/******************************************************************************/
void SeparaVetores( int VetorOriginal[],
                    int Maiores[]      ,
                    int Menores[]      ,
                    int *nMaiores      ,
                    int *nMenores      )
{
   int i, valorZero;

   (*nMaiores) = 0;
   (*nMenores) = 0;

   for( i = 0; i < TAMANHO; i++ )
      if( VetorOriginal[ i ] < 0 )
         Menores[ (*nMenores)++ ] = VetorOriginal[ i ];
      else
         Maiores[ (*nMaiores)++ ] = VetorOriginal[ i ];

}
/******************************************************************************/
/* FUNCOES PARA SELECTION SORT ************************************************/
/******************************************************************************/
int DeveRealizarTroca( int a, int b, int Crescente ){

   if( Crescente )
      return a < b;

   return a > b;
}
/******************************************************************************/
void OrdenaMetodo_Selection( int VetorParaOrdenar[], int Tamanho, int Crescente ){

   int i, j, indiceMenor, valorTemporario;

   for( i = 0; i < Tamanho; i++ ){
      indiceMenor = i;
      for( j = i+1; j < Tamanho; j++ )
         if( DeveRealizarTroca( VetorParaOrdenar[ j ], VetorParaOrdenar[ indiceMenor ], Crescente ) )
            indiceMenor = j;

      if( indiceMenor != i ){
         valorTemporario                 = VetorParaOrdenar[ i ];
         VetorParaOrdenar[ i ]           = VetorParaOrdenar[ indiceMenor ];
         VetorParaOrdenar[ indiceMenor ] = valorTemporario;
      }
   }

}
/******************************************************************************/
/* MAIN ***********************************************************************/
/******************************************************************************/
int main(){

//   int Vetor[] = { -1, -2, -3, -4, -5, 4, 3, 2, 1, 0 };
   int Vetor[TAMANHO];
   int Maiores[TAMANHO], Menores[TAMANHO];
   int nMaiores, nMenores;

   PegaLinha( Vetor );

   printf( "\nOriginal:" );
   escreveLinha( Vetor, TAMANHO );

   SeparaVetores( Vetor, Maiores, Menores, &nMaiores, &nMenores );

   printf( "\n\nMaiores:" );
   OrdenaMetodo_Selection( Maiores, nMaiores, ORDENAR_DECRESCENTE );
   escreveLinha( Maiores, nMaiores );

   printf( "\n\nMenores:" );
   OrdenaMetodo_Selection( Menores, nMenores, ORDENAR_CRESCENTE );
   escreveLinha( Menores, nMenores );

   return 0;
}
