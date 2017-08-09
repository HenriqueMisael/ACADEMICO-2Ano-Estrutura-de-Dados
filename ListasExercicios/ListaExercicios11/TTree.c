/******************************************************************************/
#include "TTree.h"
/******************************************************************************/
void TTree_Initialize( TTree* Tree ){
   Tree->root = NULL;
}
/******************************************************************************/
void TTree_WriteError( int Error ){

   switch( Error ){
      case ERROR_EXISTING_ROOT: printf( "\n A arvore ja possui raiz." );
      case ERROR_EMPTY_TREE   : printf( "\n A arvore esta vazia." );
   }

}
/******************************************************************************/
int TTree_Empty( TTree Tree ){
   
   if( Tree.root )
      return FALSE;
   return TRUE;
}
/******************************************************************************/
int TTree_Complete( TTree Tree ){
   
   return TNode_Complete( Tree.root );
}
/******************************************************************************/
int TTree_ShowHigherThan( TTree Tree, int x, int *Error ){
   
   if( TTree_Empty( Tree ) )
      *Error = ERROR_EMPTY_TREE;
   else{
      *Error = 0;
      TNode_ShowHigherThan( Tree.root, x );
   }
   return !(*Error);
}
/******************************************************************************/
int TTree_ShowInOrder( TTree Tree, int *Error ){

   if( TTree_Empty( Tree ) )
      *Error = ERROR_EMPTY_TREE;
   else{
      TNode_ShowInOrder( Tree.root );
      *Error = 0;
   }
   return !( *Error );
}
/******************************************************************************/
int TTree_ShowLeafs( TTree Tree, int *Error ){
   /*
      Exercício 1
   */

   if( TTree_Empty( Tree ) )
      *Error = ERROR_EMPTY_TREE;
   else{
      TNode_ShowLeaf( Tree.root );
      *Error = 0;
   }
   return !( *Error );
}
/******************************************************************************/
int TTree_Count( TTree Tree, int *Error ){

   int Count;

   if( TTree_Empty( Tree ) ){
      *Error = ERROR_EMPTY_TREE;
      Count = 0;
   }else{
      *Error = 0;
      Count = TNode_Count( Tree.root );
   }

   return Count;
}
/******************************************************************************/
int TTree_CountPairInt( TTree Tree ){
   return TNode_CountPairInt( Tree.root );
}
/******************************************************************************/
int TTree_CountFathersWithOneSon( TTree Tree ){
   return TNode_CountFathersWithOneSon( Tree.root );
}
/******************************************************************************/
int TTree_RemoveMinor( TTree *Tree, int *Error ){

   TNode *MinorNode;
   key Minor;

   if( TTree_Empty( *Tree ) ){
      *Error = ERROR_EMPTY_TREE;
      Minor = 0;
   }else{
      *Error = 0;
      Minor = TNode_GetMinor( Tree->root )->info;
      Tree->root = TNode_Remove( Tree->root, Minor );
   }
   TTree_ShowInOrder( *Tree, Error );
   return Minor;
}
/******************************************************************************/
TNode* TTree_SeekByInfo( TTree Tree, key info, int *Error ){
   
   TNode *Seek;

   if( TTree_Empty( Tree ) ){
      *Error = ERROR_EMPTY_TREE;
      Seek = NULL;
   }else{
      *Error = 0;
      Seek = TNode_SeekInfo( Tree.root, info );
   }
   return Seek;
}
/******************************************************************************/
void TTree_InsertOrder( TTree* Tree, key Key ){

   if( TTree_Empty( *Tree ) )
      Tree->root = TNode_New( Key );
   else
      TNode_Insert( Tree->root, Key );
}
/******************************************************************************/
void TTree_InsertVector( TTree* Tree, int Vector[], int Size ){
   
   int i;
   
   for( i = 0; i < Size; i++ )
      TTree_InsertOrder( Tree, Vector[i] );
}
/******************************************************************************/
TTree TTree_Clone( TTree Tree ){

   TTree Clone;

   Clone.root = TNode_Clone( Tree.root );
   return Clone;
}
/******************************************************************************/
int TTree_Compare( TTree First, TTree Second ){
   
   return TNode_Compare( First.root, Second.root );
}
/******************************************************************************/

