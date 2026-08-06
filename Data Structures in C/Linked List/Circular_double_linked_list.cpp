#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
};

struct node *head = NULL, *last = NULL;

// Function declarations
struct node* createNode(int data);
void create();
void display();
void insertBegin();
void insertEnd();
void insertAfterKey();
void insertBeforeKey();
void deleteBegin();
void deleteEnd();
void deleteKey();
void reverseDisplay();

int main() {
    int ch;
    printf("\n--- Circular Doubly Linked List Menu ---\n");
    printf("1. Create Node\n2. Display List\n3. Insert at Start\n4. Insert at End\n");
    printf("5. Insert After Key\n6. Insert Before Key\n7. Delete from Start\n");
    printf("8. Delete from End\n9. Delete by Key\n10. Display in Reverse\n11. Exit\n");

    do {
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: insertBegin(); break;
            case 4: insertEnd(); break;
            case 5: insertAfterKey(); break;
            case 6: insertBeforeKey(); break;
            case 7: deleteBegin(); break;
            case 8: deleteEnd(); break;
            case 9: deleteKey(); break;
            case 10: reverseDisplay(); break;
            case 11: printf("Exiting the program.\n"); break;
            default: printf("Invalid option. Try again.\n");
        }
    } while (ch != 11);

    return 0;
}

// Create a new node with given data
struct node* createNode(int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

// Create node and add to end
void create() {
    int data;
    printf("Enter data: ");
    scanf("%d", &data);
    struct node *n = createNode(data);

    if (head == NULL) {
        head = last = n;
        head->next = head->prev = head;
    } else {
        last->next = n;
        n->prev = last;
        n->next = head;
        head->prev = n;
        last = n;
    }
}

// Display list from head to last
void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node *temp = head;
    printf("List (forward): ");
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("HEAD\n");
}

// Display list in reverse order
void reverseDisplay() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node *temp = last;
    printf("List (reverse): ");
    do {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    } while (temp != last);
    printf("LAST\n");
}

// Insert at beginning
void insertBegin() {
    int data;
    printf("Enter data: ");
    scanf("%d", &data);
    struct node *n = createNode(data);

    if (head == NULL) {
        head = last = n;
        head->next = head->prev = head;
    } else {
        n->next = head;
        n->prev = last;
        head->prev = n;
        last->next = n;
        head = n;
    }
}

// Insert at end
void insertEnd() {
    int data;
    printf("Enter data: ");
    scanf("%d", &data);
    struct node *n = createNode(data);

    if (head == NULL) {
        head = last = n;
        head->next = head->prev = head;
    } else {
        last->next = n;
        n->prev = last;
        n->next = head;
        head->prev = n;
        last = n;
    }
}

// Insert after a given key
void insertAfterKey() {
    int key, data;
    printf("Enter key to insert after: ");
    scanf("%d", &key);
    struct node *temp = head;

    if (!head) {
        printf("List is empty.\n");
        return;
    }

    do {
        if (temp->data == key) {
            printf("Enter data to insert: ");
            scanf("%d", &data);
            struct node *n = createNode(data);

            n->next = temp->next;
            n->prev = temp;
            temp->next->prev = n;
            temp->next = n;
            if (temp == last) last = n;
            return;
        }
        temp = temp->next;
    } while (temp != head);

    printf("Key %d not found.\n", key);
}

// Insert before a given key
void insertBeforeKey() {
    int key, data;
    printf("Enter key to insert before: ");
    scanf("%d", &key);
    struct node *temp = head;

    if (!head) {
        printf("List is empty.\n");
        return;
    }

    do {
        if (temp->data == key) {
            printf("Enter data to insert: ");
            scanf("%d", &data);
            struct node *n = createNode(data);

            n->next = temp;
            n->prev = temp->prev;
            temp->prev->next = n;
            temp->prev = n;

            if (temp == head) head = n;
            return;
        }
        temp = temp->next;
    } while (temp != head);

    printf("Key %d not found.\n", key);
}

// Delete from beginning
void deleteBegin() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node *temp = head;

    if (head == last) {
        head = last = NULL;
    } else {
        head = head->next;
        head->prev = last;
        last->next = head;
    }
    free(temp);
    printf("First node deleted.\n");
}

// Delete from end
void deleteEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node *temp = last;

    if (head == last) {
        head = last = NULL;
    } else {
        last = last->prev;
        last->next = head;
        head->prev = last;
    }
    free(temp);
    printf("Last node deleted.\n");
}

// Delete a specific key
void deleteKey() {
    int key;
    if (!head) {
        printf("List is empty.\n");
        return;
    }

    printf("Enter key to delete: ");
    scanf("%d", &key);
    struct node *temp = head;

    do {
        if (temp->data == key) {
            if (temp == head) {
                deleteBegin();
            } else if (temp == last) {
                deleteEnd();
            } else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                free(temp);
                printf("Node with key %d deleted.\n", key);
            }
            return;
        }
        temp = temp->next;
    } while (temp != head);

    printf("Key %d not found.\n", key);
}
