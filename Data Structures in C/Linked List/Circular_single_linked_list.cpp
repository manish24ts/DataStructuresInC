//Circular Single or Singly linked list
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
} *head = NULL, *last, *n, *temp, *p;

void create();
void display();
void insertBegin();
void insertEnd();
void insertAfterKey();
void insertBeforeKey();
void deleteBegin();
void deleteEnd();
void deleteKey();

int main() {
    int ch;
    printf("1.Create\n2.Display\n3.Insert start\n4.Insert end\n5.Insert After key\n6.Insert Before key\n7.Delete start\n8.Delete end\n9.Delete key\n10.Exit\n");
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
            case 10: printf("Exiting the process\n"); exit(0);
            default: printf("Wrong option\n");
        }
    } while (ch <= 10);
}

void create() {
    n = (struct node *)malloc(sizeof(struct node));
    printf("Enter data value:\n");
    scanf("%d", &n->data);
    if (head == NULL) {
        head = n;
        last = n;
        n->next = head;
    } else {
        last->next = n;
        last = n;
        last->next = head;
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
    if (head == NULL) {
        head = n;
        last = n;
        n->next = head;
    } else {
        n->next = head;
        head = n;
        last->next = head;
    }
}

void insertEnd() {
    n = (struct node *)malloc(sizeof(struct node));
    printf("Enter data value:\n");
    scanf("%d", &n->data);
    if (head == NULL) {
        head = n;
        last = n;
        n->next = head;
    } else {
        last->next = n;
        last = n;
        last->next = head;
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
            n->next = temp->next;
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
    if (head->data == key) {
        insertBegin();
        return;
    }
    do {
        p = temp;
        temp = temp->next;
        if (temp->data == key) {
            n = (struct node *)malloc(sizeof(struct node));
            printf("Enter data value:\n");
            scanf("%d", &n->data);
            p->next = n;
            n->next = temp;
            return;
        }
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
        head = NULL;
        last = NULL;
    } else {
        head = head->next;
        last->next = head;
    }
    free(temp);
}

void deleteEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (head == last) {
        free(head);
        head = NULL;
        last = NULL;
        return;
    }
    temp = head;
    while (temp->next != last) {
        temp = temp->next;
    }
    free(last);
    last = temp;
    last->next = head;
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
    if (head->data == key) {
        deleteBegin();
        return;
    }
    do {
        p = temp;
        temp = temp->next;
        if (temp->data == key) {
            p->next = temp->next;
            if (temp == last) {
                last = p;
            }
            free(temp);
            return;
        }
    } while (temp != head);
    printf("Key not found\n");
}
