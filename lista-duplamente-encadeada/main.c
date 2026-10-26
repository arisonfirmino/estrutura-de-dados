#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct no {
  int info;
  struct no *prox;
  struct no *ant;
} no;

no* inicializa() {
  return NULL;
}

// - Inserir um elemento no início da lista.
no* insere_inicio(no *inicio, int valor) {
  no *novo = malloc((sizeof(no)));

  novo->info = valor;
  novo->ant = NULL; // por ser o novo início, não há nó anterior
  novo->prox = inicio; // aponta para o nó que era o antigo início

  if (inicio != NULL) {
    inicio->ant = novo; // se a lista não for vazia ajusta o ponteiro ant
  }

  return novo; // retorna o novo nó como novo início
}

// - Remover um elemento do início da lista.
no* remove_inicio(no *inicio) {
  no *aux = inicio; // auxiliar começa apontando pra onde início aponta

  if (inicio == NULL) {
    printf("Lista vazia!\n");
    return NULL;
  }

  inicio = inicio->prox; // inicio começa a apontar para o segundo nó

  if (inicio != NULL) { // se o inicio for diferente de NULL, quer dizer que a lista tem mais de um nó
    inicio->ant = NULL; // se a lista tiver mais de um nó, o anterior começa a apontar para NULL
  }

  free(aux); // remove o ponteiro que auxiliar aponta

  return inicio;
}

// - Exibir a lista.
void exibe_lista(no *inicio) {
  no *aux = inicio; // auxiliar começa apontando pra onde início aponta

  if (aux == NULL) {
    printf("Lista vazia!\n");
    return;
  }

  printf("NULL <=> ");

  while (aux != NULL) {
    printf("%d <=> ", aux->info);
    aux = aux->prox;
  }

  printf("NULL\n");
}

// - Exibir a lista invertida.
void exibe_lista_invertida(no *inicio) {
  no *aux = inicio; // auxiliar começa apontando pra onde início aponta

  if (aux == NULL) {
    printf("Lista vazia!\n");
    return;
  }

  while (aux->prox != NULL) {
    aux = aux->prox;
  }

  printf("NULL <=> ");

  while (aux != NULL) {
    printf("%d <=> ", aux->info);
    aux = aux->ant;
  }

  printf("NULL\n");
}

// - Inserir um elemento no fim da lista.
no* insere_fim(no *inicio, int valor) {
  no *novo = malloc((sizeof(no))), *aux = inicio;

  if (novo == NULL) {
    printf("Erro ao alocar memória!\n");
    return inicio;
  }

  novo->info = valor;
  novo->prox = NULL;
  novo->ant = NULL;

  if (inicio == NULL) {
    return novo;
  }

  while (aux->prox != NULL) {
    aux = aux->prox;
  }

  aux->prox = novo;
  novo->ant = aux;

  return inicio;
}

// - Remover um elemento do fim da lista.
no* remove_fim(no *inicio) {
  no *aux = inicio; // auxiliar começa apontando pra onde início aponta

  if (inicio == NULL) {
    printf("\nLista vazia!\n");
    return NULL;
  }

  if (inicio->prox == NULL) {
    free(inicio);
    return NULL;
  }

  while (aux->prox != NULL) {
    aux = aux->prox;
  }

  aux->ant->prox = NULL; // desconecta o último nó

  free(aux);

  return inicio;
}

// - Buscar um valor na lista.
void busca_valor(no *inicio, int valor) {
  no *aux = inicio;

  if (inicio == NULL) {
    printf("\nLista vazia!\n");
    return;
  }

  while (aux != NULL) {
    if (aux->info == valor) {
      printf("\nValor %d encontrado!\n", valor);
      return;
    }

    aux = aux->prox;
  }

  printf("\nValor %d não encontrado!\n", valor);
}

// - Liberar a memória utilizada na lista.
no* libera_lista(no *inicio) {
  no *aux = inicio, *aux2;

  while (aux != NULL) {
    aux2 = aux->prox;
    free(aux);
    aux = aux2;
  }

  return NULL;
}

int main() {
  setlocale(LC_ALL, "Portuguese");

  no *inicio;
	int valor, opcao;

	inicio = inicializa();

  do {
    printf("====== MENU DA LISTA DUPLAMENTE ENCADEADA ======\n");
    printf("[1] Inserir início\n");
		printf("[2] Remover início\n");
		printf("[3] Exibir lista\n");
		printf("[4] Exibir lista invertida\n");
		printf("[5] Inserir fim\n");
		printf("[6] Remover fim\n");
		printf("[7] Buscar valor\n");
		printf("[0] Sair\n");

		printf("Escolha uma opção: ");
		scanf("%d", &opcao);

    switch (opcao) {
      case 0: inicio = libera_lista(inicio);
              printf("\nPrograma finalizado!\n\a");
              break;

      case 1: printf("\nDigite o valor a ser inserido: ");
              scanf("%d", &valor);
              inicio = insere_inicio(inicio, valor);
              exibe_lista(inicio);
              break;

      case 2: inicio = remove_inicio(inicio);
              exibe_lista(inicio);
              break;

      case 3: exibe_lista(inicio);
              break;

      case 4: exibe_lista_invertida(inicio);
              break;

      case 5: printf("\nDigite o valor a ser inserido: ");
              scanf("%d", &valor);
              inicio = insere_fim(inicio, valor);
              exibe_lista(inicio);
              break;

      case 6: inicio = remove_fim(inicio);
              exibe_lista(inicio);
              break;

      case 7: printf("\nDigite o valor a ser buscado: ");
              scanf("%d", &valor);
              busca_valor(inicio, valor);
              exibe_lista(inicio);
              break;

      default: printf("\nA opção escolhida não existe! Escolha uma opção válida!\n");
    }

    printf("\nPressione Enter para continuar...");
    getchar();
    getchar();

		system("clear");
  } while (opcao != 0);
}
