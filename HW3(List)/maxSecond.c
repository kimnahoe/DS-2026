#include <stdio.h>
#include <stdlib.h>
typedef struct ListNode { //기본구조
	int number;
	struct ListNode* link;
} ListNode;
int max(ListNode* head) {
	int max=head->number;
	int second=head->number;
	ListNode *temp=head;
	while(temp != NULL){
		if(max<temp->number)
			max=temp->number;
		temp=temp->link;
	}
	return max;
}
int maxSecond(ListNode* head) {
	int first=max(head);
	int second=-1;
	ListNode *temp=head;
	while(temp != NULL){
		if(temp->number<first && second<temp->number)
			second=temp->number;
		temp=temp->link;
	}
	return second;
}
int main(void)
{
	ListNode* head, * newNode, * temp;
	newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->number = 5;
	newNode->link = NULL;
	head = newNode;

	newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->number = 10;
	newNode->link = NULL;
	head->link = newNode;

	newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->number = 15;
	newNode->link = NULL;
	head->link->link = newNode;
	
	newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->number = 20;
	newNode->link = NULL;
	head->link->link->link = newNode;
	
	printf("%d\n", max(head));
	printf("%d", maxSecond(head));
}
