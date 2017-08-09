/******************************************************************************/
#include <stdio.h>
/******************************************************************************/
#define ERRO_FORA_INTERVALO    1
#define ERRO_LISTA_CHEIA       2
#define ERRO_CHAVE_EXISTENTE   3
#define ERRO_LISTA_VAZIA       4
#define ERRO_CHAVE_NAO_EXISTE  6
/******************************************************************************/
#define TRUE 1
#define FALSE 0
#define MAX 100000
/******************************************************************************/
typedef int chave;
typedef struct{
   chave Chave;
   //outros   
} TRegistro;
typedef struct{
   TRegistro Elemento[MAX];
   int numeroElementos;
} TLista;
/******************************************************************************/
/* FUNCOES DE OPERACAO COM A LISTA ********************************************/
/******************************************************************************/
void TLista_Inicializa( TLista *Lista ){   
   Lista->numeroElementos = 0;   
}
/******************************************************************************/
int TLista_GetTamanho( TLista Lista ){
   return Lista.numeroElementos;
}
/******************************************************************************/
int TLista_TemEspaco( TLista Lista, int *Erro ){
   
   if( TLista_GetTamanho( Lista ) < MAX )
      return TRUE;

   (*Erro) = ERRO_LISTA_CHEIA;
   return FALSE;
}
/******************************************************************************/
TRegistro TLista_GetPrimeiroElemento( TLista Lista, int *Erro ){
   
   TRegistro Retorno;
   
   if( Lista.numeroElementos )
      Retorno = Lista.Elemento[0];
   else
      (*Erro) = ERRO_LISTA_VAZIA;
   
   return Retorno;
}
/******************************************************************************/
TRegistro TLista_GetUltimoElemento( TLista Lista, int *Erro ){
   
   TRegistro Retorno;
   
   if( Lista.numeroElementos )
      Retorno = Lista.Elemento[ Lista.numeroElementos-1 ];
   else
      (*Erro) = ERRO_LISTA_VAZIA;
      
   return Retorno;
}
/******************************************************************************/
TRegistro TLista_GetElementoByIndice( TLista Lista, int Indice ){
   return Lista.Elemento[Indice];
}
/******************************************************************************/
int TLista_GetIndiceElementoByChave_Binario( TLista Lista, chave Chave, int *Erro ){

   int i, Superior, Inferior, Diferenca;
   
   Superior = Lista.numeroElementos-1;
   Inferior = 0;

   while( Inferior <= Superior ){
      i = (Superior+Inferior)/2;
      
      if( Lista.Elemento[i].Chave == Chave )
         return i;

      if( Lista.Elemento[i].Chave < Chave )
         Inferior = i+1;
      else
         Superior = i-1;
   }

   (*Erro) = ERRO_CHAVE_NAO_EXISTE;
   return -1;
}
/******************************************************************************/
void TLista_DiscriminaElemento( TRegistro Elemento ){
   printf( " %d", Elemento.Chave );
}
/******************************************************************************/
void TLista_ListaElementos( TLista Lista ){
   
   int i;
   
   printf( "\n" );
   for( i = 0; i < TLista_GetTamanho( Lista ); i++ )
      TLista_DiscriminaElemento( TLista_GetElementoByIndice( Lista, i ) );
}
/******************************************************************************/
int TLista_InsereElementoIndice( TLista *Lista
                               , chave  Chave
                               , int    Indice
                               , int    *Erro
                               )
{
   int i;

   if( TLista_TemEspaco( *Lista, Erro ) )
      if( (Indice >= 0) && (Indice<= TLista_GetTamanho( *Lista ) ) ){
         for( i = TLista_GetTamanho( *Lista ); i > Indice; i-- )
            Lista->Elemento[i].Chave = Lista->Elemento[i-1].Chave;
         Lista->Elemento[i/*Indice*/].Chave = Chave;
         Lista->numeroElementos++;
         return TRUE;
      }else
         (*Erro) = ERRO_FORA_INTERVALO;

   return FALSE;
}
/******************************************************************************/
int TLista_InsereElementoFinal( TLista *Lista, chave Chave, int *Erro ){
   
   return TLista_InsereElementoIndice( Lista, Chave, Lista->numeroElementos, Erro );
}
/******************************************************************************/
int TLista_InsereElementoOrdenado( TLista *Lista, chave Chave, int *Erro ){
   
   int i, x;
   
   (*Erro) = 0;
   x = -1;
   if( TLista_TemEspaco( (*Lista), Erro ) )
      for( i = 0; i < Lista->numeroElementos; i++ )
         if( Chave < Lista->Elemento[i].Chave ){
            TLista_InsereElementoIndice( Lista, Chave, i, Erro );
            return TRUE;
         }else if( i == Lista->numeroElementos-1 ){
            TLista_InsereElementoFinal( Lista, Chave, Erro );
            return TRUE;
         }
         
   (*Erro) = ERRO_CHAVE_EXISTENTE;
   return FALSE;
}
/******************************************************************************/
void TLista_EscreveErro( int Erro ){
   
   printf( "\n Erro: " );
   switch( Erro ){
      case ERRO_FORA_INTERVALO:     printf( "O indice deve ser maior ou igual a 0 e no maximo o tamanho da lista" );break;
      case ERRO_LISTA_CHEIA:        printf( "Lista cheia" );break;
      case ERRO_CHAVE_EXISTENTE:    printf( "A chave que foi utilizada para inserir na lista ja existe" );break;
      case ERRO_LISTA_VAZIA:        printf( "A lista encontra-se, atualmente, vazia" );break;
      case ERRO_CHAVE_NAO_EXISTE:   printf( "A chave informada nao existe na lista" );break;
   }
   getch();
}
/******************************************************************************/
void TLista_CopiaInvertida( TLista ListaOriginal, TLista *ListaCopia ){

   int i, Erro;

   printf( "\n Inicializando lista copia..." );
   TLista_Inicializa( ListaCopia );
   printf( "\n Copiando elemetos..." );
   for( i = 0; i < ListaOriginal.numeroElementos; i++ )
      if( !TLista_InsereElementoIndice( ListaCopia, ListaOriginal.Elemento[i].Chave, 0, &Erro ) )
         TLista_EscreveErro( Erro );

}
/******************************************************************************/
void TLista_CopiaMantendoOrdem( TLista ListaOriginal, TLista *ListaCopia ){
   
   int i, Erro;
   
   printf( "\n Inicializando lista copia..." );
   TLista_Inicializa( ListaCopia );
   printf( "\n Copiando elemetos..." );
   for( i = 0; i < ListaOriginal.numeroElementos; i++ )
      if( !TLista_InsereElementoFinal( ListaCopia, ListaOriginal.Elemento[i].Chave, &Erro ) )
         TLista_EscreveErro( Erro );
   
}
/******************************************************************************/
void TLista_OrdenaInsertionSort( TLista *Lista ){
   
   TRegistro Temporario;
   int i, x;
   
   for( i = 1; i < Lista->numeroElementos; i++ ){
      Temporario = Lista->Elemento[ i ];
      for( x = i; x > 0 && Temporario.Chave < Lista->Elemento[ x-1 ].Chave; x-- )
         Lista->Elemento[ x ] = Lista->Elemento[ x-1 ];
         
      Lista->Elemento[ x ] = Temporario;
   }   
   
}
/******************************************************************************/
void TLista_RemoveElementoIndice( TLista *Lista, int Indice ){
   
   for( ; Indice < Lista->numeroElementos-1; Indice++ )
      Lista->Elemento[Indice] = Lista->Elemento[Indice+1];

   Lista->numeroElementos--;
}
/******************************************************************************/
void TLista_RemoveElementoChave( TLista *Lista, chave Chave, int *Erro ){
   
   int Indice;
   
   Indice = TLista_GetIndiceElementoByChave_Binario( (*Lista), Chave, Erro );
   if( Indice+1 )
      TLista_RemoveElementoIndice( Lista, Indice );
}
/******************************************************************************/
void TLista_RemoveElementoFinal( TLista *Lista, int *Erro ){

   if( TLista_GetTamanho( (*Lista) ) )
      TLista_RemoveElementoIndice( Lista, Lista->numeroElementos-1 );
   else
      (*Erro) = ERRO_LISTA_VAZIA;
}
/******************************************************************************/
void TLista_InverteOrdem( TLista *Lista ){

   chave Chave;
   int i, Erro;

   for( i = 0; i < Lista->numeroElementos; i++ ){
      Chave = TLista_GetUltimoElemento( *Lista, &Erro ).Chave;
      TLista_RemoveElementoFinal( Lista, &Erro ); //Nao deve dar erro
      TLista_InsereElementoIndice( Lista, Chave, i, &Erro ); //Nao deve dar erro
   }
}
/******************************************************************************/
void TLista_TrocaElementos( volatile TLista *Lista, int i, int j ){
   
   int aux;
   
   aux = Lista->Elemento[ i ].Chave;
   Lista->Elemento[ i ].Chave = Lista->Elemento[ j ].Chave;
   Lista->Elemento[ j ].Chave = aux;
   
}
