#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 3 //3으로 설정
#define MAX_STRING 100 // 추가
typedef struct { //수정
	char name[MAX_STRING];
} element;
typedef struct {
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;
//
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
void enqueue(QueueType* q, char *name)
{
	if (is_full(q)) {
		printf("대기자가 꽉찼으니 담기회를 이용\n");
		return;
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	strcpy(q->queue[q->rear].name, name);
}
// 삭제 함수
element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}
// 보기 함수
element peek(QueueType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	return q->queue[(q->front + 1) % MAX_QUEUE_SIZE];
}
int get_count(QueueType* q)
{
	return (q->rear - q->front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}
void print_queue(QueueType* q)
{
	int start = (q->front + 1) % MAX_QUEUE_SIZE; //원형이라서 나머지
	int end = (q->rear - q->front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE; //count세는거처럼 원형이라서 나머지
	for (int i = 0; i < end; i++) {
		printf("%s ", q->queue[start].name);
		start = (start + 1) % MAX_QUEUE_SIZE; //원형이라서 다시 이동시켜줘야함
	}
	printf("\n");
}
void try_match(char* name, QueueType* partnerQ, QueueType* myQ) //myQ 내가 입력한 큐, partnerQ가 상대방 큐
{
	//상대방 큐가 있으면 그냥 바로 디큐해서 커플 탄생 만들기
	if (!is_empty(partnerQ)) { //비어있지 않다면
		printf("커플이 탄생했습니다! %s과 %s\n", name, dequeue(partnerQ).name);
	}
	else { //비어있다면 엔큐로 넣어줘야함
		printf("아직 대상자가 없습니다.");
		if (!is_full(myQ)) //포화 상태가 아니라면
			printf("기다려주십시요.\n");
		enqueue(myQ, name);
	}

}
int main(void)
{
	QueueType manQ, womanQ;
	char choice;
	char name[MAX_STRING];
	char gender;
	init(&manQ);
	init(&womanQ);
	printf("미팅 주선 프로그램입니다.\n");

	printf("i(nsert, 고객입력), c(heck, 대기자 체크), q(uit):");
	scanf(" %c", &choice);
	while (choice != 'q') {
		switch (choice) {
		case 'i':
			printf("이름을 입력:");
			scanf("%s", name);
			fflush(stdin);
			printf("성별을 입력(m or f):");
			scanf(" %c", &gender);
			if (gender == 'm')
				try_match(name, &womanQ, &manQ);
			else
				try_match(name, &manQ, &womanQ);
			break;
		case 'c':
			printf("남성 대기자 %d명: ", get_count(&manQ));
			print_queue(&manQ);
			printf("여성 대기자 %d명: ", get_count(&womanQ));
			print_queue(&womanQ);
		}
		fflush(stdin);
		printf("i(nsert, 고객입력), c(heck, 대기자 체크), q(uit):");
		scanf(" %c", &choice);
	}
}
