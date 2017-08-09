/******************************************************************************/
#include "TStack.h"
/******************************************************************************/
TNode* TNode_New(){
   return (TNode*)malloc(sizeof(TNode));
}
/******************************************************************************/
void TStack_Initialize( TStack *Stack ){

   Stack->top = NULL;

}
/******************************************************************************/
void TStack_Show( TStack Stack ){

   TNode* p;

   p = Stack.top;
   while( p ){
      printf( "(%d,%d)", p->key, p->info );
      p = p->next;
      if( p )
         printf( ", " );
   }
}
/******************************************************************************/
void TStack_Pop( TStack *Stack, int key, int info ){

   TNode *Node = TNode_New();

   Node->info = info;
   Node->key = key;
   Node->next = Stack->top;
   Stack->top = Node;
}
/******************************************************************************/
TNode* TStack_Remove( TStack *Stack ){

   TNode *Node = Stack->top;

   if( Node )
      Stack->top = Node->next;
   
   return Node;
}
/******************************************************************************/
TNode* TStack_LastNode( TStack Stack ){

   TNode* p;

   p = Stack.top;
   while( p ){
      if( p->next )
         p = p->next;
      else
         break;
   }

   return p;
}
/******************************************************************************/
void TStack_FreeStack( TStack *Stack ){

   TNode *p, *next;

   p = Stack->top;
   if( !p )
      return;

   while( p->next ){
      next = p->next;
      free( p );
      p = next;
   }
}
/******************************************************************************/
int TStack_Count( TStack Stack ){

   TNode* p;
   int n;

   n = 0;
   p = Stack.top;
   
   while( p ){
      n++;
      if( p->next )
         p = p->next;
      else
         break;
   }

   return n;
}
