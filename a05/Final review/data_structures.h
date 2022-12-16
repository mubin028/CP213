#ifndef DATA_STRUCTURES_H_
#define DATA_STRUCTURES_H_

# define True 1
# define False 0
# define BLOCK 5

//------------------- Process ---------------------
typedef struct {
	unsigned long PID; 	//process id
	unsigned int time;	//requested processing time
	unsigned int arrival; //arrival time
} Process;

Process* create_process(long p_pid, int p_time, int arrival_time);
void destroy_process(Process **p);
void print_process(Process *p);
Process* copy_process(Process *p);
void get_process_info(Process *p, char *info);
int is_equal_process(Process *p1, Process *p2);
unsigned long get_UPID();

//--------------------- Data --------------------------
typedef Process Data;

void print_data(Data *d);
void print_data_array(Data *array, const int size);
void swap_data(Data *d1, Data *d2);
Data* copy_data(Data *d);
int compare_data(Data *d1, Data *d2);
void destroy_data(Data**);

//------------------- Stack -----------------------
typedef struct {
	Data *array; 	//stack array
	int top; 		//index for top of stack
	int capacity;	//maximum capacity of stack
} Stack;

Stack* create_stack(int stack_capacity);
void destroy_stack(Stack **s);
void print_stack(Stack *s);
Data* pop_stack(Stack *s);
int push_stack(Stack *s, Data *d);
Data* peek_stack(Stack *s);
int is_empty_stack(Stack *s);
int is_full_stack(Stack *s);
int len_stack(Stack *s);

//---------------- Queue ---------------------------------
typedef struct {
	Data *array; 	//array containing data items
	int front;		//index of first item in Queue
	int rear;		//index of last item in Queue
	int capacity;	//maximum queue length
} Queue;

Queue* create_queue(int capacity);
int is_empty_queue(Queue *q);
int len_queue(Queue *q);
int is_full_queue(Queue *q);
int insert_queue(Queue *q, Data *d);
Data* peek_queue(Queue *q);
Data* rear_queue(Queue *q);
Data* remove_queue(Queue *q);
void destroy_queue(Queue **q);
void print_queue(Queue *q);

//------------------- Priority Queue ---------------------
typedef struct {
	Data *array; 	//array containing data items
	int front;		//index of first item in Queue
	int rear;		//index of last item in Queue
	int capacity;	//maximum queue length
	char priority;  //'H' = Higher priority first
					//'L' = Lower priority first
} pQueue;

pQueue* create_pqueue(int capacity, char priority);
int is_empty_pqueue(pQueue *q);
int len_pqueue(pQueue *q);
int is_full_pqueue(pQueue *q);
void destroy_pqueue(pQueue **q);
void print_pqueue(pQueue *q);
int insert_pqueue(pQueue *q, Data *d);
Data* peek_pqueue(pQueue *q);
Data* remove_pqueue(pQueue *q);

//-------------------- Graph Components -------------------
typedef struct {
	int num;		//a unique number in each graph
	char name[20];	//optional label
} Vertex;

typedef struct {
	Vertex *v1;		//first vertex
	Vertex *v2;		//second vertex
	int weight; 	//non-weighted graphs = 0
	int directed; 	//undirected = 0
} Edge;

Vertex* create_vertex(int num, char *name);
void print_vertex(Vertex *v);
void destroy_vertex(Vertex **v);
int is_equal_vertex(Vertex *v1, Vertex *v2);

Edge* create_edge(Vertex *v1, Vertex *v2, int w, int d);
void print_edge(Edge *e);
void destroy_edge(Edge **e);
int is_equal_edge(Edge *e1, Edge *e2);

//--------------------- Graph --------------------------
typedef struct {
	int **matrix;			//adjacency matrix
	Vertex *vertex_list; 	//only needed if using labels
	int vertex_count;		//number of vertices
	int edge_count;			//number of edges
	int directed; 			//flag - 0:undirected, 1:directed
	int weighted; 			//flag - 0:non-weighted, 1: weighted
} Graph;

Graph* create_graph(int w, int d);
void destroy_graph(Graph **g);
void print_graph(Graph *g);

int is_null_graph(Graph *g);
int is_empty_graph(Graph *g);

int add_vertex_graph(Graph *g, Vertex *v);
int has_vertex_graph(Graph *g, Vertex *v);
int remove_vertex_graph(Graph *g, Vertex *v);

int add_edge_graph(Graph *g, Edge *e);
int has_edge_graph(Graph *g, Edge *e);
int remove_edge_graph(Graph *g, Edge *e);

#endif /* DATA_STRUCTURES_H_ */
