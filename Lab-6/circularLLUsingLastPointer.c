#include <stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

////////////Using last Pointer:
Node* last;

Node* createNewNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

//Insertion at the end of the list using last pointer

void insertAtend(int val) {
    Node* newNode = createNewNode(val);
    if (last==NULL) {
        last = newNode;
        last->next = last;
        return;
    }
    newNode->next = last->next;
    last->next = newNode;
    last = newNode;

}

//Deletion from beginning using last pointer

void deleteFromFirst() {
    if (last==NULL) {
        printf("list is empty.");
        return;
    }
    if (last->next==last) {
        free(last);
        last = NULL;
        return;
    }
    Node* t = last->next;
    last->next = last->next->next;
    free(t);
}

//Deletion from end using last pointer

void deleteFromEnd() {
    if (last==NULL||last->next==last) {
        deleteFromFirst();
        return;
    }
    Node* temp = last;
    while (temp->next!=last) {
        temp = temp->next;
    }
    Node* t = last;
    temp->next = last->next;
    last=temp;
    free(t);
}

void display() {
    if (last==NULL) {
        printf("list is empty.");
        return;
    }
    Node* temp = last->next;
    do{
        if (temp==last) {
            printf("%d",temp->data);
        }
        else {
            printf("%d->", temp->data);
        }
        temp = temp->next;
    }while (temp!=last->next);
    printf("\n");
}

int main() {
    insertAtend(0);
    display();
    insertAtend(10);
    display();
    insertAtend(20);
    display();
    insertAtend(30);
    display();
    insertAtend(40);
    display();
    deleteFromFirst();
    display();
    deleteFromEnd();
    display();
    return 0;
}
