#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int coeff;
    int exp;
    struct Node* next;
    struct Node* prev;
}Node;

Node* head1 = NULL, *head2 = NULL, *tail1 = NULL, *tail2 = NULL;

Node* createNode(int coeff, int exp) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

void createPolynomial(int coeff, int exp,Node** head, Node** tail) {
    Node* newNode = createNode(coeff,exp);
    if (*head==NULL) {
        *head = *tail = newNode;
        return;
    }
    (*tail)->next = newNode;
    newNode->prev = *tail;
    *tail = newNode;
}
Node* addPolynomials() {
    Node* temp1 = head1, *temp2 = head2;
    Node* head3 = NULL, *tail3 = NULL;
    while (temp1!=NULL&&temp2!=NULL) {
        if (temp1->exp>temp2->exp) {
            createPolynomial(temp1->coeff,temp1->exp,&head3, &tail3);
            temp1 = temp1->next;
        }
        else if (temp2->exp>temp1->exp) {
            createPolynomial(temp2->coeff,temp2->exp,&head3,&tail3);
            temp2 = temp2->next;
        }
        else {
            createPolynomial(temp1->coeff+temp2->coeff,temp1->exp,&head3,&tail3);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    while (temp1!=NULL) {
        createPolynomial(temp1->coeff, temp1->exp, &head3, &tail3);
        temp1 = temp1->next;
    }
    while (temp2!=NULL) {
        createPolynomial(temp2->coeff, temp2->exp, &head3, &tail3);
        temp2 = temp2->next;
    }
    return head3;
}
void display(Node**head) {
    Node*temp = *head;
    while (temp!=NULL) {
        printf("%dx^%d", temp->coeff, temp->exp);
        temp = temp->next;
        if (temp!=NULL)printf(" + ");
    }
    printf("\n");
}
int main() {
    printf("Creating polynomial 1:\n");
    int op,coeff,exp;
    do {
        printf("Enter coefficient: ");
        scanf("%d",&coeff);
        printf("Enter exponent: ");
        scanf("%d",&exp);
        createPolynomial(coeff,exp,&head1,&tail1);
        printf("Enter 1 to add more coefficients, Enter 2 to exit.\n");
        scanf("%d",&op);
    } while (op!=2);

    printf("Creating polynomial 2:\n");
    do {
        printf("Enter coefficient: ");
        scanf("%d",&coeff);
        printf("Enter exponent: ");
        scanf("%d",&exp);
        createPolynomial(coeff,exp,&head2,&tail2);
        printf("Enter 1 to add more coefficients, Enter 2 to exit.\n");
        scanf("%d",&op);
    } while (op!=2);
    printf("Poly1:\n ");
    display(&head1);
    printf("Poly2:\n ");
    display(&head2);
    Node* head3 = addPolynomials();
    printf("Poly3:\n ");
    display(&head3);

}
