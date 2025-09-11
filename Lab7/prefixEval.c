#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
typedef struct Node {
    int data;
    struct Node* next;
}Node;

Node* top = NULL;

Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    return  newNode;
}

void push(int val) {
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
int pop() {
    if (top==NULL) {
        printf("stack_underflow.\n");
        return '\0';
    }
    int val = top->data;
    Node*t = top;
    top = top->next;
    free(t);
    return val;
}
int peek() {
    if (top==NULL) {
        printf("stack_underflow.\n");
        return '\0';
    }
    return top->data;
}



int main() {
    char prefix[100];
    printf("Enter the prefix expression: \n");
    scanf("%s",prefix);
    int op_top;
    int op_bottom;
    for (int i=strlen(prefix)-1; i>=0; i--) {
        switch (prefix[i]) {
            case '+':
                op_top = pop();
                op_bottom = pop();
                push(op_top+op_bottom);
                break;
            case '-':
                op_top = pop();
                op_bottom = pop();
                push(op_top-op_bottom);
                break;
            case '*':
                op_top = pop();
                op_bottom = pop();
                push(op_top*op_bottom);
                break;
            case '/':
                op_top = pop();
                op_bottom = pop();
                push(op_top/op_bottom);
                break;
            case '^':
                op_top = pop();
                op_bottom = pop();
                push(pow(op_top,op_bottom));
                break;
            default: push(prefix[i]-'0');
        }
    }

    printf("answer: %d",pop());
}
//
// Created by ABHIJEET CHANDRA on 11-09-2025.
//
