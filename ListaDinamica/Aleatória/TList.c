/******************************************************************************/
#include "TList.h"
/******************************************************************************/
TNode* TNode_New(){
   return (TNode*)malloc(sizeof(TNode));
}
/******************************************************************************/
void TList_Initialize( TList *List ){

   List->first = NULL;

}
/******************************************************************************/
void TList_Show( TList List ){

   TNode* p;

   p = List.first;
   while( p ){
      printf( "%d", p->info );
      p = p->next;
      if( p )
         printf( ", " );
   }
}
/******************************************************************************/
TNode* TList_LastNode( TList List ){

   TNode* p;

   p = List.first;
   if(p)
      while( p->next ){
         p = p->next;
      }

   return p;
}
/******************************************************************************/
TNode* TList_SeekNode( TList List, TNode* *ant, int info ){

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
void TList_InsertNodeTail( TList *List, int info ){

   TNode *Last, *Node = TNode_New();

   Last = TList_LastNode( *List );
   if( Last )
      Last->next = Node;
   else
      List->first = Node;

   Node->info = info;
   Node->next = NULL;
}
/******************************************************************************/
int TList_RemoveNodeByInfo( TList *List, int info ){

   TNode *Deleted, *ant;
   
   Deleted = TList_SeekNode( *List, &ant, info );
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

