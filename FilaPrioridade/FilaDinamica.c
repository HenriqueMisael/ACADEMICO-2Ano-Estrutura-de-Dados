/******************************************************************************/
#include "TFila.c"
/******************************************************************************
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
void Mostra( TFila Fila ){
    //printf( "\n-----------------" );
    TFila_Show( Fila );
    printf( "\n-----------------" );
}
/******************************************************************************/
void Remove( TFila *Fila ){

    info Retorno;

    strcpy( Retorno, TFila_Remove( Fila ) );
    if( Retorno == NULL )
        printf( "\n Sem nada para remover." );
    else
        printf( "\n Removido %s.", Retorno );
}
/******************************************************************************/
int main(){

   TFila Fila;
   TNo *No;

   TFila_Inicializa( &Fila );
   Mostra( Fila );
   TFila_Insere( &Fila, "Henrique", 1 );
   TFila_Insere( &Fila, "Joel", 5 );
   TFila_Insere( &Fila, "Joesley", 3 );
   TFila_Insere( &Fila, "Ricardo", 4 );
   Mostra( Fila );
   Remove( &Fila );
   Mostra( Fila );
   Remove( &Fila );
   Mostra( Fila );
   Remove( &Fila );
   Mostra( Fila );
   Remove( &Fila );
   Mostra( Fila );
   Remove( &Fila );
   Mostra( Fila );
   //TFila_Remove( &Fila );
   //Mostra( Fila );

   return 0;
}
