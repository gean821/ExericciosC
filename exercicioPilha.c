////implemente um menu que permita ao usuário escolher entre as ações de
/// empilhar (push), desempilhar (pop) e imprimir a pilha.

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 5

typedef struct {
  int dados[TAMANHO];
  int topo;
} Pilha;

bool isEmpty(Pilha *pilha) { // usamos ponteiro pq n da para passar o vetor por
                             // parametro em C, apenas o ponteiro de um vetor.
  return pilha->topo == -1;
}

void push(Pilha *pilha,
          int data) { // recebe a pilha e o valor que vamos adicionar;
  if (pilha->topo == TAMANHO - 1) {
    printf("Pilha está cheia, não é possível adicionar itens.");
    return;
  }
  pilha->topo++;
  pilha->dados[pilha->topo] = data;
}

void inicializar(Pilha *p) { p->topo = -1; }

void imprimir(Pilha *pilha) {
  if (isEmpty(pilha)) {
    printf("a Pilha está vazia.");
  }
  for (int i = 0; i <= pilha->topo; i++) {
    printf("\nValor na pilha: %d\n", pilha->dados[i]);
  }
}

int pop(Pilha *pilha) {
  if (isEmpty(pilha)) {
    printf("a pilha está vazia.");
    return -1;
  }
  int removido = pilha->dados[pilha->topo]; // removo o elemento que está no topo da pilha;
  pilha->topo--;
  printf("Valor removido ---> %d", removido);
  return removido;
}

void topo(Pilha *pilha) {
  if (isEmpty(pilha)) {
    printf("pilha vazia.");
    return;
  }
  printf("topo da pilha : %d\n", pilha->dados[pilha->topo]);
}

int main() {
  int escolha;
  Pilha pilha1;
  inicializar(&pilha1);

  do {
    printf("\n-----------------------------------------\n");
    printf("\t\nMenu\n");
    printf("\n1.Empilhar pilha.\n");
    printf("\n2.Desempilhar pilha.\n");
    printf("\n3.Imprimir pilha.\n");
    printf("\n4.Sair do Menu.\n");
    scanf("%d", &escolha);

    switch (escolha) {
    case 1:
      printf("\nDiga um valor para empilhar na pilha : \n");
      int valor;
      scanf("%d", &valor);
      push(&pilha1, valor);
      break;
    case 2:
      printf("\nDesempilhando pilha :\n");
      pop(&pilha1);
      break;
    case 3:
      printf("\nImprimindo pilha --> \n");
      imprimir(&pilha1);
      break;
    case 4:
      printf("\nSaindo do menu...");
      break;
    }
  } while (escolha != 4);
}
