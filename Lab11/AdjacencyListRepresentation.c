#include<stdio.h>
#include <stdlib.h>
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
}
//
// Created by ABHIJEET CHANDRA on 19-10-2025.
//
