#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct
{
    char data[MAX_SIZE];
    int top;
} Stack;

int isOperand(char ch)
{
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
}

void push(Stack *stack, char ch)
{
    if (stack->top == MAX_SIZE - 1)
    {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack->data[++stack->top] = ch;
}

char pop(Stack *stack)
{
    if (stack->top == -1)
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack->data[stack->top--];
}

void postfixToInfix(char postfix[], char infix[])
{
    Stack stack;
    stack.top = -1;

    int length = strlen(postfix);
    for (int i = 0; i < length; i++)
    {
        if (isOperand(postfix[i]))
        {
            push(&stack, postfix[i]);
        }
        else
        {
            char operand2 = pop(&stack);
            char operand1 = pop(&stack);
            sprintf(infix, "(%c%c%c)", operand1, postfix[i], operand2);
            push(&stack, infix[0]);
        }
    }

    if (stack.top != 0)
    {
        printf("Invalid Postfix Expression\n");
        exit(1);
    }
}

int main()
{
    char postfix[MAX_SIZE];
    char infix[MAX_SIZE];

    printf("Enter a postfix expression: ");
    fgets(postfix, MAX_SIZE, stdin);
    postfix[strcspn(postfix, "\n")] = '\0';

    postfixToInfix(postfix, infix);

    printf("Infix Expression: %s\n", infix);

    return 0;
}