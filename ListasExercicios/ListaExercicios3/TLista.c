#include "ListaExercicios3.h"
/******************************************************************************/
#define ERRO_FORA_INTERVALO      1
#define ERRO_LISTA_CHEIA         2
#define ERRO_CHAVE_EXISTENTE     3
#define ERRO_LISTA_VAZIA         4
#define ERRO_VETOR_MUITO_GRANDE  5

#define MAX    50 //Tamanho máximo da lista
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
void TLista_EscreveElementosEmLinha( TLista Lista ){
   
   int i;
   
   for( i = 0; i < Lista.numeroElementos; i++ )
      printf( "%d ", Lista.Elemento[i] );
         
}
/******************************************************************************/
void TLista_EscreveErro( int Erro ){
   
   switch( Erro ){
      case ERRO_FORA_INTERVALO:      printf( "O indice deve ser maior ou igual a 0 e no maximo o tamanho da lista" );break;
      case ERRO_LISTA_CHEIA:         printf( "Lista cheia" );break;
      case ERRO_CHAVE_EXISTENTE:     printf( "A chave que foi utilizada para inserir na lista ja existe" );break;
      case ERRO_LISTA_VAZIA:         printf( "A lista encontra-se, atualmente, vazia" );break;
      case ERRO_VETOR_MUITO_GRANDE:  printf( "Nem todos os elementos foram inseridos porque o vetor era muito grande" );break;
   }
   getch();
}

