#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//ex03 --> Use duas pilhas para simular o comportamento de desfazer e refazer operações(ex: Edição de texto)

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


int main()
{
  int resposta;
  Pilha undo,redo;
  inicializar(&undo);
  inicializar(&redo);
  
  push(&undo,10);
  push(&undo,20);
  push(&undo,30);

  printf("Ações após fazer..\n");
  imprime_pilha(&undo);
  printf("\n");
  
  
  printf("\nDesfazendo ação : \n");
  
  int acao = pop(&undo);
  if (acao != -1) {  //se o desfazer chegou ao topo eu empilho o numero de desfazer no refazer.
    push(&redo, acao);
  }
  printf("\n");
  imprime_pilha(&undo);
  
  do {
    
    printf("\n\nDeseja desfazer ou refazer agora? (1- desfazer CTRL+Y) 2-(refazer CTRL+Z), Sair(3).");
    scanf("%d", &resposta);
    
    switch(resposta) 
    {  
      case 1:
        acao = pop(&undo);
        if (acao != -1) {
          push(&redo, acao);
        }
        printf("\npilha Impressa novamente após desfazer :\n");
        imprime_pilha(&undo);
      break;
    
      case 2:
        acao = pop(&redo);
        if (acao != -1) {
          push(&undo, acao);
        }
        printf("\nPilha impressa após refazer : \n");
        imprime_pilha(&undo);
      break;

      case 3 :
        printf("\nSaindo da operação.\n");
      break;
    }
  } while(resposta != 3);
}
    
  
  