# include <stdio.h>
# include <stdlib.h>
# include <assert.h>
# include <string.h>
#include "data_structures.h"

void adjust_queue(Queue *q);
void adjust_pqueue(pQueue *q);
int find_top_priority(pQueue *q);
void expand_graph(Graph *g);
void shrink_graph(Graph *g);

//------------------------ Process Implementation -------------------

Process* create_process(long pid, int p_time, int arrival_time) {
	Process *p = (Process*) malloc(sizeof(Process));

	if (p_time <= 0) {
		printf("Error(create_process): invalid time - set to 0\n");
		p->time = 0;
	} else
		p->time = p_time;

	if (arrival_time < 0) {
		printf("Error(create_process): invalid arrival time - set to 0\n");
		p->arrival = 0;
	} else
		p->arrival = arrival_time;

	if (pid <= 0) {
		printf("Error(create_process): invalid pid - set to random\n");
		p->PID = get_UPID();
	} else
		p->PID = pid;

	return p;
}

void destroy_process(Process **p) {
	assert(*p != NULL);
	(*p)->PID = 0;
	(*p)->time = 0;
	(*p)->arrival = 0;
	free(*p);
	*p = NULL;
	return;
}

unsigned long get_UPID() {

	static int counter = 100000;

	unsigned long higher5 = rand() % (39999 - 10000 + 1) + 10000;
	higher5 = higher5 * 100000;

	int lower5 = counter;
	counter++;

	return higher5 + lower5;
}

Process* copy_process(Process *p1) {
	assert(p1!=NULL);
	Process *p2 = (Process*) malloc(sizeof(Process));
	p2->PID = p1->PID;
	p2->time = p1->time;
	p2->arrival = p1->arrival;
	return p2;
}

void get_process_info(Process *p, char *info) {
	assert(p!=NULL);
	char process[30] = "";
	sprintf(process, "[%u](%lu,%u)", p->arrival, p->PID, p->time);
	strcpy(info, process);
	return;
}

void print_process(Process *p) {
	assert(p!=NULL);
	char info[30];
	strcpy(info, "");
	get_process_info(p, info);
	printf("%s", info);
	return;
}

int is_equal_process(Process *p1, Process *p2) {
	assert(p1 != NULL && p2 != NULL);
	if (p1->PID != p2->PID)
		return False;
	if (p1->time != p2->time)
		return False;
	return True;
}

//----------------------- Data Implementation -----------------------
void print_data(Data *d) {
	print_process(d);
	return;
}

void destroy_data(Data **d) {
	destroy_process(d);
	return;
}

Data* copy_data(Data *d) {
	return copy_process(d);
}

void swap_data(Data *d1, Data *d2) {
	Data temp = *d1;
	*d1 = *d2;
	*d2 = temp;
	return;
}

void print_data_array(Data *array, const int size) {
	assert(array);
	assert(size >= 1);

	int i;
	printf("[");
	for (i = 0; i < size; i++) {
		print_data(&array[i]);
		if (i != size - 1)
			printf(",");
	}
	printf("]\n");
	return;
}

int compare_data(Data *d1, Data *d2) {
	assert(d1!= NULL && d2!=NULL);
	if (d1->arrival > d2->arrival)
		return 1; //d1 > d2
	if (d1->arrival < d2->arrival)
		return 2; //d1 < d2
	if (d1->time > d2->time)
		return 1; //d1 > d2
	if (d1->time < d2->time)
		return 2; //d1 < d2
	if (d1->PID > d2->PID)
		return 1; //d1 > d2
	if (d1->PID < d2->PID)
		return 2; //d1 < d2
	return 0; //d1 == d2
}

//----------------------- Stack Implementation ----------------------

Stack* create_stack(int stack_capacity) {
	Stack *s = (Stack*) malloc(sizeof(Stack));
	if (stack_capacity < 1) {
		fprintf(stderr, "Error(create_stack): invalid capacity, set to 10\n");
		stack_capacity = 10;
	}
	s->capacity = stack_capacity;
	s->array = (Data*) malloc(sizeof(Data) * (s->capacity));
	s->top = -1;
	return s;
}

