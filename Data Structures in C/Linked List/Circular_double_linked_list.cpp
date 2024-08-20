// Double or Doubly linked list

#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
} *head = NULL, *last = NULL, *n, *temp, *p;

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
    printf("1.Create\n2.Display\n3.Insert start\n4.Insert end\n5.Insert After key\n6.Insert Before key\n7.Delete start\n8.Delete end\n9.Delete key\n10.Display in reverse\n11.Exit\n");
    do {
        printf("Enter your choice:\n");
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
            case 11: printf("Exiting the process\n"); exit(0);
            default: printf("Wrong option\n");
        }
    } while (ch <= 11);
}

void create() {
    n = (struct node *)malloc(sizeof(struct node));
    printf("Enter data value:\n");
    scanf("%d", &n->data);
    n->next = n->prev = NULL;
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

void display() {
    if (head == NULL) {
        printf("Empty list\n");
        return;
    }
    temp = head;
    printf("The linked list is:\n");
    do {
        printf("%d->", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

void insertBegin() {
    n = (struct node *)malloc(sizeof(struct node));
    printf("Enter data value:\n");
    scanf("%d", &n->data);
    n->next = n->prev = NULL;
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

void insertEnd() {
    n = (struct node *)malloc(sizeof(struct node));
    printf("Enter data value:\n");
    scanf("%d", &n->data);
    n->next = n->prev = NULL;
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

void insertAfterKey() {
    int key;
    printf("Enter key:\n");
    scanf("%d", &key);
    temp = head;
    do {
        if (temp->data == key) {
            n = (struct node *)malloc(sizeof(struct node));
            printf("Enter data value:\n");
            scanf("%d", &n->data);
            n->next = n->prev = NULL;
            n->next = temp->next;
            n->prev = temp;
            temp->next->prev = n;
            temp->next = n;
            if (temp == last) {
                last = n;
            }
            return;
        }
        temp = temp->next;
    } while (temp != head);
    printf("Key not found\n");
}

void insertBeforeKey() {
    int key;
    printf("Enter key:\n");
    scanf("%d", &key);
    temp = head;
    do {
        if (temp->data == key) {
            n = (struct node *)malloc(sizeof(struct node));
            printf("Enter data value:\n");
            scanf("%d", &n->data);
            n->next = n->prev = NULL;
            n->next = temp;
            n->prev = temp->prev;
            temp->prev->next = n;
            temp->prev = n;
            if (temp == head) {
                head = n;
            }
            return;
        }
        temp = temp->next;
    } while (temp != head);
    printf("Key not found\n");
}

void deleteBegin() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    temp = head;
    if (head == last) {
        head = last = NULL;
    } else {
        head = head->next;
        head->prev = last;
        last->next = head;
    }
    free(temp);
}

void deleteEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    temp = last;
    if (head == last) {
        head = last = NULL;
    } else {
        last = last->prev;
        last->next = head;
        head->prev = last;
    }
    free(temp);
}

void deleteKey() {
    int key;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Enter key:\n");
    scanf("%d", &key);
    temp = head;
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
            }
            return;
        }
        temp = temp->next;
    } while (temp != head);
    printf("Key not found\n");
}

void reverseDisplay() {
    if (head == NULL) {
        printf("Empty list\n");
        return;
    }
    temp = last;
    printf("The linked list in reverse is:\n");
    do {
        printf("%d->", temp->data);
        temp = temp->prev;
    } while (temp != last);
    printf("\n");
}


