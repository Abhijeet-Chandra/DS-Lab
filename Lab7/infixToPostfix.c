#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        default: return 0;
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
            return 0; //R to L
        default: return -1;
    }
}
int isEmpty() {
    if (top==NULL) return 1;
    return 0;
}

int main() {
    char infix[100];
    char postfix[100];
    int k =0;
    printf("Enter infix expression: ");
    scanf("%s",infix);
    for (int i=0; i<strlen(infix); i++) {
        switch (infix[i]) {
            case '(': push('(');
                break;
            case ')':
                while (!isEmpty()&&peek()!='(') {
                    postfix[k++] = pop();
                }
                pop();
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                if (associativity(infix[i])) {
                        while (!isEmpty()&&(precedence(infix[i])<=precedence(peek()))) {
                            postfix[k++] = pop();
                        }
                        push(infix[i]);

                }

                else {
                        while (!isEmpty()&&(precedence(infix[i])<precedence(peek()))) {
                            postfix[k++] = pop();
                        }
                        push(infix[i]);

                }
                break;
            default: postfix[k++] = infix[i];
        }
    }

    while (!isEmpty()) {
        postfix[k++] = pop();
    }
    postfix[k] = '\0';

    printf("Postfix: %s",postfix);
}

//
// Created by ABHIJEET CHANDRA on 10-09-2025.
//
