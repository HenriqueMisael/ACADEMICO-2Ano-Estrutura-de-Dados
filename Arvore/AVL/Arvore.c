/******************************************************************************/
#include "Standart.h"
#include "TTree.c"
/******************************************************************************/
void Mostra( TTree Arvore ){

   int Erro;

   printf( "\n--------------------" );
   printf( "\n Arvore: [%d]", TTree_Count( Arvore, &Erro ) );
   if( !TTree_Show( Arvore, &Erro ) )
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
   TTree_Insert( &Arvore, 100 );
   TTree_Insert( &Arvore, 120 );
   TTree_Insert( &Arvore, 150 );
   TTree_Insert( &Arvore, 30 );
   TTree_Insert( &Arvore, 35 );
   Mostra( Arvore );

   return 0;
}
/******************************************************************************/
