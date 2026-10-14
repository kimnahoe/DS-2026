#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100
typedef char element;
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
void push(StackType* s, char item)
{
	if (is_full(s)) {
		fprintf(stderr, "error\n");
		return;
	}
	else {
		(s->top)++;
		s->data[s->top] = item;
	}
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
int pick(StackType* s) {
	return s->data[s->top];
}
StackType *repeatPop(StackType *s, int size) 
{
	StackType *new;
	new=(StackType*)malloc(sizeof(StackType));
	init(new);
	
	for(int i=0; i<size; i++){
		char num=pop(s);
		if (is_empty(new) || num != new->data[new->top])
            push(new, num);
	}
	return new;
}
void print_list(StackType *new, int size){
	for(int i=new->top; i>=0; i--)
		printf("%c", new->data[i]);
}
int main(void)
{
	StackType s, *newS;
	init(&s);
	char input[MAX_STACK_SIZE];

    scanf("%s", input);

    int len = strlen(input);

    for (int i = 0; i < len; i++)
        push(&s, input[i]);

    newS = repeatPop(&s, len);
    
	len=newS->top+1;

    print_list(newS, len);
    
    free(newS);
	
	return 0;
}
