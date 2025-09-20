    #include<stdio.h>
    #include<stdlib.h>
    #include <stdbool.h>
    typedef struct Node {
        int data;
        struct Node* next;
    }Node;

    Node* head =NULL;

    Node* createNode(int val) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = val;
        newNode->next = NULL;
        return newNode;
    }


    void insert_empty(int val) {
        if(head == NULL) {
            Node* newNode = createNode(val);
            head = newNode;
        }
    }

    void insert_before(int ele, int val) {
        Node* newNode = createNode(val);
        if (head==NULL) {
            printf("List is empty therefore inserting %d at starting of list\n",val);
            insert_empty(val);
            return;
        }
        if (head->data==ele) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next!=NULL) {
            if (temp->next->data==ele) {
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        }
        printf("Element not found\n");
    }

    void insert_after(int ele, int val) {
        Node* newNode = createNode(val);
        if (head==NULL) {
            printf("List is empty therefore inserting %d at starting of list\n",val);
            insert_empty(val);
            return;
        }
        if (head->data==ele) {
            newNode->next = head->next;
            head->next = newNode;
            return;
        }
        Node* temp = head;
        while (temp!=NULL) {
            if (temp->data==ele) {
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        }
        printf("Element not found\n");
    }
    void delete(int ele){
        if (head==NULL) {
            printf("List is empty therefore No deletion\n");
            return;
        }
        if (head->data==ele) {
            Node* temp = head;
            head = head->next;
            free(temp);
            return;
        }
        Node* temp = head;
        while (temp->next!=NULL) {
            if (temp->next->data==ele) {
                Node*t = temp->next;
                temp->next = temp->next->next;
                free(t);
                return;
            }
            temp = temp->next;
        }
        printf("Element not found\n");
    }
    void reverse() {

        if (head==NULL) {
            printf("List is empty\n");
            return;
        }
        if (head->next==NULL) {
            return;
        }
        Node* prev = NULL;
        Node* temp = head;
        while (temp!=NULL) {
            Node* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        head = prev;
        printf("List is reversed\n");
    }
    void delete_alternative() {
        if (head==NULL) {
            printf("List is empty\n");
            return;
        }
        if (head->next==NULL) {
            printf("Only 1 element present");
            return;
        }
        Node* temp = head;
        while (temp!=NULL&&temp->next!=NULL) {
            Node* t = temp->next;
            temp->next = temp->next->next;
            temp = temp->next;
            free(t);
        }
    }
    void sortList() {
        Node*i,*j;
        int temp;
        for (i=head; i!=NULL; i=i->next) {
            for (j = i->next; j!=NULL; j=j->next) {
                if (i->data>j->data) {
                    temp = i->data;
                    i->data = j->data;
                    j->data = temp;
                }
            }
        }
        printf("List sorted in ascending order\n");
    }
    int isSorted() {
        if (head == NULL || head->next == NULL) return 1;
        Node* temp = head;
        bool ascending = true;
        bool descending = true;
        //ascending..
        while (temp->next!=NULL) {
            if (temp->data>temp->next->data) {
                ascending = false;
                break;
            }
            temp = temp->next;
        }
        temp = head;
        while (temp->next!=NULL) {
            if (temp->data<temp->next->data) {
                descending = false;
                break;
            }
            temp = temp->next;
        }
        if (ascending) {
            return 1;
        }
        if (descending) {
            return 2;
        }
        return (3);
    }
    void insert_sorted(int ele) {
        if (isSorted()==3) {
            printf("List is not sorted\n");
            return;
        }
        if (isSorted()==1) {
            Node* temp = head;
            while (temp!=NULL) {
                if (temp->data>ele) {
                    insert_before(temp->data, ele);
                    return;
                }
                temp = temp->next;
            }
        }
        else if (isSorted()==2) {
            Node* temp = head;
            while (temp!=NULL) {
                if (temp->data<ele) {
                    insert_before(temp->data, ele);
                    return;
                }
                temp = temp->next;
            }
        }
        //append at end
        Node* newNode = createNode(ele);
        if (head==NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next!=NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void printList() {
        Node* temp = head;
        printf("head->");
        while (temp!=NULL) {
            printf("%d->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }

    int main() {
    int choice, val, ele;
    while (1) {
        printf("\n--- Singly Linked List Operations ---\n");
        printf("1. Insert before element\n");
        printf("2. Insert after element\n");
        printf("3. Delete element\n");
        printf("4. Display list\n");
        printf("5. Reverse list\n");
        printf("6. Sort list (Ascending)\n");
        printf("7. Delete every alternate node\n");
        printf("8. Insert into sorted list\n");
        printf("9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &val);
                printf("Enter existing element before which to insert: ");
                scanf("%d", &ele);
                insert_before(ele, val);
                break;

            case 2:
                printf("Enter element to insert: ");
                scanf("%d", &val);
                printf("Enter existing element after which to insert: ");
                scanf("%d", &ele);
                insert_after(ele, val);
                break;

            case 3:
                printf("Enter element to delete: ");
                scanf("%d", &ele);
                delete(ele);
                break;

            case 4:
                printList();
                break;

            case 5:
                reverse();
                break;

            case 6:
                sortList();
                break;

            case 7:
                delete_alternative();
                break;

            case 8:
                printf("Enter element to insert: ");
                scanf("%d", &val);
                insert_sorted(val);
                break;

            case 9:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice, try again.\n");
        }
    }
    return 0;
}
