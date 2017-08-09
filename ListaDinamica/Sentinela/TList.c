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

   List->sentinel = TNode_New( 0, 0 );
   List->first = List->sentinel;

}
/******************************************************************************
chave TList_GetNextKey( TList List ){
   
   TNode* Node;
   chave Next;
   
   Next = 1;
   Node = List.first;
   while( Node )
      if( Node->chave > Next )
         break;
      else if( Node->chave == Next )
         Node
         Next++;
   
}
/******************************************************************************/
int TList_Count( TList List ){
   
   TNode* p;
   int Size;
   
   p = List.first;
   for( Size = 0; p != List.sentinel; Size++ )
      p = p->next;

   return Size;
}
/******************************************************************************/
void TList_Show( TList List ){

   TNode* p;

   p = List.first;
   while( p != List.sentinel ){
      printf( "[%d/%d]", p->chave, p->info );
      p = p->next;
      if( p != List.sentinel )
         printf( ", " );
   }
}
/******************************************************************************/
TNode* TList_LastNode( TList List ){

   TNode* p;

   p = List.first;
   if(p == List.sentinel)
      return NULL;
   
   while( p->next != List.sentinel ){
      p = p->next;
   }

   return p;
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
TNode* TList_SeekNodeByKey( TList List, TNode* *Previous, chave Key ){

   TNode *p;

   *Previous = NULL;
   p = List.first;
   List.sentinel->chave = Key;
   while( p->chave < Key ){
      *Previous = p;
      p = p->next;
   }

   if( p != List.sentinel && p->chave == Key )
      return p;
      
   return NULL;
}
/******************************************************************************/
TNode* TList_SeekNodeByPosition( TList List, int Position ){

   TNode *p;
   int i;

   p = List.first;
   for( i = 1; i < Position; i++, p = p->next )
      if( p == List.sentinel )
         return NULL;

   return p;
}
/******************************************************************************/
void TList_InsertNodeOrder( TList *List, TNode *Node ){

   TNode *Previous, *Return;

   Return = TList_SeekNodeByKey( *List, &Previous, Node->chave );
   if( Return )
      printf( "\n Chave %d existente. Valor nao inserido", Return->chave );
   else{
      if( Previous ){
         Node->next = Previous->next;
         Previous->next = Node;
      }else{
         Node->next = List->first;
         List->first = Node;
      }
   }
}
/******************************************************************************
int TList_RemoveNodeByInfo( TList *List, int info ){

   TNode *Deleted, *ant;

   Deleted = TList_SeekNodeByInfo( *List, &ant, info );
   if( Deleted ){
      if( ant )
         ant->next = Deleted->next;
      else
         List->first = Deleted->next;
      free( Deleted );
      return TRUE;
   }
   return FALSE;
}
/******************************************************************************/
int TList_RemoveNodeByKey( TList *List, chave Key ){

   TNode *Deleted, *ant;

   Deleted = TList_SeekNodeByKey( *List, &ant, Key );
   if( Deleted ){
      if( ant )
         ant->next = Deleted->next;
      else
         List->first = Deleted->next;
      free( Deleted );
      return TRUE;
   }
   return FALSE;
}
/******************************************************************************/

