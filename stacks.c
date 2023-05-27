#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char *arr;
	int capacity;
	int top;	
}Stack;

int pop(Stack *);
void push(Stack *,char);
int isEmpty(Stack *);
Stack *makeStack(int);
char *getMaxNumber(char *, int);

int main(void)
{
	char *n = (char *)malloc(50 * sizeof(char));
	int r;
	printf("enter a number: ");
	scanf("%s", n);
	printf("how many digits you want to remove: ");
	scanf("%d", &r);
	printf("maximum number after removing %d digits is %s\n", r, getMaxNumber(n, r));
	return 0;
}

int pop( Stack *stack){
	int topElement = stack->arr[stack->top];
	stack->top -= 1;
	return topElement;
}

void push(Stack *stack, char item){
	stack->top += 1;
	stack->arr[stack->top] = item;
}

int isEmpty(Stack *stack){
	if(stack->top == -1)
		return 1;
	return 0;
}

Stack *makeStack(int capacity){
	Stack *stack = (Stack*)malloc(sizeof(Stack));
	stack->capacity = capacity;	
	stack->arr = (char *)malloc(stack->capacity * sizeof(char));
	stack->top = -1;	
	return stack;
}

char *getMaxNumber(char *n, int r){
	int lengthN=strlen(n);
	Stack *stack = makeStack(lengthN);
	char *popped = (char*) malloc((lengthN-r) * sizeof(char));
	
    if (r >= lengthN){
        return "0";
    }
    
    int counter = 0;
    int i=0;
    for (; i < lengthN; i++){
			while (counter<r&&n[i] >stack->arr[stack->top]&&!isEmpty(stack)){
            pop(stack);
            counter++;
        	}
        push(stack, n[i]);
    }
    while (counter < r){
    	pop(stack);
        counter++;
    }	
    i=0;
    while (!isEmpty(stack)){
        popped[i++] = pop(stack);
    }
    popped[i] = '\0';  
	popped=strrev(popped); 
	popped[i] = '\0'; 
	return popped;
}
