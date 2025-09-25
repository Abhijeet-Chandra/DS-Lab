#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

struct Tasks {
    int doc_id;
    char name[100];
};

#define MAX_SIZE 100
struct Tasks queue[MAX_SIZE];
int rear = -1;
int front = -1;

int isEmpty() {
    return (front== rear);
}

int isFull() {
    return (!isEmpty()&&rear == MAX_SIZE-1);
}

void enqueue(struct Tasks task) {
    if (isFull()) {
        printf("Queue is Full.\n");
        return;
    }
    queue[++rear] = task;
}

struct Tasks dequeue() {
    if (isEmpty()) {
        printf("Queue is Empty.\n");
        front = rear = -1;
        struct Tasks st = {0, " "};
        return st;
    }
    struct Tasks returnval = queue[++front];
    return returnval;
}

struct Tasks peek() {
    if (isEmpty()) {
        printf("Queue is Empty.\n");
        front = rear = -1;
        struct Tasks st = {0, " "};
        return st;
    }
    return queue[front+1];
}

void display() {
    if (isEmpty()) {
        printf("Queue is Empty.\n");
        front = rear = -1;
        return;
    }
    for (int i=front+1; i<=rear; i++) {
        printf("Document id: %d\n",queue[i].doc_id);
        printf("Document Name: %s\n",queue[i].name);
        printf("\n");
    }
}

int main() {
    srand(time(0));

    int n;

    printf("Enter number of tasks: ");
    scanf("%d",&n);
    char** names = (char**)malloc(n*sizeof(char*));
    for (int i=0; i<n; i++) {
        names[i] = (char*)malloc(100*sizeof(char));
        printf("Enter task%d: ",i+1);
        scanf("%s",names[i]);
    }
    int op;

    do {
        struct Tasks task;
        task.doc_id = rand()%1000;
        strcpy(task.name,names[rand()%n]);
        printf("Generated: ID=%d, Name=%s\n", task.doc_id, task.name);
        enqueue(task);
        printf("Enter 1 to add new task, enter 2 to exit.");
        scanf("%d",&op);
    } while (op!=2);

    printf("-----Current Queue-----\n");
    display();

    printf("-----Processing Queue-----\n");
    while (!isEmpty()) {
        struct Tasks task = dequeue();
        printf("Printing job: ID=%d, Name=%s\n", task.doc_id, task.name);
    }

    printf("\nAll tasks printed!\n");


}

//
// Created by ABHIJEET CHANDRA on 19-09-2025.
//
