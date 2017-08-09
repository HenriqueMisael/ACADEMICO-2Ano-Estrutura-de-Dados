/******************************************************************************/
#include "Standart.h"
#include "TTree.c"
/******************************************************************************/
void Mostra( TTree Arvore ){

   int Erro;

   printf( "\n--------------------" );
   printf( "\n Arvore: [%d]", TTree_Count( Arvore, &Erro ) );
   if( !TTree_ShowInOrder( Arvore, &Erro ) )
      TTree_WriteError( Erro );

}
/******************************************************************************/
void Esvazia( TTree *Arvore ){

   int Erro;

   if( !TTree_Empties( Arvore, &Erro ) )
      TTree_WriteError( Erro );

}
/******************************************************************************/
void MostraFolhas( TTree Arvore ){

   int Erro;

   printf( "\n--------------------" );
   printf( "\n Folhas:" );
   if( !TTree_ShowLeafs( Arvore, &Erro ) )
      TTree_WriteError( Erro );

}
/******************************************************************************/
void Altura( TTree Arvore ){
   printf( "\n Altura: %d.", TTree_Height( Arvore ) );
}
/******************************************************************************/
void ContaFolhas( TTree Arvore ){
   printf( "\n Folhas: %d.", TTree_CountLeaf( Arvore ) );
}
/******************************************************************************/
void Nivel( TTree Arvore, key Info ){
   printf( "\n Nivel do no %d: %d.", Info, TTree_LevelOf( Arvore, Info ) );
}
/******************************************************************************/
void PaiDe( TTree Arvore, key Info ){
   
   TNode* Pai;
   
   Pai = TTree_FatherOf( Arvore, Info );
   if( Pai )
      printf( "\n O pai de %d e %d.", Info, Pai->info );
   else if( Arvore.root->info == Info )
      printf( "\n %d e raiz.", Info );
   else
      printf( "\n %d nao esta na arvore.", Info );
}
/******************************************************************************/
void Existe( TTree Arvore, key info ){
   
   int Erro;

   if( TTree_InfoExists( Arvore, info, &Erro ) )
      if( Erro )
         TTree_WriteError( Erro );
      else
         printf( "\n %d esta na arvore.", info );
   else
      printf( "\n %d nao esta na arvore.", info );
}
/******************************************************************************/
void Menor( TTree Arvore ){

   TNode *Menor;
   int Erro;

   Menor = TTree_GetMinor( Arvore, &Erro );
   if( Menor )
      printf( "\n Menor elemento: %d", Menor->info );
   else
      TTree_WriteError( Erro );
}
/******************************************************************************/
void Maior( TTree Arvore ){

   TNode *Greater;
   int Erro;

   Greater = TTree_GetGreater( Arvore, &Erro );
   if( Greater )
      printf( "\n Maior elemento: %d", Greater->info );
   else
      TTree_WriteError( Erro );
}
/******************************************************************************/
void ArvoreBusca( TTree Arvore ){

   int Erro;

   if( TTree_IsClassified( Arvore, &Erro ) )
      printf( "\n Arvore de busca." );
   else
      if( Erro )
         TTree_WriteError( Erro );
      else
         printf( "\n Nao e arvore de busca" );
}
/******************************************************************************/
int main(){
   
   TTree Arvore;
   key *Vetor;
   int Erro, Tamanho, i;

   TTree_Initialize( &Arvore );
   Maior( Arvore );
   TTree_Insert( &Arvore, 30 );
   TTree_Insert( &Arvore, 20 );
   TTree_Insert( &Arvore, 40 );
   TTree_Insert( &Arvore, 60 );
   TTree_Insert( &Arvore, 45 );
   TTree_Insert( &Arvore, 50 );
   TTree_Insert( &Arvore, 10 );
   TTree_Insert( &Arvore, -5 );
   TTree_Insert( &Arvore, 98 );
   TTree_Insert( &Arvore, 42 );
   TTree_Insert( &Arvore, -17);
   TTree_Insert( &Arvore, -2 );
   TTree_Insert( &Arvore, 11 );
   Mostra( Arvore );
   Maior( Arvore );

   i = TTree_GetNext( Arvore, 42, &Erro );
   if( i )
      printf( "\n Proximo: %d", i );
   else
      TTree_WriteError( Erro );

/*
   printf( "\n" );
   Tamanho = TTree_Count( Arvore, &Erro );
   Vetor = TTree_GetElements( Arvore, &Erro, Tamanho );
   if( Erro )
      TTree_WriteError( Erro );
   else
      for( i = 0; i < Tamanho; i++ )
         printf( "%d ", Vetor[i] );

   return 0;
*/
}
/******************************************************************************/
