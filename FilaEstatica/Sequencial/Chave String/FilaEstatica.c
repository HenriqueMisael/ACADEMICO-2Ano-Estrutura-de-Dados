#include "FilaEstatica.h"
#include "TFila.c"

void CabecalhoPrograma( TFila Pessoas ){
   
   printf( "-------------------------------------------" );
   printf( "\n Fila" );
   if( !TFila_Vazia( Pessoas ) ){
      printf( ":\n-------------------------------------------" );
      TFila_ListaElementos( Pessoas );
   }else
      printf( " vazia" );
//      MostraProximoAtendimento( Pessoas );
   printf( "\n-------------------------------------------" );
}
/******************************************************************************/
void LimpaTela(){
   system( "CLS" );
}
/******************************************************************************/
int AdicionarPessoa( TFila *Pessoas ){

   TRegistro NovaPessoa;
   int Erro;

   printf( "\n Nome da nova pessoa: " );
   scanf( "%s", &NovaPessoa.Chave );

   Erro = 0;
   if( !TFila_AdicionaElemento( Pessoas, NovaPessoa, &Erro ) )
      TFila_EscreveErro( Erro );
   else
      printf( "\n %s adicionado(a) com sucesso.", NovaPessoa.Chave );
   getch();
   
   return !Erro;
}
/******************************************************************************/
void PovoarFila( TFila *Pessoas ){
   
   char Sair;
   
   do{
      LimpaTela();
      CabecalhoPrograma( *Pessoas );
      if(AdicionarPessoa( Pessoas )){
         printf( "\n Finalizar povoamento? (S/ )" );
         Sair = getch();
      }else
         Sair = 'S';
   }while( Sair != 'S' && Sair != 's' );
   
}
/******************************************************************************/
void MovimentarFila( TFila *Pessoas ){

   TRegistro PessoaAtendida;
   int Erro;
   
   PessoaAtendida = TFila_RemoveElemento( Pessoas, &Erro );
   if( Erro )
      TFila_EscreveErro( Erro );
   else
      printf( "\n %s atendido.", PessoaAtendida.Chave );

   getch();
}
/******************************************************************************/
void MostraProximoAtendimento( TFila Pessoas ){

   TRegistro Maior, Menor;
   int Erro;

   if( TFila_MaiorMenorElemento( Pessoas, &Maior, &Menor, &Erro ) ){
      printf( "\n Proxima pessoa a ser atendida: %s", TFila_ProximoElemento( Pessoas, &Erro ).Chave );
      if( TFila_IsCrescente( Pessoas ) )
         printf( "\n Ordem: crescente" );
   }
   
   //TFila_Debuga( Pessoas );
}
/******************************************************************************/
/* FUNCAO PRINCIPAL ***********************************************************/
/******************************************************************************/
void CarregaFilaUltimaExecucao( TFila *Pessoas ){

   FILE *Arquivo;
   TRegistro *Temporario;
   int Erro, i;

   Arquivo = fopen( "salvo.bin", "rb" );

   Temporario = (TRegistro*)malloc( MAX*sizeof( TRegistro ) );
   for( i = 0; i < MAX; i++ )
      strcpy( Temporario[i].Chave, "" );

   if( Arquivo != NULL ){
      fread( Temporario, sizeof( TRegistro ), MAX, Arquivo );
      fclose( Arquivo );

      for( i = 0; i < MAX; i++ )
         printf( "\n%s", Temporario[i].Chave );
/*
         if( strcmp( Temporario[i].Chave, "" ) )
            break;
         else
            TFila_AdicionaElemento( Pessoas, Temporario[i], &Erro );
*/
   }
   getch();
}
/******************************************************************************/
void SalvaFilaParaProximaExecucao( TFila Pessoas ){

   FILE *Arquivo;

   Arquivo = fopen( "salvo.bin", "wb" );

   if( Arquivo != NULL ){
      fwrite( Pessoas.Elemento, sizeof( TRegistro ), TFila_GetTamanho( Pessoas ), Arquivo );
      fclose( Arquivo );
   }else
      printf( "\nProblema ao salvar os contatos." );

}
/******************************************************************************/
int main(){
   
   TFila Pessoas;
   int opcao;
   
   /*
      Inicializacao da fila
   */
   TFila_Inicializa( &Pessoas );
   CarregaFilaUltimaExecucao( &Pessoas );
   /*
      Menu da maneira mais generica possivel
   */
   do{
      LimpaTela();
      CabecalhoPrograma( Pessoas );
      printf( "\n [01] Povoar fila" );
      printf( "\n [02] Movimentar fila" );
      printf( "\n [03] Desfazer fila" );
      printf( "\n [00] Sair" );
      printf( "\n >" );
   
      scanf( "%d", &opcao );
      switch( opcao ){
         case 1: PovoarFila( &Pessoas );break;
         case 2: MovimentarFila( &Pessoas );break;
         case 3: TFila_Inicializa( &Pessoas );break;
         default:
            if(opcao){
               printf( "\n Opcao invalida para o menu" );
               getch();
            }
      }
      
   }while(opcao);
   
   SalvaFilaParaProximaExecucao( Pessoas );
   return 0;
}

