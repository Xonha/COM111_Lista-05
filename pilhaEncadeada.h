// TAD para Pilha Dinâmica Encadeada baseado no livro "Estrutura de dados descomplicada em lingugem C (André Backes)"

#ifndef _PILHA
#define _PILHA

typedef struct elemento Elemento;
typedef Elemento *Pilha;

// funções para alocar e desalocar memória
int criar_dado(int *dado);
Pilha *criar_pilha();
int liberar_pilha(Pilha *pi);

// função para obter informação da pilha
int tamanho_pilha(Pilha *pi);

// funções para empilhar e desempilhar elementos da pilha
int empilhar(Pilha *pi, int dado);
int desempilhar(Pilha *pi);

// função para consultar elemento no topo da pilha
int consultar_topo_pilha(Pilha *pi);

int imprimir_pilha(Pilha *pi);
void preencher_pilha(Pilha *pi);
int movimentar(Pilha *pi, Pilha *pi2);
void imprimir_tubos(Pilha *pi, Pilha *pi2, Pilha *pi3);
void printa_letras(int dado);

#endif