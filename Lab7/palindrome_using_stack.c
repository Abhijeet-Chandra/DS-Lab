
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct stack {
    int top;
    char arr [100];

}stack;

stack st;

void create_stack() {
    st.top=-1;
}
char peek() {
    if (st.top==-1) {
        printf("stack is empty\n");
        return -1;
    }
    return st.arr[st.top];
}

char pop() {
    if (st.top==-1) {
        printf("stack is empty\n");
        return -1;
    }
    char character = peek();
    st.top--;
    return character;
}

void push(char character) {
    if (st.top == 99) {
        printf("stack overflow");
        return;
    }
    st.arr[++st.top] = character;
}

bool isEmpty() {
    if (st.top==-1)
        return true;
    return false;
}
int main() {
    create_stack();
    
    char str [1000];
    printf("Enter a string: ");
    scanf("%s",str);
    int i=0,n=strlen(str);

    int counter = 0;
    for (i=0; i<n; i++) {
        push(str[i]);
    }

    for (i=0; i<n; i++) {
        if (str[i]==peek()) {
            pop();
            counter++;
        }
        else break;
    }
    if (counter==n)
        printf("String is a palindrome.");
    else {
        printf("String is not a palindrome");
    }
}



//
// Created by ABHIJEET CHANDRA on 22-08-2025.
//
