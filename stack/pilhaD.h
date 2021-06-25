#ifndef D_STACK
#define D_STACK

#include <stdio.h>
#include <stdlib.h>

typedef int tp_item;

typedef struct tp_dstackNodeAux{
	
	tp_item info;
	
	struct tp_dstackNodeAux *prox;
	
}tp_dstackNode;

typedef struct{
	
	tp_dstackNode *top;
	
}tp_dstack;

tp_dstack *start_dstack(){
	
	tp_dstack *stack = (tp_dstack *) malloc(sizeof(tp_dstack));
	stack->top = NULL;
	
	return stack;
	
}

tp_dstackNode *allocStackNode(){
	
	tp_dstackNode* pt;
	
	pt = (tp_dstackNode *) malloc(sizeof(tp_dstackNode));
	
	return pt;
	
}

int dstack_empty(tp_dstack *stack){
	
	if (stack->top == NULL) return 1;
	
	return 0;
	
}
//coloca um elemento
int push(tp_dstack *stack, tp_item e){
	
	tp_dstackNode *_new;
	_new = allocStackNode();
	
	if (!_new) return 0;
	
	_new->info = e;
	
	if(stack->top == NULL){
		
		_new->prox = NULL;
		stack->top = _new;
		
	}
	
	else{
		
		_new->prox = stack->top;
		stack->top = _new;
		
	}
	
	return 1;
}
//tira um elemento
int pop(tp_dstack *stack, tp_item *e){
	
	tp_dstackNode *atu;
	
	if(dstack_empty(stack)) return 0;
	
	*e = stack->top->info;
	atu = stack->top;
	stack->top = stack->top->prox;
	
	free(atu);
	return 1;
	
}
//armazena no tp item e o valor de top
int top(tp_dstack *stack, tp_item *e){
	
	if (dstack_empty(stack)) return 0;
	
	*e = stack->top->info;
	
	
	return 1;
	
}
//ele printa mais limpa a pilha
void print_dstack(tp_dstack *stack){
	
	tp_item e;
	
	//creates and initializes an auxiliar stack
	
	while(!dstack_empty(stack)){
		
		pop(stack, &e);
		
		printf("%d ", e);
		
	}
	
	printf("\n");
	
}
//ele printa e n deleta
void print_fdstack(tp_dstack *stack){
	
	tp_dstack *stack_aux;
	tp_item e;
	
	stack_aux = start_dstack();
	
	while(!dstack_empty(stack)){
		
		pop(stack, &e);
		push(stack_aux, e);
		
	}
	
	while(!dstack_empty(stack_aux)){
		
		pop(stack_aux, &e);
		printf("%d ", e);
		push(stack, e);
		
	}
	
	stack = stack_aux;
	
	printf("\n");
	
	free(stack_aux);
	
}

#endif