/******************************************************************************/
int TLista_InsereElementoIndice( TLista *Lista
                               , chave  Chave
                               , int    Indice
                               , int    *Erro
                               )
{
   /*
      Equivalente à função insereEmpurra(x), do exercício 1 da lista
   */
   
   int i;

   if( (Indice >= 0) && (Indice<= TLista_GetTamanho( *Lista ) ) ){
      
      for( i = TLista_GetTamanho( *Lista ); i > Indice; i-- )
         Lista->Elemento[i].Chave = Lista->Elemento[i-1].Chave;
      Lista->Elemento[i/*Indice*/].Chave = Chave;
      
      if( Lista->numeroElementos < MAX ) //Se o número de elementos for igual ao máximo, então o último elemento foi excluído e o tamanho se conserva
         Lista->numeroElementos++;
      
      return TRUE;
   }else
      (*Erro) = ERRO_FORA_INTERVALO;

   return FALSE;
}
/******************************************************************************/
int TLista_InsereElementosVetor( TLista *Lista, int Vetor[], int TamanhoVetor, int *Erro ){
   
   /*
      Referente à função pedida no exercício 5
   */   
   int i, x;
   
   (*Erro) = 0;
   if( Lista->numeroElementos < MAX )
      for( /*Before*/    i = 0, x = Lista->numeroElementos;
           /*Condition*/ i < TamanhoVetor && x < MAX;
           /*After*/     i++, x++ )
         TLista_InsereElementoIndice( Lista, Vetor[i], x, Erro ); //Apesar de ser passado por parâmetro, a variável erro não deve ser preenchida dentro.
   else
      (*Erro) = ERRO_LISTA_CHEIA;
   
   if( !(*Erro) && i < TamanhoVetor )
      (*Erro) = ERRO_VETOR_MUITO_GRANDE;
   
   return !(*Erro);
}
/******************************************************************************/
void TLista_TrocaElementos( TLista *Lista, int Primeiro, int Segundo ){

   TRegistro Temporario;

   Temporario                = Lista->Elemento[Primeiro];
   Lista->Elemento[Primeiro] = Lista->Elemento[Segundo];
   Lista->Elemento[Segundo]  = Temporario;

}
/******************************************************************************/
void TLista_RemoveElementosIntervalo_Normal( TLista *Lista
                                           , chave  Inicio
                                           , chave  Final
                                           )
{
   /*
      Equivalente à função removeArruma(L,x,y) do exercício 2
   */

   int Zerar;
   int i, Troca;
   
   Zerar = FALSE;
   for( i = 0; i < Lista->numeroElementos; i++ ){
      if( Lista->Elemento[i].Chave == Inicio )
         Zerar = TRUE;
      if( Zerar ){
         if( Lista->Elemento[i].Chave == Final ){
            Troca = i+1;
            Zerar = FALSE;
         }
         Lista->Elemento[i].Chave = 0;
      }
   }
   
   for( i = 0; i < Lista->numeroElementos; i++ )
      if( !Lista->Elemento[i].Chave )
         if( Troca < Lista->numeroElementos )
            TLista_TrocaElementos( Lista, i, Troca++ );
         else
            Lista->Elemento[i].Chave = 0;
}
/******************************************************************************/
void TLista_RemoveElementosIntervalo_Otimizado( TLista *Lista
                                              , chave  Inicio
                                              , chave  Final
                                              )
{
   /*
      Equivalente à função removeArruma(L,x,y) do exercício 3
   */

   int Zerar;
   int i, x;

   Zerar = 0;
   /*
      Zerar:
      [0] Nao comecou a zerar
      [1] Esta zerando os elementos
      [2] Ja zerou os elementos do intervalo
   */

   for( i = 0; i < Lista->numeroElementos; i++ ){
      if( !Zerar && Lista->Elemento[i].Chave == Inicio )
         Zerar = 1;
      if( Zerar == 1 ){
         x = i;
         while( Lista->Elemento[x].Chave != Final )
            x++;
         Zerar = 2;
      }
      if( Zerar == 2 )
         if( x < Lista->numeroElementos )
            TLista_TrocaElementos( Lista, i, ++x );
         else
            Lista->Elemento[i].Chave = 0;
   }
   getch();
}
/******************************************************************************/
void TLista_AlojaElementoSeForMaior( TLista *Maiores
                                   , chave ChaveAdicionar
                                   )
{
   int i, ChaveAuxiliar;
   
   for( i = 0; i < Maiores->numeroElementos; i++ )
      if( ChaveAdicionar > Maiores->Elemento[i].Chave ){
         ChaveAuxiliar = Maiores->Elemento[i].Chave;
         Maiores->Elemento[i].Chave = ChaveAdicionar;
         TLista_AlojaElementoSeForMaior( Maiores, ChaveAuxiliar );
         break;
      }
}
/******************************************************************************/
void TLista_CopiaMaioresElementos( TLista Lista
                                 , TLista *Maiores
                                 , int    K
                                 )
{
   /*
      Referente à função pedida no exercício 4
   */   
   int i, Erro;
   
   TLista_Inicializa( Maiores );
   
   for( i = 0; i < Lista.numeroElementos; i++ )
      if( Maiores->numeroElementos < K )
         TLista_InsereElementoIndice( Maiores, Lista.Elemento[i].Chave, i, &Erro );   //Variavel erro apenas porque já está definido, mas não deve ocorrer erro nesta
      else                                                                            // etapa do processo.
         TLista_AlojaElementoSeForMaior( Maiores, Lista.Elemento[i].Chave );
   
}
/******************************************************************************/
void TLista_SeparaListasMaiorMenor( TLista *Primeira, TLista *Segunda ){
   
   chave Temporario;
   int i, x;
   /*
      Referente à função pedida no exercício 6
      Utilizaremos a lista Primeira como a dos elementos maiores
   */
   
   for( i = 0; i < Segunda->numeroElementos; i++ ){ //Lembrando que as duas devem ter o mesmo tamanho
      for( x = 0; x < Primeira->numeroElementos; x++ ){
         if( Segunda->Elemento[i].Chave > Primeira->Elemento[x].Chave ){
            Temporario = Primeira->Elemento[x].Chave;
            Primeira->Elemento[x].Chave = Segunda->Elemento[i].Chave;
            Segunda->Elemento[i].Chave = Temporario;
            //Ao invés de dar um break, continuaremos a comparação, mas desta vez com o novo valor, a fim de que todos os
            // elementos da lista Primeira sejam maiores que os elementos da lista Segunda.
         }
      }
   }
}

