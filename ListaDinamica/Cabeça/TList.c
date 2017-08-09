/******************************************************************************/
#include "TList.h"
/******************************************************************************/
TNode* TNode_New( chave key, int info ){
   TNode *NewNode;

   NewNode = (TNode*)malloc(sizeof(TNode));
   NewNode->chave = key;
   NewNode->info = info;
   
   return NewNode;
}
/******************************************************************************/
void TList_Initialize( TList *List ){

   List->head = TNode_New( 0, 0 );
   List->head->next = List->head;
   List->head->prev = List->head;

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

   TNode* p;

   p = List.head->next;
   while( p != List.head ){
      printf( "[%d/%d]", p->chave, p->info );
      p = p->next;
      if( p != List.head )
         printf( ", " );
   }
}
/******************************************************************************/
void TList_ShowReverse( TList List ){

   TNode* p;

   p = List.head->prev;
   while( p != List.head ){
      printf( "[%d/%d]", p->chave, p->info );
      p = p->prev;
      if( p != List.head )
         printf( ", " );
   }
}
/******************************************************************************/
TNode* TList_LastNode( TList List ){

   TNode* p;

   if( TList_Empty( List ) )
      return NULL;
   
   return List.head->prev;
}
/******************************************************************************
TNode* TList_SeekNodeByInfo( TList List, TNode* *ant, int info ){

   TNode* p;

   *ant = NULL;
   p = List.first;
   while( p ){
      if( p->info == info )
         return p;
      *ant = p;
      p = p->next;
   }

   return NULL;
}
/******************************************************************************/
void TList_Empties( TList *List ){
   
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
TNode* TList_SeekNodeByKey( TList List, TNode* *Previous, chave Key ){

   TNode *p;

   *Previous = List.head;
   p = List.head->next;
   List.head->chave = Key;
   while( p->chave < Key ){
      *Previous = p;
      p = p->next;
   }

   if( p != List.head && p->chave == Key )
      return p;
      
   return NULL;
}
/******************************************************************************/
TNode* TList_SeekNodeByPosition( TList List, int Position ){

   TNode *p;
   int i;

   p = List.head->next;
   for( i = 1; i < Position; i++, p = p->next )
      if( p == List.head )
         return NULL;

   return p;
}
/******************************************************************************/
void TList_InsertNodeOrder( TList *List, TNode *Node ){

   TNode *Previous, *Return;

   Return = TList_SeekNodeByKey( *List, &Previous, Node->chave );
   if( Return ){
      printf( "\n Chave %d existente. Valor nao inserido", Return->chave );
      free( Node );
   }else{
      Node->next = Previous->next;
      Node->next->prev = Node;
      Node->prev = Previous;
      Node->prev->next = Node;
   }
}
/******************************************************************************/
int TList_RemoveNodeByKey( TList *List, chave Key ){

   TNode *Deleted, *ant;

   Deleted = TList_SeekNodeByKey( *List, &ant, Key );
   if( Deleted ){
      ant->next       = Deleted->next;
      ant->next->prev = Deleted->prev;
      free( Deleted );
      return TRUE;
   }
   return FALSE;
}
/******************************************************************************/
void TList_ReverseInformation( TList *List ){
   
   TNode *Left, *Right;
   chave TempKey;
   int TempInfo, i, HalfSize;
   
   Left  = List->head->next; //First node
   Right = List->head->prev; //First node
   
   HalfSize = TList_Count( *List )/2;

   for( i = 0; i < HalfSize; i++ ){
   //while( Left != Right  ){
      TempKey  = Right->chave;
      TempInfo = Right->info;
      
      Right->chave = Left->chave;
      Right->info  = Left->info;
      
      Left->chave = TempKey;
      Left->info  = TempInfo;

      Left  = Left->next;
      Right = Right->prev;
   }
}
/******************************************************************************/

