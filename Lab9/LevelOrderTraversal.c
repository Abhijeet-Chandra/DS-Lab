#include<stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int treeData;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;


//Queue (for level order traversal)
typedef struct Node {
    TreeNode* nodeData;
    struct Node* next;
}Node;
Node* front = NULL;
Node* rear = NULL;
int currSize = 0;

Node* createNode(TreeNode* node) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->nodeData = node;
    newNode->next = NULL;
    return newNode;
}

int isEmpty() {
    return currSize==0;
}
void enqueue(TreeNode* node) {
    Node* newNode = createNode(node);
    if (!newNode) {
        printf("Memory Allocation failed!Queue is FULL.\n");
        return;
    }
    if (isEmpty()) {
        front = rear = newNode;
        currSize++;
        return;
    }
    rear->next = newNode;
    rear = newNode;
    currSize++;
}

TreeNode* dequeue() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return NULL;
    }
    Node*t = front;
    TreeNode* returnValue = front->nodeData;
    front = front->next;
    if (front==NULL) rear = NULL; //resetting rear when queue is empty.
    currSize--;
    free(t);
    return returnValue;
}
TreeNode* peek() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return NULL;
    }
    return front->nodeData;
}


TreeNode* createBinaryTree() {
    int op;
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    printf("Enter value: ");
    scanf("%d",&node->treeData);
    printf("Enter 1 to insert Left of Node %d: ", node->treeData);
    scanf("%d",&op);
    if (op) {
        node->left = createBinaryTree();
    }
    else {
        node->left = NULL;
    }

    printf("Enter 1 to insert Right of Node %d: ", node->treeData);
    scanf("%d",&op);
    if (op) {
        node->right = createBinaryTree();
    }
    else {
        node->right = NULL;
    }
    return node;
}

void levelOrderTraversal(TreeNode* root) {
    if (root==NULL) {
        printf("Tree is empty.\n");
        return;
    }
    enqueue(root);
    while (!isEmpty()) {
        TreeNode* node = dequeue();
        printf("%d ",node->treeData);
        if (node->left!=NULL) enqueue(node->left);
        if (node->right!=NULL) enqueue(node->right);
    }
}

int main() {
    TreeNode* root = createBinaryTree();
    printf("Level order traversal: \n");
    levelOrderTraversal(root);
}
