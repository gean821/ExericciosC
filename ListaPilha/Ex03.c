#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//ex04 --> dada uma pilha de inteiros, remova todos os números pares mantendo a ordem dos ímpares.

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

void RemoveNumerosParesPilha(Pilha *pilha)
{
  int elementosRemovidos = 0;
  Pilha pilhaAuxiliar;
  inicializar(&pilhaAuxiliar);
  
  while (!isEmpty(pilha)) { //esvazio a pilha deixando apenas pares
    int valor = pop(pilha);
    if (valor % 2 != 0) {
      push(&pilhaAuxiliar, valor); // guardo os ímpares na pilha auxiliar.
    } else {
        elementosRemovidos++;
      }
  }
  
  while (!isEmpty(&pilhaAuxiliar)) {
    int valor = pop(&pilhaAuxiliar);  //desempilho a auxiliar e taco para a original com os valores imp.
    push(pilha, valor);
  }
  
  printf("Elemento(s) pares removido(s) com sucesso: %d\n", elementosRemovidos);
}
  


int main()
{
  Pilha p1;
  inicializar(&p1);
  
  push(&p1,10);
  push(&p1,15);
  push(&p1,20);
  push(&p1,25);
  push(&p1,14);
  push(&p1,23);
  push(&p1,16);

  RemoveNumerosParesPilha(&p1);
  imprime_pilha(&p1);

}
  
  