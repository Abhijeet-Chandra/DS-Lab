#include <stdio.h>

int main() {
    //Undirected weighted graph:
    printf("Adjacency matrix representation of Undirected weighted graph: \n");
    int vertex,edges,u,v,weight;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d",&vertex,&edges);
    int adjMat [vertex][vertex];
    //initializing adjMat to 0
    for (int i=0; i<vertex; i++) {
        for(int j=0; j<vertex; j++) {
            adjMat[i][j] = 0;
        }
    }
    for (int i=0; i<edges; i++) {
        printf("Enter edge UV(i.e. value of u and v) and weight of edge: ");
        scanf("%d %d %d",&u,&v,&weight);
        adjMat[u][v] = weight;
        adjMat[v][u] = weight;
    }
    //printing adjacency matrix:
    printf("Undirected weighted graph adjacency matrix representation: \n");
    for (int i=0; i<vertex; i++) {
        for (int j=0; j<vertex; j++) {
            printf("%d ",adjMat[i][j]);
        }
        printf("\n");
    }
    printf("\n");


    //Directed weighted graph:
    printf("Adjacency matrix representation of Directed weighted graph: \n");
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d",&vertex,&edges);
    int adjMat2 [vertex][vertex];
    //initializing adjMat2 to 0
    for (int i=0; i<vertex; i++) {
        for(int j=0; j<vertex; j++) {
            adjMat2[i][j] = 0;
        }
    }
    for (int i=0; i<edges; i++) {
        printf("Enter edge UV(i.e. value of u and v) and weight of edge: ");
        scanf("%d %d %d",&u,&v,&weight);
        adjMat2[u][v] = weight;
    }
    //printing adjacency matrix:
    printf("Directed weighted graph adjacency matrix representation: \n");
    for (int i=0; i<vertex; i++) {
        for (int j=0; j<vertex; j++) {
            printf("%d ",adjMat2[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}



//
// Created by ABHIJEET CHANDRA on 19-10-2025.
//
