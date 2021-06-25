#ifndef DQUEUE_H
#define DQUEUE_H

#include <stdio.h>
#include <stdlib.h>

typedef int tp_item;

typedef struct tp_dqueueNodeAux{
	
	tp_item info;
	
	struct tp_dqueueNodeAux *prox;
	
}tp_dqueueNode;

typedef struct{
	
	tp_dqueueNode *start;
	tp_dqueueNode *end;
	
	//int size;

}tp_dqueue;

tp_dqueue *start_dqueue(){
	
	tp_dqueue *queue = (tp_dqueue *) malloc(sizeof(tp_dqueue));
	queue->start = NULL;
	queue->end = NULL;
	
	return queue;
	
}

tp_dqueueNode *allocQueueNode(){
	
	tp_dqueueNode* pt;
	
	pt = (tp_dqueueNode *) malloc(sizeof(tp_dqueueNode));
	
	return pt;
	
}

int dqueue_empty(tp_dqueue *queue){
	
	if(queue->start == NULL) return 1;
	
	return 0;
	
}

int insert_dqueue(tp_dqueue *queue, tp_item e){
	
	tp_dqueueNode *_new;
	_new = allocQueueNode();
	
	if(!_new) return 0;
	
	_new->info = e;
	_new->prox = NULL;
	
	if(queue->start == NULL) queue->start = _new;
	
	else queue->end->prox = _new;
	
	queue->end = _new;
	
	return 1;
}

int remove_dqueue(tp_dqueue *queue, tp_item *e){
	
	tp_dqueueNode *aux;
	
	if(dqueue_empty(queue)) return 0;
	
	*e = queue->start->info;
	aux = queue->start;
	
	if(queue->start == queue->end) queue->start = queue->end = NULL;
	else queue->start = queue->start->prox;
	
	free(aux);
	
	return 1;
	
}

void print_dqueue(tp_dqueue *queue){
	
	tp_dqueue *queue_aux;
	tp_item e;
	
	queue_aux = start_dqueue();
	
	while(!dqueue_empty(queue)){
		
		remove_dqueue(queue, &e);
			
		printf("%d ", e);
		
		insert_dqueue(queue_aux, e);
			
	}
	
	while(!dqueue_empty(queue_aux)){
		
		remove_dqueue(queue_aux, &e);
		insert_dqueue(queue, e);
		
	}
	
}

#endif
