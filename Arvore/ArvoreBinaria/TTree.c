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
int TTree_ShowPreOrder( TTree Tree, int *Error ){

   if( TTree_Empty( Tree ) )
      *Error = ERROR_EMPTY_TREE;
   else{
      TNode_ShowPreOrder( Tree.root );
      *Error = 0;
   }
   return !( *Error );
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
int TTree_ShowPostOrder( TTree Tree, int *Error ){

   if( TTree_Empty( Tree ) )
      *Error = ERROR_EMPTY_TREE;
   else{
      TNode_ShowPostOrder( Tree.root );
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
TNode* TTree_SeekByInfo( TTree *Tree, key info, int *Error ){
   
   TNode *Seek;
   
   if( TTree_Empty( *Tree ) )
      *Error = ERROR_EMPTY_TREE;
   else{
      *Error = 0;
      Seek = TNode_SeekInfo( Tree->root, info );
   }
   return Seek;
}
/******************************************************************************/
int TTree_SetRoot( TTree* Tree, TNode* Root, int *Error ){
   
   if( !TTree_Empty( *Tree ) )
      *Error = ERROR_EXISTING_ROOT;
   else{
      *Error = 0;
      Tree->root = Root;
   }
   return !(*Error);
}
/******************************************************************************/
int TTree_InsertNodeLeft( TTree* Tree, TNode* New, key Reference, int *Error ){

   TNode *Father;

   Father = TTree_SeekByInfo( Tree, Reference, Error );
   if( Father && !Father->left );
      Father->left = New;

   return !( *Error );
}
/******************************************************************************/
int TTree_InsertNodeRight( TTree* Tree, TNode* New, key Reference, int *Error ){

   TNode *Father;

   Father = TTree_SeekByInfo( Tree, Reference, Error );
   if( Father && !Father->right );
      Father->right = New;

   return !( *Error );
}
/******************************************************************************/

