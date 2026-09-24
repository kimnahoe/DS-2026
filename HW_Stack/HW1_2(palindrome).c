#define _CRT_SECURE_NO_WARNINGS
#define MAX_STRING 100
#include <stdio.h>
typedef char element;
typedef struct {
	element data[MAX_STRING];
	int top;
} StackType;
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
int palindrome(char str[])
{
	StackType s; // 배열을 사용할 경우 스택배열을 만듦
	// 필요한 변수들 선언
	
	s.top = -1; // 스택을 초기화하라
	if (is_full(&s))
		return 0;
	else {
		for (int i = 0; str[i] != '\0'; i++) {
			(s.top)++;
			s.data[s.top] = str[i];
		}
	}
	//스택에서 하나씩 빼면서 str 의 문자들과 차례로 비교
	for (int i = 0; str[i] != '\0'; i++) {
		if (s.data[s.top] != str[i]) //같지 않으면
			return 0;
		else
			s.top--;
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
