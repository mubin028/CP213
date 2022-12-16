#ifndef FINAL_H_
#define FINAL_H_

#include "data_structures.h"

//--------------- Task 1----------------------
typedef struct {
	void *item; 	//pointer to data item
	char type;		//'i' = integer, 'p' = process
} MData;

MData* create_mdata(void *item, char type);
void destroy_mdata(MData **d);
void print_mdata(MData *d);
MData* copy_mdata(MData *d);

//--------------- Task 2 ----------------------
void schedule_SJFS(Queue *q);

//--------------- Task 3 ----------------------
Stack* slice_stack(Stack *s1, int index);

//--------------- Task 4 ----------------------
void shift_queue(Queue *q, int shifts, char direction);

//---------------- Task 5 --------------------
int find_distnace(Graph *g, Vertex *v1, Vertex *v2);

#endif /* FINAL_H_ */
