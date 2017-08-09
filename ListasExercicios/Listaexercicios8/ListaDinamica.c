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
void MostraLista( TList Lista ){

   printf( "\n-------------------------" );
	printf( "\n Completa (%d): ", TList_Count( Lista ) );
   TList_Show( Lista );
   printf( "\n-------------------------" );
   
}
/******************************************************************************/
void RemoveElementos( TList *Lista, Palavra Nome ){
	
	printf( "\n Removeu %d elementos.", TList_RemoveNodeByName( Lista, Nome ) );
}
/******************************************************************************/
void InsereElemento( TList *Lista, Palavra Nome, Palavra Endereco, int Idade, int Index ){

   Pessoa* NewNode;

	NewNode = Pessoa_New( Nome, Endereco, Idade );
   TList_InsertNodeIndex( Lista, NewNode, Index );
   printf( "\n Inseriu: " );
	TNode_Show( *TNode_New( NewNode ) );
}
/******************************************************************************/
void Pesquisar( TList Lista, Palavra Nome ){
   /*
      Equivalente à função pesquisar() do exercício 1e
   */
   TNode* NoAnterior;
   
   NoAnterior = TList_GetPreviousNode( Lista, Nome );
   if( NoAnterior ){
      printf( "\n " );
      TNode_Show( *NoAnterior->next );
   }else
      printf( "\n %s nao esta na lista.", Nome );
}
/******************************************************************************/
int GetFileSize( FILE *File ){
   
   if( !File )
      return 0;

   fseek(File, 0, SEEK_END);
   return ftell( File );
   fseek(File, 0, SEEK_SET);
}
/******************************************************************************/
int main(){
   
   TList Lista;

   TList_Initialize( &Lista );
   /**********************************************
   *comp()           = TList_GetPreviousNode()
   *compPessoa()     = TList_HasInfo()
   *inserir()        = TList_InsertNodeIndex()
   *remover()        = TList_RemoveNodeByName()
   *pesquisar()      = Pesquisar()
   *mostrar()        = TList_Show()
   *mostrarInvert()  = TList_ShowReverse()
   *limpar()         = TList_Empties()
   *salvar()         = TList_WriteOnFile()
   *importar()       = TList_ImportFromFile()
   *conjunto()       = TList_RemoveDuplicated()
   **********************************************/

   return 0;
}
/******************************************************************************/
