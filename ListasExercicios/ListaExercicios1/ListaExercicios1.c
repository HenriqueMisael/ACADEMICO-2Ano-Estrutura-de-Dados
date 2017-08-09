#include <stdio.h>
#include <Windows.h>
#include <string.h>
/******************************************************************************/
#define EX1_TAMANHO 8
#define EX2_TAMANHO 10
#define EX3_TAMANHO 5
#define EX4_TAMANHO 3
#define EX5_TAMANHO 3
#define EX8_TAMANHO 5
#define EX9_TAMANHO 4
/******************************************************************************/
typedef char String[4];
/******************************************************************************/
/* FUNCOES DE USO GERAL *******************************************************/
/******************************************************************************/
int EncontraLinhaMaiorElemento( int** Matriz, int Tamanho ){
   
   int MaiorLinha, MaiorElemento;
   int i, j;
   
   for( i = 0; i < Tamanho; i++ )
      for( j = 0; j < Tamanho; j++ )
         if( !i&&!j || Matriz[i][j] > MaiorElemento ){
            if( i != MaiorLinha )
               MaiorLinha = i;
               
            MaiorElemento = Matriz[i][j];            
         }
            
   
   return MaiorLinha;
}
/******************************************************************************/
int EncontraMenorElemento( int* Vetor, int Tamanho ){
   
   int MenorElemento;
   int i;
   
   for( i = 0; i < Tamanho; i++ )
      if( !i || Vetor[i] < MenorElemento )
         MenorElemento = Vetor[i];
   
   return MenorElemento;
}
/******************************************************************************/
int DiferencaAbsoluta( int x, int y ){
   
   if( x > y )
      return x-y;
   
   return y-x;
}
/******************************************************************************/
int PegaValorEntreIntervalo( int Menor, int Maior ){
   
   int Tamanho;
   
   do{
      scanf( "%d", &Tamanho );      
   }while( Tamanho > Maior || Tamanho < Menor );
   
   return Tamanho;
}
/******************************************************************************/
void LimpaTela(){
   system( "CLS" );
}
/******************************************************************************/
int** CriaMatriz( int i, int j ){

   int** TabelaNova;
   int x;

   TabelaNova = (int**)malloc( i * sizeof( int ) );
   for( x = 0; x < i; x++ )
      TabelaNova[x] = (int*)malloc( j * sizeof( int ) );

   return TabelaNova;
}
/******************************************************************************/
void EscreveElementosMatriz( int** Matriz, int Tamanho, int Elementos ){
   
   int i, j;
   
   for( i = 0; i < Tamanho && Elementos; i++ )
      for( j = 0; j < Tamanho && Elementos; j++, Elementos-- ){
         if( j )
            printf( "  %d", Matriz[i][j] );
         else
            printf( "\n %d", Matriz[i][j] );
      }
}
/******************************************************************************/
int** RetornaMatrizQuadradaPreenchida( int Tamanho, int NumeroExercicio ){

   int** Matriz;
   int i, j, nElementos;
   
   Matriz = CriaMatriz( Tamanho, Tamanho );
   nElementos = 0;
   
   for( i = 0; i < Tamanho; i++ )
      for( j = 0; j < Tamanho; j++ ){
         LimpaTela();
         printf( "\n -------------------------------" );
         printf( "\n EXERCICIO %d", NumeroExercicio   );
         printf( "\n -------------------------------" );
         printf( "\n Digitacao da matriz de %d posicoes:", (Tamanho*Tamanho) );
         EscreveElementosMatriz( Matriz, Tamanho, nElementos++ );
         if( nElementos <= (Tamanho*Tamanho) ){
            printf( "\n\n Digite o %d elemento ([%d][%d])\n >", nElementos, i, j );
            scanf( "%d", &Matriz[i][j] );
         }else
            break;
      }
   
   printf( "\n\nsaiu" );
   
   return Matriz;
}
/******************************************************************************/
/* FUNCOES PARA EXERCICIO 1 ***************************************************/
/******************************************************************************/
int CalculaMaiorElementoDiagonalPrincipal( int** Matriz ){
   
   int MaiorElemento;
   int i;
   
   MaiorElemento = Matriz[0][0];
   for( i = 1; i < EX1_TAMANHO; i++ )
      if( MaiorElemento < Matriz[i][i] )
         MaiorElemento = Matriz[i][i];      
   
   return MaiorElemento;
}
/******************************************************************************/
void Exercicio1(){

   int** Matriz;
   int i, j, nElementos, MaiorElemento;
   
   Matriz = RetornaMatrizQuadradaPreenchida( EX1_TAMANHO, 1 );
   
   MaiorElemento = CalculaMaiorElementoDiagonalPrincipal( Matriz );
   for( i = 0; i < EX1_TAMANHO; i++ )
      for( j = 0; j < EX1_TAMANHO; j++ )
         Matriz[i][j] /= MaiorElemento;
   
   printf( "\n\n Ao dividir todos os elementos da matriz por %d, temos como resultante uma nova matriz: ", MaiorElemento );
   EscreveElementosMatriz( Matriz, EX1_TAMANHO, nElementos );
   getch();
}
/******************************************************************************/
/* FUNCOES PARA EXERCICIO 2 ***************************************************/
/******************************************************************************/
void TrocaColunaMatriz( int** Matriz, int Coluna1, int Coluna2 ){
   
   int Temporario;
   int i;
   
   for( i = 0; i < EX2_TAMANHO; i++ ){
      Temporario         = Matriz[i][Coluna1];
      Matriz[i][Coluna1] = Matriz[i][Coluna2];
      Matriz[i][Coluna2] = Temporario;            
   }
}
/******************************************************************************/
void TrocaLinhaMatriz( int** Matriz, int Linha1, int Linha2 ){
   
   int Temporario;
   int j;
   
   for( j = 0; j < EX2_TAMANHO; j++ ){
      Temporario        = Matriz[Linha1][j];
      Matriz[Linha1][j] = Matriz[Linha2][j];
      Matriz[Linha2][j] = Temporario;            
   }
}
/******************************************************************************/
void TrocaDiagonaisMatriz( int** Matriz ){
   
   int Temporario;
   int x;
   
   for( x = 0; x < EX2_TAMANHO; x++ ){
      Temporario = Matriz[x][x];
      Matriz[x][x] = Matriz[x][EX2_TAMANHO-1-x];
      Matriz[x][EX2_TAMANHO-1-x] = Temporario;
   }
}
/******************************************************************************/
void Exercicio2(){

   int** Matriz;
   int i, j, nElementos, MaiorElemento;
   
   Matriz = RetornaMatrizQuadradaPreenchida( EX2_TAMANHO, 2 );
   LimpaTela();
   printf( " Matriz digitada:" );
   EscreveElementosMatriz( Matriz, EX2_TAMANHO, EX2_TAMANHO*EX2_TAMANHO );
   
   TrocaLinhaMatriz( Matriz, 2, 8 );
   TrocaColunaMatriz( Matriz, 4, 10 );
   TrocaDiagonaisMatriz( Matriz );
   TrocaLinhaMatriz( Matriz, 5, 10 );
   
   printf( "\n\n Matriz apos as trocas:" );
   EscreveElementosMatriz( Matriz, EX2_TAMANHO, EX2_TAMANHO*EX2_TAMANHO );
   
   getch();
}
/******************************************************************************/
/* FUNCCOES PARA EXERCICIO 3 **************************************************/
/******************************************************************************/
float MediaAritmeticaELementosAbaixoDiagonalPrincipal( int** Matriz ){

   int nElementos = 0;
   int i, j;
   float Soma = 0;
   
   for( i = 1; i < EX3_TAMANHO; i++ )
      for( j = 0; j < i; j++, nElementos++ )
         Soma += Matriz[i][j];

   return Soma/nElementos;
}
/******************************************************************************/
void Exercicio3(){

   int** Matriz;
   
   Matriz = RetornaMatrizQuadradaPreenchida( EX3_TAMANHO, 3 );
   LimpaTela();
   printf( " Matriz digitada:" );
   EscreveElementosMatriz( Matriz, EX3_TAMANHO, EX3_TAMANHO*EX3_TAMANHO );

   printf( "\n A media dos elementos abaixo da diagonal principal desta matriz e %.2f.", MediaAritmeticaELementosAbaixoDiagonalPrincipal( Matriz ) );
   getch();
}
/******************************************************************************/
/* FUNCCOES PARA EXERCICIO 4 **************************************************/
/******************************************************************************/
void Exercicio4(){

   int** Matriz;
   int nElementos;
   int i, j;
   
   Matriz = RetornaMatrizQuadradaPreenchida( EX4_TAMANHO, 4 );
   LimpaTela();
   printf( " Matriz digitada:" );
   EscreveElementosMatriz( Matriz, EX4_TAMANHO, EX4_TAMANHO*EX4_TAMANHO );

   for( i = 0; i < EX4_TAMANHO; i++ )
      for( j = 0; j < EX4_TAMANHO; j++ )
         if( (j+i)%2 )
            printf( "%d", Matriz[i][j] );

   getch();
}
/******************************************************************************/
/* FUNCOES PARA EXERCICIO 5 ***************************************************/
/******************************************************************************/
int MatrizesTranspostas( int** A1, int** A2 ){
   
   int i, j;
   
   for( i = 0; i < EX5_TAMANHO; i++ )
      for( j = 0; j < EX5_TAMANHO; j++ )
         if( A1[i][j] != A2[j][i] )
            return 0;
         
   
   return 1;
}
/******************************************************************************/
void Exercicio5(){

   int** A1;
   int** A2;
   int nElementos;
   int i, j;
   
   A1 = RetornaMatrizQuadradaPreenchida( EX5_TAMANHO, 5 );
   A2 = RetornaMatrizQuadradaPreenchida( EX5_TAMANHO, 5 );
   LimpaTela();
   printf( " Matrizes digitadas:" );
   EscreveElementosMatriz( A1, EX5_TAMANHO, EX5_TAMANHO*EX5_TAMANHO );
   printf( "\n" );   
   EscreveElementosMatriz( A2, EX5_TAMANHO, EX5_TAMANHO*EX5_TAMANHO );

   if( MatrizesTranspostas( A1, A2 ) )
      printf( "\n A primeira matriz digitada e transposta a segunda." );
   else
      printf( "\n A primeira matriz digitada nao e transposta a segunda." );
   
   getch();
}
/******************************************************************************/
/* FUNCOES PARA EXERCICIO 6 ***************************************************/
/******************************************************************************/
int MatrizSimetrica( int** Matriz, int Tamanho ){ //Se é uma matriz quadrada, então não há necessidade de ter duas dimensões, uma vez
                                                  // que as duas dimensões serão iguais
   
   int i, j;
   
   for( i = 0; i < Tamanho; i++ )
      for( j = 0; j < Tamanho; j++ )
         if( Matriz[i][j] != Matriz[j][i] )
            return 0;

   return 1;
}
/******************************************************************************/
void Exercicio6(){

   int** Matriz;
   int Tamanho;
   int i, j;
   
   printf( "\n Defina o tamanho da matriz (altura e largura, um unico valor) a ser digitada: " );
   scanf( "%d", &Tamanho );
   Matriz = RetornaMatrizQuadradaPreenchida( Tamanho, 6 );
   LimpaTela();
   printf( " Matriz digitada:" );
   EscreveElementosMatriz( Matriz, Tamanho, Tamanho*Tamanho );

   if( MatrizSimetrica( Matriz, Tamanho ) )
      printf( "\n A matriz digitada e simetrica." );
   else
      printf( "\n A matriz digitada nao e simetrica." );
   
   getch();
}
/******************************************************************************/
/* FUNCOES PARA EXERCICIO 7 ***************************************************/
/******************************************************************************/
int** GeraMatrizPartindoDiagonalPrincipal( int N ){
   
   int** Matriz;
   int i, j;
   
   Matriz = CriaMatriz( N, N );
   
   for( i = 0; i < N; i++ )
      for( j = 0; j < N; j++ )
         Matriz[i][j] = N-DiferencaAbsoluta( i, j );
         
   return Matriz;   
}
/******************************************************************************/
void Exercicio7(){

   int Tamanho;
   
   LimpaTela();
   printf( "\n Digite o valor N a ser utilizado para gerar a matriz: " );
   Tamanho = PegaValorEntreIntervalo( 1, 9 );

   EscreveElementosMatriz( GeraMatrizPartindoDiagonalPrincipal( Tamanho ), Tamanho, Tamanho*Tamanho );
   
   getch();
}
/******************************************************************************/
/* FUNCOES PARA EXERCICIO 8 ***************************************************/
/******************************************************************************/
void Exercicio8(){

   int** Matriz;
  
   Matriz = RetornaMatrizQuadradaPreenchida( EX8_TAMANHO, 8 );
   LimpaTela();
   printf( " Matriz digitada:" );
   EscreveElementosMatriz( Matriz, EX8_TAMANHO, EX8_TAMANHO*EX8_TAMANHO );
   
   printf( "\n O elemeto minimax da matriz e %d.", EncontraMenorElemento( Matriz[ EncontraLinhaMaiorElemento( Matriz, EX8_TAMANHO ) ], EX8_TAMANHO ) );
   
   getch();
}
/******************************************************************************/
/* FUNCOES PARA EXERCICIO 8 ***************************************************/
/******************************************************************************/
int OcorreStringNaMatriz( char A[EX9_TAMANHO][EX9_TAMANHO+1], String S, int *Vertical ){
   
   char B[EX9_TAMANHO][EX9_TAMANHO+1];
   int i, j;
   
   for( i = 0; i < EX9_TAMANHO; i++ )
      if( !strcmp( A[i], S ) ){
         (*Vertical) = 0;
         return 1;
      }

   for( i = 0; i < EX9_TAMANHO; i++ ){
      for( j = 0; j < EX9_TAMANHO; j++ )
         B[i][j] = A[j][i];
      
      B[i][EX9_TAMANHO+1] = 0;
   }
   
   for( i = 0; i < EX9_TAMANHO; i++ )
      if( !strcmp( B[i], S ) ){
         (*Vertical) = 1;
         return 1;
      }
   
   return 0;
}
/******************************************************************************/
char* PegaDirecao( int Vertical ){
   
   if( Vertical )
      return "vertical";
      
   return "horizontal";   
}
/******************************************************************************/
void Exercicio9(){

   int Vertical;
   char Matriz[EX9_TAMANHO][EX9_TAMANHO+1];
   String Busca;   
   
   /*
   a b c d
   e f g h
   i j k l
   m n o p   
   */
   Matriz[0][0] = 'a';
   Matriz[0][1] = 'b';
   Matriz[0][2] = 'c';
   Matriz[0][3] = 'd';
   Matriz[0][4] = 0;
   Matriz[1][0] = 'e';
   Matriz[1][1] = 'f';
   Matriz[1][2] = 'g';
   Matriz[1][3] = 'h';
   Matriz[1][4] = 0;
   Matriz[2][0] = 'i';
   Matriz[2][1] = 'j';
   Matriz[2][2] = 'k';
   Matriz[2][3] = 'l';
   Matriz[2][4] = 0;
   Matriz[3][0] = 'm';
   Matriz[3][1] = 'n';
   Matriz[3][2] = 'o';
   Matriz[3][3] = 'p';
   Matriz[3][4] = 0;

   LimpaTela();
   printf( "\n" );
   printf( "\n %s", Matriz[0] );
   printf( "\n %s", Matriz[1] );
   printf( "\n %s", Matriz[2] );
   printf( "\n %s", Matriz[3] );
   printf( "\n\n Digite quatro letras que, sequencialmente, serao buscadas na matriz: " );
   scanf( "%s", &Busca );
   
   if( OcorreStringNaMatriz( Matriz, Busca, &Vertical ) )
      printf( "\n Ocorre %s na matriz na direcao %s", Busca, PegaDirecao( Vertical ) );
   else
      printf( "\n Nao ocorre %s em nenhuma direcao na matriz", Busca );
   
   getch();
}
/******************************************************************************/
/* FUNCOES PARA EXERCICIO 10 **************************************************/
/******************************************************************************/
int MatrizInca( int** A, int Tamanho ){
   
   int i, j, k, Val, IsInca = 1;
   
   Val = A[0][0] - 1;
   
   for (i = 0; i < (Tamanho / 2) && IsInca; i++) {
      
      for (j = i; j < (Tamanho - i) && IsInca; j++)
         IsInca = A[i][j] == ++Val;
      
      for (k = i + 1; k < (Tamanho - i - 1) && IsInca; k++)
         IsInca = A[k][Tamanho - i - 1] == ++Val;
      
      for (j = (Tamanho - i - 1); j >= i && IsInca; j--)
         IsInca = A[Tamanho - i - 1][j] == ++Val;
      
      for (k = (Tamanho - i - 2); k >= (i + 1) && IsInca; k--)
         IsInca = A[k][i] == ++Val;
      
   }

   if (Tamanho % 2 && IsInca) {
      i = ((Tamanho + 1) / 2) - 1;
      IsInca = A[i][i] == ++Val;
   }

   return IsInca;   
}
/******************************************************************************/
void Exercicio10(){

   int** Matriz;
   int Tamanho;
   
   printf( "\n Digite um numero de 1 a 10 sobre o qual sera gerada a matriz inca: " );
   Tamanho = PegaValorEntreIntervalo( 1, 10 );
   
   Matriz = RetornaMatrizQuadradaPreenchida( Tamanho, 10 );
   LimpaTela();
   EscreveElementosMatriz( Matriz, Tamanho, Tamanho*Tamanho );
   
   if( MatrizInca( Matriz, Tamanho ) )
      printf( "\n A matriz e uma matriz inca." );
   else
      printf( "\n A matriz nao e uma matriz inca." );
      
   getch();
}
/******************************************************************************/
/* FUNCAO PRINCIPAL ***********************************************************/
/******************************************************************************/
int main(){

   int opcao;

   do{
      LimpaTela();
	  
	   printf( "\n Universidade Estadual de Maringá, curso de Informática - Turma 31"   );
	   printf( "\n Lista de Exercicios 1, diciplina de Estrutura de Dados"              );
	   printf( "\n Henrique Misael Machado - ra99660"                                   );
      printf( "\n -------------------------------"                                     );
      printf( "\n Escolha o exercicio a executar:"                                     );
      printf( "\n [01] Divide elementos pelo maior da diagonal"                        );
      printf( "\n [02] Troca elementos de linhas e colunas"                            );
      printf( "\n [03] Media abaixo da diagonal principal"                             );
      printf( "\n [04] Elementos cuja soma da linha e coluna resultam em numero impar" );
      printf( "\n [05] Verifica transposicao de duas matrizes"                         );
      printf( "\n [06] Verifica simetria de matriz de tamanho ajustavel"               );
      printf( "\n [07] Gerar matriz a partir da diagonal principal"                    );
      printf( "\n [08] Encontrar elemento minimax de matriz digitada"                  );
      printf( "\n [09] Encontrar string na matriz"                                     );
      printf( "\n [10] Gera matriz inca a partir de numero digitado"                   );
      printf( "\n [00] Fecha o programa"                                               );
      printf( "\n >" );

      scanf( "%d", &opcao );
 
      switch( opcao ){
         case  0: break;
         case  1: Exercicio1();break;
         case  2: Exercicio2();break;         
         case  3: Exercicio3();break;         
         case  4: Exercicio4();break;         
         case  5: Exercicio5();break;         
         case  6: Exercicio6();break;         
         case  7: Exercicio7();break;         
         case  8: Exercicio8();break;         
         case  9: Exercicio9();break;         
         case 10: Exercicio10();break;         
         default: printf( "Nao existe opcao %d a ser executada, tente novamente.", opcao );getch();
      }

   }while( opcao );

   return opcao;
}
