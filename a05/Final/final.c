/**
 * ---------------------------------
 * Student Name:Mubin Qureshi
 * Student ID:180181900
 * Student Email:qure1900@mylaurier.ca
 * ---------------------------------
 */

/**
 * ---------------------------------
 *
 * Put your academic honesty certification
 * in this box
 *I certify that I completed this final exam according to academic honesty guidelines. I attest that
I did not use any external help, neither in person nor virtually. I understand that plagiarizing will
lead to my failure in the course, in addition to other penalties according to the University
policies.
 * ---------------------------------
 */

/**
 * ---------------------------------
 *
 * If you have any comments to the instructor
 * put it in this box
 *
 * ---------------------------------
 */
 
# include <stdio.h>
# include <stdlib.h>
# include <assert.h>
# include "final.h"
# include "data_structures.h"

//--------------- Task 1 -----------------------
Stack* sort_stacks(Stack *stacks[5], const int size){

int sum = 0;
int i;
	for (i = 0; i < size;i++){
		sum+= len_stack(stacks[i]);
	}
	Stack* sorted;
	sorted = create_stack(sum);

	int min;
	while (sum > 0) {
		min = 0;

		for (i = 0; i < size; i++) {
			if (peek_stack(stacks[min]) < peek_stack(stacks[i])) {
				min = i;
			}
		}
		Data* d = NULL;
		d = pop_stack(stacks[min]);
		push_stack(sorted, d);
		sum--;
	}
	return sorted;
}

//--------------- Task 2 -----------------
int delete_mid_list(List* list){

	if(is_empty_list(list)){
		printf("Error(delete_mid_list): empty list\n");
		return -1;
	}

	int cut=list->size/2;
	if (list->size % 2 ==0&& cut != 0){
		cut = cut -1;
	}
	//printf("%d\n",cut);

	int x = 0;
	Node *previous = NULL;
	Node *current = list->head;


	if (list->size==1){

		list->head = NULL;

		list->size--;
		destroy_node(&current);
		return cut;

	}

	if (list->size==2){
		list->head=current->next;
		destroy_node(&current);
		list->size--;
		return cut;

	}

	while (x<cut) {
		previous = current;
		current = current->next;
		x++;
	}

	if (list->size == 1)
		list->head = NULL;
	else if (cut ==list->size-1)
		previous->next = NULL;
	else
		previous->next=current->next;

	if (list->size==2){
		list->head=current->next;
	}
	destroy_node(&current);
	list->size--;

	return cut;
}
//-------------- Task 3 ------------------
MData* create_mdata(void *item, char type) {


	if (!item){
		printf("Error(create_mdata): invalid pointer\n");
		return NULL;
	}

	if (type =='i'){
		MData*d = (MData*)malloc(sizeof(int));
		d->item=copy_data(item);
		d->type=type;
		return d;
	}

	else if (type =='p'){
		MData *d = (MData*) malloc(sizeof(Process));
		d->item = copy_process(item);
		d->type = type;
		return d;

		}
		printf("Error(create_mdata): invalid data type\n");
		return NULL;

}

void destroy_mdata(MData **d) {

	assert(*d && d);

	if ((*d)->type == 'p') {
		if ((*d)->item != NULL) {
			destroy_process((*d)->item);
			(*d)->item = NULL;
		}

		*d = NULL;

	} else if ((*d)->type == 'i') {
		if ((*d)->item != NULL) {
			destroy_data((*d)->item);
			(*d)->item = NULL;
		}

		*d = NULL;
	}

	return;
}

void print_mdata(MData *d) {
	 if(d==NULL){
			printf("<NULL MData>\n");
			return;
		}

	if (d->type == 'p') {
		printf("type = process, value = ");
		print_process(d->item);
		printf("\n");
		return;
	}else if(d->type == 'i'){


		printf("type = integer, value = ");
		print_data(d->item);
		printf("\n");
				return;
	}
	else{
		printf("Error(print_mdata): unsupported data\n");
		return;
	}
	return;
}

MData* copy_mdata(MData *d) {

	assert(d);
	if (d->type!='p'&& d->type!='i'){
		printf("Error(copy_mdata): unsupported data\n");
	}

	MData *new = NULL;

	if (d->type=='p'){
		new = create_mdata(copy_process(d->item), 'p');
	}else if (d->type=='i'){
		new = create_mdata(copy_data(d->item), 'i');
	}

	return new;
}
//----------------------------------
