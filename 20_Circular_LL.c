#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Function to create circular linked list
void createList(int n) {
    struct Node *newNode, *temp;
    int data, i;

    if (n <= 0) {
        printf("Invalid number of nodes.\n");
        return;
    }

    head = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data for node 1: ");
    scanf("%d", &data);
    head->data = data;
    head->next = head; // circular link
    temp = head;

    for (i = 2; i <= n; i++) {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = head;   // new node links to head
        temp->next = newNode;   // previous node links to new
        temp = newNode;
    }
    printf("Circular Linked List created successfully!\n");
}

// Function to display circular linked list
void displayList() {
    struct Node *temp = head;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Insert at beginning
void insertAtBeginning(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = head;
    newNode->data = data;

    if (head == NULL) {
        head = newNode;
        head->next = head;
    } else {
        while (temp->next != head)
            temp = temp->next;  // reach last node

        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
    printf("%d inserted at beginning.\n", data);
}

// Insert at end
void insertAtEnd(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = head;
    newNode->data = data;

    if (head == NULL) {
        head = newNode;
        head->next = head;
    } else {
        while (temp->next != head)
            temp = temp->next;  // reach last node
        temp->next = newNode;
        newNode->next = head;
    }
    printf("%d inserted at end.\n", data);
}

// Delete from beginning
void deleteFromBeginning() {
    struct Node *temp = head, *last = head;
    if (head == NULL) {
        printf("List is empty, deletion not possible.\n");
        return;
    }

    if (head->next == head) { // only one node
        printf("%d deleted.\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    while (last->next != head)
        last = last->next;

    printf("%d deleted.\n", head->data);
    last->next = head->next;
    head = head->next;
    free(temp);
}

// Delete from end
void deleteFromEnd() {
    struct Node *temp = head, *prev;
    if (head == NULL) {
        printf("List is empty, deletion not possible.\n");
        return;
    }

    if (head->next == head) { // only one node
        printf("%d deleted.\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    while (temp->next->next != head)
        temp = temp->next;
    
    printf("%d deleted.\n", temp->next->data);
    free(temp->next);
    temp->next = head;
}

// Main menu-driven function
int main() {
    int choice, n, data;

    while (1) {
        printf("\n--- Circular Linked List Menu ---\n");
        printf("1. Create List\n");
        printf("2. Display List\n");
        printf("3. Insert at Beginning\n");
        printf("4. Insert at End\n");
        printf("5. Delete from Beginning\n");
        printf("6. Delete from End\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                createList(n);
                break;
            case 2:
                displayList();
                break;
            case 3:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 4:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 5:
                deleteFromBeginning();
                break;
            case 6:
                deleteFromEnd();
                break;
            case 7:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}