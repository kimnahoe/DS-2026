// palindrome 함수 내부에서 push, pop 함수를 이용
#define _CRT_SECURE_NO_WARNINGS
#define MAX_STRING 100
#include <stdio.h>
typedef char element;
typedef struct {
	element data[MAX_STRING];
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
	return (s->top == (MAX_STRING - 1));
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
int palindrome(char str[])
{
	StackType s; // 배열을 사용할 경우 스택배열을 만듦
	// 필요한 변수들 선언
	init(&s); //스택 초기화
	if (is_full(&s))
		return 0;
	else {
		for (int i = 0; str[i] != '\0'; i++)
			push(&s, str[i]); //문자열 하나씩 복사
	}
	//스택에서 하나씩 빼면서 str 의 문자들과 차례로 비교
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] != pop(&s)) //같지 않으면
			return 0;
	}
	return 1;
}
int main(void)
{
	char word[MAX_STRING];
	printf("Enter a word to check palindrome: ");
	scanf("%s", word);
	if (palindrome(word))
		printf("palindrome 입니다.\n");
	else
		printf("palindrome 이 아닙니다.\n");
}
