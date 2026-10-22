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
void print_dlist(DListNode* phead)
{
 	DListNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink)
 		printf("<-| |%d| |-> ", p->data);
 	printf("\n");
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
void last_insert(DListNode *head, element data){
	DListNode *newnode = (DListNode *)malloc(sizeof(DListNode));
 	newnode->data = data;
 	head->llink->rlink=newnode;
 	newnode->rlink=head;
 	newnode->llink=head->llink;
 	head->llink=newnode;
}
void ddelete(DListNode* head, DListNode* removed)
{
	if (removed == head) return;
	removed->llink->rlink=removed->rlink;
	removed->rlink->llink=removed->llink;
	free(removed);
}
void delete_first(DListNode *head){
	DListNode* removed;
	if (head->rlink == head) return; 
	removed=head->rlink;
	head->rlink=removed->rlink;
	removed->rlink->llink=head;
	free(removed);
}
void delete_last(DListNode *head){
	DListNode* removed;
	if (head->rlink == head) return; 
	removed=head->llink;
	head->llink=removed->llink;
	removed->llink->rlink=head;
	free(removed);
}
void print_reverse_dlist(DListNode* head)
{
	DListNode* p;
	p=head->llink;
	while(p != head) {
		printf("<-| |%d| |-> ", p->data);
		p = p->llink;
	}
	printf("\n");
}
DListNode* search(DListNode *head, element data)
{
	DListNode* p;
	for (p = head->rlink; p != head; p = p->rlink)
		if(p->data == data)
			return p;
	return NULL;
}
int main(void)
{
 	DListNode* head = (DListNode *)malloc(sizeof(DListNode));
 	DListNode* key = (DListNode *)malloc(sizeof(DListNode));

 	init(head);
 	printf("insert\n");

//노드 삽입
 	dinsert(head, 10);
 	print_dlist(head);
 	dinsert(head, 20);
 	print_dlist(head);
 	dinsert(head, 30);
 	print_dlist(head);

//역순
 	printf("\nreverse\n");
 	print_reverse_dlist(head);

// 맨 뒤에 노드를 삽입하려면?
	printf("\nlast_insert\n");
	last_insert(head, 40);
	print_dlist(head);
//노드 삭제
 	printf("\ndelete\n");
 	ddelete(head, head->llink);
 	print_dlist(head);
// 맨 앞의 노드를 삭제
	printf("\ndelete_first\n");
 	delete_first(head);
 	print_dlist(head);
// 맨 뒤의 노드를 삭제하려면?
	printf("\ndelete_last\n");
	delete_last(head);
 	print_dlist(head);
//해당 key찾기
	printf("\nsearch\n");
	key = search(head, 70);
	if(key != NULL)
		printf("%d", key->data);
	else
		printf("X");
	
 	free(head);
 	
	return 0;
}
