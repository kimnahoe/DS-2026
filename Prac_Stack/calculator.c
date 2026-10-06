#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
typedef char element;;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;
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
// 삽입함수
void push(StackType* s, char item)
{
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else {
		(s->top)++;
		s->data[s->top] = item - '0';
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
		s->data[s->top];
		(s->top)--;
	}
}
int pick(StackType* s) {
	return s->data[s->top];
}
int calculate(StackType *s, char opp) //지금까지 스택에 담겨있는 거, 부호만
{
	int i;
	if (opp == '+') {
		int num = pick(s);
		pop(s);
		int num2 = pick(s);
		pop(s);
		return num2 + num;
	}
	else if (opp == '-') {
		int num = pick(s);
		pop(s);
		int num2 = pick(s);
		pop(s);
		return num2 - num;
	}
	else if (opp == '*') {
		int num = pick(s);
		pop(s);
		int num2 = pick(s);
		pop(s);
		return num2 * num;
	}
	else if (opp == '/') {
		int num = pick(s);
		pop(s);
		int num2 = pick(s);
		pop(s);
		return num2 / num;
	}
}
int main(void)
{
	StackType s;
	init(&s);
	scanf("%s", s.data);

	int sum = 0;
	for (int i = 0; s.data[i] != '\0'; i++) {
		if (s.data[i] >= '0' && s.data[i] <= '9')//숫자면 스택에 추가
			push(&s, s.data[i]);
		else { //그냥 부호면 스택에 있는 수 2개 빼서 지금 현재 부호랑 계산
			sum = calculate(&s, s.data[i]);
			push(&s, sum + '0');
		}
	}
	
	printf("%d", sum);

	return 0;
}
