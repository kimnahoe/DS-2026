//특정 환자를 찾음
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 4

typedef struct {
	int patient_id;      // 환자 번호
	char name[100];
} Patient;

typedef struct {
	Patient queue[MAX_QUEUE_SIZE];
	int front, rear;
} HospitalQueue;

// 기본 함수들은 이미 구현되어 있음
// (init, is_empty, is_full, enqueue, dequeue 등)
//오류 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
// 초기화 함수
void init(HospitalQueue* q)
{
	q->front = q->rear = 0;
}
// 공백 상태 검출 함수
int is_empty(HospitalQueue* q)
{
	return (q->front == q->rear);
}
// 포화 상태 검출 함수
int is_full(HospitalQueue* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}
// 삽입 함수
void enqueue(HospitalQueue* q, Patient *p)
{
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = *p; //실제 데이터 값을 가져와야함
}
// 삭제 함수
Patient dequeue(HospitalQueue* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}
// 엿보기 함수
Patient peek(HospitalQueue* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	return q->queue[(q->front + 1) % MAX_QUEUE_SIZE];
}


// 1. "특정 환자가 대기 중인가?" 확인하는 함수
int is_patient_waiting(HospitalQueue* q, int patient_id) {
	// 반환값: 1 (있음), 0 (없음)
	//queue 돌면서 id와 같은거 잇으면 1 없으면 0

	int count = (q->rear - q->front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE; //총 몇명있는지
	int i = (q->front + 1) % MAX_QUEUE_SIZE; //원형이라서 나머지하고 나머지서부터 시작
	for (int j = 0; j < count; j++) {
		if (q->queue[i].patient_id == patient_id)
			return 1;
		i = (i + 1) % MAX_QUEUE_SIZE; //원형이라서 다시 이동시켜줘야함 q구조체 배열 끝까지 봐야함
	}
	return 0;
}


// 2. "대기열의 맨 앞 환자가 누구인가?" 확인하는 함수
Patient peek_front(HospitalQueue* q) {
	// ???
	// 맨 앞 환자의 정보 반환
}

int main(void) {
	HospitalQueue q;
	Patient p;

	// ... enqueue로 환자 추가 ...
	// 현재 대기: 환자1, 환자2, 환자3

	//환자 정보를 구조체에 저장
	p.patient_id = 135;
	strcpy(p.name, "김나회");//그냥 문자열 함수써서 복사

	//환자 정보 구조체의 주소를 enqueue에 전달(삽입)
	enqueue(&q, &p);//구조체 변수 주소 자체를 보내야함

	// 테스트 1
	if (is_patient_waiting(&q, 2))
		printf("찾으시는 환자가 대기중입니다.\n");
	else
		printf("찾으시는 환자가 없습니다.\n");

	// 테스트 2
	//Patient front = peek_front(&q);
	//printf("맨 앞: %s\n", front.name);  // 환자1 출력

	return 0;
}
