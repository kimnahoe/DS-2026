#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct DListNode {
 element data;
struct DListNode* llink;
struct DListNode* rlink;
} DListNode;
void init(DListNode* phead)
{
	phead->llink=phead;
	phead->rlink=phead;
}
void dinsert(DListNode *before, element data)
{
 	DListNode *newnode = (DListNode *)malloc(sizeof(DListNode));
 	newnode->data = data;
 	
 	newnode->llink=before;
 	newnode->rlink=before->rlink;
 	before->rlink->llink=newnode;
 	before->rlink=newnode;
}
void print_dlist(DListNode* phead)
{
 	DListNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink)
 		printf("<-| |%d| |-> ", p->data);
 	printf("\n");
}
int count_node(DListNode* head){
	DListNode* p;
	int len=0;
	for (p = head->rlink; p != head; p = p->rlink)
		len++;
	return len;
}
void insert_before(DListNode *head, element target, element data){
	DListNode* p;
	DListNode *newnode = (DListNode *)malloc(sizeof(DListNode));
 	newnode->data = data;
	for (p = head->rlink; p != head; p = p->rlink) {
		if(p->data == target){
			newnode->rlink=p;
			newnode->llink=p->llink;
			p->llink->rlink=newnode;
			break;
		}
	}
}
DListNode* search(DListNode *head, element data)
{
	DListNode* p;
	for (p = head->rlink; p != head; p = p->rlink)
		if(p->data == data)
			return p;
	return NULL;
}
void delete_value(DListNode *head, element data){ //data delete
	DListNode* removed=search(head, data);
	if(removed == NULL) {
		printf("X");
		return;
	}
	removed->llink->rlink=removed->rlink; //10
	removed->rlink->llink=removed->llink; //30
	free(removed);
}
int main(void)
{
 	DListNode* head = (DListNode *)malloc(sizeof(DListNode));

 	init(head);
 	
 	printf("insert\n");
 	dinsert(head, 10);
 	print_dlist(head);
 	dinsert(head, 20);
 	print_dlist(head);
 	dinsert(head, 30);
 	print_dlist(head);
 	dinsert(head, 40);
 	print_dlist(head);

//delete value
	printf("\ndelete value\n");
	delete_value(head, 30);
	print_dlist(head);
//size, len
	printf("\ncount\n");
	int len=count_node(head);
	printf("%d\n", len);
//target front insert
	printf("\ninsert_before\n");
	insert_before(head, 20, 72);
	print_dlist(head);
	
 	free(head);
 	
	return 0;
}
