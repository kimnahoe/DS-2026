#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int calculate(char str[])
{
	char* stack = (char*)malloc(sizeof(char) * 10000);
	int i = 0;
	int sum = 0;
	int top = 0;
	char lastCal='+';
	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] >= '0' && str[i] <= '9') { //숫자면 push
			stack[top++] = str[i];
		}
		else { //부호면 pop 그 전에 있던 수까지 전부다 빼야함
			if (str[i] == '+') {
				for (int j = 0; j < top; j++)
					sum += (stack[j]-'0');
			}
			if (str[i] == '-') {
				for (int j = 0; j < top; j++)
					sum -= (stack[j] - '0');
			}
			if (str[i] == '*') {
				for (int j = 0; j < top; j++)
					sum *= (stack[j] - '0');
			}
			if (str[i] == '/') {
				for (int j = 0; j < top; j++)
					sum /= (stack[j] - '0');
			}
			top = 0;
			lastCal = str[i];
		}
	}
	if (top > 0) {
		if (lastCal == '+') {
			for (int j = 0; j<top; j++)
				sum += (stack[j] - '0');
		}
		if (lastCal == '-') {
			for (int j = 0; j < top; j++)
				sum -= (stack[j] - '0');
		}
		if (lastCal == '*') {
			for (int j = 0; j < top; j++)
				sum *= (stack[j] - '0');
		}
		if (lastCal == '/') {
			for (int j = 0; j < top; j++)
				sum /= (stack[j] - '0');
		}
	}
	free(stack);
	return sum;
}
int main(void)
{
	char* str = (char*)malloc(sizeof(char) * 1000);
	scanf("%s", str); //괄호 입력
	printf("%d", calculate(str)); //짝 확인 함수

	free(str);

	return 0;
}
