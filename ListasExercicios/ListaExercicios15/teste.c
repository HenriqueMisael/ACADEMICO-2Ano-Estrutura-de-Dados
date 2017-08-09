// ************************************************************
//   Exemplo de uso de arquivo binário
//   Este programa lê um arquivo binário e imprime o seu
//   conteudo na tela.
// ************************************************************
#include <stdio.h>


void main()
{
  FILE *arq;
  int Vet[100];
  int result;
  int i;
  // Abre um arquivo BINÁRIO para LEITURA
  arq = fopen("teste.in", "rb");
  if (arq == NULL)  // Se houve erro na abertura
  {
     printf("Problemas na abertura do arquivo\n");
     return;
  }
  result = fread (&Vet[0], sizeof(double), 100, arq);
  printf("Nro de elementos lidos: %d\n", result);

  for (i=0; i<result; i++)
      printf("%lf\n", Vet[i]);

  fclose(arq);
}
