#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100
//오류 함수
typedef struct {
	int queue[MAX_QUEUE_SIZE];
	int front, rear;
} Rotation;
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
// 초기화 함수
void init(Rotation* c)
{
	c->front = c->rear = 0;
}
// 공백 상태 검출 함수
int is_empty(Rotation* c)
{
	return (c->front == c->rear);
}
// 포화 상태 검출 함수
int is_full(Rotation* c)
{
	return ((c->rear + 1) % MAX_QUEUE_SIZE == c->front);
}
// 삽입 함수
void enqueue(Rotation* c, int item)
{
	if (is_full(c))
		error("큐가 포화상태입니다");
	c->rear = (c->rear + 1) % MAX_QUEUE_SIZE;
	c->queue[c->rear] = item;
}
// 삭제 함수
int dequeue(Rotation* c)
{
	if (is_empty(c))
		error("큐가 공백상태입니다");
	c->front = (c->front + 1) % MAX_QUEUE_SIZE;
	return c->queue[c->front];
}
int pick(Rotation* c) {
	return c->queue[(c->front + 1) % MAX_QUEUE_SIZE];
}
int main(void)
{
	Rotation c;
	init(&c);

	int n, target;
	scanf("%d", &n); //배열 개수
	for (int j = 0; j < n; j++) {
		int num;
		scanf("%d", &num);
		enqueue(&c, num); //엔큐로 삽입
	}
	scanf("%d", &target); //num값

	int count = (c.rear - c.front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	int i = (c.front + 1) % MAX_QUEUE_SIZE;

	for (int j = 0; j < count; j++) {
		if (c.queue[i] == target) {
			printf("%d", j);
			return 0;
		}
		i = (i + 1) % MAX_QUEUE_SIZE;
	}
	dequeue(&c);

	return 0;
}
