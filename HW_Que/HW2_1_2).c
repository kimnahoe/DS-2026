//start반복문안에서는 다음꺼로 넘어가야 하니까 start=start+1로 해줘야함
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 3
#define MAX_STRING 100 // 추가
typedef struct { //수정
	char name[MAX_STRING];
} element;
typedef struct {
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;
//오류 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
// 초기화 함수
void init(QueueType* q)
{
	q->front = q->rear = 0;
}
// 공백 상태 검출 함수
int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}
// 포화 상태 검출 함수
int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}
// 삽입 함수
void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}
// 삭제 함수
element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}
// 엿보기 함수
element peek(QueueType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	return q->queue[(q->front + 1) % MAX_QUEUE_SIZE];
}
int get_count(QueueType* q) //남자 카운트 세는거
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	return (q->rear - q->front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}
void print_queue(QueueType* q)
{
	int start = (q->front + 1) % MAX_QUEUE_SIZE; //원형이라서 나머지
	int end = (q->rear - q->front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE; //count세는거처럼 원형이라서 나머지
	for (int i = 0; i < end; i++) {
		printf("%s ", q->queue[start].name);
		start = (start+1) % MAX_QUEUE_SIZE; //원형이라서 다시 이동시켜줘야함
	}
}
// 주 함수
int main(void)
{
	QueueType manQ;
	element newPerson;
	char name[MAX_STRING];
	init(&manQ);
	printf("이름을 입력:");
	scanf("%s", newPerson.name);
	enqueue(&manQ, newPerson);
	printf("%d명: ", get_count(&manQ));
	print_queue(&manQ);

	printf("\n이름을 입력:");
	scanf("%s", newPerson.name);
	enqueue(&manQ, newPerson);
	printf("%d명: ", get_count(&manQ));
	print_queue(&manQ);

	printf("\n이름을 입력:");
	scanf("%s", newPerson.name);
	enqueue(&manQ, newPerson); // 원형큐의 사이즈가 3이므로 3번째 요소를 넣으려하면 포화 에러가 난다
	printf("%d명: ", get_count(&manQ));
	print_queue(&manQ);
}
