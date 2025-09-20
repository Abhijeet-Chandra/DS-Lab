#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
}Node;

Node* head = NULL;
Node* tail = NULL;
Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}
int isEmpty() {
    return head==NULL;
}
void enqueue(int val) {
    Node* newNode = createNode(val);
    if (!newNode) {
        printf("Cant allocate memory.Queue is FULL.");
        return;
    }
    if (isEmpty()) {
        head=tail=newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty.");
        return -1;
    }
    int returnval = head->val;
    Node* t = head;
    head = head->next;
    free(t);
    return returnval;
}

int peek() {
    if (isEmpty()) {
        printf("Queue is empty.");
        return -1;
    }
    return head->val;
}

void displayQueue() {
    if (isEmpty()) {
        printf("Empty queue.\n");
        return;
    }
    Node* temp = head;
    while (temp!=NULL) {
        printf("%d-",temp->val);
        temp = temp->next;
    }
    printf("END\n");
}

int main() {
    int choice, val;

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
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                enqueue(val);
                break;

            case 2:
                val = dequeue();
                if (val != -1) {
                    printf("Dequeued: %d\n", val);
                }
                break;

            case 3:
                val = peek();
                if (val != -1) {
                    printf("Front element: %d\n", val);
                }
                break;

            case 4:
                printf("Queue contents: ");
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
