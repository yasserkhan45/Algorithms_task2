https://www.hackerrank.com/challenges/balanced-brackets/problem


#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}
 
int isFull(struct Stack* stack)
{
    return stack->top == stack->capacity - 1;
}
 
int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}
 
void push(struct Stack* stack, int item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}
 
int pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}

int top(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top];
}

char* isBalanced(char* s) {
    struct Stack *st = createStack(1000);  
    
    for (int i = 0; i < strlen(s); i++) {
        switch (s[i]) {
            case '{':
            case '(':
            case '[':
                push(st, s[i]);
                break;
            case '}':
                if (isEmpty(st) || (top(st) != '{')) {
                    return "NO";
                }
                pop(st);
                break;
            case ')':
                if (isEmpty(st) || (top(st) != '(')) {
                    return "NO";
                }
                pop(st);
                break;
            case ']':
                if (isEmpty(st) || (top(st) != '[')) {
                    return "NO";
                }
                pop(st);
                break;
        }
    }
    
    return isEmpty(st) ? "YES" : "NO";
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int a0 = 0; a0 < n; a0++){
        char s[1000];
        scanf("%s", s);
        printf("%s\n", isBalanced(s));
    }
    return 0;
}

