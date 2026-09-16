//팩토리얼 과정 출력
#include <stdio.h>
void print_fact_exp(int n)
{
	if (n == 0 || n == 1) {
		printf("1");
		return; //void 형식이니까 반환값 없음
	}
	printf("%d * ", n);
	print_fact_exp(n - 1); //n갈수록 -1
}
int main(void)
{
	int n;
	printf("Enter a number:");
	scanf("%d", &n);
	printf("%d! = ", n);
	print_fact_exp(n);
	printf("\n");
}
