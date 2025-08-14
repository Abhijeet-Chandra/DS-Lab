#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int coeff;
    int exp;
    struct Node* next;
    struct Node* prev;
}Node;

Node* head1 = NULL;
Node* head2 = NULL;
Node* head3 = NULL;

Node* create_node(int coeff, int exp) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
void create_polynomial(Node** head, int coeff, int exp) {
    Node* newNode = create_node(coeff,exp);
    if (*head==NULL) {
        *head = newNode;
        (*head)->prev = NULL;
        return;
    }
    newNode->next = *head;
    (*head)->prev = newNode;
    (*head) = newNode;
    (*head)->prev = NULL;
}
void print_polynomial(Node** head) {
    Node* temp = *head;
    while (temp != NULL) {
        if (temp->next==NULL) {
            printf("%dx^%d", temp->coeff, temp->exp);
            break;
        }
        printf("%dx^%d + ", temp->coeff, temp->exp);
        temp = temp->next;
    }
    printf("\n");
}
void add_polynomials(Node** head1, Node** head2) {
    if (*head1==NULL) {
        head3 = *head2;
        return;
    }
    if (*head2==NULL) {
        head3 = *head1;
        return;
    }
    Node* temp1 = *head1;
    Node* temp2 = *head2;
    while (temp1->next!=NULL) {
        temp1 = temp1->next;
    }
    while (temp2->next!=NULL) {
        temp2 = temp2->next;
    }
    while (temp1!=NULL&&temp2!=NULL) {
        create_polynomial(&head3, temp1->coeff+temp2->coeff, temp1->exp);
        temp1 = temp1->prev;
        temp2 = temp2->prev;
    }
    while (temp1!=NULL) {
        create_polynomial(&head3, temp1->coeff, temp1->exp);
        temp1 = temp1->prev;
    }
    while (temp2!=NULL) {
        create_polynomial(&head3, temp2->coeff, temp2->exp);
        temp2 = temp2->prev;
    }

}
int main() {
    int degree,coeff;
    printf("Enter degree of polynomial1: ");
    scanf("%d", &degree);
    for (int i=0; i<=degree; i++) {
        printf("Enter coefficient for x^%d: ", i);
        scanf("%d",&coeff);
        create_polynomial(&head1,coeff,i);
    }
    printf("Enter degree of polynomial2: ");
    scanf("%d", &degree);
    for (int i=0; i<=degree; i++) {
        printf("Enter coefficient for x^%d: ", i);
        scanf("%d",&coeff);
        create_polynomial(&head2,coeff,i);
    }
    print_polynomial(&head1);
    print_polynomial(&head2);
    add_polynomials(&head1,&head2);
    print_polynomial(&head3);
}
