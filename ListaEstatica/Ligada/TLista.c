#include "ListaLigadaEstatica.h"
/******************************************************************************/
#define ERRO_FORA_INTERVALO    1
#define ERRO_LISTA_CHEIA       2
#define ERRO_CHAVE_EXISTENTE   3
#define ERRO_LISTA_VAZIA       4
#define ERRO_CHAVE_NAO_EXISTE  6
/******************************************************************************/
typedef int chave;
typedef struct{
   chave Chave;
   int Info;
   int Proximo;
   //outros
} TRegistro;
typedef struct{
   TRegistro Elemento[MAX];
   int inicioR, inicioD, numeroElementos;
} TLista;
/******************************************************************************/
/* FUNCOES DE OPERACAO COM A LISTA ********************************************/
/******************************************************************************/
void TLista_Inicializa( TLista *Lista ){

   int i;

   Lista->inicioR = FIM;
   Lista->numeroElementos = 0;
   Lista->inicioD = 0;

   for( i = 0; i < MAX-1; i++ )
      Lista->Elemento[i].Proximo = i+1;
   Lista->Elemento[i /*MAX-1*/].Proximo = FIM;
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
int TLista_Vazia( TLista Lista, int *Erro ){

   if( Lista.inicioR == FIM )
      return TRUE;

   *Erro = ERRO_LISTA_VAZIA;
   return FALSE;
}
/******************************************************************************/
int TLista_TemEspaco( TLista Lista, int *Erro ){

   if( Lista.inicioD != FIM )
      return TRUE;

   *Erro = ERRO_LISTA_CHEIA;
   return FALSE;
}
/******************************************************************************/
int TLista_GetTamanho( TLista Lista ){
   return Lista.numeroElementos;
}
/******************************************************************************/
int TLista_GetProximoDisponivel( TLista *Lista, int *Erro ){

   int Proximo;

   Proximo = Lista->inicioD;
   Lista->inicioD = Lista->Elemento[ Proximo ].Proximo;

   if( Proximo == FIM ){
      *Erro = ERRO_LISTA_CHEIA;
   }

   return Proximo;
}
/******************************************************************************/
void TLista_LiberaPosicao( TLista *Lista, int j ){

	Lista->Elemento[j].Proximo = Lista->inicioD;
	Lista->inicioD = j;
	
}
/******************************************************************************/
TRegistro TLista_GetPrimeiroElemento( TLista Lista, int *Erro ){

   TRegistro Retorno;

   if( TLista_GetTamanho( Lista ) )
      Retorno = Lista.Elemento[Lista.inicioR];
   else
      (*Erro) = ERRO_LISTA_VAZIA;

   return Retorno;
}
/******************************************************************************/
TRegistro TLista_GetElementoByIndice( TLista Lista, int Indice ){
   return Lista.Elemento[Indice];
}
/******************************************************************************/
void TLista_DiscriminaElemento( TRegistro Elemento ){
   printf( " [%d/%d]", Elemento.Chave, Elemento.Info );
}
/******************************************************************************/
void TLista_Ordena( TLista *Lista ){

   int Trocou;
   int i, Temporario, Alterado;

   do{
      Trocou = 0;
      TLista_ListaElementos( *Lista );
      sleep(2);
      printf( "\n" );
	  for( i = Lista->inicioR; i != FIM; i = Lista->Elemento[i].Proximo ){
        if( Lista->Elemento[i].Chave < Lista->Elemento[i+1].Chave ){
            Temporario = Lista->Elemento[i].Proximo;
            Lista->Elemento[i].Proximo = Lista->Elemento[i+1].Proximo;
            Lista->Elemento[i+1].Proximo = Temporario;
            Trocou = 1;
        }
      }
   }while( Trocou );
}
/******************************************************************************/
void TLista_ListaElementos( TLista Lista ){

   int Erro, i;

//   if( !TLista_Vazia( Lista, &Erro ) )
   for( i = Lista.inicioR; i != FIM; i = Lista.Elemento[i].Proximo )
      TLista_DiscriminaElemento( TLista_GetElementoByIndice( Lista, i ) );

}
/******************************************************************************/
int TLista_BuscaChaveOrdenado( TLista *Lista, chave ChaveBusca, int *Anterior, int *Erro ){

   int i;

   *Anterior = -1;
   
   if( TLista_Vazia( *Lista, Erro ) ){
      return FIM;
   }

   for(  i = Lista->inicioR; i != FIM; *Anterior = i, i = Lista->Elemento[i].Proximo )
      if( Lista->Elemento[i].Chave >= ChaveBusca )
         break;
   *Erro = 0;

   if( i != FIM && Lista->Elemento[i].Chave == ChaveBusca )
      return i;

   return FIM;
}
/******************************************************************************/
int TLista_InsereNoInicio( TLista *Lista, TRegistro Registro, int *Erro ){

   int Indice;

   if( !TLista_TemEspaco( *Lista, Erro ) ){
      return FALSE;
   }

   Indice = TLista_GetProximoDisponivel( Lista, Erro);
   Registro.Proximo = Lista->inicioR;
   Lista->Elemento[ Indice ] = Registro;
   Lista->inicioR = Indice;
   Lista->numeroElementos++;
   *Erro = 0;

   return TRUE;
}
/******************************************************************************/
int TLista_InsereOrdenado( TLista *Lista, TRegistro Registro, int *Erro ){

   int Indice, Inserir, Anterior;

   if( !TLista_TemEspaco( *Lista, Erro ) ){
      return FALSE;
   }

   Inserir = TLista_BuscaChaveOrdenado( Lista, Registro.Chave, &Anterior, Erro );
   if( Anterior == FIM )
      return TLista_InsereNoInicio( Lista, Registro, Erro );

   Indice = TLista_GetProximoDisponivel( Lista, Erro);
   Registro.Proximo = Lista->Elemento[ Anterior ].Proximo;
   Lista->Elemento[ Anterior ].Proximo = Indice;
   Lista->Elemento[ Indice ] = Registro;
   Lista->numeroElementos++;
   *Erro = 0;

   return TRUE;
}
/******************************************************************************/
int TLista_RemoveElemento( TLista *Lista, chave Remover, int *Erro ){
	
	int Anterior, i, NovoInicio;
	
	i = TLista_BuscaChaveOrdenado( Lista, Remover, &Anterior, Erro );
	if( i == FIM )
		return FALSE;
		
	if( Anterior == FIM ){ //Remover primeiro elemento
		NovoInicio = TLista_GetPrimeiroElemento( *Lista, Erro ).Proximo;
		TLista_LiberaPosicao( Lista, Lista->inicioR );
		Lista->inicioR = NovoInicio;
	}else{
		Lista->Elemento[Anterior].Proximo = Lista->Elemento[i].Proximo;
		TLista_LiberaPosicao( Lista, i );
	}
	
	return TRUE;	
}
