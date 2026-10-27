#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct no {
  float info;
  struct no *prox;
} no;

typedef struct {
  no *topo;
} pilha;

// inicializa a pilha
pilha *inicializa() {
  pilha *p = malloc(sizeof(pilha));

  p->topo = NULL;

  return p;
}

// - Push.
void push(pilha *p, float valor) {
  no *novo = malloc(sizeof(no));

  novo->info = valor;
  novo->prox = p->topo;
  p->topo = novo;
}

// - Pop.
void pop(pilha *p) {
  no *aux = p->topo;

  if (p->topo == NULL) {
    printf("\nPilha vazia!\n");
    return;
  }

  p->topo = p->topo->prox;

  free(aux);
}

// - Exibir a pilha.
void exibe_pilha(pilha *p) {
  no *aux = p->topo;

  if (p->topo == NULL) {
    printf("\nPilha vazia!\n");
    return;
  }

  while (aux != NULL) {
    printf("%.2f -> ", aux->info);
    aux = aux->prox;
  }

  printf("NULL\n");
}

// - Liberar a memória utilizada na pilha.
void libera_pilha(pilha *p) {
  no *aux;

  if (p == NULL) {
    return;
  }

  while (p->topo != NULL) {
    aux = p->topo;
    p->topo = p->topo->prox;
    free(aux);
  }

  free(p);
}

int main() {
  setlocale(LC_ALL, "Portuguese");

  pilha *p = inicializa();

  float valor;
  int opcao;

  do {
    printf("====== MENU DA PILHA ======\n");
    printf("[1] Push\n");
		printf("[2] Pop\n");
		printf("[3] Exibir pilha\n");
		printf("[0] Sair\n");

		printf("Escolha uma opção: ");
		scanf("%d", &opcao);

    switch (opcao) {
      case 0: libera_pilha(p);
              p = NULL;
              printf("\nPrograma finalizado!\n\a");
              break;

      case 1: printf("\nDigite o valor a ser inserido: ");
              scanf("%f", &valor);
              push(p, valor);
              exibe_pilha(p);
              break;

      case 2: pop(p);
              exibe_pilha(p);
              break;

      case 3: exibe_pilha(p);
              break;

      default: printf("\nA opção escolhida não existe! Escolha uma opção válida!\n");
    }

    printf("\nPressione Enter para continuar...");
    getchar();
    getchar();

		system("clear");
  } while (opcao != 0);
}
