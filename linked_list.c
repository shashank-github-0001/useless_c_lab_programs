#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

void insert_front(int);
void delete_front();
void display();

struct node *HEAD = NULL;

int main() {
    int option;
    while (1) {
        printf("enter one of the below options\n");
        printf("enter 1 to insert\n");
        printf("enter 2 to delete\n");
        printf("enter 3 to display\n");
        scanf("%d", &option);
        int data;
        switch (option) {
            case 1:
                printf("enter data to insert: ");
                scanf("%d", &data);
                insert_front(data);
                break;
            case 2:
                delete_front();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
        };
    }
}

void insert_front(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("stack overflow");
        return;
    }
    new_node->data = data;
    new_node->link = HEAD;
    HEAD = new_node;
}

void display() {
    struct node *current = HEAD;
    while (current != NULL) {
        printf("|%d|->", current->data);
        current = current->link;
    }
    printf("NULL\n");
}

void delete_front() {
    if (HEAD != NULL) {
        struct node *temp = HEAD;
        HEAD = HEAD->link;
        printf("the deleted item is %d\n", temp->data);
        free(temp);
    } else {
        printf("linked list is empty\n");
    }
}
