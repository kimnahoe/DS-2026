#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100
typedef struct { //우선순위랑 인덱스 필요. 우선순위가 큰 게 있으면 그거 먼저 수행해야 하기 때문
	int priority;
	int index;
} Document;
typedef struct {
	Document queue[MAX_QUEUE_SIZE]; //원형 배열
	int front, rear;
} pri;
//오류 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
// 초기화 함수
void init(pri* c)
{
	c->front = c->rear = 0;
}
// 공백 상태 검출 함수
int is_empty(pri* c)
{
	return (c->front == c->rear);
}
// 포화 상태 검출 함수
int is_full(pri* c)
{
	return ((c->rear + 1) % MAX_QUEUE_SIZE == c->front);
}
// 삽입 함수
void enqueue(pri* c, Document *d)
{
	if (is_full(c))
		error("큐가 포화상태입니다");
	c->rear = (c->rear + 1) % MAX_QUEUE_SIZE;
	c->queue[c->rear]=*d;
}
// 삭제 함수
Document dequeue(pri* c)
{
	if (is_empty(c))
		error("큐가 공백상태입니다");
	c->front = (c->front + 1) % MAX_QUEUE_SIZE;
	return c->queue[c->front];
}
Document pick(pri* c) {
	return c->queue[(c->front + 1) % MAX_QUEUE_SIZE];
}
int main(void)
{
	Document d;
	pri c;
	int n, find;
	int i;
	init(&c); 
	scanf("%d%d", &n, &find); //문서개수, 내가 찾아야 할 문서의 인덱스(이때는 1부터)
	find = find - 1;

	for (i = 0; i < n; i++) {
		int priority;
		scanf("%d", &priority); //문서 우선순위
		d.priority = priority;
		d.index = i;
		enqueue(&c, &d);
	}

	int order, search;
	order = search = 0;
	while (!is_empty(&c)) {
		Document front = dequeue(&c);

		int count = (c.rear - c.front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
		int i = (c.front + 1) % MAX_QUEUE_SIZE;

		search = 0;

		for (int j = 0; j < count; j++) {
			if (c.queue[i].priority > front.priority) {//반복문 돌면서 우선순위 더 높은거 서치
				search = 1; //더 높은거 발견
				break;
			}
			i = (i + 1) % MAX_QUEUE_SIZE; //원형큐 핵심, 공간 활용(처음꺼 비우면 다시 맨 처음부터 채움)
		}

		if (search) //더 먼저 해야하는 우선순위 발견하면
			enqueue(&c, &front);
		else {
			order++; 
			if (front.index == find)//같을때만 order출력해서 몇번째에서 하는건지
				printf("%d", order);
		}
	}

	return 0;
}
