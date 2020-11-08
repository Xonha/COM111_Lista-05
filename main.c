
// bibliotecas do sistema
#include <stdio.h>
#include <stdlib.h>

// bibliotecas do projeto
#include "pilhaEncadeada.h"
#include "pilhaEncadeada.c"

// protótipo da função que cria um dado
int criar_dado(int *dado);

// funcao principal
int main(void)
{

  // no início a pilha está vazia, logo, o ponteiro inicio tem valor NULL
  //o ponteiro inicio conterá o endereço do primeiro elemento da pilha
  Pilha *pi[3];
  int opcao, ok;
  int dado, tuboSaida, tuboEntrada;

  // menu de opções para execuções de operações sobre a pilha
  do
  {
    printf("\n\nMenu de opções");
    printf("\n0 - Sair");
    printf("\n1 - Criar pilha");
    printf("\n2 - Liberar pilha");
    printf("\n3 - Empilhar elemento");
    printf("\n4 - Desempilhar elemento");
    printf("\n5 - Consultar topo");
    printf("\n6 - Movimentar Cubo");
    printf("\n7 - Imprimir Tubos");
    printf("\nOpção: ");
    scanf("%d", &opcao);
    printf("\n");

    switch (opcao)
    {
    case 0:

      // libera memória e finaliza programa
      liberar_pilha(pi[0]);
      liberar_pilha(pi[1]);
      liberar_pilha(pi[2]);
      printf("\nFinalizando...");
      break;

    case 1:

      // criar pilha
      pi[0] = criar_pilha();
      pi[1] = criar_pilha();
      pi[2] = criar_pilha();
      preencher_pilha(pi[0]);

      if (pi[0] != NULL && pi[1] != NULL && pi[2] != NULL)
      {
        printf("\nPilha criada com sucesso!");
      }
      else
      {
        printf("\nPilha não criada!");
      }
      break;

    case 2:

      // liberar pilha
      ok = liberar_pilha(pi[0]);

      if (ok)
      {
        printf("\nPilha liberada com sucesso!");
      }
      else
      {
        printf("\nPilha não liberada!");
      }
      break;

    case 3:

      // empilhar elemento
      ok = criar_dado(&dado);
      ok = empilhar(pi[0], dado);

      if (ok == 1)
      {
        printf("\nInserção realizada com sucesso!");
      }
      else
      {
        printf("\nFalha na inserção!");
      }

      break;

    case 4:

      // desempilhar elemento
      ok = desempilhar(pi[0]);

      if (ok == 1)
      {
        printf("\nRemoção realizada com sucesso!");
      }
      else
      {
        printf("\nFalha na remoção!");
      }
      break;

    case 5:

      ok = consultar_topo_pilha(pi[0]);

      if (ok)
      {
        printf("\nBusca realizada com sucesso!");
        printf("\nElemento no topo da pilha: ");
        printf("%d", ok);
      }
      else
      {
        printf("\nPilha vazia!");
      }

      break;

    case 6:
      printf("Entre a pilha de saida (0 - 2): ");
      scanf("%d", &tuboSaida);
      printf("Entre a pilha de saida (0 - 2): ");
      scanf("%d", &tuboEntrada);

      if (tuboSaida < 0 || tuboSaida > 2 || tuboEntrada < 0 || tuboEntrada > 2)
        printf("\nIndices dos tubos inválidos");
      else
        movimentar(pi[tuboSaida], pi[tuboEntrada]);

      break;

    case 9:
      printf("Tubo 0: ");
      ok = imprimir_pilha(pi[0]);
      printf("\nTubo 1: ");
      ok = imprimir_pilha(pi[1]);
      printf("\nTubo 2: ");
      ok = imprimir_pilha(pi[2]);
      break;

    default:
      printf("\nOpção inválida!");
      break;
    }

  } while (opcao != 10);

  return 0;
}
