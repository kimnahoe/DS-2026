#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;
void init(StackType* s)
{
	s->top = -1;
}
int is_empty(StackType* s)
{
	return (s->top == -1);
}
int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}
void push(StackType* s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "error\n");
		return;
	}
	else
		s->data[++(s->top)] = item;
}
element pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "error\n");
		exit(1);
	}
	else
		return s->data[(s->top)--];
}
element peek(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "error\n");
		exit(1);
	}
	else
		return s->data[s->top];
}
StackType *reverse(StackType *s, int size){
	StackType *reverseS;
	reverseS=(StackType*)malloc(sizeof(StackType));
	init(reverseS);
	
	for(int i=0; i<size; i++) {
		push(reverseS, pop(s));
	}
	return reverseS;
}
void print_reverse(StackType *new, int size){
	for(int i=0; i<size; i++)
		printf("%d ", new->data[i]);
}
void main()
{
	StackType s, *new;
	init(&s);
	init(new);
	int size;
	scanf("%d",&size);

	for (int i = 0; i < size; i++) {
    	int num;
    	scanf("%d", &num);
    	push(&s, num);
	}
	new=reverse(&s, size);
	print_reverse(new, size);
}
