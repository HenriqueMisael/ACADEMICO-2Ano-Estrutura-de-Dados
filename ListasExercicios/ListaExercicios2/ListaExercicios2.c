#include <stdio.h>
/******************************************************************************/
#define TAMANHO 10
/******************************************************************************/
typedef struct{
   
   int Numero;
   int Ocorrencias;
   
} elementoOrdenar;
/******************************************************************************/
void escreveLinha();
/******************************************************************************/
/* EXERCICIO 1 ****************************************************************/
/******************************************************************************/
void InsertionSort( int *Vetor ){
   
}
/******************************************************************************/
/* EXERCICIO 2 ****************************************************************/
/******************************************************************************/
int pegaIndiceMenorValor( int v[], int indiceMenor ){

   int i;

   for( i = indiceMenor; i < TAMANHO; i++ )
      if( v[indiceMenor] < v[i] )
         indiceMenor = i;

   return indiceMenor;
}
/******************************************************************************/
void OrdenaMetodo_Selection( int VetorParaOrdenar[] ){

   int i, indiceMenor, valorTemporario;

   for( i = 0; i < TAMANHO; i++ ){
      indiceMenor = pegaIndiceMenorValor( VetorParaOrdenar, i );
      if( indiceMenor != i ){
         valorTemporario                 = VetorParaOrdenar[ i ];
         VetorParaOrdenar[ i ]           = VetorParaOrdenar[ indiceMenor ];
         VetorParaOrdenar[ indiceMenor ] = valorTemporario;
      }
   }
}
/******************************************************************************/
/* EXERCICIO 3 ****************************************************************/
/******************************************************************************/
int EncontraPosicaoValorDefinido( elementoOrdenar Vetor[], int Valor ){
   
   int i;
   
   for( i = 0; i < TAMANHO; i++ )
      if( Vetor[i].Numero == Valor )
         Vetor[i].Ocorrencias++;
   
}
/******************************************************************************/
void OrdenaAcordandoNumeroOcorrencias( int Vetor[] ){
   
   elementoOrdenar Auxiliar[TAMANHO], Temporario;
   int qtdeNumeros, Preencheu, Trocou, NumeroInserir;
   int i, j, n;
   
   Preencheu   = 0;
   qtdeNumeros = 0;
   
   /*
      Preenchemos o vetor auxiliar, que irá informar a quantidade de ocorrências de cada número.
   */      
   for(  i = 0; i < TAMANHO; i++ ){
      for( j = 0; j < qtdeNumeros; j++ )
         if( Auxiliar[j].Numero == Vetor[i] ){
            Auxiliar[j].Ocorrencias++;
            Preencheu = 1;
         }
      if( !Preencheu ){
         Auxiliar[ qtdeNumeros++ ].Numero = Vetor[i];
         Auxiliar[ qtdeNumeros++ ].Ocorrencias = 1;
      }else Preencheu = 0;
   }
   printf( "\n----------------------------------------" );
   for( i = 0; i < qtdeNumeros; i++ )
      printf( "\n%d %d", Auxiliar[i].Numero, Auxiliar[i].Ocorrencias );
   printf( "\n----------------------------------------" );
   
   /*
      Utilizando o método bubble sort, vamos ordenar o vetor auxiliar utilizando como chave "Ocorrencias", de maneira crescente.
   */
   do{
      Trocou = 0;
      for( j = 0; j < qtdeNumeros; j++ )
         if( Auxiliar[j].Ocorrencias < Auxiliar[j+1].Ocorrencias ){
            Temporario      = Auxiliar[j];
            Auxiliar[ j ]   = Auxiliar[ j+1 ];
            Auxiliar[ j+1 ] = Temporario;
            Trocou = 1;
         }
   }while( Trocou );
   
   for( i = 0; i < qtdeNumeros; i++ )
      printf( "\n%d %d", Auxiliar[i].Numero, Auxiliar[i].Ocorrencias );
   
   for( j = i = 0; i < TAMANHO; i++ ){
      if( Auxiliar[j].Ocorrencias-- )
         NumeroInserir = Auxiliar[j].Numero;
      else{
         j++;
         i--;
      }  
      Vetor[i] = NumeroInserir;
   }
}   
/******************************************************************************/
/* MAIN ***********************************************************************/
/******************************************************************************/
void escreveLinha( int v[] ){

    int i;

    printf( "\n" );
    for( i = 0; i < TAMANHO; i++ ){
       printf( "\t%d", v[i] );
    }
}
/******************************************************************************/
int main(){
   
   int Vetor[TAMANHO];
   
   Vetor[0] = 10;   
   Vetor[1] = 10;   
   Vetor[2] = 23;   
   Vetor[3] = 14;   
   Vetor[4] = 61;   
   Vetor[5] = 14;   
   Vetor[6] = 14;   
   Vetor[7] = 12;   
   Vetor[8] = 14;   
   Vetor[9] = 18;
   
   //OrdenaMetodo_Selection( Vetor );
   OrdenaAcordandoNumeroOcorrencias( Vetor );
   escreveLinha( Vetor );
   
   return 0;
}
