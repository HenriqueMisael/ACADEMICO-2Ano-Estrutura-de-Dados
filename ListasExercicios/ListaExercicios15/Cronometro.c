/******************************************************************************/
#include "Standart.h"
#include <time.h>
/******************************************************************************/
typedef struct{
   double elapsed;
   struct timeval lastStart;
   short int start;
} TChrono;
/******************************************************************************/
TChrono* newTChrono()
{
   TChrono *newChrono;
   
   newChrono = (TChrono*)malloc( sizeof( TChrono ) );
   TChrono_Blank( newChrono );
   
   return newChrono;
}
/******************************************************************************/
int TChrono_Start( TChrono* c )
{
   if( c->start )
      return FALSE;

   c->start = TRUE;
   gettimeofday( &c->lastStart, NULL );
   
   return TRUE;
}
/******************************************************************************/
int TChrono_Stop( TChrono* c )
{
   struct timeval aux;
   double lastElapsed;
   
   if( !c->start )
      return FALSE;
      
   gettimeofday( &aux, NULL );
   lastElapsed = (double)(aux.tv_sec - c->lastStart.tv_sec)+(double)(aux.tv_usec - c->lastStart.tv_usec)/1000000;

   c->elapsed += lastElapsed;
   c->start = FALSE;

   return TRUE;
}
/******************************************************************************/
int TChrono_Blank( TChrono* c )
{
   c->elapsed = 0;
   c->start = FALSE;
}
/******************************************************************************/
