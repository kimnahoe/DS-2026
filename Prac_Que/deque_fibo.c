#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 3
//오류 함수
typedef struct {
	int queue[MAX_QUEUE_SIZE];
	int front, rear;
} DequeType;
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
// 초기화 함수
void init(DequeType* c)
{
	c->front = c->rear = 0;
}
// 공백 상태 검출 함수
int is_empty(DequeType* c)
{
	return (c->front == c->rear);
}
// 포화 상태 검출 함수
int is_full(DequeType* c)
{
	return ((c->rear + 1) % MAX_QUEUE_SIZE == c->front);
}
// 삽입 함수
void enqueue(DequeType* c, int item)
{
	if (is_full(c))
		error("큐가 포화상태입니다");
	c->rear = (c->rear + 1) % MAX_QUEUE_SIZE;
	c->queue[c->rear] = item;
}
// 삭제 함수
int dequeue(DequeType* c)
{
	if (is_empty(c))
		error("큐가 공백상태입니다");
	c->front = (c->front + 1) % MAX_QUEUE_SIZE;
	return c->queue[c->front];
}
int del_front(DequeType* c) {//맨 앞 삭제
	c->front = (c->front + 1) % MAX_QUEUE_SIZE;
	return c->queue[c->front];
}
int del_rear(DequeType* c) {//맨 뒤 삭제
	c->rear = (c->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return c->queue[c->rear];
}

int add_front(DequeType* c, int item) {//맨 앞 추가
	c->front = (c->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return c->queue[c->front] = item;
}
int add_rear(DequeType* c, int item) {//맨 뒤 추가
	c->rear = (c->rear + 1) % MAX_QUEUE_SIZE;
	return c->queue[c->rear] = item;
}

int get_front(DequeType* c) { //맨 앞 가져옴
	return c->queue[(c->front + 1) % MAX_QUEUE_SIZE];
}
int get_rear(DequeType* c) {//맨 뒤 가져옴
	return c->queue[(c->rear) % MAX_QUEUE_SIZE];
}
int fibo(int n)
{
	DequeType f;
	init(&f);
	int count = 0;
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	for (int i = 0; i < 2; i++)
		enqueue(&f, i);
	while (count != n) {
		int sum = get_front(&f) + get_rear(&f);//앞뒤 합
		del_front(&f);//맨 앞 삭제
		add_rear(&f, sum);//삭제한 곳에 sum 넣음
		count++;
	}

	return get_front(&f);
}
int main(void)
{
	int f;
	scanf("%d", &f);
	printf("%d", fibo(f));
	return 0;
}
