#include <stdio.h>
#include <string.h>
#include "ListaSequencialEstatica.h"
#include "TLista.c"
/******************************************************************************/
/* FUNCAO PRINCIPAL ***********************************************************/
/******************************************************************************/
chave PedeChaveCliente(){
   
   chave Chave;

   printf( "\n Digite a chave do cliente: " );
   scanf( "%d", &Chave );
   
   return Chave;
}
/******************************************************************************/
void InserirClienteIndice( TLista *Clientes ){
   
   chave Chave;
   int Indice, Erro;
   
   Chave = PedeChaveCliente();

   printf( "\n Onde inserir este cliente? \n >" );
   scanf( "%d", &Indice );
   
   if( !TLista_InsereElementoIndice( Clientes, Chave, Indice, &Erro ) )
      TLista_EscreveErro( Erro );
      
}
/******************************************************************************/
void InserirClienteFinal( TLista *Clientes ){
   
   chave Chave;
   int Indice, Erro;
   
   Chave = PedeChaveCliente();
   
   if( !TLista_InsereElementoFinal( Clientes, Chave, &Erro ) )
      TLista_EscreveErro( Erro );
      
}
/******************************************************************************/
void InserirClienteOrdenado( TLista *Clientes ){
   
   chave Chave;
   int Indice, Erro;
   
   Chave = PedeChaveCliente();
   
   if( !TLista_InsereElementoOrdenado( Clientes, Chave, &Erro ) )
      TLista_EscreveErro( Erro );
      
}
/******************************************************************************/
void ListarClientes( TLista Clientes ){
   
   TLista_ListaElementos( Clientes );
   getch();
      
}
/******************************************************************************/
void SubmenuOrdenacao( TLista *Clientes ){
   
   int opcao;

   printf( "\n Ordenar pelo metodo" );
   printf( "\n [1] Insertion Sort" );
   printf( "\n >" );
   scanf( "%d", &opcao );
   switch( opcao ){
      case 1: TLista_OrdenaInsertionSort( Clientes );break;
      default:
         if(opcao){
            printf( "\n Opcao invalida para o menu" );
            getch();
         }
   }
      
}
/******************************************************************************/
void SubmenuListagem( TLista Clientes, TLista clientesInvertidos, TLista clientesCopia ){   

   int opcao;

   printf( "\n Listar qual lista" );
   printf( "\n [1] Lista principal" );
   printf( "\n [2] Lista invertida" );
   printf( "\n [3] Lista copia" );
   printf( "\n >" );
   scanf( "%d", &opcao );
   switch( opcao ){
      case 1: ListarClientes( Clientes );break;
      case 2: ListarClientes( clientesInvertidos );break;
      case 3: ListarClientes( clientesCopia );break;
      default:
         if(opcao){
            printf( "\n Opcao invalida para o menu" );
            getch();
         }
   }
      
}
/******************************************************************************/
void AtualizarListasSecundarias( TLista Clientes, TLista *clientesInvertidos, TLista *clientesCopia ){
   
   TLista_CopiaInvertida( Clientes, clientesInvertidos );
   TLista_CopiaMantendoOrdem( Clientes, clientesCopia );
    
}
/******************************************************************************/
TRegistro PegaClientePelaChave( TLista Clientes, int *Erro ){

   TRegistro Registro;
   chave Chave;
   int Indice;
   
   Chave = PedeChaveCliente();
   
   Indice = TLista_GetIndiceElementoByChave_Binario( Clientes, Chave, Erro );
   if( Indice+1 )
      Registro = Clientes.Elemento[Indice];

   return Registro;
}
/******************************************************************************/
void ConsultaCliente( TLista Clientes ){

   TRegistro Cliente;
   int opcao, Erro;

   Erro = 0;
   printf( "\n [1] Primeiro cliente" );
   printf( "\n [2] Ultimo cliente" );
   printf( "\n [3] Cliente especifico" );
   printf( "\n >" );
   scanf( "%d", &opcao );
   switch( opcao ){
      case 1: Cliente = TLista_GetPrimeiroElemento( Clientes, &Erro );break;
      case 2: Cliente = TLista_GetUltimoElemento( Clientes, &Erro );break;
      case 3: Cliente = PegaClientePelaChave( Clientes, &Erro );break;
      default:
         if(opcao){
            printf( "\n Opcao invalida para o menu" );
            getch();
            return;
         }
   }
   
   if( Erro )
      TLista_EscreveErro( Erro );
   else{
      TLista_DiscriminaElemento( Cliente );
      getch();
   }      
}
/******************************************************************************/
void RemoveClienteLista( TLista *Clientes ){

   int Erro;

   TLista_RemoveElementoChave( Clientes, PedeChaveCliente(), &Erro );
   if( Erro )
      TLista_EscreveErro( Erro );
}
/******************************************************************************/
void RemoveUltimoClienteLista( TLista *Clientes ){

   int Erro;

   Erro = 0;
   TLista_RemoveElementoFinal( Clientes, &Erro );
   if( Erro )
      TLista_EscreveErro( Erro );
}
/******************************************************************************/
int main(){
   
   TLista Clientes, clientesInvertidos, clientesCopia;
   int opcao;
   
   /*
      Inicializacao de todas as listas, inclusive as copias, para evitar problemas caso sejam listadas antes de preenchidas
   */
   TLista_Inicializa( &Clientes );
   TLista_Inicializa( &clientesInvertidos );
   TLista_Inicializa( &clientesCopia );

   /*
      Menu da maneira mais generica possivel
   */
   do{
      system( "CLS" );
      printf( "\n [01] Inserir cliente novo" );
      printf( "\n [02] Inserir cliente novo ao final" );
      printf( "\n [03] Inserir cliente novo ordenado" );
      printf( "\n [04] Listar clientes" );
      printf( "\n [05] Consultar cliente" );
      printf( "\n [06] Atualizar listas secundarias" );
      printf( "\n [07] Ordenar lista" );
      printf( "\n [08] Remove cliente da lista pela chave" );
      printf( "\n [09] Remove ultimo cliente da lista" );
      printf( "\n [10] Inverte ordem da lista" );
      printf( "\n [00] Sair" );
      printf( "\n >" );
   
      scanf( "%d", &opcao );
      switch( opcao ){
         case 1: InserirClienteIndice( &Clientes );break;
         case 2: InserirClienteFinal( &Clientes );break;
         case 3: InserirClienteOrdenado( &Clientes );break;
         case 4: SubmenuListagem( Clientes, clientesInvertidos, clientesCopia );break;
         case 5: ConsultaCliente( Clientes );break;
         case 6: AtualizarListasSecundarias( Clientes, &clientesInvertidos, &clientesCopia );break;
         case 7: SubmenuOrdenacao( &Clientes );break;
         case 8: RemoveClienteLista( &Clientes );break;
         case 9: RemoveUltimoClienteLista( &Clientes );break;
         case 10: TLista_InverteOrdem( &Clientes );break;
         default:
            if(opcao){
               printf( "\n Opcao invalida para o menu" );
               getch();
            }
      }
      
   }while(opcao);
   
   return 0;
}

