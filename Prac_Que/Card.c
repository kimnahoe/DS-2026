#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100
//오류 함수
typedef struct {
	int queue[MAX_QUEUE_SIZE];
	int front, rear;
} card;
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
// 초기화 함수
void init(card* c)
{
	c->front = c->rear = 0;
}
// 공백 상태 검출 함수
int is_empty(card* c)
{
	return (c->front == c->rear);
}
// 포화 상태 검출 함수
int is_full(card *c)
{
	return ((c->rear + 1) % MAX_QUEUE_SIZE == c->front);
}
// 삽입 함수
void enqueue(card* c, int item)
{
	if (is_full(c))
		error("큐가 포화상태입니다");
	c->rear = (c->rear + 1) % MAX_QUEUE_SIZE;
	c->queue[c->rear] = item;
}
// 삭제 함수
int dequeue(card* c)
{
	if (is_empty(c))
		error("큐가 공백상태입니다");
	c->front = (c->front + 1) % MAX_QUEUE_SIZE;
	return c->queue[c->front];
}
int pick(card* c) {
	return c->queue[(c->front + 1) % MAX_QUEUE_SIZE];
}
int main(void)
{
	card c;
	int n;
	int i;
	init(&c); //맨 처음에 초기화 무조건 추가
	scanf("%d", &n);
	
	for (i = 1; i <= n; i++)
		enqueue(&c, i); //8까지 입력을 한다

	//i가 1이 될때까지 디큐를 반복하면됨
	int count = n;
	while (count != 1) {
		count--;
		dequeue(&c);
		int num = pick(&c);
		dequeue(&c);
		enqueue(&c, num);
	}
	printf("%d", pick(&c));
	return 0;
}
