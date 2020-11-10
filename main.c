// bibliotecas do sistema
#include <stdio.h>
#include <stdlib.h>

// bibliotecas do projeto
#include "pilhaEncadeada.h"

// funcao principal
int main(void)
{

  // no início a pilha está vazia, logo, o ponteiro inicio tem valor NULL
  //o ponteiro inicio conterá o endereço do primeiro elemento da pilha
  Pilha *pi[3];
  int opcao, ok, cont = 0;
  int dado, tuboSaida, tuboEntrada;

  pi[0] = criar_pilha();
  pi[1] = criar_pilha();
  pi[2] = criar_pilha();
  preencher_pilha(pi[0]);

  if (pi[0] == NULL && pi[1] == NULL && pi[2] == NULL)
    printf("\nErro na criação dos Tubos");
  imprimir_tubos(pi[0], pi[1], pi[2]);

  do
  {
    printf("Entre a pilha de saida (0 - 2): ");
    scanf("%d", &tuboSaida);
    printf("Entre a pilha de saida (0 - 2): ");
    scanf("%d", &tuboEntrada);
    printf("\n");

    if (tuboSaida < 0 || tuboSaida > 2 || tuboEntrada < 0 || tuboEntrada > 2)
      printf("\nIndices dos tubos inválidos\n\n");
    else
      movimentar(pi[tuboSaida], pi[tuboEntrada]);

    imprimir_tubos(pi[0], pi[1], pi[2]);

    if ((*pi[0]) == NULL && (*pi[1]) == NULL)
    {
      printf("!! Parabéns você ganhou !!\n\n");
      return 0;
    }

    cont++;
    printf("Movimentos: %d\n\n", cont);

  } while (0 == 0);

  return 0;
}
