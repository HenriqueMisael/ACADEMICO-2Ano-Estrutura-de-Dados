#include "ListaExercicios3.h"
#include "TLista.c"
/******************************************************************************/
TLista Lista, Secundaria, Maiores;
int K;
/******************************************************************************/
void LimpaTela(){
   system( "CLS" );
}
/******************************************************************************/
/* FUNCAO EXERCICIO 1 *********************************************************/
/******************************************************************************/
void InserirUnicoElemento(){
   
   chave Chave;
   int Indice, Erro;
      
   printf( "\n Digite o numero a ser inserido na lista: " );
   scanf( "%d", &Chave );
   printf( "\n Em que posicao (a partir do 0) da lista o numero %d deve ser inserido? ", Chave );
   scanf( "%d", &Indice );
   
   if( !TLista_InsereElementoIndice( &Lista, Chave, Indice, &Erro ) )
      TLista_EscreveErro( Erro );   
}
/******************************************************************************/
/* FUNCAO EXERCICIO 5 *********************************************************/
/******************************************************************************/
void InserirVariosElementos( TLista *Lista ){
   
   int i, Tamanho, *Vetor, Erro;
   
   printf( "\n Quantos elementos devem ser incluidos na lista? " );
   scanf( "%d", &Tamanho );
   Vetor = malloc( Tamanho*sizeof( int ) );
   
   printf( "\n" );
   for( i = 0; i < Tamanho; i++ ){
      printf( "Vetor[%d] = ", i );
      scanf( "%d", &Vetor[i] );
   }   
   
   if( !TLista_InsereElementosVetor( Lista, Vetor, Tamanho, &Erro ) ){
      printf( "\n Erro: ", Erro );
      TLista_EscreveErro( Erro );
   }
}
/******************************************************************************/
/* FUNCAO EXERCICIO 3 *********************************************************/
/******************************************************************************/
void RemoverElementosIntervalo(){

   int opcao, Inicial, Final;
   
   printf( "\n Digite os dois numeros que serao os limites do intervalo \n" );
   scanf( "%d", &Inicial );
   scanf( "%d", &Final );

   printf( "\n Versao [1]Normal ou [2]Otimizada? " );
   scanf( "%d", &opcao );
   if(opcao == 1)
      TLista_RemoveElementosIntervalo_Normal( &Lista, Inicial, Final );
   else if(opcao == 2)
      TLista_RemoveElementosIntervalo_Otimizado( &Lista, Inicial, Final );
}
/******************************************************************************/
/* FUNCAO EXERCICIO 4 *********************************************************/
/******************************************************************************/
void Exercicio4(){

   printf( "\n Deseja atualizar a lista com quantos dos maiores elementos? (Min. 1; Max. %d)\n >", Lista.numeroElementos-1 );
   do{
      K = getch()-'0';
   }while( K < 1 || K >= Lista.numeroElementos );
   printf( "%d", K );
   
   TLista_CopiaMaioresElementos( Lista, &Maiores, K );
   
}
/******************************************************************************/
/* FUNCAO EXERCICIO 6 *********************************************************/
/******************************************************************************/
void Exercicio6(){

   TLista_SeparaListasMaiorMenor( &Lista, &Secundaria );

}
/******************************************************************************/
/* FUNCAO EXERCICIO 7 *********************************************************/
/******************************************************************************/
int PegaProximaEstacao( int Inicial, int Pular ){
   
   int Proxima;

   for( Proxima = Inicial; Pular; Pular-- )
      if( Proxima == Lista.numeroElementos-1 )
         Proxima = 0;
      else
         Proxima++;
         
   return Proxima;
}
/******************************************************************************/
char* Sentido( int ParaTras ){
   
   if( ParaTras )
      return "para tras";
   return "para frente";
}
/******************************************************************************/
void Exercicio7(){

   /*
      Pelo que foi explicado pessoalmente, eu entendi que haveriam as rotas maiores partindo de cada
         uma das estações, ou seja, N rotas maiores. Entre estas N, deveria ser exibida a menor.
   */
   
   chave Rotas[Lista.numeroElementos][3];
   chave DistanciaMaior, DistanciaFrente, DistanciaCircuito;
   int FrenteTras, menorDistancia;
   int i, j, x;

   /*
      Utilizaremos uma matriz Nx3, onde o elemento:
         *Rotas[i][1] é a distancia maior encontrada partindo de i para as outras;
         *Rotas[i][2] é a estacao destino;
         *Rotas[i][3] é um flag demonstrando se foi indo [0]"para frente" ou [1]"para trás".
   */

   /*
      Calcular a distancia total do circuito, porque a soma da distancia pra frente com a distancia para trás sempre dará
         este valor calculado abaixo.
   */
   DistanciaCircuito = 0;
   for( i = 0; i < Lista.numeroElementos; i++ )
      DistanciaCircuito += Lista.Elemento[i].Chave;

   /*
      Preencher a matriz das rotas.
   */
   for( i = 0; i < Lista.numeroElementos; i++ ){
      // Para cada estacao, calculamos...
      for( j = 1; j < Lista.numeroElementos; j++ ){
         //A distancia até cada uma das outras
         DistanciaFrente = 0;
         for( x = 0; x < j; x++ )
            DistanciaFrente += Lista.Elemento[ PegaProximaEstacao( i, x ) ].Chave; //Calcular a distancia indo "pra frente"

         if( DistanciaFrente > DistanciaCircuito-DistanciaFrente ){ //Se a distancia "para frente" for maior do que a "para trás"
            DistanciaMaior = DistanciaFrente;
            FrenteTras = 0;
         }else{
            DistanciaMaior = DistanciaCircuito-DistanciaFrente;
            FrenteTras = 1;
         }

         if( j == 1 || DistanciaMaior > Rotas[i][1] ){
            Rotas[i][1] = DistanciaMaior;
            Rotas[i][2] = PegaProximaEstacao( i, j );
            Rotas[i][3] = FrenteTras;
         }
      }
   }

   /*
      Agora que já temos as rotas preenchidas a variavel menorDistancia ira receber o índice
         da rota com distancia menor
   */
   for( i = 0; i < Lista.numeroElementos; i++ )
      if( !i || Rotas[i][1] > Rotas[menorDistancia][1] )
         menorDistancia = i;


   /*
      Exibimos a informacao que foi pedida no exercicio
   */
   printf( "\n Dentre as rotas de maior distancia partindo de cada estacao, temos que a menor destas e %d, que se obtem partindo da estacao %d para ir ate a estacao %d no sentido %s.", Rotas[menorDistancia][1],
                                                                                                                                                                                         menorDistancia,
                                                                                                                                                                                         Rotas[menorDistancia][2],
                                                                                                                                                                                         Sentido( Rotas[menorDistancia][3] ) );
   getch();
}
/******************************************************************************/
/* FUNCAO PRINCIPAL ***********************************************************/
/******************************************************************************/
int main(){

   int opcao;
   
   TLista_Inicializa( &Lista );
   TLista_Inicializa( &Maiores );
   TLista_Inicializa( &Secundaria );

   do{
      LimpaTela();
	  
	   printf( "\n Universidade Estadual de Maringa, curso de Informatica - Turma 31"  );
	   printf( "\n Lista de Exercicios 3, diciplina de Estrutura de Dados"             );
	   printf( "\n Henrique Misael Machado - ra99660"                                  );
      printf( "\n -------------------------------"                                    );
      printf( "\n Lista principal: "                                                  );
      TLista_EscreveElementosEmLinha( Lista );
      printf( "\n %d maiores elementos: ", K                                          );
      TLista_EscreveElementosEmLinha( Maiores );
      printf( "\n Lista secundaria: "                                                 );
      TLista_EscreveElementosEmLinha( Secundaria );
      printf( "\n -------------------------------"                                    );
      printf( "\n [1] Inserir um unico elemento na lista principal e empurrar"        );
      printf( "\n [2] Inserir varios elementos ao final da lista principal"           );
      printf( "\n [3] Inserir varios elementos ao final da lista secundaria"          );
      printf( "\n [4] Remover elementos do intervalo"                                 );
      printf( "\n [5] Atualizar lista dos maiores elementos da lista principal"       );
      printf( "\n [6] Separar os elementos das listas em maiores e menores"           );
      printf( "\n [7] Calcular menor distancia das maiores"                           );
      printf( "\n [0] Fechar o programa"                                              );
      printf( "\n >" );

      scanf( "%d", &opcao );
 
      switch( opcao ){
         case  0: break;
         case  1: InserirUnicoElemento();break;
         case  2: InserirVariosElementos( &Lista );break;         
         case  3: InserirVariosElementos( &Secundaria );break;
         case  4: RemoverElementosIntervalo();break;
         case  5: Exercicio4();break;         
         case  6: Exercicio6();break;
         case  7: Exercicio7();break;
         default: printf( "Nao existe opcao %d a ser executada, tente novamente.", opcao );getch();
      }

   }while( opcao );

   return opcao;
}

