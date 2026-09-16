//새로운 포인터 구조체 반환하려면 그 함수 내 정의에서 동적할당으로 메모리 할당해줘야 함
#include <stdio.h>
#include <stdlib.h>
//1) typedef으로 Score를 정의
typedef struct {
	int midterm;
	int final;
} Score;
void printScore(Score* p) //2)
{
	printf("중간고사 성적은 %d\n", p->midterm);
	printf("학기말고사 성적은 %d\n", p->final);
}
Score* biggerScore(Score* p1, Score* p2) //3)
{
	Score* bigger = (Score*)malloc(sizeof(Score));
	if (p1->midterm + p1->final > p2->midterm + p2->final) {
		bigger->midterm = p1->midterm;
		bigger->final = p1->final;
	}
	else {
		bigger->midterm = p2->midterm;
		bigger->final = p2->final;
	}
	return bigger;
}

Score* totalScore(Score* p1, Score* p2) //4)
{
	Score *total = (Score*)malloc(sizeof(Score));
	total->midterm = p1->midterm + p2->midterm;
	total->final = p1->final + p2->final;
	return total;
}

Score* createScore(int m, int f) //5)
{
	Score* create = (Score*)malloc(sizeof(Score));
	create->midterm = m;
	create->final = f;
	return create;
}
int main(void) {
	Score* p1, * p2, * p3;
	//1) p1, p2를 각각 메모리 할당을 한 후
	// 가리키는 변수에 값 대입

	p1 = (Score*)malloc(sizeof(Score));
	p2 = (Score*)malloc(sizeof(Score));

	p1->midterm = 50;
	p1->final = 100;
	p2->midterm = 70;
	p2->final = 70;

	printScore(p1);
	printScore(p2);
	printf("-----------------------------\n");
	printf("둘중 성적이 좋은 점수:\n");
	printScore(biggerScore(p1, p2));

	printf("-----------------------------\n");
	printf("두 성적의 총 합:\n");
	printScore(totalScore(p1, p2));
	printf("-----------------------------\n");
	p3 = createScore(100, 100);
	printScore(p3);
	free(p1); free(p2); free(p3);
}
