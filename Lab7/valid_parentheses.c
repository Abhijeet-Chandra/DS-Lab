#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
int top = -1;

char stack[MAX_SIZE];

void push(char ch) {
    if (top == MAX_SIZE-1) {
        printf("Stack_overflow.");
        return;
    }

    stack[++top] = ch;
}

char pop() {
    if (top==-1) {
        printf("Stack_underflow.");
        return '\0';
    }
    return stack[top--];
}

char peek() {
    if (top==-1) {
        printf("Stack_underflow.");
        return '\0';
    }
    return stack[top];
}

int isEmpty() {
    return top==-1;
}

int main() {
    char str[100];
    printf("Enter an expression: ");
    scanf("%s",str);
    for (int i=0; i<strlen(str); i++) {
        if (str[i]=='('||str[i]=='['||str[i]=='{') {
            push(str[i]);
        }
        else if (str[i]==')'||str[i]==']'||str[i]=='}') {
            if (isEmpty()) {
                printf("Invalid\n");
                return 0;
            }
            if ((str[i]==')'&&peek()=='(')||(str[i]==']'&&peek()=='[')||(str[i]=='}'&&peek()=='{')) {
                pop();
            }
            else {
                printf("Invalid\n");
                return 0;
            }
        }

    }
    if (isEmpty()) {
        printf("Valid.");
    }
    else {
        printf("invalild");
    }
}
//
// Created by ABHIJEET CHANDRA on 11-09-2025.
//
