#ifndef LISTA_H
#define LISTA_H
#include<stdio.h>
#define MAX_LISTA 5

typedef int tp_item;

typedef struct{
	tp_item item[MAX_LISTA];
	int ini,fim;
}tp_lista;

//inicializar a lista
void inicializa_lista(tp_lista *lista){
	lista->fim = lista->ini = 0;
}

//verificar se a lista esta vazia
int lista_vazia(tp_lista* lista){
	if(lista->ini == lista->fim){
		return 1;
	}else{
		return 0;
	}
}

//verificar se a lista esta cheia
int lista_cheia(tp_lista *lista){
	if(lista->fim == MAX_LISTA){
		return 1;
	}else{
		return 0;
	}
}

//insira um item no final da lista
int insere_lista_no_fim(tp_lista *lista,tp_item e){
	if(lista_cheia(lista)){
		return 0;
	}else{
		lista->item[lista->fim]= e;
		lista->fim++;
		return 1;
	}
}

//imprimir uma lista toda
void imprime_lista(tp_lista *lista){
	int i;
	printf("elementos da lista:");
	for(i=0;i<lista->fim;i++){
		printf("%d",lista->item[i]);
	}
	printf("\n");
}

//remover um item da lista
int remove_lista(tp_lista *lista,tp_item e ){
	int i=0;
	if(lista_vazia(lista)){//se a lista estiver vazia
		return 0;
	}
	while((i<lista->fim) && (lista->item[i] != e)){
		i++;
	}
	if(i==lista->fim){// se nao achou o elemento
		return 0;
	}
	for(;i<lista->fim;i++){
		lista->item[i]=lista->item[i+1];
	}
	lista->fim--;
	return 1;
}

#endif
