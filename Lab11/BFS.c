#include<stdio.h>
#include <stdlib.h>
//creating adjacency list for graph...
typedef struct graphNode {
    int vertex;
    int weight;
    struct graphNode* next;
}graphNode;

int numVertex;
int isDirected;

graphNode* createGraphNode(int vertex, int weight) {
    graphNode* newNode = (graphNode*)malloc(sizeof(graphNode));
    newNode->vertex = vertex;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}
void readGraph(graphNode* head[]) {
    graphNode* newNode;
    int vertex, neighbour,k,weight;
    for (int i=0; i<numVertex; i++) {
        graphNode* tail = NULL;
        printf("Enter vertex: \n");
        scanf("%d",&vertex);
        if (head[vertex]==NULL)
            head[vertex] = tail = createGraphNode(vertex,-1);
        tail = head[vertex];
        while (tail->next!=NULL) {
            tail = tail->next;
        }
        printf("Enter the number of neighbours for vertex %d: ",vertex);
        scanf("%d",&k);
        for (int j=0; j<k; j++) {
            printf("Enter vertex number: ");
            scanf("%d",&neighbour);
            printf("Enter weight: ");
            scanf("%d",&weight);
            newNode = createGraphNode(neighbour,weight);
            tail->next = newNode;
            tail = newNode;
            if (!isDirected) {
                graphNode* revNode = createGraphNode(vertex,weight);
                if (head[neighbour]==NULL) {
                    head[neighbour] = createGraphNode(neighbour,-1);
                    head[neighbour]->next = revNode;
                }
                else {
                    revNode->next = head[neighbour]->next;
                    head[neighbour]->next = revNode;
                }
            }
        }
    }
}
void printGraph(struct graphNode* head[]) {
    for (int i = 0; i<numVertex; i++) {
        graphNode* temp = head[i];
        while (temp!=NULL) {
            if (temp==head[i]) {
                printf("Vertex %d->",temp->vertex);
            }
            else {
                printf("{%d %d}, ",temp->vertex,temp->weight);
            }
            temp = temp->next;
        }
        printf("\n");
    }
}

//BFS traversal:
//we need to make queue first
//Queue:
typedef struct Node {
    graphNode* data;
    struct Node* next;
}Node;

Node* front = NULL;
Node* rear = NULL;

int isEmpty() {
    return front == NULL;
}

Node* createQueueNode(graphNode* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void enqueue(graphNode* data) {
    Node* newNode = createQueueNode(data);
    if (!newNode) {
        printf("Memory allocation failed.\n");
        return;
    }
    if (isEmpty()) {
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}

graphNode* dequeue() {
    if (isEmpty()) {
        printf("Queue is Empty.\n");
        return NULL;
    }
    graphNode* returnvalue = front->data;
    Node* t = front;
    front = front->next;
    free(t);
    return returnvalue;
}


//BFS traversal:
int visited[100];
void BFS(graphNode* head[], int start) {
    int visited[100] = {0};
    enqueue(head[start]);
    visited[start] = 1;
    while (!isEmpty()) {
        graphNode* node = dequeue();
        printf("%d ",node->vertex);
        graphNode* temp = node->next;
        while (temp!=NULL) {
            if (visited[temp->vertex]==0) {
                visited[temp->vertex]=1;
                enqueue(head[temp->vertex]);
            }
            temp = temp->next;
        }
    }
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d",&numVertex);
    printf("Enter 1 if graph is directed and enter 0 if its undirected.\n");
    scanf("%d", &isDirected);
    graphNode* head[numVertex];
    for (int i = 0; i < numVertex; i++) {
        head[i] = NULL;
    }
    readGraph(head);
    printGraph(head);
    BFS(head,0);
}
//
// Created by ABHIJEET CHANDRA on 20-10-2025.
//
