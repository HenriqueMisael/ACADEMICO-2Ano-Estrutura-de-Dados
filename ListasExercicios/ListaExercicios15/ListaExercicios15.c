/******************************************************************************/
#include "Standart.h"
#include "HeapSort.c"
#include "MergeSort.c"
#include "QuickSort.c"
#include "Cronometro.c"
/******************************************************************************/
int ContadorCasos;
/******************************************************************************/
long calcularTamanhoArquivo(FILE *arquivo)
{
    long posicaoAtual = ftell(arquivo);
    long tamanho;

    fseek(arquivo, 0, SEEK_END);
    tamanho = ftell(arquivo);

    fseek(arquivo, posicaoAtual, SEEK_SET);

    return tamanho;
}
/******************************************************************************/
void EscreveOrdenado( TLista Lista, FILE *out, FILE *result )
{
   int i;

   for( i = 0; i < Lista.numeroElementos; i++ )
      fprintf( out, "%d ", Lista.Elemento[i].Chave );
   fprintf( out, "\n" );
}
/******************************************************************************/
void OrdenaMerge( FILE *Arquivo, FILE *Out, FILE *Result )
{
   TLista li;
   TChrono *Cronometro;
   int Erro, n, x, p = 1;
   int h, m, s, i;

   ContadorCasos = 1;
   Cronometro = newTChrono();

   printf( "MergeSort:" );
   fprintf( Result, "MergeSort: " );
   fprintf( Out, "MergeSort:\n" );

   fscanf( Arquivo, "%d", &n );
   do{
      printf( "\n Executando caso %d", ContadorCasos );

      TLista_Inicializa( &li );
      i = 0;
      while( n-- )
      {
         fscanf( Arquivo, "%d", &x );
         li.Elemento[ i++ ].Chave = x;
      }
      li.numeroElementos = i;

      TChrono_Start( Cronometro );
      MergeSort( &li );
      TChrono_Stop( Cronometro );

      EscreveOrdenado( li, Out, Result );

      ContadorCasos++;
      fscanf( Arquivo, "%d", &n );
   }while( n );
   //TChrono_Calculate( Cronometro, &h, &m, &s );
   fprintf( Result, "\t %.6f", Cronometro->elapsed );
}
/******************************************************************************/
void OrdenaHeap( FILE *Arquivo, FILE *Out, FILE *Result )
{
   TLista li;
   TChrono *Cronometro;
   int Erro, n, x, i, p = 1;
   int h, m, s;

   ContadorCasos = 1;
   Cronometro = newTChrono();

   printf( "\nHeapSort:" );
   fprintf( Result, "HeapSort: " );
   fprintf( Out, "HeapSort:\n" );

   fscanf( Arquivo, "%d", &n );
   do{
      printf( "\n Executando caso %d", ContadorCasos );
      TLista_Inicializa( &li );
      i = 0;
      while( n-- )
      {
         fscanf( Arquivo, "%d", &x );
         li.Elemento[ i++ ].Chave = x;
      }
      li.numeroElementos = i;

      TChrono_Start( Cronometro );
      heapSort( &li );
      TChrono_Stop( Cronometro );

      EscreveOrdenado( li, Out, Result );

      ContadorCasos++;
      fscanf( Arquivo, "%d", &n );
   }while( n );
   fprintf( Result, "\t %.6f", Cronometro->elapsed );
}
/******************************************************************************/
void OrdenaQuick( FILE *Arquivo, FILE *Out, FILE *Result )
{
   TLista li;
   TChrono *Cronometro;
   int Erro, n, x, p = 1;
   int h, m, s, i;

   ContadorCasos = 1;
   Cronometro = newTChrono();

   printf( "\nQuickSort:" );
   fprintf( Result, "QuickSort: " );
   fprintf( Out, "QuickSort:\n" );

   fscanf( Arquivo, "%d", &n );
   do{
      printf( "\n Executando caso %d", ContadorCasos );
      TLista_Inicializa( &li );
      i = 0;
      while( n-- )
      {
         fscanf( Arquivo, "%d", &x );
         li.Elemento[ i++ ].Chave = x;
      }
      li.numeroElementos = i;

      TChrono_Start( Cronometro );
      QuickSort( &li );
      TChrono_Stop( Cronometro );

      EscreveOrdenado( li, Out, Result );

      ContadorCasos++;
      fscanf( Arquivo, "%d", &n );
   }while( n );
   fprintf( Result, "\t %.6f", Cronometro->elapsed );
}
/******************************************************************************/
int main()
{
   FILE *ArquivoEntrada, *ArquivoSaida, *arquivoResultados;

   ArquivoEntrada = fopen( "lista_sort.in", "r" );
   ArquivoSaida = fopen( "lista_sort.out", "w" );
   arquivoResultados = fopen( "tabela_resultados.txt", "w" );

   if( !ArquivoEntrada || !ArquivoSaida || !arquivoResultados )
      printf( " Falha na abertura de arquivos" );
   else
   {
      OrdenaMerge( ArquivoEntrada, ArquivoSaida, arquivoResultados );
      fseek( ArquivoEntrada, 0, SEEK_SET );
      fprintf( arquivoResultados, "\n" );
      OrdenaHeap( ArquivoEntrada, ArquivoSaida, arquivoResultados );
      fseek( ArquivoEntrada, 0, SEEK_SET );
      fprintf( arquivoResultados, "\n" );
      OrdenaQuick( ArquivoEntrada, ArquivoSaida, arquivoResultados );
   }

   return 0;
}
/******************************************************************************/

