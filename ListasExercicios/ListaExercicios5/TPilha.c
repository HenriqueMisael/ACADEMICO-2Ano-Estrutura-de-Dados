#include "ListaExercicios5.h"
/******************************************************************************/
#define MAX    50 //Tamanho máximo da lista

#define ERRO_PILHA_CHEIA       1
#define ERRO_CHAVE_EXISTENTE   2
#define ERRO_PILHA_VAZIA       3
/******************************************************************************/
typedef int chave;
typedef struct{
   chave Chave;
   char Val;
} TRegistro;
typedef struct{
   TRegistro Elemento[MAX];
   int numeroElementos;
} TPilha;
/******************************************************************************/
/* FUNCOES DE OPERACAO COM A PILHA ********************************************/
/******************************************************************************/
void TPilha_Inicializa( TPilha *Pilha ){
   Pilha->numeroElementos = 0;
}
/******************************************************************************/
int TPilha_GetTamanho( TPilha Pilha ){
   return Pilha.numeroElementos;
}
/******************************************************************************/
int TPilha_TemEspaco( TPilha Pilha, int *Erro ){

   if( TPilha_GetTamanho( Pilha ) < MAX )
      return TRUE;

   (*Erro) = ERRO_PILHA_CHEIA;
   return FALSE;
}
/******************************************************************************/
int TPilha_Vazia( TPilha Pilha ){
   return !Pilha.numeroElementos;
}
/******************************************************************************/
int TPilha_ExisteChave( TPilha Pilha, chave Chave, int *Erro ){

   int i;
   for( i = 0; i < Pilha.numeroElementos; i++ )
      if( Pilha.Elemento[i].Chave == Chave ){
         *Erro = ERRO_CHAVE_EXISTENTE;
         return TRUE;
      }

   return FALSE;
}
/******************************************************************************/
void TPilha_EscreveErro( int Erro ){

   printf( "\n Erro: " );
   switch( Erro ){
      case ERRO_PILHA_CHEIA:        printf( "Pilha cheia" );break;
      case ERRO_CHAVE_EXISTENTE:    printf( "A chave que foi utilizada para inserir na pilha ja existe" );break;
      case ERRO_PILHA_VAZIA:        printf( "A pilha encontra-se, atualmente, vazia" );break;
   }
}
/******************************************************************************/
void TPilha_DiscriminaElemento( TRegistro Elemento ){
   printf( "%d", Elemento.Val );
}
/******************************************************************************/
void TPilha_ListaElementos( TPilha Pilha ){

   int i;

   for( i = 0; i < TPilha_GetTamanho( Pilha ); i++ ){
      TPilha_DiscriminaElemento( Pilha.Elemento[i] );
   }
}
/******************************************************************************/
int TPilha_EmpilhaElemento( TPilha    *Pilha
                          , TRegistro Registro
                          , int       *Erro
                          )
{
   int i;

   if( !TPilha_TemEspaco( *Pilha, Erro ) )
      return FALSE;
   if( TPilha_ExisteChave( *Pilha, Registro.Chave, Erro ) )
      return FALSE;

   Pilha->Elemento[Pilha->numeroElementos++] = Registro;

   return TRUE;
}
/******************************************************************************/
int TPilha_MostraTopo( TPilha *Pilha
                     , int    *Erro
                     )
{
   int i;

   if( TPilha_Vazia( *Pilha ) )
      return FALSE;

   TPilha_DiscriminaElemento( Pilha->Elemento[Pilha->numeroElementos-1] );

   return TRUE;
}
/******************************************************************************/
TRegistro TPilha_Desempilha( TPilha *Pilha, int *Erro ){

   TRegistro Retorno;

   if( !TPilha_Vazia( *Pilha ) ){
      Retorno = Pilha->Elemento[ --Pilha->numeroElementos ];
      *Erro = 0;
   }else
      *Erro = ERRO_PILHA_VAZIA;
      
   return Retorno;
}
/******************************************************************************/
TRegistro TPilha_NovoRegistro( TPilha Pilha, char Valor ){
   
   //Inicializamos um novo registro, com uma chave disponível, e retornamos
   TRegistro Novo;
   int *Erro;
   
   Novo.Chave = 1;
   Novo.Val = Valor;
   while( TPilha_ExisteChave( Pilha, Novo.Chave, Erro ) )
      Novo.Chave++;
      
   return Novo;
}
