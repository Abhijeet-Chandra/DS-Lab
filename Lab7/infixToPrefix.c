#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node* next;
}Node;

Node* top = NULL;

Node* createNode(char val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    return  newNode;
}

void push(char val) {
    Node* newNode = createNode(val);
    if (newNode==NULL) {
        printf("Memory allocation failed.Stack overflow.");
        return;
    }
    if (top==NULL) {
        top = newNode;
        return;
    }
    newNode->next = top;
    top = newNode;
}
char pop() {
    if (top==NULL) {
        printf("stack_underflow.\n");
        return '\0';
    }
    char val = top->data;
    Node*t = top;
    top = top->next;
    free(t);
    return val;
}
char peek() {
    if (top==NULL) {
        printf("stack_underflow.\n");
        return '\0';
    }
    return top->data;
}

int isEmpty() {
    return top==NULL;
}
int precedence(char symbol) {
    switch (symbol) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

int associativity(char symbol) {
    switch (symbol) {
        case '*':
        case '/':
        case '+':
        case '-':
            return 1; //L to R
        case '^':
            return 0; //R to L;
        default: return -1;
    }
}

int main() {
    char infix[100];
    char prefix[100];
    printf("Enter infix expression: ");
    scanf("%s",infix);

    int k  = 0;
    int n = strlen(infix);

    for (int i=0; i<n/2; i++) {
        char temp = infix[i];
        infix[i] = infix[n-i-1];
        infix[n-i-1] = temp;
    }

    for (int i=0; i<n; i++) {
        if (infix[i]==')') infix[i] = '(';
        else if (infix[i]=='(') infix[i] = ')';
    }
    for (int i=0; i<n; i++) {
        switch (infix[i]) {
            case '(':
                push(infix[i]);
                break;
            case ')':
                while (!isEmpty()&&peek()!='(') {
                    prefix[k++] = pop();
                }
                pop();
                break;
            case '^':
            case '*':
            case '/':
            case '+':
            case '-':
                if (associativity(infix[i])) {
                    while (!isEmpty()&&precedence(infix[i])<=precedence(peek())) {
                        prefix[k++] = pop();
                    }
                    push(infix[i]);
                }
                else {
                    while (!isEmpty()&&precedence(infix[i])<precedence(peek())) {
                        prefix[k++] = pop();
                    }
                    push(infix[i]);
                }
                break;
            default: prefix[k++] = infix[i];
        }
    }

    while (!isEmpty()) {
        prefix[k++] = pop();
    }

    prefix[k] = '\0';
    for (int i=0; i<k/2; i++) {
        char temp = prefix[i];
        prefix[i] = prefix[k-i-1];
        prefix[k-i-1] = temp;
    }


    printf("prefix: %s",prefix);
}

//
// Created by ABHIJEET CHANDRA on 11-09-2025.
//
