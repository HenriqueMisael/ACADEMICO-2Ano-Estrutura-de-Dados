#include "FilaEstatica.h"
#include "TFila.c"
/******************************************************************************/
void AdicionarPessoa( TFila *Pessoas ){

   TRegistro NovaPessoa;
   int Erro;

   printf( "\n Chave da nova pessoa: " );
   scanf( "%d", &NovaPessoa.Chave );

   if( !TFila_AdicionaElemento( Pessoas, NovaPessoa, &Erro ) )
      TFila_EscreveErro( Erro );
   else
      printf( "\n Pessoa %d adicionada com sucesso.", NovaPessoa.Chave );
   getch();
}
/******************************************************************************/
void MovimentarFila( TFila *Pessoas ){

   TRegistro PessoaAtendida;
   int Erro;
   
   PessoaAtendida = TFila_RemoveElemento( Pessoas, &Erro );
   if( Erro )
      TFila_EscreveErro( Erro );
   else
      printf( "\n Pessoa %d atendida.", PessoaAtendida );

   getch();
}
/******************************************************************************/
void MostraProximoAtendimento( TFila Pessoas ){

   TRegistro Maior, Menor;
   int Erro;

   if( TFila_MaiorMenorElemento( Pessoas, &Maior, &Menor, &Erro ) ){
      printf( "\n Proxima pessoa a ser atendida: %d", TFila_ProximoElemento( Pessoas, &Erro ).Chave );
      printf( "\n Maior: %d", Maior.Chave );
      printf( "\n Menor: %d", Menor.Chave );
      if( TFila_IsCrescente( Pessoas ) )
         printf( "\n Ordem: crescente" );
   }
   
   //TFila_Debuga( Pessoas );
}
/******************************************************************************/
/* FUNCAO PRINCIPAL ***********************************************************/
/******************************************************************************/
int main(){
   
   TFila Pessoas;
   int opcao;
   
   /*
      Inicializacao da fila
   */
   TFila_Inicializa( &Pessoas );

   /*
      Menu da maneira mais generica possivel
   */
   do{
      system( "CLS" );
      printf( "-------------------------------------------" );
      printf( "\n Fila: " );
      TFila_ListaElementos( Pessoas );
      MostraProximoAtendimento( Pessoas );
      printf( "\n-------------------------------------------" );
      printf( "\n [01] Adicionar pessoa a fila" );
      printf( "\n [02] Movimentar fila" );
      printf( "\n [03] Desfazer fila" );
      printf( "\n [00] Sair" );
      printf( "\n >" );
   
      scanf( "%d", &opcao );
      switch( opcao ){
         case 1: AdicionarPessoa( &Pessoas );break;
         case 2: MovimentarFila( &Pessoas );break;
         case 3: TFila_Inicializa( &Pessoas );break;
         default:
            if(opcao){
               printf( "\n Opcao invalida para o menu" );
               getch();
            }
      }
      
   }while(opcao);
   
   return 0;
}

