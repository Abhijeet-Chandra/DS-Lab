
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
        return -1;
    }
    return st.arr[st.top];
}

char pop() {
    if (st.top==-1) {
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

    for (i=0; i<n; i++) {
        if (str[i]=='{'||str[i]=='['||str[i]=='(') {
            push(str[i]);
        }
        else if ((str[i]=='}'&&peek()=='{')||(str[i]==']'&&peek()=='[')||(str[i]==')'&&peek()=='(')) {
            pop();
        }
        else {
            printf("Not a valid parentheses");
            return 0;
        }

    }

    if (isEmpty()) {
        printf("Valid parentheses");
    }
    else {
        printf("Not a valid parentheses");
    }

}


