/******************************************************************************/
#include "TNode.h"
/******************************************************************************/
TNode* TNode_New( key Information ){

   TNode* New;

   New = (TNode*)malloc( sizeof( TNode ) );
   New->info  = Information;
   New->left  = NULL;
   New->right = NULL;

   return New;
}
/******************************************************************************/
void TNode_ShowInOrder( TNode *Node ){

   if( Node ){
      TNode_ShowInOrder( Node->left );
      printf( "\n %d", Node->info );
      TNode_ShowInOrder( Node->right );
   }
}
/******************************************************************************/
void TNode_ShowPreOrder( TNode *Node ){

   if( Node ){
      printf( "\n %d", Node->info );
      TNode_ShowPreOrder( Node->left );
      TNode_ShowPreOrder( Node->right );
   }
}
/******************************************************************************/
void TNode_ShowPostOrder( TNode *Node ){

   if( Node ){
      TNode_ShowPostOrder( Node->left );
      TNode_ShowPostOrder( Node->right );
      printf( "\n %d", Node->info );
   }
}
/******************************************************************************/
TNode* TNode_SeekInfo( TNode *Node, key info ){

   TNode* Seek;

   if( !Node )
      Seek = NULL;
   else if( Node->info == info )
      Seek = Node;
   else if( Node->info > info )
      Seek = TNode_SeekInfo( Node->left, info );
   else if( Node->info < info )
      Seek = TNode_SeekInfo( Node->right, info );
      
   return Seek;
}
/******************************************************************************/
int TNode_InfoExists( TNode *Node, key info ){

   int Return;

   if( Node ){
      Return = TNode_InfoExists( Node->left, info );
      if( !Return ){
         Return = TNode_InfoExists( Node->right, info );
         if( !Return && Node->info == info )
            Return = TRUE;
      }
   }else
      Return = FALSE;
   return Return;
}
/******************************************************************************/
void TNode_ShowLeaf( TNode *Node ){

   if( Node )
      if( !Node->left && !Node->right )
         printf( "\n %d", Node->info );
      else{
         TNode_ShowLeaf( Node->left );
         TNode_ShowLeaf( Node->right );
      }
}
/******************************************************************************/
int TNode_Count( TNode* Node ){

   if( Node )
      return 1+TNode_Count( Node->left ) + TNode_Count( Node->right );
   return 0;
}
/******************************************************************************/
int TNode_CountLeaf( TNode* Node ){

   int Count;

   if( !Node )
      Count = 0;
   else if( !Node->left && !Node->right )
      Count = 1;
   else{
      Count = TNode_CountLeaf( Node->left );
      Count += TNode_CountLeaf( Node->right );
   }

   return Count;
}
/******************************************************************************/
int TNode_Height( TNode* Node ){

   int HeightLeft, HeightRight;

   if( !Node )
      return 0;

   HeightLeft  = TNode_Height( Node->left );
   HeightRight = TNode_Height( Node->right );

   if( HeightRight++ > HeightLeft++ )
      return HeightRight;

   return HeightLeft;
}
/******************************************************************************/
int TNode_LevelOf( TNode* Node, key Info, int Level ){

   int NewLevel;

   if( !Node )
      return -1;
   if( Node->info == Info )
      return Level;

   NewLevel = TNode_LevelOf( Node->left, Info, Level+1 );
   if( NewLevel == -1 )
      NewLevel = TNode_LevelOf( Node->right, Info, Level+1 );
   return NewLevel;
}
/******************************************************************************/
TNode* TNode_FatherOf( TNode* Node, key Info ){

   TNode* Father;

   if( !Node )
      Father = NULL;
   else if( ( Node->left && Node->left->info == Info ) || ( Node->right && Node->right->info == Info ) )
      Father = Node;
   else{
      Father = TNode_FatherOf( Node->left, Info );
      if( !Father )
         Father = TNode_FatherOf( Node->right, Info );
   }
   return Father;
}
/******************************************************************************/
TNode* TNode_Empties( TNode *Node ){

   if( Node ){
      Node->left = TNode_Empties( Node->left );
      Node->right = TNode_Empties( Node->right );
   }
   return NULL;
}
/******************************************************************************/
TNode* TNode_GetMinor( TNode *Node ){

   if( Node->left )
      return TNode_GetMinor( Node->left );

   return Node;
}
/******************************************************************************/
TNode* TNode_GetGreater( TNode *Node ){

   if( Node->right )
      return TNode_GetGreater( Node->right );

   return Node;
}
/******************************************************************************/
key TNode_GetMinorKey( TNode *Node ){
   TNode* Minor = TNode_GetMinor( Node );
   if( Minor )
      return Minor->info;
   return 0;
}
/******************************************************************************/
key TNode_GetGreaterKey( TNode *Node ){
   TNode* Greater = TNode_GetGreater( Node );
   if( Greater )
      return Greater->info;
   return 0;
}
/******************************************************************************/
TNode* TNode_GetElements( TNode *Node, key Array[], int *i ){

   if( Node ){
      TNode_GetElements( Node->left, Array, i );
      Array[(*i)++] = Node->info;
      TNode_GetElements( Node->right, Array, i );
   }

   return Node;
}
/******************************************************************************/
int TNode_IsClassified( TNode *Node, key Bigger ){

   int Return;

   if( Node ){
      Return = TNode_IsClassified( Node->left, Node->info );
      if( Return )
         Return = TNode_IsClassified( Node->right, Node->info );
      if( Return )
         if( Node->left && Node->left->info > Node->info )
            Return = FALSE;
         else if( Node->right && Node->right->info < Node->info )
            Return = FALSE;
         else if( Bigger && Node->info > Bigger )
            Return = FALSE;
   }else Return = TRUE;

   return Return;
}
/******************************************************************************/
void TNode_Insert( TNode *Node, key Key ){
   
   if( Node )
      if( Key > Node->info )
         if( Node->right )
            TNode_Insert( Node->right, Key );
         else
            Node->right = TNode_New( Key );
      else if( Key < Node->info )
         if( Node->left )
            TNode_Insert( Node->left, Key );
         else
            Node->left = TNode_New( Key );
}
/******************************************************************************/
int TNode_GetNext( TNode *Node, key Key ){
   
   key Next;

   if( Node ){
      Next = TNode_GetNext( Node->left, Key );
      if( Next <= Key )
         if( Node->info > Key )
            Next = Node->info;
         else
            Next = TNode_GetNext( Node->right, Key );
   }else
      Next = Key;
   return Next;
}
/******************************************************************************/