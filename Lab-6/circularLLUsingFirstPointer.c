#include <stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;
////////////Using First Pointer:
Node* first;

Node* createNewNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}
//Insertion at the end of the list using First pointer
void insertAtend(int val) {
    Node* newNode = createNewNode(val);
    if (first==NULL) {
        first = newNode;
        first->next = first;
        return;
    }
    Node* temp = first;
    while (temp->next!=first) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = first;
}
//Deletion from the beginning using First Pointer

void deleteFromFirst() {
    if (first==NULL) {
        printf("List is empty");
        return;
    }
    if (first->next==first) {
        Node* t = first;
        first = NULL;
        free(t);
        return;
    }
    Node* temp = first;
    while (temp->next!=first) {
        temp = temp->next;
    }
    Node* t = first;
    first = first->next;
    temp->next = first;
    free(t);
}

//Deletion from the End using First Pointer

void deleteFromEnd() {
    if (first==NULL) {
        printf("List is empty.");
        return;
    }
    if (first->next==first) {
        deleteFromFirst();
        return;
    }
    Node* temp = first;
    while (temp->next->next!=first) {
        temp = temp->next;
    }
    Node*t = temp->next;
    temp->next = first;
    free(t);

}

//Display function using First Pointer

void display() {
    Node* temp = first;
    printf("First->");
    do{
        if (temp->next==first) {
            printf("%d->First", temp->data);
        }
        else {
            printf("%d->",temp->data);
        }
        temp = temp->next;
    }while (temp!=first);
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

    /*
    "C:\Users\ABHIJEET CHANDRA\CLionProjects\untitled1\cmake-build-debug\untitled1.exe"
    First->0->First
    First->0->10->First
    First->0->10->20->First
    First->0->10->20->30->First
    First->0->10->20->30->40->First
    First->10->20->30->40->First
    First->10->20->30->First
     */
}
