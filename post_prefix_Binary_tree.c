#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Node of Expression Tree
struct Node {
    char data;
    struct Node *left, *right;
};

// Stack for characters (operators)
struct CharStack {
    int top;
    char arr[MAX];
};

// Stack for nodes (expression tree nodes)
struct NodeStack {
    int top;
    struct Node* arr[MAX];
};

// Functions for CharStack
void pushChar(struct CharStack* stack, char c) {
    stack->arr[++stack->top] = c;
}
char popChar(struct CharStack* stack) {
    return stack->arr[stack->top--];
}
char peekChar(struct CharStack* stack) {
    return stack->arr[stack->top];
}
int isEmptyChar(struct CharStack* stack) {
    return stack->top == -1;
}

// Functions for NodeStack
void pushNode(struct NodeStack* stack, struct Node* node) {
    stack->arr[++stack->top] = node;
}
struct Node* popNode(struct NodeStack* stack) {
    return stack->arr[stack->top--];
}

// Create new tree node
struct Node* newNode(char data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Infix to Postfix conversion (Shunting-yard algorithm)
void infixToPostfix(char infix[], char postfix[]) {
    struct CharStack stack;
    stack.top = -1;
    int k = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        if (isalnum(c)) {  // operand
            postfix[k++] = c;
        }
        else if (c == '(') {
            pushChar(&stack, c);
        }
        else if (c == ')') {
            while (!isEmptyChar(&stack) && peekChar(&stack) != '(')
                postfix[k++] = popChar(&stack);
            popChar(&stack); // remove '('
        }
        else { // operator
            while (!isEmptyChar(&stack) && precedence(peekChar(&stack)) >= precedence(c))
                postfix[k++] = popChar(&stack);
            pushChar(&stack, c);
        }
    }
    while (!isEmptyChar(&stack))
        postfix[k++] = popChar(&stack);

    postfix[k] = '\0';
}

// Build Expression Tree from Postfix
struct Node* constructTree(char postfix[]) {
    struct NodeStack stack;
    stack.top = -1;

    for (int i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];

        if (isalnum(c)) {
            pushNode(&stack, newNode(c));
        } else {
            struct Node* t = newNode(c);
            t->right = popNode(&stack);
            t->left = popNode(&stack);
            pushNode(&stack, t);
        }
    }
    return popNode(&stack);
}

// Traversals
void printPrefix(struct Node* root) {
    if (root != NULL) {
        printf("%c", root->data);
        printPrefix(root->left);
        printPrefix(root->right);
    }
}
void printPostfix(struct Node* root) {
    if (root != NULL) {
        printPostfix(root->left);
        printPostfix(root->right);
        printf("%c", root->data);
    }
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    struct Node* root = constructTree(postfix);

    printf("\nPrefix expression: ");
    printPrefix(root);

    printf("\nPostfix expression: ");
    printPostfix(root);

    printf("\n");

    return 0;
}
