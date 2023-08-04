#include <stdio.h>
#include <ctype.h> 
#define MAX_SIZE 100
typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;
void initializeStack(Stack* stack) {
    stack->top = -1;
}
int isEmpty(Stack* stack) {
    return stack->top == -1;
}
int isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}
void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow. Cannot push element.\n");
        return;
    }
    stack->top++;
    stack->data[stack->top] = value;
}
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow. Cannot pop element.\n");
        return -1; 
    }
    int poppedValue = stack->data[stack->top];
    stack->top--;
    return poppedValue;
}
int evaluatePostfixExpression(const char* postfix) {
    Stack stack;
    initializeStack(&stack);
    int i, operand1, operand2, result;
    char ch;
    for (i = 0; postfix[i] != '\0'; i++) {
        ch = postfix[i];
        if (isdigit(ch)) {
            push(&stack, ch - '0');
        } else {
            operand2 = pop(&stack);
            operand1 = pop(&stack);
            switch (ch) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Invalid operator: %c\n", ch);
                    return -1; 
            }
            push(&stack, result);
        }
    }
    return pop(&stack);
}
int main() {
    char postfixExpression[] = "523*+4-"; 
    int result = evaluatePostfixExpression(postfixExpression);
    printf("Result: %d\n", result); 

    return 0;
}
