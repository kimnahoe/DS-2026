#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct ListNode {
element data;
struct ListNode *link;
} ListNode;
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
ListNode* insert_next(ListNode *head, ListNode *pre, element value)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
 	pre->link = p;
 	return head;
}
ListNode* insert_first(ListNode *head, int value)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value; 
 	p->link = head; 
 	head = p; 
 	return head; 
}
ListNode* insert_last(ListNode *head, int value)
{
	ListNode *temp = head;
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = NULL;
 	if (head == NULL) 
 	head = p;
 	else {
 		while (temp->link != 0)
 			temp = temp->link;
 		temp->link = p;
		return head;
	}
}
ListNode* delete_next(ListNode *head, ListNode *pre)
{
	ListNode *removed;
 	removed = pre->link;
 	pre->link = removed->link; 
 	free(removed);

	return head;
}
ListNode* delete_first(ListNode *head)
{
	ListNode *removed;
	if (head == NULL) error("error");
 	removed = head;
 	head = removed->link; 
 	free(removed);
 	return head;
}
ListNode* delete_last(ListNode *head)
{
	ListNode *temp = head;
	ListNode *prevTemp;
	ListNode *removed;
	if (head == NULL) error("error");
 	if (temp->link == NULL) {
 		free(temp);
 		return NULL;
 	}
 	else {
 		while (temp->link != NULL) {
 			prevTemp = temp;
 			temp = temp->link;
 		}
 		removed = temp;
 		prevTemp->link = NULL;
 		free(removed);
 		return head; 
	}
}
void print_list(ListNode *head)
{
ListNode *p;
for (p = head; p != NULL; p = p->link)
printf("%d->", p->data);
printf("NULL \n");
}
int main(void)
{
ListNode *list1 = NULL, *list2 = NULL, *list3;

list1 = insert_first(list1, 10);
list1 = insert_first(list1, 20);
list1 = insert_first(list1, 30);

printf("list1 = ");
print_list(list1);

return 0;
}
