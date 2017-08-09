/******************************************************************************/
#include "HASH.c"
#include <conio.h>
/******************************************************************************/
#define MAX 1111
#define TOTAL 100
/******************************************************************************/
int random()
{
   int random;
   return random%(MAX-1);
}
/******************************************************************************/
int main()
{
   HASH ht;
   int i;
   
   inicializarHash( &ht );
   /*
   for( i = 0; i < TOTAL; i++ )
      inserir( &ht, rand()%MAX );
   */


   inserir( &ht,  4 );
   inserir( &ht, 17 );
   inserir( &ht, 13 );
   inserir( &ht, 35 );
   inserir( &ht, 25 );
   inserir( &ht, 11 );
   inserir( &ht,  2 );
   inserir( &ht, 10 );
   inserir( &ht, 32 );
   remover( &ht, 25 );
   remover( &ht, 11 );
   inserir( &ht, 40 );
   inserir( &ht,  3 );
     
   imprimeHash( ht );
   return 0;
}
