#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//dado um vetor de inteiros, use uma pilha para inverter a ordem dos elementos

//no exercicio tem comentários para o meu próprio entendimento e revisão futuramente !!

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define TAMANHO 10

typedef struct {
    int dados[TAMANHO];
    int topo;
} Pilha;

bool isEmpty(Pilha *p){
  return p->topo == -1;
}

void inicializar(Pilha *p){
    p->topo = -1;
}

void push(Pilha *p, int dado){

  if(p->topo == TAMANHO - 1){
    printf("Pilha Cheia!");
    return;
  }

  p->topo++;
  p->dados[p->topo] = dado;

}

int imprime_pilha(Pilha *p){

  if(isEmpty(p)){
    printf("Pilha Vazia");
    return -1;
  }
  
  for(int i  = 0; i <= p->topo; i++){
    printf("%d -> ", p->dados[i]);
  }
  
  printf("topo");
  return p->topo;
}


int pop(Pilha *p){

  if(isEmpty(p)){
    printf("Pilha Vazia!");
    return -1;
  }

  int temp = p->dados[p->topo];
  p->topo--;
  return temp;
}

void topo(Pilha *p){
  if(isEmpty(p)){
    printf("Pilha Vazia!");
    return;
  }

  printf("\n\nTopo => %d", p->dados[p->topo]);
}


int main()
{
  
  Pilha pilha1;
  int vetor[] = {1,2,3,4,5,6};
  
  inicializar(&pilha1);
  int tamanhoVetor = sizeof(vetor) / sizeof(vetor[0]);

  printf("Dados do vetor antes :\n");
  for (int i = 0; i < tamanhoVetor; i++) {
    printf("%d ", vetor[i]);
    push(&pilha1, vetor[i]);  
  }

  printf("\n\nVetor após ser invertido pela pilha:\n");
  for (int i = 0; i < tamanhoVetor; i++) {
    vetor[i] = pop(&pilha1);   // aqui ele está desempilhando cada indice e salvando no vetor
    printf("%d ", vetor[i]);
  }
}




