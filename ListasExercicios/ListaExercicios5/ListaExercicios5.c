#include "ListaExercicios5.h"
#include "TPilha.c"
/******************************************************************************/
void Inserir( TPilha *String ){
   
   short int Branco;
   int Erro, i, Tamanho;
   char *NovaString;

   Tamanho = MAX-String->numeroElementos;
   NovaString = (char*)malloc( Tamanho * sizeof( char ) );
   printf( "\n Digite o texto a ser adicionado a pilha (Max.: %d): ", Tamanho );
   scanf( "%[^\n]s", NovaString );
   printf( "\n %s", NovaString );
   for( i = 0; i < Tamanho; i++ )
      if( NovaString[i] == ' ' )
         if( Branco )
            break;
         else
            Branco = TRUE;
      else{
         if( Branco )
            Branco = FALSE;
         if( !TPilha_EmpilhaElemento( String, TPilha_NovoRegistro( *String, NovaString[i] ), &Erro ) )
            TPilha_EscreveErro( Erro );
      }
}
/******************************************************************************/
void Remover( TPilha *String ){
   
   int Quantidade, Erro;
   
   printf( "\n\n Quantidade de caracteres para remover da pilha: " );
   scanf( "%d", &Quantidade );
   
   while( Quantidade-- ){
      TPilha_Desempilha( String, &Erro );
      if( Erro )
         TPilha_EscreveErro( Erro );
   }
}
/******************************************************************************/
/* FUNCAO PRINCIPAL ***********************************************************/
/******************************************************************************/
int main(){
   
   TPilha String;
   int opcao;
   
   /*
      Inicializacao da pilha
   */
   TPilha_Inicializa( &String );

   /*
      Menu da maneira mais generica possivel
   */
   do{
      system( "CLS" );
      printf( "-------------------------------------------" );
      printf( "\n Pilha: " );
      TPilha_ListaElementos( String );
      printf( "\n-------------------------------------------" );
      printf( "\n [01] Inserir string na pilha" );
      printf( "\n [02] Remover caracteres da pilha" );
      printf( "\n [03] Desfazer pilha" );
      printf( "\n [00] Sair" );
      printf( "\n >" );
   
      scanf( "%d", &opcao );
      switch( opcao ){
         case 1: Inserir( &String );break;
         case 2: Remover( &String );break;
         case 3: TPilha_Inicializa( &String );break;
         default:
            if(opcao){
               printf( "\n Opcao invalida para o menu" );
               getch();
            }
      }
      
   }while(opcao);
   
   return 0;
}

