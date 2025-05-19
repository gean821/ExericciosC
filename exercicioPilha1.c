#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define TAMANHO 5

int stack[TAMANHO];
int top = -1;

bool isEmpty() { return top == -1; }

void push(int data) {
  if (top == TAMANHO - 1) {
    printf("A Pilha está cheia.\n");
    return;
  }

  top++;
  stack[top] = data;
}

int pop() {
  if (isEmpty()) {
    printf("A pilha está vazia.\n");
    return -1;
  }

  int temp = stack[top];
  top--;
  return temp;
}

void imprimir() {
  if (isEmpty()) {
    printf("A Pilha está vazia.\n");
    return;
  }
  printf("\nElementos da pilha:\n");
  for (int i = 0; i <= top; i++) {
    printf("%d\n", stack[i]);
  }
  printf("topo\n");
}

int main() {
  int escolha, valor;

  do {
    printf("\n-----------------------------------------\n");
    printf("\tMenu\n");
    printf("1. Empilhar pilha.\n");
    printf("2. Desempilhar pilha.\n");
    printf("3. Imprimir pilha.\n");
    printf("4. Sair do Menu.\n");
    printf("Escolha: ");
    scanf("%d", &escolha);

    switch (escolha) {
    case 1:
      printf("\nDiga um valor para empilhar na pilha: ");
      scanf("%d", &valor);
      push(valor);
      break;
    case 2:
      printf("\nValor removido da pilha: %d\n", pop());
      break;
    case 3:
      printf("\nImprimindo pilha:\n");
      imprimir();
      break;
    case 4:
      printf("\nSaindo do menu...\n");
      break;
    }
  } while (escolha != 4);
}
