/******************************************************************************/
#include <stdio.h>
#include <strings.h>
/******************************************************************************/
int funcaoHash( char String[] )
{
   unsigned long hash, hashTemp;
   int tamanho, i;
   
   tamanho = strlen( String );

   for( hash = 0, i = 0; i < tamanho; i++ )
   {
      printf( "\n %d * 128^%d", String[i], tamanho-i-1 );
      hashTemp = String[ i ] * pow(128, tamanho-i-1);
      hash += hashTemp;
   }
   return hash;
}
/******************************************************************************/
int main()
{
   char String[4] = { 'C', 'L', 'R', 'S' };
   
   printf( "\n hash: %d", funcaoHash( String ) );

   return 0;
}

