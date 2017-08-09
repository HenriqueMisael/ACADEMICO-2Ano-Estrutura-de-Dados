#include <stdio.h>
#include <string.h>
#include "FilaEstatica.h"
/******************************************************************************/
#define MAX    6 //Tamanho máximo da lista

#define ERRO_FILA_CHEIA      1
#define ERRO_CHAVE_EXISTENTE 2
#define ERRO_FILA_VAZIA      3
/******************************************************************************/
typedef char chave[30];
typedef struct{
   chave Chave;
   //outros   
} TRegistro;
typedef struct{
   TRegistro Elemento[MAX];
   int inicio;
   int fim;
} TFila;
/******************************************************************************/
/* FUNCOES DE OPERACAO COM A Fila ********************************************/
/******************************************************************************/
void TFila_Debuga( TFila Fila ){
   
   printf( "\n---------\nDebug:\n%d\n%d\n%d\n---------", Fila.inicio, Fila.fim, TFila_GetTamanho( Fila ) );
}
/******************************************************************************/
void TFila_Inicializa( TFila *Fila ){
   Fila->inicio = 0;
   Fila->fim = 0;
}
/******************************************************************************/
int TFila_GetTamanho( TFila Fila ){
   return Fila.fim - Fila.inicio;
}
/******************************************************************************/
int TFila_TemEspaco( TFila Fila, int *Erro ){

   if( Fila.fim < MAX )
      return TRUE;

   (*Erro) = ERRO_FILA_CHEIA;
   return FALSE;
}
/******************************************************************************/
int TFila_Vazia( TFila Fila ){
   return !TFila_GetTamanho( Fila );
}
/******************************************************************************/
int TFila_ExisteChave( TFila Fila, chave Chave, int *Erro ){

   int i;

   for( i = Fila.inicio; i < Fila.fim; i++ )
      if( !strcmp( Fila.Elemento[i].Chave, Chave ) ){
         *Erro = ERRO_CHAVE_EXISTENTE;
         return TRUE;
      }

   return FALSE;
}
/******************************************************************************/
void TFila_EscreveErro( int Erro ){

   printf( "\n Erro: " );
   switch( Erro ){
      case ERRO_FILA_CHEIA:        printf( "Fila cheia" );break;
      case ERRO_CHAVE_EXISTENTE:   printf( "A chave que foi utilizada para inserir na Fila ja existe" );break;
      case ERRO_FILA_VAZIA:        printf( "A Fila encontra-se, atualmente, vazia" );break;
   }
}
/******************************************************************************/
void TFila_DiscriminaElemento( TRegistro Elemento ){
   printf( "%s", Elemento.Chave );
}
/******************************************************************************/
void TFila_ListaElementos( TFila Fila ){

   int i;

   for( i = Fila.inicio; i < Fila.fim; i++ ){
      printf( "\n " );
      TFila_DiscriminaElemento( Fila.Elemento[i] );
   }
}
/******************************************************************************/
int TFila_AdicionaElemento( TFila *Fila, TRegistro Registro, int *Erro ){

   if( TFila_TemEspaco( *Fila, Erro ) && !TFila_ExisteChave( *Fila, Registro.Chave, Erro ) ){
      Fila->Elemento[ Fila->fim++ ] = Registro;
      return TRUE;
   }
   
   return FALSE;
}
/******************************************************************************/
TRegistro TFila_RemoveElemento( TFila *Fila, int *Erro ){

   TRegistro Retorno;

   if( !TFila_Vazia( *Fila ) ){
      Retorno = Fila->Elemento[ Fila->inicio++ ];
      *Erro = 0;
      if( Fila->inicio == Fila->fim )
         TFila_Inicializa( Fila );
   }else
      *Erro = ERRO_FILA_VAZIA;

   return Retorno;
}
/******************************************************************************/
TRegistro TFila_ProximoElemento( TFila Fila, int *Erro ){

   TRegistro Retorno;

   if( !TFila_Vazia( Fila ) ){
      Retorno = Fila.Elemento[ Fila.inicio ];
      *Erro = 0;
   }else
      *Erro = ERRO_FILA_VAZIA;

   return Retorno;
}
/******************************************************************************/
int TFila_MaiorMenorElemento( TFila Fila, TRegistro *Maior, TRegistro *Menor, int *Erro ){
   
   int i;

   *Maior = TFila_ProximoElemento( Fila, Erro );
   *Menor = TFila_ProximoElemento( Fila, Erro );

   if( !TFila_Vazia( Fila ) ){
      for( i = Fila.inicio; i < Fila.fim; i++ ){
         if( Fila.Elemento[i].Chave > (*Maior).Chave )
            *Maior = Fila.Elemento[i];
         if( Fila.Elemento[i].Chave < (*Menor).Chave )
            *Menor = Fila.Elemento[i];
      }
      return TRUE;
   }
   
   return FALSE;
}
/******************************************************************************/
int TFila_IsCrescente( TFila Fila ){
   
   int i;
   
   for( i = Fila.inicio; i < Fila.fim-1; i++ )
      if( Fila.Elemento[i].Chave > Fila.Elemento[i+1].Chave )
         return FALSE;

   return TRUE;
}
