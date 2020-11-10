// TAD para Lista Dinâmica Encadeada baseado no livro "Estrutura de dados descomplicada em lingugem C (André Backes)"

#include <stdio.h>
#include <stdlib.h>
#include "pilhaEncadeada.h"

// definição do struct elemento
struct elemento
{
  int dado;
  Elemento *prox;
};

int criar_dado(int *dado)
{
  printf("\nDigite um número inteiro: ");
  scanf("%d", dado);

  return 1;
}

// função para alocar memória do tipo Pilha
Pilha *criar_pilha()
{
  Pilha *pi = (Pilha *)malloc(sizeof(Pilha));

  // se a lista foi criada corretamente, indica que ela está vazia
  if (pi != NULL)
    *pi = NULL;

  return pi;
}

void preencher_pilha(Pilha *pi)
{
  int vogais[5] = {5, 4, 3, 2, 1};

  for (int i = 0; i < 5; i++)
  {
    empilhar(pi, vogais[i]);
  }
}

// função para liberar memória
int liberar_pilha(Pilha *pi)
{
  if (pi == NULL)
  {
    return 0;
  }

  // libera todos os nós da pilha que foram alocados
  Elemento *no;
  while (*pi != NULL)
  {
    no = *pi;
    *pi = (*pi)->prox;
    free(no);
  }

  // libera o ponteiro da pilha
  free(pi);

  return 1;
}

// função para obter o tamanho da pilha
int tamanho_lista(Pilha *pi)
{
  // a pilha não foi criada corretamente
  if (pi == NULL)
  {
    return 0;
  }

  int cont = 0;
  Elemento *no = *pi;

  // acrescenta cont até acabar a lista
  while (no != NULL)
  {
    cont++;
    no = no->prox;
  }

  return cont;
}

// função para alocar memória do tipo Elemento
Elemento *criar_elemento()
{
  Elemento *no = (Elemento *)malloc(sizeof(Elemento));

  return no;
}

// função para inserir elemento no início da pilha (topo)
int empilhar(Pilha *pi, int dado)
{
  if (pi == NULL)
    return 0;

  // cria um elemento novo
  Elemento *no = criar_elemento();

  if (no == NULL)
    return 0;

  // atribui valores ao elemento novo
  no->dado = dado;
  no->prox = (*pi);

  // insere elemento no início da pilha (topo)

  if ((*pi) == NULL)
  {
    *pi = no;
  }
  else if ((*pi)->dado < no->dado)
  {
    printf("Ordem não alfabetica\n\n");
    return 0;
  }
  else
  {
    *pi = no;
  }

  return 1;
}

// função para remover elemento do início da pilha (topo)
int desempilhar(Pilha *pi)
{
  if (pi == NULL)
    return 0;

  // pilha vazia, não remove nada
  if ((*pi) == NULL)
    return 0;

  // muda inicio para o proximo elemento
  Elemento *atual;
  atual = *pi;
  *pi = atual->prox;

  // libera Elemento atual
  free(atual);

  return 1;
}

// função para consultar o primeiro elemento (topo)
int consultar_topo_pilha(Pilha *pi)
{
  // verifica se a pilha foi criada corretamente e se não está vazia
  if (pi == NULL || *pi == NULL)
    return 0;

  // copia o dado do topo da pilha (início da lista)
  int dado = (*pi)->dado;

  return dado;
}

int movimentar(Pilha *pi, Pilha *pi2)
{
  int ok, res;
  res = consultar_topo_pilha(pi);
  if (res != 1 && res != 2 && res != 3 && res != 4 && res != 5)
  {
    printf("Nada nesse tubo!\n\n");
    return 0;
  }

  ok = empilhar(pi2, res);
  if (ok == 1)
    ok = desempilhar(pi);
  else
    return 0;

  return 1;
}

void imprimir_tubos(Pilha *pi, Pilha *pi2, Pilha *pi3)
{
  printf("Tubo 1: ");
  imprimir_pilha(pi);
  printf("\nTubo 2: ");
  imprimir_pilha(pi2);
  printf("\nTubo 3: ");
  imprimir_pilha(pi3);
  printf("\n\n");
}

int imprimir_pilha(Pilha *pi)
{
  if (pi == NULL || (*pi) == NULL)
    return 0;

  Elemento *aux = (*pi);

  while (aux->prox != NULL)
  {
    printa_letras(aux->dado);
    aux = aux->prox;
  }
  printa_letras(aux->dado);

  return 1;
}

void printa_letras(int dado)
{
  switch (dado)
  {
  case 1:
    printf("A");
    break;
  case 2:
    printf("B");
    break;
  case 3:
    printf("C");
    break;
  case 4:
    printf("D");
    break;
  case 5:
    printf("E");
    break;
  }
}