void destroy_stack(Stack **s) {
	assert(s!= NULL);
	while (!is_empty_stack(*s)) {
		Data *d = pop_stack(*s);
		destroy_data(&d);
	}
	free((*s)->array);
	(*s)->array = NULL;
	(*s)->capacity = 0;
	(*s)->top = 0;
	free(*s);
	*s = NULL;
	return;
}

int is_empty_stack(Stack *s) {
	assert(s!=NULL);
	return (s->top == -1);
}

int is_full_stack(Stack *s) {
	assert(s!=NULL);
	return (s->top == s->capacity - 1);
}

int len_stack(Stack *s) {
	assert(s!=NULL);
	return s->top + 1;
}

void print_stack(Stack *s) {
	assert(s!=NULL);
	printf("Stack Size = %d\n", len_stack(s));
	if (is_empty_stack(s))
		printf("<empty_stack>\n");
	for (int i = s->top; i >= 0; i--) {
		print_data(&s->array[i]);
		printf("\n");
	}
	return;
}

int push_stack(Stack *s, Data *d) {
	assert(s!=NULL && d!=NULL);
	if (is_full_stack(s)) {
		printf("Error(push_stack): stack is full\n");
		return False;
	}
	s->top++;
	s->array[s->top] = *copy_data(d);
	return True;
}

Data* peek_stack(Stack *s) {
	assert(s!=NULL);
	if (is_empty_stack(s)) {
		printf("Error(peek_stack): stack is empty\n");
		return NULL;
	}
	return copy_data(&(s->array[s->top]));
}

Data* pop_stack(Stack *s) {
	assert(s!=NULL);
	Data *d = NULL;
	if (is_empty_stack(s)) {
		printf("Error(pop_stack): stack is empty\n");
		return d;
	}

	d = copy_data(&s->array[s->top]);
	Data *temp = &s->array[s->top];
	destroy_data(&temp);
	s->top--;
	return d;
}

//----------------------- Queue Implementation ----------------------

Queue* create_queue(int capacity) {
	Queue *q = (Queue*) malloc(sizeof(Queue));
	if (capacity < 1) {
		printf("Error(create_queue): invalid queue capacity, set to 10\n");
		capacity = 10;
	}
	q->capacity = capacity;
	q->array = (Data*) malloc(sizeof(Data) * capacity);
	q->front = -1;
	q->rear = -1;
	return q;
}

int len_queue(Queue *q) {
	assert(q!=NULL);
	if (q->front == -1)
		return 0;
	return q->rear - q->front + 1;
}

int is_empty_queue(Queue *q) {
	assert(q!=NULL);
	return (len_queue(q) == 0);
}

int is_full_queue(Queue *q) {
	assert(q!=NULL);
	return (len_queue(q) == q->capacity);
}

void print_queue(Queue *q) {
	assert(q!=NULL);
	int i;
	printf("Capacity = %d, Size = %d, front = %d, rear = %d\n", q->capacity,
			len_queue(q), q->front, q->rear);
	if (is_empty_queue(q))
		printf("<empty_queue>\n");
	else {
		int counter = 0;
		for (i = q->front; i <= q->rear; i++) {
			print_data(&q->array[i]);
			if ((counter + 1) % 5 == 0 && counter != len_queue(q) - 1)
				printf("\n");
			else
				printf("\t");
			counter++;
		}
		printf("\n");
	}
	return;
}

int insert_queue(Queue *q, Data *d) {
	assert(q!=NULL && d!=NULL);
	if (is_full_queue(q)) {
		printf("Error(insert_queue): queue is full\n");
		return False;
	}
	if (is_empty_queue(q))
		q->front = 0;
	else if (q->rear == q->capacity - 1)
		adjust_queue(q);
	q->rear++;
	q->array[q->rear] = *copy_data(d);
	return True;
}

