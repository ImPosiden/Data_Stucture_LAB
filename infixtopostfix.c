#include <stdio.h>

char stack[100];
int top = -1;

void push(char c) {
    if (top < 100 - 1) {
        top++;
        stack[top] = c;
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0';
}

char peek() {
    if (top >= 0)
        return stack[top];
    return '\0';
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int isOperand(char c) {
    return (c >= 'A' && c <= 'Z');  
}

void infixtoPostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    char ch;
    
    while ((ch = infix[i++]) != '\0') {
        if (isOperand(ch)) {
            postfix[j++] = ch; 
        } else if (ch == '(') {
            push(ch); 
        } else if (ch == ')') {
            while (peek() != '(' && top != -1) {
                postfix[j++] = pop();
            }
            pop(); 
        } else if (isOperator(ch)) {
            while (top != -1 && precedence(peek()) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch); 
        }
    }
    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

int main() {
    char infix[100], postfix[100];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    infixtoPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}
