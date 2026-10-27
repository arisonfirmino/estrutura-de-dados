#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// definiçào do nó
typedef struct no {
  float info;
  struct no *prox;
} no;

// definição do descritor
typedef struct {
  no *inicio;
  no *fim;
} fila;

// inicialização da fila
fila* inicializa() {
  fila *f = malloc(sizeof(fila));

  f->inicio = NULL;
  f->fim = NULL;

  return f;
}

// - Enfileirar.
void enfileira(fila *f, float valor) {
  no *novo = malloc(sizeof(no));

  novo->info = valor;
  novo->prox = NULL;

  // se a fila estiver vazia
  if (f->inicio == NULL) {
    f->inicio = novo;
  } else {
    f->fim->prox = novo;
  }

  f->fim = novo;
}

// - Desenfileirar.
void desinfileira(fila *f) {
  no *aux = f->inicio;

  // se a fila estiver vazia
  if (f->inicio == NULL) {
    printf("\nFila vazia!\n");
    return;
  }

  f->inicio = f->inicio->prox; // avança o início para o próximo nó

  // se a fila ficou vazia, atualiza o fim
  if (f->inicio == NULL) {
    f->fim = NULL;
  }

  free(aux);
}

// - Exibir a fila.
void exibe_lista(fila *f) {
  no *aux = f->inicio;

  // se a fila estiver vazia
  if (f->inicio == NULL) {
    printf("\nFila vazia!\n");
    return;
  }

  while (aux != NULL) {
    printf("%.2f -> ", aux->info);
    aux = aux->prox;
  }

  printf("NULL\n");
}

// - Liberar a memória utilizada na fila.
void libera_fila(fila *f) {
  no *aux;

  if (f == NULL) {
    return;
  }

  while (f->inicio != NULL) {
    aux = f->inicio;
    f->inicio = f->inicio->prox;

    free(aux);
  }

  f->fim = NULL;

  free(f);
}

int main() {
  setlocale(LC_ALL, "Portuguese");

  fila *f = inicializa();

  float valor;
  int opcao;

  do {
    printf("====== MENU DA FILA ======\n");
    printf("[1] Enfileirar\n");
		printf("[2] Desenfileirar\n");
		printf("[3] Exibir fila\n");
		printf("[0] Sair\n");

		printf("Escolha uma opção: ");
		scanf("%d", &opcao);

    switch (opcao) {
      case 0: libera_fila(f);
              f = NULL;
              printf("\nPrograma finalizado!\n\a");
              break;

      case 1: printf("\nDigite o valor a ser inserido: ");
              scanf("%f", &valor);
              enfileira(f, valor);
              exibe_lista(f);
              break;

      case 2: desinfileira(f);
              exibe_lista(f);
              break;

      case 3: exibe_lista(f);
              break;

      default: printf("\nA opção escolhida não existe! Escolha uma opção válida!\n");
    }

    printf("\nPressione Enter para continuar...");
    getchar();
    getchar();

		system("clear");
  } while (opcao != 0);
}
