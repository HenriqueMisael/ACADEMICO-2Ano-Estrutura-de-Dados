/******************************************************************************/
#include "TList.c"
/******************************************************************************/
void MostraLista( TList Lista ){
   printf( "\n Completa: " );
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

   if( !Chave )
      Chave = TLista_GetNextey( *Lista );

   TList_InsertNodeOrder( Lista, TNode_New( Chave, info ) );
}
/******************************************************************************/
int main(){
   
   TList Lista;
   TNode *Previous;
   
   TList_Initialize( &Lista );
   TList_InsertNodeOrder( &Lista, TNode_New( 3, 30, NULL ) );
   TList_InsertNodeOrder( &Lista, TNode_New( 1, 10, NULL ) );
   TList_InsertNodeOrder( &Lista, TNode_New( 2, 20, NULL ) );
   RemoveElemento( &Lista, 2 );
   RemoveElemento( &Lista, 2 );
   RemoveElemento( &Lista, 1 );
   RemoveElemento( &Lista, 3 );
   MostraLista( Lista );

   return 0;
}
/******************************************************************************/
