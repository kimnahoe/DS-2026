#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode *link;
} ListNode;
void print_list(ListNode* head)
{
	ListNode* p;
	if (head == NULL) return;
	p = head->link;
	do{
		printf("%d->", p->data);
		p=p->link;
	}while(p != head->link);
	printf("NULL\n");
}
ListNode* insert_first(ListNode* head, element data)
{
	ListNode *node = (ListNode *)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = node;
	}
	else {
		node->link = head->link; 
		head->link = node;
	}
	return head;
}
ListNode* insert_last(ListNode* head, element data)
{
	ListNode *node = (ListNode *)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = node;
	}
	else {
		node->link = head->link;
		head->link = node;
		head = node;
	}
	return head;
}
ListNode* delete_first(ListNode* head)
{
 	ListNode *temp;
 	if (head == NULL) {
 		printf("error\n");
 		return NULL;
 	}
 	else if (head == head->link) {
 		temp = head;
 		head = NULL;
 		free(temp);
 	}
 	else {
 		temp = head->link;
 		head->link = temp->link;
 		free(temp);
 	}
	return head;
}
ListNode* delete_last(ListNode* head)
{
	ListNode* p;
	ListNode *prev;
	if ((head == NULL) || (head == head->link)) return NULL;
	prev=head;//removed=30;
	p=head->link;//p=40;
	while(p->link != head) {//원형이라서
		prev=p;
		p=p->link;
	}
	return head;
}
ListNode* search(ListNode* head, element data)
{
    ListNode* p;
    if (head == NULL) return NULL;
    p = head->link;
    do {
        if (p->data == data)
            return p;
        p = p->link;
    } while (p != head->link);
    return NULL;
}
int get_size(ListNode* head)
{
	int len=0;
	ListNode* p;
	if (head == NULL) return 0;
	p = head->link;
	do{
		len++;
		p=p->link;
	}while(p != head->link);
	return len;
}
int main(void)
{
	ListNode *head = NULL;
// list = 10->20->30->40
	head = insert_last(head, 20);
	print_list(head);
 	head = insert_last(head, 30);
 	print_list(head);
 	head = insert_last(head, 40);
 	print_list(head);
 	head = insert_first(head, 10);
 	print_list(head);
 	head = delete_first(head);
 	print_list(head);
 	
 	printf("get_size(head): %d\n", get_size(head));
 	printf("delete_first(head): ");
 	head = delete_first(head);
	print_list(head);
	printf("search(head): ");
 	head = search(head, 40);
	print_list(head);

	return 0;
} 
