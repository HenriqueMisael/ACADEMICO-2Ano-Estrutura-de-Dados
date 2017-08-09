#include <stdio.h>
#include <Windows.h>

#define TAMANHO 7

int PercorreuTotalLacos = 0;

void escreveLinha( int v[], int VezesJaPercorridas ){

    int i;

    printf( "\n %d:", VezesJaPercorridas );
    for( i = 0; i < TAMANHO; i++ ){
       printf( "\t%d", v[i] );
    }
}

void PegaLinha( int v[] ){

    int i;


    for( i = 0; i < TAMANHO; i++ ){
        scanf( "%d", &v[i] );
        system( "CLS" );
    }
}
/******************************************************************************/
/* FUNCOES PARA BUBBLE SORT ***************************************************/
/******************************************************************************/
int verificaTroca( int v[], int n ){

    int i, Temporario, Alterado;

    Alterado = 0;
    for( i = 0; i < n-1; i++ ){
        if( v[i] < v[i+1] ){
            Temporario = v[i];
            v[ i ] = v[ i+1 ];
            v[ i+1 ] = Temporario;
            Alterado = 1;
        }
        PercorreuTotalLacos++;
    }

    return Alterado;
}
/******************************************************************************/
void OrdenaMetodo_Bubble( int VetorParaOrdenar[]){

   int n;

   n = 0;
   escreveLinha( VetorParaOrdenar, TAMANHO-n );

   while(verificaTroca( VetorParaOrdenar, n-- ))
      escreveLinha( VetorParaOrdenar, TAMANHO-n );

}
/******************************************************************************/
/* FUNCOES PARA SELECTION SORT ************************************************/
/******************************************************************************/
int pegaIndiceMenorValor( int v[], int indiceMenor ){

   int i;

   for( i = indiceMenor; i < TAMANHO; i++ )
      if( v[indiceMenor] < v[i] )
         indiceMenor = i;

   return indiceMenor;
}
/******************************************************************************/
void OrdenaMetodo_Selection( int VetorParaOrdenar[] ){

   int i, indiceMenor, valorTemporario;

   for( i = 0; i < TAMANHO; i++ ){
      escreveLinha( VetorParaOrdenar, TAMANHO-i );
      indiceMenor = pegaIndiceMenorValor( VetorParaOrdenar, i );
      if( indiceMenor != i ){
         valorTemporario                 = VetorParaOrdenar[ i ];
         VetorParaOrdenar[ i ]           = VetorParaOrdenar[ indiceMenor ];
         VetorParaOrdenar[ indiceMenor ] = valorTemporario;
      }
   }

}
/******************************************************************************/
/* FUNCOES PARA INSERTION SORT ************************************************/
/******************************************************************************/
void OrdenaMetodo_Insertion( int VetorParaOrdenar[] ){

   int Temporario;
   int i, x;
   
   for( i = 1; i < TAMANHO; i++ ){
      Temporario = VetorParaOrdenar[ i ];
      for( x = i; x > 0 && Temporario < VetorParaOrdenar[ x-1 ];x-- )
         VetorParaOrdenar[ x ] = VetorParaOrdenar[ x-1 ];
         
      VetorParaOrdenar[ x ] = Temporario;
   }

}
/******************************************************************************/
/* MAIN ***********************************************************************/
/******************************************************************************/
int main(){

    int Vetor[TAMANHO];

    PegaLinha( Vetor );

    //OrdenaMetodo_Bubble( Vetor );
    //OrdenaMetodo_Selection( Vetor );
    OrdenaMetodo_Insertion( Vetor );  
    escreveLinha( Vetor, TAMANHO );

    //printf( "\n\n Percorreu %d vezes o laco interno de ordenacao.", PercorreuTotalLacos );

    return 0;
}