void adjust_queue(Queue *q) {
	assert(q!=NULL);
	int length = len_queue(q);
	int i;
	for (i = 0; i < len_queue(q); i++)
		q->array[i] = q->array[i + q->front];
	q->front = 0;
	q->rear = length - 1;
	return;
}

Data* peek_queue(Queue *q) {
	assert(q!=NULL);
	if (is_empty_queue(q)) {
		printf("Error(peek_queue): Queue is empty\n");
		return NULL;
	}
	return copy_data(&(q->array[q->front]));
}

Data* remove_queue(Queue *q) {
	assert(q!=NULL);
	Data *d = NULL;
	if (is_empty_queue(q)) {
		printf("Error(remove_queue): queue is empty\n");
		return d;
	}

	d = copy_data(&q->array[q->front]);
	Data *temp = &q->array[q->front];
	destroy_data(&temp);

	q->front++;

	if (len_queue(q) == 0) {
		q->front = -1;
		q->rear = -1;
	}
	return d;
}

void destroy_queue(Queue **q) {
	assert(q!= NULL);
	while (!is_empty_queue(*q)) {
		Data *d = remove_queue(*q);
		destroy_data(&d);
	}
	free((*q)->array);
	(*q)->array = NULL;
	(*q)->capacity = 0;
	(*q)->front = 0;
	(*q)->rear = 0;
	free(*q);
	*q = NULL;
	return;
}

//--------------------------------- Priority Queue -----------------------------

pQueue* create_pqueue(int capacity, char priority) {
	pQueue *q = (pQueue*) malloc(sizeof(pQueue));
	if (capacity < 1) {
		printf("Error(create_pqueue): invalid pqueue capacity, set to 10\n");
		capacity = 10;
	}
	q->capacity = capacity;
	q->array = (Data*) malloc(sizeof(Data) * capacity);
	q->front = -1;
	q->rear = -1;
	if (priority == 'H' || priority == 'L')
		q->priority = priority;
	else {
		printf("Error(create_pqueue): invalid priority, set to 'H'\n");
		q->priority = 'H';
	}
	return q;
}

int len_pqueue(pQueue *q) {
	assert(q!=NULL);
	if (q->front == -1)
		return 0;
	return q->rear - q->front + 1;
}

int is_empty_pqueue(pQueue *q) {
	assert(q!=NULL);
	return (len_pqueue(q) == 0);
}

int is_full_pqueue(pQueue *q) {
	assert(q!=NULL);
	return (len_pqueue(q) == q->capacity);
}

void print_pqueue(pQueue *q) {
	assert(q!=NULL);
	int i;
	printf("Capacity = %d, Size = %d, front = %d, rear = %d\n", q->capacity,
			len_pqueue(q), q->front, q->rear);
	if (is_empty_pqueue(q))
		printf("<empty_pqueue>\n");
	else {
		int counter = 0;
		for (i = q->front; i <= q->rear; i++) {
			print_data(&q->array[i]);
			if ((counter + 1) % 5 == 0 && counter != len_pqueue(q) - 1)
				printf("\n");
			else
				printf("\t");
			counter++;
		}
		printf("\n");
	}
	return;
}

int insert_pqueue(pQueue *q, Data *d) {
	assert(q!=NULL && d!=NULL);
	if (is_full_pqueue(q)) {
		printf("Error(insert_pqueue): pqueue is full\n");
		return False;
	}
	if (is_empty_pqueue(q))
		q->front = 0;
	else if (q->rear == q->capacity - 1)
		adjust_pqueue(q);
	q->rear++;
	q->array[q->rear] = *copy_data(d);
	return True;
}

void adjust_pqueue(pQueue *q) {
	assert(q!=NULL);
	int length = len_pqueue(q);
	int i;
	for (i = 0; i < len_pqueue(q); i++)
		q->array[i] = q->array[i + q->front];
	q->front = 0;
	q->rear = length - 1;
	return;
}

