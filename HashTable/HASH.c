/******************************************************************************/
#include "LISTA.c"
/******************************************************************************/
#define TAMANHO 11
/******************************************************************************/
typedef struct{
   LISTA tab[TAMANHO];
} HASH;
/******************************************************************************/
void inicializarHash( HASH *htTabela )
{
   int i;

   for( i = 0; i < TAMANHO; i++ )
   {
      inicializar( &htTabela->tab[i] );
   }
}
/******************************************************************************/
int funcaoHash( int chave )
{
   return chave%TAMANHO;
}
/******************************************************************************/
void inserir( HASH *htTabela, int dado )
{
   if( !inserirElem( dado, &htTabela->tab[ funcaoHash( dado ) ] ) )
   {
      printf( "\n Falha ao inserir %d.", dado );
   }else
   {
      printf( "\n Inserido %d com sucesso.", dado );
   }
}
/******************************************************************************/
void remover( HASH *htTabela, int dado )
{
   if( !excluirElem( dado, &htTabela->tab[ funcaoHash( dado ) ] ) )
   {
      printf( "\n Falha ao excluir %d.", dado );
   }else
   {
      printf( "\n Removido %d com sucesso.", dado );
   }
}
/******************************************************************************/
void imprimeHash( HASH htTabela )
{
   NO* p;
   int i;
   
   for( i = 0; i < TAMANHO; i++ )
   {
      printf( "\n\t%d:", i );
      p = htTabela.tab[i].inicio;
      while( p )
      {
         printf( " %d", p->info );
         p = p->prox;
      }
   }
}

