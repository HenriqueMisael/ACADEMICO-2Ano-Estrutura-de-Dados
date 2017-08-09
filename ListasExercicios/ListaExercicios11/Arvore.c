/******************************************************************************/
#include "Standart.h"
#include "TTree.c"
/******************************************************************************/
#define TAMANHO_INSERIR 10
/******************************************************************************/
void Mostra( TTree Arvore ){

   int Erro;

   printf( "\n--------------------" );
   printf( "\n Arvore: [%d]", TTree_Count( Arvore, &Erro ) );
   if( !TTree_ShowInOrder( Arvore, &Erro ) )
      TTree_WriteError( Erro );

}
/******************************************************************************/
void MostraMenor( TTree Arvore ){

   TNode* Menor;
   int Erro;

   Menor = TNode_GetMinor( Arvore.root );
   if( !Menor )
      printf( "\n vazia?" );
   else
      printf( "\n Menor: %d", Menor->info );

}
/******************************************************************************/
/* EXERCICIOS *****************************************************************/
/******************************************************************************/
void Exercicio1( TTree Arvore ){

   int Erro;

   printf( "\n--------------------" );
   printf( "\n Folhas:" );
   if( !TTree_ShowLeafs( Arvore, &Erro ) )
      TTree_WriteError( Erro );

}
/******************************************************************************/
void Exercicio2( TTree Arvore ){

   int Erro;

   printf( "\n--------------------" );
   printf( "\n Numeros pares: %d", TTree_CountPairInt( Arvore ) );
}
/******************************************************************************/
void Exercicio3( TTree Arvore ){

   int Erro;

   printf( "\n--------------------" );
   printf( "\n Nos com um unico filho: %d", TTree_CountFathersWithOneSon( Arvore ) );
}
/******************************************************************************/
void Exercicio4( TTree Original, TTree *Clonada ){

   *Clonada = TTree_Clone( Original );
}
/******************************************************************************/
void Exercicio5( TTree Arvore, int x ){

   int Erro;

   if( !TTree_ShowHigherThan( Arvore, x, &Erro ) )
      TTree_WriteError( Erro );
}
/******************************************************************************/
void Exercicio6( TTree *Arvore, int x ){
   TTree_InsertOrder( Arvore, x );
}
/******************************************************************************/
void Exercicio7( TTree *Arvore1, TTree *Arvore2, int Vetor1[TAMANHO_INSERIR], int Vetor2[TAMANHO_INSERIR] ){

   TTree_InsertVector( Arvore1, Vetor1, TAMANHO_INSERIR );
   TTree_InsertVector( Arvore2, Vetor2, TAMANHO_INSERIR );
   if( TTree_Compare( *Arvore1, *Arvore2 ) )
      printf( "\n As arvores sao equivalentes." );
   else
      printf( "\n As arvores nao sao equivalentes." );
}
/******************************************************************************/
void Exercicio8( TTree *Arvore ){

   key Removido;
   int Erro;

   Removido = TTree_RemoveMinor( Arvore, &Erro );
   if( !Removido )
      TTree_WriteError( Erro );
   else
      printf( "\n Removido: %d", Removido );

}
/******************************************************************************/
void Exercicio9( TTree Arvore ){

   if( TTree_Complete( Arvore ) )
      printf( "\n A arvore esta completa." );
   else
      printf( "\n A arvore nao esta completa." );
}
/******************************************************************************/
int main(){
   
   TTree Arvore, ArvoreClonada;

   TTree_Initialize( &Arvore );
   TTree_InsertVector( &Arvore, (int[]){8, 2, 5, 3, 1, 6, 10, 9, 7, 4 }, TAMANHO_INSERIR );
   Mostra( Arvore );
   Exercicio8( &Arvore );
   Mostra( Arvore );

   return 0;
}
/******************************************************************************/
