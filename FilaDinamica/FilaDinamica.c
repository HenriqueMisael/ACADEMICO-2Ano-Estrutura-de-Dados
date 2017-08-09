/******************************************************************************/
#include "TFila.c"
/******************************************************************************/
void Povoar( TFila *Fila ){
   
   info Nome;
   char Finalizar;
   
   do{
      printf( "\n\n Digite um nome: " );
      scanf( "%s", Nome );
      
      TFila_Insere( Fila, Nome );
      printf( " Finalizar insercao? (S/ )" );
      Finalizar = getch();
   }while( Finalizar != 'S' );
}
/******************************************************************************/
int main(){
   
   TFila Fila;
   TNo *No;
   
   TFila_Inicializa( &Fila );
   Povoar( &Fila );
   printf( "\n" );
   TFila_Show( Fila );
   TFila_InverteNos( &Fila );
   printf( "\n" );
   TFila_Show( Fila );

   return 0;
}
