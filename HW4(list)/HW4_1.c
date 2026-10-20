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
ListNode *reverse(ListNode *head)
{
	ListNode *p, *q, *r; //r...q...p
	p=head;
	q=NULL;
	while(p != NULL) {
		r=q;
		q=p;
		p=p->link;
		q->link=r;
	}
	return q;
}
ListNode *concat(ListNode *head1, ListNode *head2)
{
	ListNode *p;
	if(head1 == NULL) return head2;
	else if(head2 == NULL) return head2;
	else {
		p=head1;
		while(p->link!= NULL){
			p=p->link;
		}
		p->link=head2;
	}
	
	return head1;
}
int is_in_list(ListNode *head, element item){
	ListNode *p;
	p=head;
	while(p != NULL){
		if(p->data == item)
			return 1;
		p=p->link;
	}
	return 0;
}
int get_length(ListNode *head){
	int len=0;
	ListNode *p;
	p=head;
	while(p != NULL){
		len++;
		p=p->link;
	}
	return len;
}
int get_total(ListNode *head){
	int sum=0;
	ListNode *p;
	p=head;
	while(p != NULL){
		sum += p->data;
		p=p->link;
	}
	return sum;
}
element get_entry(ListNode *head, int pos){
	int index=0;
	ListNode *p;
	p=head;
	while(p != NULL){
		if(index == pos)
			return p->data;
		p=p->link;
		index++;
	}
}
ListNode * delete_by_key(ListNode *head, int key){ //key data delete
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
 			if(temp->data == key){
 				removed = temp;
 				prevTemp->link = removed->link;
 				free(removed);
 				return head; 
			 }
 			prevTemp = temp;
 			temp = temp->link;
 		}
	}
}
ListNode * insert_pos(ListNode *head, int pos, element value){
	int index=0;
	ListNode *temp = head;
	ListNode *prevTemp;
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = NULL;
	if (pos == 0) //first
		insert_first(head, value);
	else if(pos == get_length(head)) //pos == NULL
		insert_last(head, value);
	else{
		while (temp->link != NULL) {
 			prevTemp = temp;
 			temp = temp->link;
 			index++;
 			if(index == pos) {
 				p->link = temp;
 				prevTemp->link = p;
 				return head; 
			}
 		}
	}
}
ListNode * delete_pos(ListNode *head, int pos){
	int index=0;
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
 			if(index == pos){
 				removed = temp;
 				prevTemp->link = removed->link;
 				free(removed);
 				return head; 
			 }
 			prevTemp = temp;
 			temp = temp->link;
 			index++;
 		}
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
ListNode *head=NULL;

list1 = insert_first(list1, 10);
list1 = insert_first(list1, 20);
list1 = insert_first(list1, 30);
printf("list1 = ");
print_list(list1);
//list1의 맨 앞 노드를 삭제한다 즉, list1 = 20->10->
// list1을 출력
list1=delete_first(list1);
printf("list1 = ");
print_list(list1);
//list2 = 11->22->33->44->를 만든다. 이때 11, 22, 33, 44의 순으로 노드를 삽입한다.
// list2를 출력
list2 = insert_first(list2, 11);
list2 = insert_first(list2, 22);
list2 = insert_first(list2, 33);
list2 = insert_first(list2, 44);
list2 = reverse(list2);
printf("list2 = ");
print_list(list2);
// list2의 맨 뒤 노드를 삭제한다. 즉, list2 = 11->22->33->
// list2를 출력
list2=delete_last(list2);
printf("list2 = ");
print_list(list2);
//list2를 역순으로 바꾼 리스트를 list3가 가리키게 한다. list3 = 33->22->11->를 만든다.
//list3를 출력한다.
list3=reverse(list2);
printf("list3 = ");
print_list(list3);
// list1 = 20->10->33->22->11->를 만든다. 즉, list1과 list3를 합쳐서 list1이 가리키게 한다.
//list1을 출력한다.
list1=concat(list1, list3);
printf("list1 = ");
print_list(list1);
//(A) 주의: 여기서부터는 list1만 사용하여 함수들을 테스트하자
int key=is_in_list(list1, 10);
int len=get_length(list1);
int sum=get_total(list1);
int posData=get_entry(list1, 3);
printf("%d %d %d %d\n", key, len, sum, posData);

list1=delete_by_key(list1, 33);
printf("delete_by_key. list1 = ");
print_list(list1);

list1=insert_pos(list1, 3, 45);
printf("insert_pos. list1 = ");
print_list(list1);

list1=delete_pos(list1, 1);
printf("delete_pos. list1 = ");
print_list(list1);

return 0;
}
