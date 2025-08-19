#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;
Node* head1=NULL, *head2 = NULL, *tail1=NULL, *tail2=NULL;
Node* createNewNode(int val)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void createList(int val, Node**head, Node** tail){
    Node* newNode = createNewNode(val);
    if(*(head)==NULL)
    {
        *head = newNode;
        *tail = newNode;
    }
    else{
        (*tail)->next = newNode;
        newNode->prev = *(tail);
        *tail = newNode;
    }
}
void printlist(Node**head){
    Node* temp = *(head);
    printf("Head<=>");
    while(temp!=NULL)
    {
        printf("%d<=>",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
Node* concat()
{
    if(head1==NULL)
    {
        return head2;
    }
    if(head2==NULL)
    {
        return head1;
    }
    Node* temp = head1;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = head2;
    head2->prev = temp;
    return head1;

}
int main(){
    int n1, n2, val;
    printf("Creating List 1:\n ");
    printf("Enter no of elements in list 1: ");
    scanf("%d",&n1);
    for(int i=0; i<n1; i++)
    {
        printf("Enter the element: ");
        scanf("%d",&val);
        createList(val,&head1, &tail1);
    }

    printf("Creating List 2:\n ");
    printf("Enter no of elements in list 2: ");
    scanf("%d",&n2);
    for(int i=0; i<n2; i++)
    {
        printf("Enter the element: ");
        scanf("%d",&val);
        createList(val,&head2, &tail2);
    }
    printlist(&head1);
    printlist(&head2);
    Node* head3 = concat();
    printlist(&head3);
}
