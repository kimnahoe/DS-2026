//main 반복문(for문)으로
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_STACK_SIZE 3 // 배열을 이용한 스택은 사이즈의 제한이 있다
// 스택을 위한 타입 정의
typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;
// 스택 초기화 함수
void init(StackType* s)
{
	s->top = -1;
}
// 공백 상태 검출 함수
int is_empty(StackType* s)
{
	return (s->top == -1);
}
// 포화 상태 검출 함수
int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}
//현재 스택 모습 출력
void stack_print(StackType* s)
{
	printf("현재 스택 출력: ");
	for (int i = s->top; i >= 0; i--)
		printf("%d ", s->data[i]);
	printf("\n");
}
// 삽입함수
void push(StackType* s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else
		s->data[++(s->top)] = item;
}
// 삭제함수
element pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
		return s->data[(s->top)--];
}
// 피크함수
element peek(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
		return s->data[s->top];
}
// 주함수
void main()
{
	StackType s;
	init(&s);

	for (int i = 0; i < MAX_STACK_SIZE; i++) {
		push(&s, (i+1)*10);
		stack_print(&s);
	}
	pop(&s); //30삭제
	stack_print(&s);

	push(&s, 40); //40추가
	stack_print(&s);
	pop(&s); //40삭제
	stack_print(&s);

	push(&s, 50);//50추가
	for (int i = 0; i < MAX_STACK_SIZE; i++) {
		stack_print(&s);//현재 상태 확인
		pop(&s); //삭제
	}

	if (is_empty(&s))
		printf("<empty>\n");
}
