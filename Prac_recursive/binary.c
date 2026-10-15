#include <stdio.h>
#include <string.h>

void binary(int num){
	if(num > 0){
		binary(num/=2);
		printf("%d", num%2);
	}
}
int main(void)
{
	int num;
	scanf("%d", &num);
	
	binary(num);
	
	return 0;
}