int find_top_priority(pQueue *q) {
	assert(q!=NULL);
	assert(!is_empty_pqueue(q));
	int index = q->front, i;
	for (i = q->front; i <= q->rear; i++) {
		if (q->priority == 'H'
				&& compare_data(&q->array[i], &q->array[index]) == 1)
			index = i;
		else if (q->priority == 'L'
				&& compare_data(&q->array[i], &q->array[index]) == 2)
			index = i;
	}
	return index;
}

Data* peek_pqueue(pQueue *q) {
	assert(q!=NULL);
	if (is_empty_pqueue(q)) {
		printf("Error(peek_pqueue): pqueue is empty\n");
		return NULL;
	}
	return copy_data(&(q->array[find_top_priority(q)]));
}

Data* remove_pqueue(pQueue *q) {
	assert(q!=NULL);
	Data *d = NULL;
	if (is_empty_pqueue(q)) {
		printf("Error(remove_pqueue): pqueue is empty\n");
		return d;
	}

	int index = find_top_priority(q); //O(n)

	d = copy_data(&q->array[index]);
	Data *temp = &q->array[index];
	destroy_data(&temp);

	if (index == q->front)
		q->front++;
	else {
		for (int i = index; i < q->rear; i++)
			q->array[i] = q->array[i + 1];
		q->rear--;
	}

	if (len_pqueue(q) == 0) {
		q->front = -1;
		q->rear = -1;
	}

	return d;
}

void destroy_pqueue(pQueue **q) {
	assert(q!= NULL);
	while (!is_empty_pqueue(*q)) {
		Data *d = remove_pqueue(*q);
		destroy_data(&d);
	}
	free((*q)->array);
	(*q)->array = NULL;
	(*q)->capacity = 0;
	(*q)->front = 0;
	(*q)->rear = 0;
	free(*q);
	*q = NULL;
	return;
}

//------------------------------ Graph Components -----------------------
Vertex* create_vertex(int n, char *s) {
	Vertex *v = (Vertex*) malloc(sizeof(Vertex));
	v->num = n;
	if (strcmp(s, "") == 0)
		sprintf(v->name, "V%d", n);
	else
		strcpy(v->name, s);
	return v;
}

void print_vertex(Vertex *v) {
	assert(v);
	printf("(%d,%s)", v->num, v->name);
	return;
}

void destroy_vertex(Vertex **v) {
	assert(v!= NULL && *v!=NULL);
	(*v)->num = 0;
	strcpy((*v)->name, "");
	free(*v);
	(*v) = NULL;
	return;
}

int is_equal_vertex(Vertex *v1, Vertex *v2) {
	assert(v1 && v2);
	return (strcmp(v1->name, v2->name) == 0);
}

Edge* create_edge(Vertex *v1, Vertex *v2, int w, int d) {
	assert(v1 && v2);
	Edge *e = (Edge*) malloc(sizeof(Edge));
	if (is_equal_vertex(v1, v2)) {
		printf("Error(create_edge): loops are not supported\n");
		return NULL;
	}
	e->v1 = v1;
	e->v2 = v2;
	e->weight = 0;
	e->directed = 0;
	return e;
}

void destroy_edge(Edge **e) {
	assert(e && *e);
	free(*e);
	*e = NULL;
	return;
}

void print_edge(Edge *e) {
	assert(e!=NULL);
	printf("[");
	print_vertex(e->v1);
	printf("------");
	print_vertex(e->v2);
	printf("]");
	return;
}

int is_equal_edge(Edge *e1, Edge *e2) {
	assert(e1 && e2);
	if (e1->weight != e2->weight)
		return False;

	if (e1->directed != e2->directed)
		return False;

	if (is_equal_vertex(e1->v1, e2->v1) && is_equal_vertex(e1->v2, e2->v2))
		return True;

	if (is_equal_vertex(e1->v2, e2->v1) && is_equal_vertex(e1->v1, e2->v2))
		return True;

	return False;
}

