#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#define N 20
#define M 10000000


typedef struct NODE node;
struct NODE{
	  node* next;
	  double value;
};


node* create_list(void){
	node *head = NULL;
	return head;
}

node* create_new_node(double timeStamp){
	node* new_node;
	new_node = malloc(sizeof(node));
	if (new_node == NULL){
		printf("Error: malloc failed. Not enough memory.");
		exit(EXIT_FAILURE);
	}
	new_node->next = NULL;
	new_node->value = timeStamp;
	return new_node;
}

/*
node* add_to_list(node *list, double timeStamp){
	//allocate memory for the list
	node* new_node = (node*) malloc(sizeof(struct node));

	if(new_node == NULL){
		printf("Error: malloc failed \n");
		exit(EXIT_FAILURE);
	}

	new_node->next = list;
	new_node->value = timeStamp;

	return new_node;
}
*/

node* insert_new(node *list, node* new_node){
	node* prev, *curr;
	for(curr = list, prev = NULL;
		curr != NULL && curr->value < new_node->value;
		prev = curr, curr = curr->next)
		;

	if (prev == NULL){
		new_node->next = curr;
		return new_node;
	}
	else{
		prev->next = new_node;
		new_node->next = curr;
		return list;
	}
}

void freeList(node* list){
	node *current;
	while(list->next != NULL){
		current = list->next;
		list = list->next;
		free(current);
	}
	free(list);
}

int main(){
	srand(time(NULL));
	int i;
	double timeStamp;
	node *new_node, *list, *head;
	double t_start, t_end, delt_t;

	list = creat_list();

	//generate a sorted list containing N nodes
	for(i=0; i<N; i++){
		timeStamp = (double)rand()/RAND_MAX;
		new_node = create_new_node(timeStamp);
		list = insert_new(list, new_node);
	}

	t_start = time(NULL)*1000; //convert to ms

	//insert a new and delete the first node for M times
	for (i=0; i<M; i++){
		timeStamp = (double)rand()/RAND_MAX;
		new_node = create_new_node(timeStamp);
		list = insert_new(list, new_node);
		head = list;
		list = list->next;
		free(head);
	}

	t_end = time(NULL)*1000; //convert to ms
	delt_t= t_end-t_start;
	printf("Time Cost: %f ms\n", delt_t);

}
