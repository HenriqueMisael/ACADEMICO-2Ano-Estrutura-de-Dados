#include <stdio.h>
#define MAX 4

int main(){
   
   int i;

   i = -1;
   printf( " %d", ++i%MAX );
   printf( " %d", ++i%MAX );
   printf( " %d", ++i%MAX );
   printf( " %d", ++i%MAX );
   printf( " %d", ++i%MAX );

   return 0;

}