//------------------------------ Graph --------------------------------

Graph* create_graph(int w, int d) {
	Graph *g = (Graph*) malloc(sizeof(Graph));

	g->vertex_list = (Vertex*) malloc(sizeof(Vertex) * BLOCK);

	g->matrix = (int**) malloc(sizeof(int*) * BLOCK); //create BLOCKxBLOCK matrix
	int i, j;
	for (i = 0; i < BLOCK; i++)
		g->matrix[i] = (int*) malloc(sizeof(int) * BLOCK);

	for (i = 0; i < BLOCK; i++)
		for (j = 0; j < BLOCK; j++)
			g->matrix[i][j] = 0;

	g->vertex_count = 0;
	g->edge_count = 0;

	g->directed = 0;
	g->weighted = 0;

	return g;
}

void destroy_graph(Graph **g) {
	assert(g && *g);

	int num_of_blocks = (*g)->vertex_count / BLOCK + 1;
	int i;
	for (i = 0; i < num_of_blocks; i++) {
		free((*g)->matrix[i]);
		(*g)->matrix[i] = NULL;
	}

	(*g)->vertex_count = 0;
	(*g)->edge_count = 0;

	free((*g)->matrix);
	(*g)->matrix = NULL;

	free(*g);
	*g = NULL;
	return;
}

int is_null_graph(Graph *g) {
	assert(g);
	return (g->vertex_count == 0);
}

int is_empty_graph(Graph *g) {
	assert(g);
	return (g->edge_count == 0);
}

void print_graph(Graph *g) {
	assert(g);
	int i, j;
	printf("(Adjacency Matrix Representation): #Vertices = %d, #Edges = %d\n",
			g->vertex_count, g->edge_count);
	if (is_null_graph(g)) {
		printf("<null graph>\n");
		return;
	}

	printf("Vertices: ");
	for (i = 0; i < g->vertex_count; i++) {
		print_vertex(&g->vertex_list[i]);
		if ((i + 1) % BLOCK == 0 || i == g->vertex_count - 1)
			printf("\n");
		else
			printf(" , ");
	}

	if (g->vertex_count == 1)
		printf("%5s\n", "-");
	else {
		for (i = 0; i < g->vertex_count; i++) {
			for (j = 0; j < g->vertex_count; j++) {
				if (g->matrix[i][j] == 0)
					printf("%5s ", "-");
				else
					printf("%5d ", g->matrix[i][j]);
			}
			printf("\n");
		}
	}

	return;
}

int has_vertex_graph(Graph *g, Vertex *v) {
	assert(g && v);
	if (is_null_graph(g))
		return False;
	if (v->num < g->vertex_count)
		return True;
	return False;
}

int add_vertex_graph(Graph *g, Vertex *v) {
	assert(g && v);

	if (has_vertex_graph(g, v)) {
		printf("Error(add_vertex_graph): Vertex already exist\n");
		return False;
	}

	if (!is_null_graph(g) && (g->vertex_count) % BLOCK == 0)
		expand_graph(g);

	v->num = g->vertex_count;

	g->vertex_count++;
	g->vertex_list[g->vertex_count - 1] = *v;

	return True;
}

void expand_graph(Graph *g) {
	assert(g!=NULL);

	int i, j;
	int new_size = g->vertex_count + BLOCK;

	g->vertex_list = realloc(g->vertex_list, sizeof(Vertex) * new_size);

	g->matrix = realloc(g->matrix, sizeof(int*) * new_size);

	for (int i = 0; i < g->vertex_count; i++)
		g->matrix[i] = realloc(g->matrix[i], sizeof(int) * new_size);

	for (i = 0; i < g->vertex_count; i++)
		for (j = g->vertex_count; j < new_size; j++)
			g->matrix[i][j] = 0;

	for (i = g->vertex_count; i < new_size; i++)
		g->matrix[i] = (int*) malloc(sizeof(int) * new_size);

	for (i = g->vertex_count; i < new_size; i++)
		for (j = 0; j < new_size; j++)
			g->matrix[i][j] = 0;

	return;
}

