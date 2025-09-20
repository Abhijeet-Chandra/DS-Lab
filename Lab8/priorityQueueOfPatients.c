#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
        char name[20];
        int age;
        int priority;
    struct Node* next;
}Node;

Node* head = NULL;
Node* tail = NULL;
Node* createNode(char name[], int age, int priority) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name,name);
    newNode->age = age;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}
int isEmpty() {
    return head==NULL;
}
void enqueue(char name[], int age, int priority) {
    Node* newNode = createNode(name,age,priority);
    if (isEmpty()) {
        head = tail = newNode;
        return;
    }
    if (head->priority>newNode->priority) {
        newNode->next = head;
        head = newNode;
        return;
    }
    Node* temp = head;
    Node* temp2 = head;
    while (temp!=NULL) {

        if (temp->priority>newNode->priority) {
            newNode->next = temp2->next;
            temp2->next = newNode;
            return;
        }
        temp2 = temp;
        temp = temp->next;
    }
    temp2->next = newNode;
    tail = newNode;
}

Node dequeue() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        Node st = {" ",0, -1};
        return st;
    }
    Node returnval = *head;
    Node* t = head;
    head = head->next;
    if (head==NULL) {
        tail = NULL;
    }
    free(t);
    return returnval;
}

Node peek() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        Node st = {" ",0, -1};
        return st;
    }
    return *head;
}

void displayQueue() {
    if (isEmpty()) {
        printf("Empty queue.\n");
        return;
    }
    Node* temp = head;
    while (temp!=NULL) {
        printf("Patient Name: %s\n",temp->name);
        printf("Patient age: %d\n",temp->age);
        printf("Priority: %d\n",temp->priority);
        temp = temp->next;
        printf("-------------------------------\n");
    }
    printf("END\n");
}

int main() {
    int choice, age, priority;
    char name[20];

    do {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Patient name: ");
                scanf("%s", name);
                printf("Enter Patient age: ");
                scanf("%d", &age);
                printf("Enter Priority: ");
                scanf("%d", &priority );
                enqueue(name,age,priority);
                break;

            case 2:
                Node returnval = dequeue();
                if (returnval.priority != -1) {
                    printf("Dequeued: \n");
                    printf("Patient Name: %s\n",returnval.name);
                    printf("Patient Age: %d\n",returnval.age);
                    printf("Priority: %d\n",returnval.priority);
                }
                break;

            case 3:
                Node returnval1 = peek();
                if (returnval1.priority != -1) {
                    printf("Patient Details: \n");
                    printf("Patient Name: %s\n",returnval1.name);
                    printf("Patient Age: %d\n",returnval1.age);
                    printf("Priority: %d\n",returnval1.priority);
                }
                break;

            case 4:
                printf("Queue contents:\n ");
                displayQueue();
                printf("\n");
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 5);

    return 0;
}

//
// Created by ABHIJEET CHANDRA on 20-09-2025.
//
