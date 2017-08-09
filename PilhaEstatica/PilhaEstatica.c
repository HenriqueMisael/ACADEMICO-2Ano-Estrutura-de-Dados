#include <stdio.h>
#include <string.h>
#include "PilhaEstatica.h"
#include "TPilha.c"
/******************************************************************************/
void InserirMoeda( TPilha *Moedas ){
   
   int opcao, Erro;
   TRegistro Registro;

   printf( "\n [1] 1 centavo" );
   printf( "\n [2] 5 centavos" );
   printf( "\n [3] 10 centavos" );
   printf( "\n [4] 25 centavos" );
   printf( "\n [5] 50 centavos" );
   printf( "\n >" );

   scanf( "%d", &opcao );
   switch( opcao ){
      case 1: Registro.Chave = 1;break;
      case 2: Registro.Chave = 5;break;
      case 3: Registro.Chave = 10;break;
      case 4: Registro.Chave = 25;break;
      case 5: Registro.Chave = 50;break;
      default:
         if(opcao){
            printf( "\n Opcao invalida para o menu" );
            getch();
            return;
         }
   }
   if( !TPilha_EmpilhaElemento( Moedas, Registro, &Erro ) ){
      TPilha_EscreveErro( Erro );
      getch();
   }
}
/******************************************************************************/
void RemoverMoeda( TPilha *Moedas ){
   
   TRegistro MoedaRemovida;
   int Erro;
   
   MoedaRemovida = TPilha_Desempilha( Moedas, &Erro );
   if( Erro ){
      TPilha_EscreveErro( Erro );
      getch();
   }
   else
      printf( "\n Removida a moeda de valor %d.", MoedaRemovida.Chave );

   getch();
}
/******************************************************************************/
/* FUNCAO PRINCIPAL ***********************************************************/
/******************************************************************************/
int main(){
   
   TPilha Moedas;
   int opcao;
   
   /*
      Inicializacao da pilha
   */
   TPilha_Inicializa( &Moedas );

   /*
      Menu da maneira mais generica possivel
   */
   do{
      system( "CLS" );
      printf( "-------------------------------------------" );
      printf( "\n Pilha: " );
      TPilha_ListaElementos( Moedas );
      printf( "\n-------------------------------------------" );
      printf( "\n [01] Empilhar moeda" );
      printf( "\n [02] Desempilhar moeda" );
      printf( "\n [03] Desfazer pilha de moedas" );
      printf( "\n [00] Sair" );
      printf( "\n >" );
   
      scanf( "%d", &opcao );
      switch( opcao ){
         case 1: InserirMoeda( &Moedas );break;
         case 2: RemoverMoeda( &Moedas );break;
         case 3: TPilha_Inicializa( &Moedas );break;
         default:
            if(opcao){
               printf( "\n Opcao invalida para o menu" );
               getch();
            }
      }
      
   }while(opcao);
   
   return 0;
}

