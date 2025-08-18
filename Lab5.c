#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
}Node;
Node* head = NULL;
Node* tail = NULL;
int size = 0;
Node* createNewNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}
void insertAtend(int val) {
    Node* newNode = createNewNode(val);
    if (head==NULL) {
        head = newNode;
        tail = newNode;
        size++;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
    size++;
}
void deleteFromEnd() {
    if (head==NULL) {
        printf("List is empty. No deletion needed");
        return;
    }
    if (head->next==NULL) {
        free(head);
        head = tail = NULL;
        size--;
        return;
    }
    Node* temp = tail->prev;
    Node* t = tail;
    temp->next = NULL;
    tail = temp;
    free(t);
    size--;
}
void insertAtIndex(int index, int val) {
    if (index<0||index>size) {
        printf("Out of bounds");
        return;
    }
    Node* newNode = createNewNode(val);
    if (index==0) {
        if (head==NULL) {
            head = tail = newNode;
            size++;
            return;
        }
        newNode->next = head;
        head->prev= newNode;
        head = newNode;
        size++;
        return;
    }
    if (index==size) {
        insertAtend(val);
        return;
    }
    int counter = 0;
    Node* temp = head;
    while (temp!=NULL&& temp->next!=NULL) {
        if (counter==index-1) {
            newNode->next = temp->next;
            temp->next->prev = newNode;
            temp->next = newNode;
            newNode->prev = temp;
            size++;
            return;
        }
        counter++;
        temp = temp->next;
    }
}
void deleteAtIndex(int index) {
    if (index<0||index>=size) {
        printf("out of bounds");
        return;
    }
    if (head==NULL) {
        printf("List is Empty.Nothing to delete");
        return;
    }
    if (index==0) {
        Node* t = head;
        head = head->next;
        free(t);
        size--;
        return;
    }
    if (index==size-1) {
        deleteFromEnd();
        return;
    }
    int counter = 0;
    Node* temp = head;
    while (temp!=NULL&&temp->next!=NULL) {
        if (counter==index-1) {
            Node*t = temp->next;
            temp->next= temp->next->next;
            free(t);
            if (temp->next!=NULL)
                temp->next->prev = temp;
            size--;
            return;
        }
        temp = temp->next;
        counter++;
    }
}
void insertBefore(int ele, int val) {
    if (head==NULL) {
        printf("List is empty.\n");
        return;
    }
    if (head->data == ele) {
        insertAtIndex(0,val);
        return;
    }
    Node* temp = head;
    while (temp!=NULL) {
        if (temp->data==ele) {
            Node* newNode = createNewNode(val);
            newNode->next = temp;
            temp->prev->next = newNode;
            newNode->prev = temp->prev;
            temp->prev = newNode;
            size++;
            return;
        }
        temp = temp->next;
    }
    printf("Element not found");
}
void insertAfter(int ele, int val) {
    if (head==NULL) {
        printf("List is Empty.\n");
        return;
    }
    if (head->data==ele) {
        insertAtIndex(1,val);
        return;
    }
    Node* temp = head;
    while (temp!=NULL) {
        if (temp->data==ele) {
            Node* newNode = createNewNode(val);
            newNode->next=temp->next;
            if (temp->next!=NULL)
                temp->next->prev = newNode;
            else
                tail = newNode;
            temp->next = newNode;
            newNode->prev = temp;
            size++;
            return;
        }
        temp = temp->next;
    }
    printf("Element not found.");
}
void printlist() {
    Node* temp = head;
    printf("Head<=>");
    while (temp!=NULL) {
        printf("%d<=>", temp->data);
        temp = temp->next;
    }
    printf("Tail\n");
}
void print_reverse() {

    Node* temp = tail;
    printf("Tail<=>");
    while (temp!=NULL) {
        printf("%d<=>", temp->data);
        temp = temp->prev;
    }
    printf("Head\n");
}
int main() {
    int choice, val, pos, ele;

    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert at rear\n");
        printf("2. Delete from rear\n");
        printf("3. Insert at a given position\n");
        printf("4. Delete from a given position\n");
        printf("5. Insert after a given value\n");
        printf("6. Insert before a given value\n");
        printf("7. Traverse forward\n");
        printf("8. Traverse backward\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insertAtend(val);
                break;
            case 2:
                deleteFromEnd();
                break;
            case 3:
                printf("Enter value and position: ");
                scanf("%d %d", &val, &pos);
                insertAtIndex(pos, val);
                break;
            case 4:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteAtIndex(pos);
                break;
            case 5:
                printf("Enter element after which to insert and the new value: ");
                scanf("%d %d", &ele, &val);
                insertAfter(ele, val);
                break;
            case 6:
                printf("Enter element before which to insert and the new value: ");
                scanf("%d %d", &ele, &val);
                insertBefore(ele, val);
                break;
            case 7:
                printlist();
                break;
            case 8:
                print_reverse();
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
