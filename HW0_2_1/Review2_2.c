//역문자열 만들기 s 0부터 e 인덱스 맨 끝
#include <stdio.h>
#include <string.h>
void reverse_string(char* str, int s, int e)
{
	int temp;

	if (s >= e) //시작시점이 더 크면 종료
		return 0;

	temp = str[s];
	str[s] = str[e];
	str[e] = temp;

	reverse_string(str, s + 1, e - 1);
}
int main()
{
	char str[100];
	printf("Enter any string:");
	scanf("%s", str);
	reverse_string(str, 0, strlen(str) - 1);
	printf("\nReversed String is: %s", str);
	return 0;
}
