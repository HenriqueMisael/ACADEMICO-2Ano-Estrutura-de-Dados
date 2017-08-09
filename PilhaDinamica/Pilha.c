/******************************************************************************/
#include "TStack.c"
/******************************************************************************/
void MostraLista( TStack Pilha ){
   printf( "\n Completa: " );
   TStack_Show( Pilha );
}
/******************************************************************************/
void Conta( TStack Pilha ){
   printf( "\n Tem %d nos.", TStack_Count( Pilha ) );
}
/******************************************************************************/
int main(){
   
   TStack Pilha;
   TNode* Removed;
   
   TStack_Initialize( &Pilha );

   TStack_Pop( &Pilha, 1, 10 );
   TStack_Pop( &Pilha, 2, 13 );
   TStack_Pop( &Pilha, 2, 13 );
   TStack_Pop( &Pilha, 2, 13 );
   TStack_Pop( &Pilha, 2, 13 );
   MostraLista( Pilha );
   TStack_FreeStack( &Pilha );
   MostraLista( Pilha );

   return 0;
}
/******************************************************************************/
