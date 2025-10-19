#include <stdio.h>
#include <stdlib.h>

int numVertex;
int isDirected;
typedef struct graphNode {
    int vertex;
    int weight;
    struct graphNode* next;
}graphNode;

graphNode* createGraphNode(int vertex, int weight) {
    graphNode* newNode = (graphNode*)malloc(sizeof(graphNode));
    newNode->vertex = vertex;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

void readGraph(struct graphNode* head[]) {
    graphNode* newNode;
    int vertex,k,weight,neighbour;
    for (int i=0; i<numVertex; i++) {
        graphNode* tail = NULL;
        printf("Enter Vertex: ");
        scanf("%d",&vertex);
        if (head[vertex]==NULL)
            head[vertex] = tail = createGraphNode(vertex,-1);
        tail = head[vertex];
        while (tail->next!=NULL) {
            tail = tail->next;
        }
        printf("Enter number of vertices connected to vertex %d:",vertex);
        scanf("%d", &k);
        for (int j=0; j<k; j++) {
            printf("Enter vertex number: ");
            scanf("%d",&neighbour);
            printf("Enter weight: ");
            scanf("%d",&weight);
            newNode = createGraphNode(neighbour,weight);
            tail->next = newNode;
            tail = newNode;
            if (!isDirected) {
                if (head[neighbour] == NULL) {
                    head[neighbour] = createGraphNode(neighbour, -1);
                }
                graphNode *revNode = createGraphNode(vertex, weight);
                revNode->next = head[neighbour]->next;
                head[neighbour]->next = revNode;
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
    printf("Enter 1 if the graph is directed else enter 0: ");
    scanf("%d",&isDirected);
    graphNode* head[numVertex];
    for (int i=0; i<numVertex; i++) {
        head[i] = NULL;
    }
    readGraph(head);
    printGraph(head);
}

//
// Created by ABHIJEET CHANDRA on 19-10-2025.
//
