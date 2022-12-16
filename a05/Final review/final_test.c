# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include "data_structures.h"
# include "final.h"

void test_task1();
void test_task2();
void test_task3();
void test_task4();
void test_task5();
int read_processes(char*, Data*);

int main() {
	setbuf(stdout, NULL);
	//test_task1();
	//test_task2();
	//test_task3();
	//test_task4();
	test_task5();
	return 0;
}

void test_task1() {
	printf("------------------------------\n");
	printf("Start: Testing MData:\n\n");

	printf("Testing create_mdata:\n");
	int pid = 1000010000, arrival = 30, time = 1;
	Process *p = create_process(pid++, time++, arrival++);
	MData *d1 = create_mdata(p, 'p');
	if (d1 && d1->type == 'p')
		printf("MData of type p created successfully\n");

	int *num1 = (int*) malloc(sizeof(int));
	*num1 = 10;
	MData *d2 = create_mdata(num1, 'i');
	if (d2 && d2->type == 'i')
		printf("MData of type i created successfully\n");

	MData *d3 = create_mdata(num1, 'f');
	MData *d4 = create_mdata(NULL, 'i');
	printf("\n");

	printf("Testing print_mdata:\n");
	print_mdata(d1);
	print_mdata(d2);
	d2->type = 'f';
	print_mdata(d2);
	d2->type = 'i';
	print_mdata(d3);
	printf("\n");

	printf("Testing copy_mdata:\n");
	d3 = copy_mdata(d1);
	printf("Copy data of type p: ");
	print_mdata(d3);
	printf("Copy data of type i: ");
	d4 = copy_mdata(d2);
	print_mdata(d4);
	d2->type = 'f';
	printf("Copy data of type f: ");
	MData *d5 = copy_mdata(d2);
	print_mdata(d5);
	printf("\n");
	printf("Testing destroy_mdata:\n");
	destroy_mdata(&d1);
	printf("mdata of type p successfully destroyed\n");
	destroy_mdata(&d2);
	printf("mdata of type i successfully destroyed\n");
	printf("\n");

	printf("End: Testing MData\n");
	printf("------------------------------\n\n");
	return;
}

void test_task2() {
	printf("------------------------------\n");
	printf("Start: Testing SJFS Scheduler\n\n");

	Data *array = NULL;
	Queue *q = NULL;
	int size = 0;

	array = (Data*) malloc(sizeof(Data) * 30);
	size = read_processes("processes.txt", array);
	q = create_queue(size);
	for (int i = 0; i < size; i++)
		insert_queue(q, &array[i]);
	schedule_SJFS(q);
	free(array);
	array = NULL;
	destroy_queue(&q);
	printf("\n");

	printf("End: Testing SJFS Scheduler\n");
	printf("------------------------------\n\n");
	return;
}

void test_task3() {
	printf("------------------------------\n");
	printf("Start: Testing slice_stack\n\n");

	Stack *s1 = create_stack(10);
	Stack *s2 = NULL;

	int cases[6] = { 2, -1, 9, 5, 0, 15 };
	for (int k = 0; k < 6; k++) {
		printf("\n----------- Case %d -----------\n\n", k);
		if (k == 1 || k == 5)
			for (int i = 0; i < 10; i++)
				push_stack(s1,
						create_process(i + 1, (i + 1) * 10, (i + 1) * 100000));
		printf("Before slice: s1 =\n");
		print_stack(s1);
		printf("\n");
		printf("Calling slice_stack(s1,%d):\n", cases[k]);
		s2 = slice_stack(s1, cases[k]);
		printf("\n");
		printf("After slice: s1 =\n");
		print_stack(s1);
		printf("\n");
		printf("After slice: s2 =\n");
		print_stack(s2);
		destroy_stack(&s2);
		s2 = NULL;
	}

	printf("\n");
	printf("End: Testing slice_stack\n");
	printf("------------------------------\n\n");
	return;
}

