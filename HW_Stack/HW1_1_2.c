//StackType라는 구조체 안에 data라는 구조체 안에 element(숫자), ele_string(문자)이라는 요소 추가
//ele_string은 문자 전체를 받아야 하고, 문자는 변하지 않기 때문에 const char string[](배열로 받아야지 가능 char string이거는 문자 하나만 가능, const char *string(포인터로 받아도 가능))
//push는 top 증가 후(애초에 top은 -1부터 시작하기 때문) element, ele_string 삽입, pup은 top에 삽입 후 --
#define _CRT_SECURE_NO_WARNINGS
#define MAX_STACK_SIZE 3 // 배열을 이용한 스택은 사이즈의 제한이 있다
#include <stdio.h>
#include <string.h>
// 스택을 위한 타입 정의
typedef struct {
	struct {
		int element;
		char ele_string[10];
	} data[MAX_STACK_SIZE];
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
	for (int i = s->top; i >= 0; i--) {
		if (i == s->top)
			printf("[%d, %s] <- top\n", s->data[i].element, s->data[i].ele_string);
		else
			printf("[%d, %s]\n", s->data[i].element, s->data[i].ele_string);
	}
	printf("--\n");
}
// 삽입함수
void push(StackType* s, int item, const char string[])
{
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else {
		(s->top)++;
		s->data[s->top].element = item;
		strcpy(s->data[s->top].ele_string, string);
	}
}
// 삭제함수
void pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else {
		s->data[s->top].element;
		s->data[s->top].ele_string;
		(s->top)--;
	}
}
// 피크함수
void peek(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else {
		s->data[s->top].element;
		s->data[s->top].ele_string;
	}
}
// 주함수
void main()
{
	StackType s;
	init(&s);
	if (is_empty(&s))
		printf("<empty>\n--\n");

	push(&s, 10, "ten");
	stack_print(&s);
	push(&s, 20, "twenty");
	stack_print(&s);
	push(&s, 30, "thirty");
	stack_print(&s);
	push(&s, 40, "forty");
	stack_print(&s);
	pop(&s);
	stack_print(&s);

	push(&s, 50, "fifty");
	stack_print(&s);
	pop(&s);
	stack_print(&s);
	pop(&s);
	stack_print(&s);
	pop(&s);

	if (is_empty(&s))
		printf("<empty>\n--");
}
