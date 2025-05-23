#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//ex05 --> dada uma pilha de inteiros, use apenas operacoes de pilha para ordena-la em ordem crescente (pode usar pilha auxiliar).

//no exercicio tem comentários para o meu próprio entendimento e revisão futuramente !!

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

void OrdenaPilhaCrescente(Pilha *pilha)
{
  
  Pilha PilhaAuxiliar;
  inicializar(&PilhaAuxiliar);
  
  while (!isEmpty(pilha)) {
    int temporaria = pop(pilha);
    while (!isEmpty(&PilhaAuxiliar) && PilhaAuxiliar.dados[PilhaAuxiliar.topo] > temporaria) {
      push(pilha, pop(&PilhaAuxiliar));
    }
    push(&PilhaAuxiliar, temporaria);
  }

  while (!isEmpty(&PilhaAuxiliar)) { 
    push(pilha, pop(&PilhaAuxiliar));
  }
}

int main()
{
  
  Pilha p1;
  inicializar(&p1);
  
  push(&p1,10);
  push(&p1,15);
  push(&p1,12);
  push(&p1,16);
  push(&p1,11);
  push(&p1,9);
  push(&p1,3);
  
  OrdenaPilhaCrescente(&p1);
  imprime_pilha(&p1);
  
}
  
  