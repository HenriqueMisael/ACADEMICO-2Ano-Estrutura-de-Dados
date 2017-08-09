/******************************************************************************/
#include "TList.h"
/******************************************************************************/
Pessoa* Pessoa_New( Palavra Nome, Palavra Endereco, int Idade ){
	
	Pessoa *New;
	
	New = (Pessoa*)malloc(sizeof(Pessoa));
   strcpy( New->nome, Nome );
   strcpy( New->endereco, Endereco );
   New->idade = Idade;
	
	return New;
}
/******************************************************************************/
TNode* TNode_New( Pessoa *Info ){
   
   TNode *NewNode;

   NewNode = (TNode*)malloc(sizeof(TNode));
   NewNode->info = Info;
   
   return NewNode;
}
/******************************************************************************/
void TNode_Show( TNode Node ){

	printf( "%s, %d anos\t%s", Node.info->nome, Node.info->idade, Node.info->endereco );
}
/******************************************************************************/
void TList_Initialize( TList *List ){

   List->head = TNode_New( Pessoa_New( "", "", 0 ) );
   List->head->next = List->head;

}
/******************************************************************************/
int TList_HasInfo( TList List, Pessoa *Info ){

	/*
		Equivalente à função compPessoa() do exercício 1b
	*/
	TNode *p;

   p = List.head->next;
   List.head->info = Info;
   while( strcmp( p->info->nome	  , Info->nome     ) ||
			 strcmp( p->info->endereco, Info->endereco ) ||
			 p->info->idade != Info->idade )
      p = p->next;

   if( p == List.head )
		return FALSE;
	return TRUE;

}
/******************************************************************************/
int TList_Empty( TList List ){
   return List.head == List.head->next;
}
/******************************************************************************/
int TList_Count( TList List ){
   
   TNode* p;
   int Size;
   
   p = List.head->next;
   for( Size = 0; p != List.head; Size++ )
      p = p->next;

   return Size;
}
/******************************************************************************/
void TList_Show( TList List ){
   /*
      Equivalente à função mostrar() do exercício 1f
   */
   TNode* p;

   p = List.head->next;
   while( p != List.head ){
		printf( "\n" );
      TNode_Show( *p );
      p = p->next;
   }
}
/******************************************************************************/
Pessoa* *TList_GetInfoArray( TList List, int FirstXNodes ){

   Pessoa* *Temp;
   TNode* p;
   int i;

   Temp = (Pessoa**)malloc( sizeof( Pessoa )*FirstXNodes );
   p = List.head->next;
   i = 0;

   while( p != List.head && i < FirstXNodes ){
      Temp[ i++ ] = p->info;
      p = p->next;
   }

   return Temp;
}
/******************************************************************************/
void TList_ShowReverse( TList List ){

   Pessoa* *InfoArray;
   int Size;

   Size = TList_Count( List );
   InfoArray = TList_GetInfoArray( List, Size );
   while( Size ){
      printf( "\n" );
      TNode_Show( *TNode_New( InfoArray[--Size] ) );
   }
}
/******************************************************************************/
int TList_WriteOnFile( TList *List, FILE *File ){
   /*
      Equivalente à função salvar() do exercício 1i
   */
   TNode *p;
   
   p = List->head->next;
   while( p != List->head )
      if( fwrite( p->info, sizeof( Pessoa ), 1, File ) != 1)
         return FALSE;
      else
         p = p->next;
   return TRUE;
}
/******************************************************************************/
void TList_ImportFromFile( TList *List, FILE *File ){
   /*
      Equivalente à função importar() do exercício 1j
   */
   Pessoa *Temp; //Cria um vetor Dinamico, pois o cálculo para o número de
   int numberOfNodesOnFile; //posições que precisaremos será feito posteriormente
   int i;

   numberOfNodesOnFile = GetFileSize( File )/sizeof(Pessoa);
   Temp = (Pessoa*)malloc( sizeof( Pessoa )*numberOfNodesOnFile );
   
   fread( Temp, sizeof( Pessoa ), numberOfNodesOnFile, File );
   for( i = 0; i < numberOfNodesOnFile; i++ ){
      TList_InsertNodeIndex( List, Pessoa_New( Temp[i].nome, Temp[i].endereco, Temp[i].idade ), i );
   }
   free( Temp );
}
/******************************************************************************/
TNode* TList_LastNode( TList List ){

   TNode* p;

   p = List.head->next;
   while( p->next != List.head )
      p = p->next;

	if( p == List.head )
		return NULL;
   return p;
}
/******************************************************************************/
void TList_RemoveNode( TList *List, TNode *Previous ){

   TNode *Remove;

   Remove = Previous->next;
	Previous->next = Previous->next->next;
	free( Remove );
}
/******************************************************************************/
void TList_Empties( TList *List ){
   /*
      Equivalente à função limpar() do exercício 1h
   */
   TNode* p;
   
   p = List->head->next;
   while( p != List->head ){
      List->head->next = p->next;
      free( p );
      p = List->head->next;
   }
   List->head->next = List->head;
}
/******************************************************************************/
void TList_RemoveDuplicated( TList *List ){
   /*
      Equivalente à função conjunto() do exercício 1k
   */
   TList Temp;
   TNode *p, *Previous;

   TList_Initialize( &Temp );

   Previous = List->head;
   p = Previous->next;

   while( p != List->head ){
      if( TList_HasInfo( Temp, p->info ) ){
         TList_RemoveNode( List, Previous );
         p = Previous->next;
      }else{
         TList_InsertNodeIndex( &Temp, p->info, 1 );
         Previous = p;
         p = p->next;
      }
   }
}
/******************************************************************************/
int TList_InsertNodeIndex( TList *List, Pessoa *Info, int Index ){
	/*
		Equivalente à função inserir() do exercício 1c
	*/
	TNode *New, *previous;

   previous = List->head;
   while( Index-- )
      if( previous->next == List->head )
         break;
      else{
         previous = previous->next;
      }
   New = TNode_New( Info );
	New->next = previous->next;
	previous->next = New;

   return TRUE;
}
/******************************************************************************/
TNode* TList_GetPreviousNode( TList List, Palavra Nome ){
	/*
		Equivalente à função comp() do exercício 1a
	*/
   TNode *p, *Previous;

   Previous = List.head;
   p = List.head->next;
   strcpy( List.head->info->nome, Nome );
   while( strcmp( p->info->nome, Nome ) ){
      Previous = p;
      p = p->next;
   }

   if( p != List.head )
      return Previous;

   return NULL;
}
/******************************************************************************/
int TList_RemoveNodeByName( TList *List, Palavra Nome ){

	/*
		Equivalente à função remover() do exercício 1d
	*/	
	TNode *PreviousRemove;
	TNode *Remove;
	int n;
	
	n = 0;
	PreviousRemove = TList_GetPreviousNode( *List, Nome );
	while( PreviousRemove ){
      TList_RemoveNode( List, PreviousRemove );
		n++;
      PreviousRemove = TList_GetPreviousNode( *List, Nome );
	}
	return n;
}
/******************************************************************************/
















