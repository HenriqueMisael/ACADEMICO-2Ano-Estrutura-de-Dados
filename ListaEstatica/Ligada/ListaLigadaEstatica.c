#include "ListaLigadaEstatica.h"
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
chave PedeNumeroCliente(){

   int Numero;

   printf( "\n Digite o numero do cliente: " );
   scanf( "%d", &Numero );

   return Numero;
}
/******************************************************************************
void InserirClienteIndice( TLista *Clientes ){

   TRegistro Cliente;
   int Indice, Erro;

   Cliente.Chave = PedeChaveCliente();

   printf( "\n Onde inserir este cliente? \n >" );
   scanf( "%d", &Indice );

   if( !TLista_InsereElementoIndice( Clientes, Chave, Indice, &Erro ) )
      TLista_EscreveErro( Erro );

}
/******************************************************************************/
void InserirClienteInicio( TLista *Clientes ){

   TRegistro Cliente;
   int Indice, Erro;

   Cliente.Chave = PedeChaveCliente();
   Cliente.Info  = PedeNumeroCliente();

   if( !TLista_InsereNoInicio( Clientes, Cliente, &Erro ) ){
      TLista_EscreveErro( Erro );
      getch();
   }
}
/******************************************************************************/
void InserirClienteOrdenado( TLista *Clientes ){

   TRegistro Cliente;
   int Indice, Erro;

   Cliente.Chave = PedeChaveCliente();
   Cliente.Info  = PedeNumeroCliente();

   if( !TLista_InsereOrdenado( Clientes, Cliente, &Erro ) ){
      TLista_EscreveErro( Erro );
      getch();
   }
}
/******************************************************************************/
void BuscaCliente( TLista Clientes ){

   chave ChaveBusca;
   int Posicao, Anterior, Erro;

   ChaveBusca = PedeChaveCliente();
   Posicao = TLista_BuscaChaveOrdenado( &Clientes, ChaveBusca, &Anterior, &Erro );

   if( Posicao == FIM )
      TLista_EscreveErro( Erro );
   else
      printf( "\n Encontrada a chave %d na posicao %d da lista. Sua anterior e %d.", ChaveBusca, Posicao, Anterior );
      
    getch();
}
/******************************************************************************/
int main(){

   TLista Clientes;
   int opcao;

   /*
      Inicializacao de todas as listas, inclusive as copias, para evitar problemas caso sejam listadas antes de preenchidas
   */
   TLista_Inicializa( &Clientes );

   /*
      Menu da maneira mais generica possivel
   */
   do{
      system( "CLS" );
      printf( "-------------------------------------" );
      printf( "\nLista: " );
      TLista_ListaElementos( Clientes );
      //printf( "\n %d, %d, %d", Clientes.inicioD, Clientes.inicioR, Clientes.numeroElementos );
      printf( "\n-------------------------------------" );
      printf( "\n [01] Inserir cliente inicio" );
      printf( "\n [02] Inserir cliente ordenado" );
      printf( "\n [03] Remover cliente" );
      printf( "\n [04] Busca cliente" );
      printf( "\n [05] Ordenar" );
      printf( "\n [00] Sair" );
      printf( "\n >" );

      scanf( "%d", &opcao );
      switch( opcao ){
         case 1: InserirClienteInicio( &Clientes );break;
         case 2: InserirClienteOrdenado( &Clientes );break;
//         case 3: BuscaCliente( Clientes );break;
         case 4: BuscaCliente( Clientes );break;
         case 5: TLista_Ordena( &Clientes );break;
         default:
            if(opcao){
               printf( "\n Opcao invalida para o menu" );
               getch();
            }
      }

   }while(opcao);

   return 0;
}