void test_task4() {
	printf("------------------------------\n");
	printf("Start: Testing shift_queue\n\n");

	int size = 5;
	Queue *q = create_queue(size);

	printf("Testing special cases:\n");
	shift_queue(q, 3, 'R');
	insert_queue(q, create_process(1, 10, 1000000));
	shift_queue(q, -1, 'L');
	shift_queue(q, 5, 'T');
	printf("\n");

	char direction = 'L';
	printf("Testing Left Shift:\n");

	for (int i = 2; i < 6; i++)
		insert_queue(q, create_process(i, i * 10, i * 1000000));

	int cases[6] = { 0, 1, 3, 4, 5, 7 };
	int indx;
	for (int i = 0; i < 12; i++) {
		indx = i % 6;
		if (i == 6) {
			direction = 'R';
			printf("\nTesting Right Shift:\n");
		}
		printf("Before: ");
		print_queue(q);
		printf("After shift_queue(q,%d,%c):\n", cases[indx], direction);
		shift_queue(q, cases[indx], direction);
		print_queue(q);
		printf("\n");
	}

	destroy_queue(&q);

	printf("End: Testing shift_queue\n");
	printf("------------------------------\n\n");
}

void test_task5() {
	printf("\n");
	printf("----------- start of test_findPath() -----------\n");

	Graph *g = create_graph(1, 1);

	int i;
	Vertex *v[6];
	Edge *e[5];

	for (i = 0; i < 6; i++) {
		v[i] = create_vertex(i, "");
		add_vertex_graph(g, v[i]);
	}

	e[0] = create_edge(v[0], v[1], 10, 1);
	e[1] = create_edge(v[1], v[2], 20, 1);
	e[2] = create_edge(v[3], v[0], 50, 1);
	e[3] = create_edge(v[2], v[4], 30, 1);
	e[4] = create_edge(v[4], v[5], 40, 1);

	for (i = 0; i < 5; i++)
		add_edge_graph(g, e[i]);

	//manuall change the graph into directed graph.
	g->directed = 1;
	g->matrix[0][3] = 0;
	g->matrix[1][0] = 0;
	g->matrix[2][1] = 0;
	g->matrix[4][2] = 0;
	g->matrix[5][4] = 0;

	print_graph(g);

	int distance;
	printf("\n");
	distance = find_distnace(g, v[0], v[1]);
	printf("Distance = %d\n\n", distance);
	distance = find_distnace(g, v[1], v[0]);
	printf("Distance = %d\n\n", distance);
	distance = find_distnace(g, v[0], v[2]);
	printf("Distance = %d\n\n", distance);
	distance = find_distnace(g, v[3], v[2]);
	printf("Distance = %d\n\n", distance);
	distance = find_distnace(g, v[3], v[5]);
	printf("Distance = %d\n\n", distance);
	distance = find_distnace(g, v[5], v[3]);
	printf("Distance = %d\n\n", distance);
	distance = find_distnace(g, v[1], v[4]);
	printf("Distance = %d\n\n", distance);

	printf("----------- end of test_findPath() -----------\n");

}

int read_processes(char *fileName, Data *array) {
	FILE *inFile = NULL;
	inFile = fopen(fileName, "r");
	if (inFile == NULL) {
		printf("Error(read_processes): Cannot open file %s\n", fileName);
		return 0;
	}

	char line[40], tempArrival[7], tempPID[12], tempTime[7], *dummy;
	int marker1, marker2, i, factor, digit;
	unsigned int arrival, time;
	unsigned long pid;

	int counter = 0;
	while (fgets(line, sizeof(line), inFile) != NULL) {
		counter++;
		i = 0;

		while (line[i] != ']')
			i++;
		marker1 = i;
		for (i = 1; i < marker1; i++)
			tempArrival[i - 1] = line[i];
		arrival = (unsigned int) strtol(tempArrival, &dummy, 10);

		marker1 += 2;
		for (i = marker1; i < (marker1 + 10); i++)
			tempPID[i - marker1] = line[i];

		pid = 0;
		factor = 1000000000;
		for (i = 0; i < 10; i++) {
			digit = tempPID[i] - '0';
			pid += digit * factor;
			factor = factor / 10;
		}

		marker1 += 11;
		i = marker1;
		while (line[i] != ')')
			i++;
		marker2 = i;

		for (i = marker1; i < marker2; i++)
			tempTime[i - marker1] = line[i];
		tempTime[i - marker1] = '\0';

		time = (unsigned int) strtol(tempTime, &dummy, 10);
		array[counter - 1] = *create_process(pid, time, arrival);
	}
	fclose(inFile);
	return counter;
}
