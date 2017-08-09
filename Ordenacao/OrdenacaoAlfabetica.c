#include <stdio.h>
#include <string.h>
/******************************************************************************/
#define TAMANHO      9
#define TAMANHO_NOME 15
/******************************************************************************/
typedef char Pessoa[30];
/******************************************************************************/
/* FUNCOES PARA USO GERAL *****************************************************/
/******************************************************************************/
void escreveLista( Pessoa v[] ){

    int i;

    for( i = 0; i < TAMANHO; i++ ){
       printf( "\n%s", v[i] );
    }
}
/******************************************************************************/
void PegaLista( Pessoa v[]){

    int i;


    for( i = 0; i < TAMANHO; i++ ){
        gets( v[i] );
        system( "CLS" );
    }
}
/******************************************************************************/
/* FUNCOES PARA INSERTION SORT ************************************************/
/******************************************************************************/
void OrdenaMetodo_Insertion( Pessoa VetorParaOrdenar[] ){

   Pessoa Temporario;
   int i, x;
   
   for( i = 1; i < TAMANHO; i++ ){
      strcpy( Temporario, VetorParaOrdenar[ i ] );
      for( x = i; x > 0 && strcmp( Temporario, VetorParaOrdenar[ x-1 ] ) < 0;x-- )
         strcpy( VetorParaOrdenar[ x ], VetorParaOrdenar[ x-1 ] );
         
      strcpy( VetorParaOrdenar[ x ], Temporario );
   }

}
/******************************************************************************/
/* MAIN ***********************************************************************/
/******************************************************************************/
int main(){

    Pessoa Vetor[TAMANHO];

    PegaLista( Vetor );

    OrdenaMetodo_Insertion( Vetor );  
    escreveLista( Vetor );

    return 0;
}
