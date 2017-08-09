/******************************************************************************/
#include "TList.c"
/******************************************************************************/
TNode* PrimeiroElemento( TList Lista ){

   if( !TList_Empty( Lista ) )
      return Lista.head->next;

   printf( "\n Lista vazia" );
   return NULL;
}
/******************************************************************************/
TNode* UltimoElemento( TList Lista ){

   TNode* Last;

   Last = TList_LastNode( Lista );
   if( Last )
      printf( "\n Ultimo: [%d/%d]", Last->chave, Last->info );
   else
      printf( "\n Lista vazia" );
      
   return Last;
}
/******************************************************************************/
void MostraLista( TList Lista ){

   printf( "\n Completa (%d): ", TList_Count( Lista ) );
   TList_Show( Lista );
   
}
/******************************************************************************/
void RemoveElemento( TList *Lista, chave Chave ){
   MostraLista( *Lista );
   if( TList_RemoveNodeByKey( Lista, Chave ) )
      printf( "\n Removido: %d.", Chave );
   else
      printf( "\n Chave %d nao encontrada para remocao.", Chave );
}
/******************************************************************************/
void InsereElemento( TList *Lista, chave Chave, int info ){

   TNode* NewNode;

//   if( !Chave )
//      Chave = TLista_GetNextey( *Lista );

   NewNode = TNode_New( Chave, info );
   TList_InsertNodeOrder( Lista, NewNode );
   printf( "\n Inseriu [%d/%d].", NewNode->chave, NewNode->info );
}
/******************************************************************************/
int main(){
   
   TList Lista;

   TList_Initialize( &Lista );
   InsereElemento( &Lista, 3, 20 );
   InsereElemento( &Lista, 1, 10 );
   InsereElemento( &Lista, 4, 25 );
   InsereElemento( &Lista, 2, 15 );
   InsereElemento( &Lista, 5, 30 );
   MostraLista( Lista );
   TList_ReverseInformation( &Lista );
   MostraLista( Lista );

   return 0;
}
/******************************************************************************/