int remove_vertex_graph(Graph *g, Vertex *v) {
	assert(g && v);

	if (is_null_graph(g)) {
		printf("Error(remove_vertex_graph): graph is null\n");
		return 0;
	}

	if (!has_vertex_graph(g, v)) {
		printf("Error(remove_vertex_graph): Vertex does not exist\n");
		return 0;
	}

	int i, j;
	int num = v->num;

	for (i = 0; i < g->vertex_count; i++)
		g->matrix[i][num] = 0;

	for (j = 0; j < g->vertex_count; j++)
		g->matrix[num][j] = 0;

	if (num != g->vertex_count - 1) {
		for (i = 0; i < g->vertex_count; i++)
			g->matrix[i][num] = g->matrix[i][g->vertex_count - 1];

		for (i = 0; i < g->vertex_count; i++)
			g->matrix[num][i] = g->matrix[g->vertex_count - 1][i];
	}

	strcpy(g->vertex_list[num].name, g->vertex_list[g->vertex_count - 1].name);
	g->vertex_list = realloc(g->vertex_list,
			sizeof(Vertex) * (g->vertex_count - 1));
	g->vertex_count--;

	int edge_counter = 0;
	for (i = 0; i < g->vertex_count; i++)
		for (j = 0; j < g->vertex_count; j++)
			if (g->matrix[i][j] != 0)
				edge_counter++;
	g->edge_count = edge_counter / 2;

	if (!is_null_graph(g) && g->vertex_count % BLOCK == 0) {
		shrink_graph(g);
	}
	return True;
}

void shrink_graph(Graph *g) {
	assert(g!=NULL);

	int new_size = g->vertex_count;
	printf("new size = %d\n", new_size);

	g->vertex_list = realloc(g->vertex_list, sizeof(Vertex) * new_size);

	g->matrix = realloc(g->matrix, sizeof(int*) * new_size);

	for (int i = 0; i < BLOCK; i++)
		g->matrix[i] = realloc(g->matrix[i], sizeof(int) * new_size);

	g->matrix = realloc(g->matrix, sizeof(int*) * new_size);

	return;
}

int has_edge_graph(Graph *g, Edge *e) {
	assert(g!=NULL && e!=NULL);

	if (is_empty_graph(g))
		return False;

	if (e->v1->num >= g->vertex_count || e->v2->num >= g->vertex_count)
		return False;

	if (e->directed || e->weight)
		return False;

	if (g->matrix[e->v1->num][e->v2->num] == 1)
		return True;
	return False;
}

int add_edge_graph(Graph *g, Edge *e) {
	assert(g && e);

	if (has_edge_graph(g, e)) {
		printf("Error(add_edge_graph): edge already exist\n");
		return False;
	}

	if (!is_empty_graph(g))
		if (e->directed || e->weight) {
			printf("Error(add_edge_graph): incompatible edge\n");
			return False;
		}

	if (!has_vertex_graph(g, e->v1))
		add_vertex_graph(g, e->v1);
	if (!has_vertex_graph(g, e->v2))
		add_vertex_graph(g, e->v2);

	g->matrix[e->v1->num][e->v2->num] = 1;
	g->matrix[e->v2->num][e->v1->num] = 1;

	g->edge_count++;

	return True;
}

int remove_edge_graph(Graph *g, Edge *e) {
	assert(g && e);

	if (is_empty_graph(g) || !has_edge_graph(g, e)) { //edge does not exist
		printf("Error(remove_edge_graph): Edge does not exist\n");
		return False;
	}

	g->matrix[e->v1->num][e->v2->num] = 0;
	g->matrix[e->v2->num][e->v1->num] = 0;

	g->edge_count--;

	return True;
}
