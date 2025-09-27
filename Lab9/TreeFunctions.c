#include<stdio.h>
#include<stdlib.h>
# define MAX(a,b) ((a) > (b) ? (a) : (b))
typedef struct TreeNode {
    int treeData;
    struct TreeNode* right;
    struct TreeNode* left;
}TreeNode;

//Stack implementation:
#define MAX_SIZE 100

typedef struct Node {
    TreeNode* data;
    struct Node* next;
}Node;

Node* top = NULL;

int isEmpty() {
    return top==NULL;
}

Node* createNode(TreeNode* val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void push(TreeNode* val) {
    Node* newNode = createNode(val);
    if (!newNode) {
        printf("Memory Allocation failed! Stack overflow.\n");
        return;
    }
    if (top==NULL) {
        top = newNode;
        return;
    }
    newNode->next = top;
    top = newNode;
}

TreeNode* pop() {
    if (isEmpty()) {
        printf("Stack Underflow.\n");
        return NULL;
    }
    TreeNode* returnval = top->data;
    Node* t = top;
    top = top->next;
    free(t);
    return returnval;
}

TreeNode* peek() {
    if (isEmpty()) {
        printf("Stack Underflow.\n");
        return NULL;
    }
    return top->data;
}

//creating Tree
int index = -1;
TreeNode* createBinaryTree(int preorder[]) {
    index++;
    if (preorder[index]==-1) {
        return NULL;
    }
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    root->treeData = preorder[index];
    root->left = createBinaryTree(preorder);
    root->right = createBinaryTree(preorder);
    return root;
}

void recursivePreorderTraversal(TreeNode* root) {
    if (root==NULL) {
        return;
    }
    printf("%d ",root->treeData);
    recursivePreorderTraversal(root->left);
    recursivePreorderTraversal(root->right);
}

void recursivePostorderTraversal(TreeNode* root) {
    if (root==NULL) {
        return;
    }
    recursivePostorderTraversal(root->left);
    recursivePostorderTraversal(root->right);
    printf("%d ",root->treeData);
}

void recursiveInorderTraversal(TreeNode* root) {
    if (root==NULL) {
        return;
    }
    recursiveInorderTraversal(root->left);
    printf("%d ",root->treeData);
    recursiveInorderTraversal(root->right);
}

void iterativePreorderTraversal(TreeNode* root) {
    if (root==NULL) {
        return;
    }
    push(root);
    while (!isEmpty()) {
        TreeNode* temp = pop();
        printf("%d ",temp->treeData);
        if (temp->right!=NULL) {
            push(temp->right);
        }
        if (temp->left!=NULL) {
            push(temp->left);
        }
    }

}

void iterativeInorderTraversal(TreeNode* root) {
    if (root==NULL) {
        return;
    }
    TreeNode* temp = root;
    while (!isEmpty()||temp!=NULL) {
        while (temp!=NULL) {
            push(temp);
            temp = temp->left;
        }
        temp = pop();
        printf("%d ",temp->treeData);

        temp = temp->right;
    }
}

void iterativePostorderTraversal(TreeNode* root) {
    int result[MAX_SIZE];
    int resIndex = 0;
    if (root==NULL) {
        return;
    }
    push(root);
    while (!isEmpty()) {
        TreeNode* temp = pop();
        result[resIndex++] = temp->treeData;
        if (temp->left!=NULL) {
            push(temp->left);
        }
        if (temp->right!=NULL) {
            push(temp->right);
        }
    }
    for (int i=resIndex-1; i>=0; i--) {
        printf("%d ",result[i]);
    }
}

int heightBT(TreeNode* root) {
    if (root==NULL) {
        return 0;
    }
    int leftHeight = heightBT(root->left);
    int rightHeight = heightBT(root->right);
    return MAX(leftHeight,rightHeight)+1;
}

int leafCount(TreeNode*root) {
    if (root == NULL)
        return 0;
    if (root->left==NULL&&root->right==NULL) {
        return 1;
    }
    return leafCount(root->left)+leafCount(root->right);
}

int print_ancestors(TreeNode* root, int target) {
   if (root==NULL) return 0;
    if (root->treeData==target) {
        return 1;
    }
    if (print_ancestors(root->left,target)||print_ancestors(root->right,target)) {
        printf("%d ",root->treeData);
        return 1;
    }
    return 0;
}

void print_parent(TreeNode* root, int target) {
    if (root==NULL) return;
    if ((root->left!=NULL&&root->left->treeData==target)||(root->right!=NULL&&root->right->treeData==target)) {
        printf("Parent is: %d ",root->treeData);
        printf("\n");
        return;
    }
    print_parent(root->left,target);
    print_parent(root->right,target);
}

int main() {
    int preorder[] = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    TreeNode* root = createBinaryTree(preorder);

    int choice, target;
    do {
        printf("\n\n--- Binary Tree Menu ---\n");
        printf("1. Recursive Preorder Traversal\n");
        printf("2. Recursive Inorder Traversal\n");
        printf("3. Recursive Postorder Traversal\n");
        printf("4. Iterative Preorder Traversal\n");
        printf("5. Iterative Inorder Traversal\n");
        printf("6. Iterative Postorder Traversal\n");
        printf("7. Height of Tree\n");
        printf("8. Leaf Count\n");
        printf("9. Print Ancestors of a Node\n");
        printf("10. Print Parent of a Node\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Recursive preorder: ");
                recursivePreorderTraversal(root);
                printf("\n");
                break;

            case 2:
                printf("Recursive inorder: ");
                recursiveInorderTraversal(root);
                printf("\n");
                break;

            case 3:
                printf("Recursive postorder: ");
                recursivePostorderTraversal(root);
                printf("\n");
                break;

            case 4:
                printf("Iterative preorder: ");
                iterativePreorderTraversal(root);
                printf("\n");
                break;

            case 5:
                printf("Iterative inorder: ");
                iterativeInorderTraversal(root);
                printf("\n");
                break;

            case 6:
                printf("Iterative postorder: ");
                iterativePostorderTraversal(root);
                printf("\n");
                break;

            case 7:
                printf("Height of tree: %d\n", heightBT(root));
                break;

            case 8:
                printf("Leaf count: %d\n", leafCount(root));
                break;

            case 9:
                printf("Enter target node: ");
                scanf("%d", &target);
                printf("Ancestors of %d: ", target);
                if (!print_ancestors(root, target)) {
                    printf("Node not found or no ancestors.");
                }
                printf("\n");
                break;

            case 10:
                printf("Enter target node: ");
                scanf("%d", &target);
                print_parent(root, target);
                break;

            case 0:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    } while(choice != 0);

    return 0;
}
