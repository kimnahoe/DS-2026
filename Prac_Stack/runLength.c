#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_STACK_SIZE 100
typedef char element;
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
		s->data[s->top] = item;
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
char peek(StackType* s) {
	return s->data[s->top];
}
char* runLength(StackType* s)
{
	// num이랑 삭제(pop) 후 num2랑 같으면 숫자 세기
	//count로 숫자 센 거 만큼 앞에 숫자 쓰고 뒤에 문자열 쓰기
	//앞에 숫자 쓰고 그리고 num써야함

	char* newStr;
	newStr = (char *)malloc(sizeof(char) * 50);

	int count = 1;
	int index = 0; //새로운 문자열 저장 인덱스
	int num;
	while (!is_empty(s)) {
		num = tolower(peek(s)); //연속된 문자 확인하기 위해서 맨 처음
		pop(s); //num del
		if (!is_empty(s)) {
			if (tolower(num) == tolower(peek(s)))
				count++;
			else {//다르면 count랑 같이 
				newStr[index++] = count + '0';
				newStr[index++] = num;
				count = 1;
			}
		}
	}
	if (count > 0) {
		newStr[index++] = count + '0';
		newStr[index++] = num;
	}

	newStr[index] = '\0';

	return newStr;
}
int main(void)
{
	StackType s;
	init(&s);

	char ch;
	while (scanf("%c", &ch) == 1 && ch != '\n') {
		push(&s, ch);
	}

	char* new = runLength(&s);
	printf("%s", new);
	free(new);

	return 0;
}
