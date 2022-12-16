/**
 * ---------------------------------
 * Student Name:
 * Student ID:
 * Student Email:
 * ---------------------------------
 */

/**
 * ---------------------------------
 *
 * Put your academic honesty certification
 * in this box
 *
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

//---- Do not change imports -----------------
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <ctype.h>
# include <assert.h>

# include "data_structures.h"
# include "final.h"
//------------------------------------------------

//--------------------- Task 1 --------------------
MData* create_mdata(void *item, char type) {
	//your solution here
	return NULL;
}

void destroy_mdata(MData **d) {
	//your solution here
	return;
}

void print_mdata(MData *d) {
	//your solution here
	return;
}

MData* copy_mdata(MData *d) {
	//your solution here
	return NULL;
}

//------------------------ Task 2 -----------------------------
void schedule_SJFS(Queue *q) {
	//your solution here
	return;
}

//----------------------------- Task 3 -----------------------------
Stack* slice_stack(Stack *s1, int index) {
	//your solution here
	return NULL;
}

//---------------------------- Task 4 -------------------------
void shift_queue(Queue *q, int shifts, char direction) {
	//your solution here
	return;
}

//-------------------- Task 5 -------------------------
int find_distnace(Graph *g, Vertex *v1, Vertex *v2) {



int out = 0;
int current = v1->num;
int counter = 0;
int distance = 0;
int found = 0;
int stop[g->vertex_count];


	if (g->matrix[v1->num][v2->num]==1){
		printf("Path from Vertex (%d) to Vertex (%d):\n",v1->num,v2->num);
		printf("(%d)-->(%d)\n",v1->num,v2->num);
		return 1;

	}

	while (found == 0 && current <= g->vertex_count) {

		while (out == 0 && counter <= g->vertex_count) {
			if (g->matrix[current][counter] == 1) {
				stop[distance] = counter;
				distance++;
				current = counter;
				out = 1;
				if (counter == v2->num) {
					//printf("found %d\n",counter);
					found = 1;
				}
			}
			counter++;
			if (counter > g->vertex_count){
				printf("Path from Vertex (%d) to Vertex (%d):\n",v1->num,v2->num);
				printf("no path was found\n");
				return 0;
			}

		}
		out = 0;
		counter = 0;
	}
	printf("Path from Vertex (%d) to Vertex (%d):\n",v1->num,v2->num);
	printf("(%d)-->",v1->num);
	for (int y = 0; y <distance-1;y++){
		printf("(%d)-->",stop[y]);
	}
	printf("(%d)\n",v2->num);
	return distance;
}

