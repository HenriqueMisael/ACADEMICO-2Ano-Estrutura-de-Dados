/******************************************************************************/
#include "Standart.h"
#include "TTree.c"
/******************************************************************************/
void Mostra( TTree Arvore ){

   int Erro;

   printf( "\n--------------------" );
   printf( "\n Arvore: [%d]", TTree_Count( Arvore, &Erro ) );
   if( !TTree_ShowPostOrder( Arvore, &Erro ) )
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
void InsereRaiz( TTree *Arvore, key infoRaiz ){

   int Erro;

   if( !TTree_SetRoot( Arvore, TNode_New( infoRaiz ), &Erro ) )
      TTree_WriteError( Erro );

}
/******************************************************************************/
void InsereNoEsquerda( TTree *Arvore, key infoPai, key infoFilho ){

   int Erro;

   if( !TTree_InsertNodeLeft( Arvore, TNode_New( infoFilho ), infoPai, &Erro ) )
      TTree_WriteError( Erro );
}
/******************************************************************************/
void InsereNoDireita( TTree *Arvore, key infoPai, key infoFilho ){

   int Erro;

   if( !TTree_InsertNodeRight( Arvore, TNode_New( infoFilho ), infoPai, &Erro ) )
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
int main(){
   
   TTree Arvore;

   TTree_Initialize( &Arvore );

   InsereRaiz( &Arvore, 10 );

   InsereNoEsquerda( &Arvore, 10, 11 );
   InsereNoEsquerda( &Arvore, 11, 12 );
   InsereNoDireita( &Arvore, 12, 14 );
   InsereNoDireita( &Arvore , 10, 13 );
   InsereNoDireita( &Arvore, 13, 15 );
   InsereNoDireita( &Arvore, 15, 16 );
   InsereNoDireita( &Arvore, 16, 19 );
   InsereNoDireita( &Arvore, 19, 21 );
   InsereNoEsquerda( &Arvore, 19, 20 );
   InsereNoEsquerda( &Arvore, 16, 17 );
   InsereNoEsquerda( &Arvore, 17, 18 );
   InsereNoEsquerda( &Arvore, 20, 22 );
   InsereNoEsquerda( &Arvore, 15, 23 );

   Mostra( Arvore );
   Esvazia( &Arvore );
   Mostra( Arvore );
   Esvazia( &Arvore );
   //Altura( Arvore );
   //ContaFolhas( Arvore );
   //Nivel( Arvore, 14 );
   //PaiDe( Arvore, 9 );
   //Existe( Arvore, 10.5 );
   //MostraFolhas( Arvore );

   return 0;
}
/******************************************************************************/
