#include<stdio.h>
#include<stdlib.h>

typedef struct queueNode{
    int data;
    struct queueNode* next;
}queueNode;

queueNode* front = NULL, *rear = NULL;

queueNode* createQueueNode(int data){
    queueNode* newNode = (queueNode*)malloc(sizeof(queueNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int isEmpty(){
    return front == NULL;
}

void enqueue(int data){
    queueNode* newNode = createQueueNode(data);
    if(newNode==NULL){
        printf("Memory allocation failed.\n");
        return;
    }
    if(isEmpty()){
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}

int dequeue(){
    if(isEmpty()){
        printf("Queue is empty.\n");
        return -1;
    }
    queueNode* t = front;
    int returnvalue = front->data;
    front = front->next;
    free(t);
    return returnvalue;
}


typedef struct graphNode{
    int vertex;
    int weight;
    struct graphNode* next;
}graphNode;


int numVertex, isDirected;

graphNode* createGraphNode(int vertex, int weight){
    graphNode* newNode = (graphNode*)malloc(sizeof(graphNode));
    newNode->vertex = vertex;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

void readGraph(graphNode* head[]){
    graphNode* newNode;
    int vertex, neighbour, k, weight;
    for(int i = 0; i<numVertex; i++){
        graphNode* tail = NULL;
        printf("Enter Vertex: ");
        scanf("%d",&vertex);
        if(head[vertex]==NULL)
            head[vertex] = createGraphNode(vertex,-1);
        tail = head[vertex];
        while(tail->next!=NULL){
            tail = tail->next;
        }    
        printf("Enter the number of vertex for Vertex %d: ",vertex);
        scanf("%d",&k);
        for(int j =0; j<k; j++){
            printf("Enter vertex number: ");
            scanf("%d",&neighbour);
            printf("Enter weight: ");
            scanf("%d",&weight);
            newNode = createGraphNode(neighbour,weight);
            tail->next = newNode;
            tail = newNode;
            if(!isDirected){
                graphNode* revNode = createGraphNode(vertex,weight);
                if(head[neighbour]==NULL){
                    head[neighbour] = createGraphNode(neighbour,-1);
                    head[neighbour]->next = revNode;
                }
                else{
                    revNode->next = head[neighbour]->next;
                    head[neighbour]->next = revNode;
                }
            }
        }
    }
}

void printGraph(graphNode* head[]){
    for(int i=0; i<numVertex; i++){
        graphNode* temp = head[i];
        while(temp!=NULL){
            if(temp == head[i]){
                printf("Vertex %d->",temp->vertex);
            }
            else{
                printf("{%d %d}, ",temp->vertex,temp->weight);
            }
            temp = temp->next;
        }
        printf("\n");
    }
}

int visited[100] = {0};
void dfs(graphNode* head[], int start){
    if(head[start]==NULL)return;
    visited[start] = 1;
    printf("%d ",start);
    graphNode* temp = head[start]->next;
    while(temp!=NULL){
        if(visited[temp->vertex]==0){
            dfs(head,temp->vertex);
        }
        temp = temp->next;
    }
}

void bfs(graphNode* head[], int start){
    int visited[100] = {0};
    if(head[start]==NULL)return;
    visited[start] = 1;
    enqueue(start);
    while(!isEmpty()){
        int node = dequeue();
        printf("%d ",node);
        graphNode* temp = head[node]->next;
        while(temp!=NULL){
            if(visited[temp->vertex]==0){
                enqueue(temp->vertex);
                visited[temp->vertex] = 1;
            }
            temp = temp->next;
        }
    }
}

int main(){
    printf("Enter number of vertices: ");
    scanf("%d",&numVertex);
    printf("Enter 1 for directed graph 0 for undirected: ");
    scanf("%d",&isDirected);
    graphNode* head[numVertex];
    for(int i=0; i<numVertex; i++){
        head[i]= NULL;
    }
    readGraph(head);
    printGraph(head);
    dfs(head,0);
    printf("\n");
    bfs(head,0);
}
