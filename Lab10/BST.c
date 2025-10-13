#include<stdio.h>
#include<stdlib.h>
# define MAX(a,b) ((a) > (b) ? (a) : (b))
typedef struct TreeNode {
    int data;
    int height;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

TreeNode* createTreeNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

TreeNode* createBinarySearchTree(TreeNode* root,int data) {
    if (root==NULL) {
        TreeNode* newNode = createTreeNode(data);
        return newNode;
    }
    if (data<root->data) {
        root->left = createBinarySearchTree(root->left,data);
    }
    else if (data>root->data) {
        root->right = createBinarySearchTree(root->right,data);
    }
    return root;
}

void preorder(TreeNode* root) {
    if (root==NULL) {
        return;
    }
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(TreeNode* root) {
    if (root==NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void postorder(TreeNode* root) {
    if (root==NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

int searchElement(TreeNode* root, int element) {
    if (root==NULL)return 0;
    if (element<root->data) return searchElement(root->left,element);
    if (element>root->data) return searchElement(root->right,element);
    return 1;
}

int findMax(TreeNode* root) {
    TreeNode* temp = root;
    while (temp->right!=NULL) {
        temp = temp->right;
    }
    return temp->data;
}

int findMin(TreeNode* root) {
    TreeNode* temp = root;
    while (temp->left!=NULL) {
        temp = temp->left;
    }
    return temp->data;
}

TreeNode* deleteNodeBST(TreeNode* root, int element) {
    if (root==NULL)return root;
    if (root->data==element) {
        //0 child.(leaf Node)
        if (root->left==NULL&&root->right==NULL) {
            free(root);
            return NULL;
        }
        //1 child (left child)
        if (root->left!=NULL&&root->right==NULL) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        //1 child (right child)
        if (root->left==NULL&&root->right!=NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        }
        //2 children
        if (root->left!=NULL&&root->right!=NULL) {
            int minval = findMin(root->right);
            root->data = minval;
            root->right = deleteNodeBST(root->right,minval);
            return root;
        }
    }
    else if (root->data>element) {
        root->left = deleteNodeBST(root->left,element);
    }
    else {
        root->right = deleteNodeBST(root->right,element);
    }
    return root;
}

//get height
int getHeight(TreeNode* root) {
    if (root==NULL)return 0;
    return 1+MAX(getHeight(root->left),getHeight(root->right));
}

//get balance factor
int getBalance(TreeNode* root) {
    if (root==NULL)return 0;
    return getHeight(root->left)-getHeight(root->right);
}
//left rotation
TreeNode* leftRotate(TreeNode* root) {
    TreeNode* child = root->right;
    TreeNode* childLeft = child->left;
    child->left = root;
    root->right = childLeft;
    root->height = getHeight(root);
    child->height = getHeight(child);
    return child;
}

//right rotation
TreeNode* rightRotate(TreeNode* root) {
    TreeNode* child = root->left;
    TreeNode* childRight = child->right;
    child->right = root;
    root->left = childRight;
    root->height = getHeight(root);
    child->height = getHeight(child);
    return child;
}

TreeNode* createAVLTree(TreeNode* root, int data) {
    if (root==NULL) {
        return createTreeNode(data);
    }
    if (data<root->data) {
        root->left = createAVLTree(root->left,data);
    }
    else if (data>root->data) {
        root->right = createAVLTree(root->right,data);
    }
    else {
        return root;
    }

    root->height = getHeight(root);
    int balance = getBalance(root);

    //left left rotation
    if (balance>1&&data<root->left->data) {
        return rightRotate(root);
    }
    //right right rotation
    if (balance<-1&&data>root->right->data) {
        return leftRotate(root);
    }
    //left right rotation
    if (balance>1&&data>root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    //right left rotation
    if (balance<-1&&data<root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
    }
int main() {
    int n,ele;
    printf("Enter number of nodes:");
    scanf("%d",&n);
    TreeNode* root = NULL;
    for (int i=0; i<n; i++) {
        printf("Enter element:");
        scanf("%d",&ele);
        root = createBinarySearchTree(root,ele);
    }
    printf("Inorder Traversal.\n");
    inorder(root);
    printf("\n");
    printf("Preorder: \n");
    preorder(root);
    printf("\n");
    printf("Postorder: \n");
    postorder(root);
    printf("\n");
    printf("Enter element to search:");
    scanf("%d",&ele);
    if (searchElement(root,ele)) {
        printf("Element found.\n");
    }
    else {
        printf("Element not found.\n");
    }
    printf("Max element: %d\n",findMax(root));
    printf("Min element: %d\n",findMin(root));
    root = deleteNodeBST(root,40);
    printf("After deletion.\n");
    inorder(root);
    printf("\n");

    printf("AVL Tree Creation.\n");
    printf("Enter number of nodes:");
    scanf("%d",&n);
    TreeNode* AVLroot = NULL;
    for (int i=0; i<n; i++) {
        printf("Enter element:");
        scanf("%d",&ele);
        AVLroot = createAVLTree(AVLroot,ele);
    }
    inorder(AVLroot);
}
//
// Created by ABHIJEET CHANDRA on 13-10-2025.
//
