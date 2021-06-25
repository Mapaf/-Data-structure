#ifndef PILHA_H

#define PILHA_H

#include<stdio.h>

#define MAX_PILHA 100




typedef int tp_item;




typedef struct{

 int topo;

 tp_item item[MAX_PILHA];

}tp_pilha;



//inicia uma pilha
void inicializa_pilha(tp_pilha *p){

 p->topo=-1;

}



//ve se  a pilha ta vazia
int pilha_vazia(tp_pilha *p){

 if(p->topo == -1) return 1;

 return 0;

}
//ve se a pilha ta cheia
int pilha_cheia(tp_pilha *p){

 if(p->topo == MAX_PILHA-1){

  return 1;

 }else{

  return 0;   

 }

}
//adiciona um item a pilha
int push(tp_pilha *p, tp_item e){

 if(pilha_cheia(p)==1)return 0;

 p->topo++;

 p->item[p->topo]=e;

 return 1;

}
//remove um item da pilha
int pop(tp_pilha *p,tp_item *e){

 if(pilha_vazia(p))return 0;

 *e=p->item[p->topo];

 p->topo--;

 return 1;

}
//mostra o item q esta no topo da pilha
int top(tp_pilha *p,tp_item *e){

 if(pilha_vazia(p))return 0;

 *e=p->item[p->topo];

 return 1;

}
//mostra os valores dentro da pilha sem remove-los
void imprime_pilha(tp_pilha p){

 tp_item e;

 while(!pilha_vazia(&p)){

  pop(&p,&e);

  printf("%d\n",e);

 }

}
//informa a altura da pilha
int altura_pilha(tp_pilha *p){

 return p->topo+1;

}
//concatena duas pilhas
int concatena_pilha(tp_pilha *p1,tp_pilha *p2 ){
	if(pilha_vazia(p2)||(p1->topo+p2->topo>MAX_PILHA-1))return 0;
	tp_pilha p3;
	inicializa_pilha(&p3);
	tp_item e;
	int i;
	while(!pilha_vazia(p2)){
		pop(p2,&e);
		push(&p3,e);
	}
	while(!pilha_vazia(&p3)){
		pop(&p3,&e);
		push(p1,e);
	}
	return 1;
	
}
//retira os numeros impares da pilha
int retira_impares(tp_pilha *p){
	if(pilha_vazia(p))return 0;
	tp_pilha ps;
	inicializa_pilha(&ps);
	tp_item e;
	while(! pilha_vazia(p)){
		pop(p,&e);
		if(e %2 ==0){
			push(&ps,e);
		}
	}
	imprime_pilha(ps);
	return 1;
}
//ve se duas pilhas sao iguais
int compara_pilha(tp_pilha p1, tp_pilha p2){

	tp_item e1, e2;

	if (pilha_vazia(&p1) && pilha_vazia(&p1)) return 1;
	if (altura_pilha(&p1) != altura_pilha(&p2)) return 0;
	
	while(!pilha_vazia(&p1)){

		pop(&p1, &e1);		
		pop(&p2, &e2);

		if (e1 != e2) return 0;
			
	}

	return 1;

}

#endif


