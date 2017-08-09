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
int TTree_Show( TTree Tree, int *Error ){

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

   if( TTree_Empty( Tree ) )
      *Error = ERROR_EMPTY_TREE;
   else{
      TNode_ShowLeaf( Tree.root );
      *Error = 0;
   }
   return !( *Error );
}
/******************************************************************************/
int TTree_Empties( TTree *Tree, int *Error ){

   if( TTree_Empty( *Tree ) )
      *Error = ERROR_EMPTY_TREE;
   else{
      Tree->root = TNode_Empties( Tree->root );
      *Error = 0;
   }
   return !( *Error );
}
/******************************************************************************/
TNode* TTree_GetMinor( TTree Tree, int *Error ){

   TNode *MinorNode;

   if( TTree_Empty( Tree ) ){
      *Error = ERROR_EMPTY_TREE;
      MinorNode = NULL;
   }else
      MinorNode = TNode_GetMinor( Tree.root );
   return MinorNode;
}
/******************************************************************************/
TNode* TTree_GetGreater( TTree Tree, int *Error ){

   TNode *GreaterNode;

   if( TTree_Empty( Tree ) ){
      *Error = ERROR_EMPTY_TREE;
      GreaterNode = NULL;
   }else
      GreaterNode = TNode_GetGreater( Tree.root );
   return GreaterNode;
}

/******************************************************************************/
key* TTree_GetElements( TTree Tree, int *Error, int Tamanho ){

   key *Array;
   int i;

   Array = (key*)malloc( Tamanho*sizeof( key ) );

   i = 0;
   if( TTree_Empty( Tree ) ){
      *Error = ERROR_EMPTY_TREE;
   }else
      TNode_GetElements( Tree.root, Array, &i );
   return Array;
}
/******************************************************************************/
int TTree_InfoExists( TTree Tree, key info, int *Error ){

   if( TTree_Empty( Tree ) )
      *Error = ERROR_EMPTY_TREE;
   else{
      *Error = 0;
      if( TNode_InfoExists( Tree.root, info ) )
         return TRUE;
   }
   return FALSE;
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
int TTree_CountLeaf( TTree Tree ){
   return TNode_CountLeaf( Tree.root );
}
/******************************************************************************/
int TTree_Height( TTree Tree ){
   return TNode_Height( Tree.root );
}
/******************************************************************************/
int TTree_LevelOf( TTree Tree, key Info ){
   return TNode_LevelOf( Tree.root, Info, 0 );
}
/******************************************************************************/
TNode* TTree_FatherOf( TTree Tree, key Info ){
   return TNode_FatherOf( Tree.root, Info );
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
void TTree_Insert( TTree *Tree, key Key ){
   TNode_Insert( &Tree->root, Key );
}
/******************************************************************************/
int TTree_IsClassified( TTree Tree, int *Error ){

   if( TTree_Empty( Tree ) ){
      *Error = ERROR_EMPTY_TREE;
      return FALSE;
   }
   *Error = 0;
   return TNode_IsClassified( Tree.root, 0 );
}
/******************************************************************************/
key TTree_GetNext( TTree Tree, key info, int *Error ){

   if( TTree_Empty( Tree ) ){
      *Error = ERROR_EMPTY_TREE;
      return FALSE;
   }
   *Error = 0;
   return TNode_GetNext( Tree.root, info );
}
/******************************************************************************/
void TTree_Balance( TTree *Tree ){
   Tree->root = TNode_Balance( Tree->root );
}
/******************************************************************************/

