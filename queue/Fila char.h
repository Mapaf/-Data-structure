#ifndef FILA_H
#define FILA_H
#define MAX 6

#include <stdio.h>

typedef char tp_item;

typedef struct{
	tp_item item[MAX];
	int ini,fim;
}tp_fila;

void inicializa_fila(tp_fila *f){
	f->ini=f->fim=MAX-1;
}

int fila_vazia(tp_fila *f){
	if(f->ini==f->fim) return 1;
	return 0;
}

int proximo(int pos){
	if(pos==MAX-1)return 0;
	else return ++pos;
}

int fila_cheia(tp_fila *f){
	if(proximo(f->fim)==f->ini) return 1;
	return 0;
}

char insere_fila(tp_fila *f,tp_item e){
	if(fila_cheia(f)) return 0;
	f->fim=proximo(f->fim);
	f->item[f->fim]=e;
	return 1;
}

int remove_fila(tp_fila *f,tp_item *e){
	if(fila_vazia(f))return 0;
	f->ini=proximo(f->ini);
	*e=f->item[f->ini];
	return 1;
}

void imprime_fila(tp_fila f){
	tp_item e;
	while(!fila_vazia(&f)){
		remove_fila(&f,&e);
		
	printf("%c\n",e);
	
	}
}

int tamanho_fila(tp_fila *f){
	if(fila_vazia(f))return 0;
	if(fila_cheia(f))return MAX-1;
	if(f->fim>f->ini)return(f->fim - f->ini);
	else return (MAX - f->ini + f->fim);
}

#endif
