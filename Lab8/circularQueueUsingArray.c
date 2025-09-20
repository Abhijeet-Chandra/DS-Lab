#include <stdio.h>

#define MAX_SIZE 5
int front = -1;
int rear = -1;
int curr_size = 0;
int queue[MAX_SIZE];

int isEmpty() {
    return curr_size==0;
}

void enqueue(int val) {
    if (curr_size==MAX_SIZE) {
        printf("Queue is full.\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
        queue[rear] = val;
        curr_size++;
        return;
    }
    rear = (rear+1)%MAX_SIZE;
    queue[rear] = val;
    curr_size++;
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return -1;
    }
    int returnval = queue[front];
    front = (front+1)%MAX_SIZE;
    curr_size--;
    return returnval;
}

int peek() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return -1;
    }
    return queue[front];
}

void displayQueue() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    int i = front;
    for (int count = 0; count<curr_size; count++) {
        printf("%d ",queue[i]);
        i = (i+1)%MAX_SIZE;
    }
    printf("\n");
}
int main() {
    int choice, val;
    do {
        printf("\n--- Circular Queue Menu ---\n");
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
                if (val != -1)
                    printf("Dequeued: %d\n", val);
                break;

            case 3:
                val = peek();
                if (val != -1)
                    printf("Front element: %d\n", val);
                break;

            case 4:
                displayQueue();
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
