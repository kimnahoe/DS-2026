#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_QUEUE_SIZE 6
typedef struct {
	int queue[MAX_QUEUE_SIZE];
	int front, rear;
} DequeType;
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
void init(DequeType* c)
{
	c->front = c->rear = 0;
}
int is_empty(DequeType* c)
{
	return (c->front == c->rear);
}
int is_full(DequeType* c)
{
	return ((c->rear + 1) % MAX_QUEUE_SIZE == c->front);
}
void enqueue(DequeType* c, int item)
{
	if (is_full(c))
		error("error");
	c->rear = (c->rear + 1) % MAX_QUEUE_SIZE;
	c->queue[c->rear] = item;
}
int dequeue(DequeType* c)
{
	if (is_empty(c))
		error("error");
	c->front = (c->front + 1) % MAX_QUEUE_SIZE;
	return c->queue[c->front];
}

int pop_front(DequeType* c) {
	if (is_empty(c))
		error("error");
	c->front = (c->front + 1) % MAX_QUEUE_SIZE;
	return c->queue[c->front];
}
int pop_rear(DequeType* c) {
	if (is_empty(c))
		error("error");
	int value=c->queue[c->rear];
	c->rear = (c->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return value;
}

int add_front(DequeType* c, int item) {
	c->front = (c->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return c->queue[c->front] = item;
}
int add_rear(DequeType* c, int item) {
	if (is_full(c))
		error("error");
	c->rear = (c->rear + 1) % MAX_QUEUE_SIZE;
	return c->queue[c->rear] = item;
}

int get_front(DequeType* c) {
	return c->queue[(c->front + 1) % MAX_QUEUE_SIZE];
}
int get_rear(DequeType* c) {
	return c->queue[(c->rear) % MAX_QUEUE_SIZE];
}

int rotate_left(DequeType *c){
	return add_rear(c, pop_front(c));
}

void print_deq(DequeType *c){
    if (is_empty(c)) {
        printf("\n");
        return;
    }
    for (int i = (c->front + 1) % MAX_QUEUE_SIZE; ; i = (i + 1) % MAX_QUEUE_SIZE) {
        printf("%d ", c->queue[i]);
        if (i == c->rear) break;
    }
    printf("\n");
}
int main(void)
{
	DequeType q;
	init(&q);
	int size;
	scanf("%d", &size);
	for (int i = 0; i < size; i++) {
    	int num;
    	scanf("%d", &num);
    	enqueue(&q, num);
	}
	rotate_left(&q);
	print_deq(&q);
	return 0;
}
