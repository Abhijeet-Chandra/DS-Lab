#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

Node* head = NULL;
Node* tail = NULL;
int size = 0;
Node* create_node(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}
void insertHead(int val) {
    Node* newNode = create_node(val);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        tail->next = head;
        size++;
        return;
    }
    newNode->next = head;
    head = newNode;
    tail->next = head;
    size++;
}
void insertTail(int val) {
    Node* newNode = create_node(val);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        tail->next = head;
        size++;
        return;
    }
    tail->next = newNode;
    tail = newNode;
    tail->next = head;
    size++;
}
void deleteHead() {
    if (head == NULL) {
        printf("The list is empty\n");
        return;
    }
    if (head==tail) {
        free(head);
        head =tail= NULL;
        return;
    }
    Node* t = head;
    head = head->next;
    tail->next = head;
    free(t);
    size--;
}
void deleteTail() {
    if (head == NULL) {
        printf("The list is empty\n");
        return;
    }
    if (head==tail) {
        free(head);
        head =tail= NULL;
        return;
    }
    Node* temp = head;
    while (temp->next!=tail) {
        temp=temp->next;
    }
    Node* t = temp->next;
    tail = temp;
    tail->next = head;
    free(t);
    size--;
}
void display() {
    Node* temp = head;
    printf("Head->");
    do {
        printf("%d->", temp->data);
        temp = temp->next;
    }while (temp!=head);
    printf("Head\n");
}
int main() {
    insertHead(10);
    insertTail(20);
    insertTail(30);
    insertTail(40);
    insertTail(50);
    insertTail(60);
    insertTail(70);
    insertTail(80);
    display();
    deleteHead();
    deleteTail();
    deleteHead();

    display();

}
