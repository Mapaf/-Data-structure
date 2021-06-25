#ifndef SL_LIST
#define SL_LIST

#include <stdlib.h>
#include <stdio.h>

typedef int tp_item;

typedef struct tp_slistNode{
	
	tp_item info;
	
	struct tp_slistNode *next;
		
}tp_slist;

tp_slist *start_slist(){
	
	return NULL;
	
}

int slist_empty(tp_slist *l){
	
	if (l == NULL) return 1;
	
	else return 0;
	
}

tp_slist *alloc_slist(){
	
	tp_slist *list;
	
	list = (tp_slist *) malloc(sizeof(tp_slist));
	
	return list;
	
}

int insert_slist_end (tp_slist **l, tp_item e){
	
	tp_slist *new_node, *atu;
	
	new_node = alloc_slist();
	
	if (new_node == NULL) return 0;
	
	new_node->info = e;
	new_node->next = NULL;
	
	if (slist_empty(*l)) *l = new_node;
	
	else{
		
		atu = *l;
		
		while(atu->next != NULL){
		
			atu = atu->next;
		
		} 
		
		atu->next = new_node;
		
	}
	
	return 1;
		
	}
	
int insertOrder_slist(tp_slist **l, tp_item e){
	
	tp_slist *new_node, *atu, *ant;
	
	new_node = alloc_slist();
	
	if (new_node == NULL) return 0;
	
	new_node->info = e;
	
	atu = *l;
	ant = NULL;
	
	while((atu != NULL) && (atu->info < e)){
		
		ant = atu;
		atu = atu->next;
		
	}
	
	if (ant == NULL) *l = new_node;
	
	else ant->next = new_node;
	
	new_node->next = atu;
	
	return 1;
	
}
	
void print_slist (tp_slist *l){
	
	tp_slist *atu;
	atu = l;
	
	while (atu != NULL){
		
		printf("%d\n", atu->info);
		atu = atu->next;
		
		
	}
	
}

int remove_slist (tp_slist **l, tp_item e){
	
	tp_slist *ant, *atu;
	atu = *l;
	ant = NULL;
	
	while(( atu != NULL) && ( atu->info != e )){
		
		ant = atu;
		
		atu = atu->next;
		
	}
	
	if (atu == NULL) return 0;
	if (ant == NULL) *l = atu->next;
	
	else ant->next = atu->next;
	
	free(atu);
	atu = NULL;
	
}

tp_slist *search_slist (tp_slist *l, tp_item e){
	
	tp_slist *atu;
	
	atu = l;
	
	while((atu != NULL) && (atu->info != e)){
		
		atu = atu->next;
		
	}
	
	if (atu == NULL) return NULL;
	
	return atu;
	
}

int size_slist (tp_slist *l){
	
	int cont = 0;
	
	tp_slist *atu;
	atu = l;
	
	while( atu != NULL){
		
		cont++;
		
		atu = atu->next;
		
	}
	
	return cont;
	
}

void destroi_slist (tp_slist **l){
	
	tp_slist *atu;
	atu = *l;
	
	while (atu != NULL){
		
		*l = atu->next;
		
		free(atu);
		
		atu = *l;
		
	}
	
	*l = NULL;
	
}

void concatenate_slists(tp_slist **l1, tp_slist **l2){
	
	tp_slist *atu;
	
	atu = *l1;
	
	while(atu->next != NULL){
		
		atu = atu->next;
		
	}
	
	atu->next = *l2;
	atu = *l2;
	
	while(atu->next != NULL){
		
		atu = atu->next;
		
	}
	
	atu->next = *l1;
	
	*l2 = *l1;
	
}

tp_slist *divide_slist(tp_slist *list1, int n){
	
	tp_slist *p, *atu;
	
	p = search_slist(list1, n);
	
	atu = p->next;
	
	p->next = NULL;
	
	return atu;
	
}

#endif
