#ifndef DL_LIST
#define DL_LIST

#include <stdio.h>
#include <stdlib.h>

typedef int tp_item;
typedef struct tp_dlistAuxNode{
	
	tp_item info;
	
	struct tp_dlistAuxNode *ant;
	struct tp_dlistAuxNode *next;
	
	//int size;
	
}tp_dlistNode;

typedef struct{
	
	tp_dlistNode *start;
	tp_dlistNode *end;
	
}tp_dlist;

tp_dlist *start_dlist(){
	
	tp_dlist *list = (tp_dlist *) malloc(sizeof(tp_dlist));
	
	list->start = NULL;
	list->end = NULL;
  //list->size = 0;	
	
	return list;
	
}

tp_dlistNode *allocDlistNode(){
	
	tp_dlistNode *pt;
	
	pt = (tp_dlistNode *) malloc(sizeof(tp_dlistNode));
	
	return pt;
	
}

int dlist_empty(tp_dlist *list){
	
	if ((list->start == NULL) && (list->end == NULL)) return 1;
	
	return 0;
	
}

int insert_dlist_end (tp_dlist *list, tp_item e){
	
	tp_dlistNode *_new;
	
	_new = allocDlistNode();
	
	if (!_new) return 0;
	
	_new->info = e;
	
	if (dlist_empty(list)){
		
		_new->next = NULL;
		_new->ant = NULL;
		
		list->start = list->end = _new;
		
	}
	
	else{
		
		_new->next = NULL;
		_new->ant = list->end;
		
		list->end->next = _new;
		list->end = _new;
		
	}
	
	//list->size++;
	
	return 1;
}

int insert_dlist_start (tp_dlist *list, tp_item e){
	
	tp_dlistNode *_new;
	
	_new = allocDlistNode();
	
	if (!_new) return 0;
	
	_new->info = e;
	
	if (dlist_empty(list)){
		
		_new->next = NULL;
		_new->ant = NULL;
		
		list->start = list->end = _new;
		
	}
	
	else{
		
		_new->ant = NULL;
		_new->next = list->start;
		
		list->start->ant = _new;
		list->start = _new;
		
	}
	
	//list->size++;
	
	return 1;
}

void print_dlist(tp_dlist *list, int order){
	
	if (dlist_empty(list)){
		
		printf("The list is empty\n");
		
	}
	
	else{
	
		tp_dlistNode *atu;
	
		switch(order){
		
			case 1: 
				atu = list->start;
				
				while(atu != NULL){
					
					printf("%d ", atu->info);
					atu = atu->next;
					
				}
			
				printf("\n");
				
				break;
				
			case 2:
			
				atu = list->end;
			
				while(atu != NULL){
				
					printf("%d ", atu->info);
				
					atu = atu->ant;
				
				}
			
				printf("\n");
			
				break;
			
			default: printf("Invalid code\n");
				
		}
	}
	
}

int remove_dlist(tp_dlist *list, tp_item e){
	
	tp_dlistNode *atu;
	
	atu = list->start;
	
	while( (atu != NULL) && (atu->info != e)) atu = atu->next;
	
	if (atu == NULL){
	 
	 printf("Not removed, element not present in list\n");
	 
	 return 0;
	 
	}
	
	if (list->start == list->end) list->start = list->end = NULL;
	
	else{
		
		if (list->start == atu){
			
			list->start = atu->next;
			atu->next->ant = NULL;
			
		}
		
		else{
			
			if (list->end == atu){
				
				list->end = atu->ant;
				atu->ant->next = NULL;
				
			}
			
			else{
				
				atu->next->ant = atu->ant;
				atu->ant->next = atu->next;
				
			}
			
		}
				
	}
	
	free(atu);
  //list->size--;
  
	return 1;
	
}

tp_dlistNode *search_dlist(tp_dlist *list, tp_item e){
	
	tp_dlistNode *atu;
	
	atu = list->start;
	
	while((atu != NULL) && (atu->info != e)){
		
		atu = atu->next;
		
	}
	
	return atu;
}

#endif
