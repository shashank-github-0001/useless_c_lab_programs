#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

void insert_front(int);
void delete_front();
void display();
void insert_rear(int);
void delete_rear();
void delete_by_data(int);

struct node *HEAD = NULL;

int main() {
    int option;
    while (1) {
        printf("enter one of the below options\n");
        printf("enter 1 to insert_front\n");
        printf("enter 2 to delete_front\n");
        printf("enter 3 to display\n");
        printf("enter 4 to insert_rear\n");
        printf("enter 5 to delete_rear\n");
        printf("enter 6 to delete_by_data\n");
        printf("enter 7 to exit\n");
        scanf("%d", &option);
        int data;
        switch (option) {
            case 1:
                printf("enter data to insert_front: ");
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
                printf("give data to insert_rear: ");
                scanf("%d", &data);
                insert_rear(data);
                break;
            case 5:
                delete_rear();
                break;
            case 6:
                printf("give data to delete_from_data: ");
                scanf("%d", &data);
                delete_by_data(data);
                break;
            case 7:
                exit(0);
        };
    }
}

void insert_front(int data) {
    struct node *temp = malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("stack overflow");
        return;
    }
    temp->data = data;
    temp->link = HEAD;
    HEAD = temp;
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
    if (HEAD == NULL) {
        printf("linked list is empty\n");
        return;
    }
    struct node *temp = HEAD;
    HEAD = HEAD->link;
    printf("the deleted item is %d\n", temp->data);
    free(temp);
}

void delete_rear() {
    struct node *cur;
    if (HEAD == NULL) {
        printf("linked list is empty\n");
        return;
    }
    if (HEAD->link == NULL) {
        free(HEAD);
        HEAD = NULL;
        return;
    }
    cur = HEAD;
    while (cur->link->link != NULL) {
        cur = cur->link;
    }
    printf("the deleted item is %d\n", cur->link->data);
    free(cur->link);
    cur->link = NULL;
}

void insert_rear(int data) {
    struct node *cur;
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    if (HEAD == NULL) {
        HEAD = temp;
        return;
    }
    cur = HEAD;
    while (cur->link != NULL) {
        cur = cur->link;
    }
    cur->link = temp;
}

void delete_by_data(int data) {
    struct node* cur = HEAD;
    struct node* temp;
    while( cur->link!= NULL ) {
        if ( cur->link->data == data ) {
            temp = cur->link;
            cur->link = cur->link->link;
            free(temp);
            continue; 
        }
        cur = cur->link;
    }
    if ( HEAD == NULL ) {
        printf("empty list\n");
        return;
    }
    if ( HEAD->data == data ) {
        temp = HEAD;
        HEAD = HEAD->link;
        free(temp);
        return;
    }
}


/*
* enter one of the below options
* enter 1 to insert_front
* enter 2 to delete_front
* enter 3 to display
* enter 4 to insert_rear
* enter 5 to delete_rear
* enter 6 to delete_by_data
* enter 7 to exit
* 1
* enter data to insert_front: 10
* enter one of the below options
* enter 1 to insert_front
* enter 2 to delete_front
* enter 3 to display
* enter 4 to insert_rear
* enter 5 to delete_rear
* enter 6 to delete_by_data
* enter 7 to exit
* 1
* enter data to insert_front: 20
* enter one of the below options
* enter 1 to insert_front
* enter 2 to delete_front
* enter 3 to display
* enter 4 to insert_rear
* enter 5 to delete_rear
* enter 6 to delete_by_data
* enter 7 to exit
* 4
* give data to insert_rear: 30
* enter one of the below options
* enter 1 to insert_front
* enter 2 to delete_front
* enter 3 to display
* enter 4 to insert_rear
* enter 5 to delete_rear
* enter 6 to delete_by_data
* enter 7 to exit
* 3
* |20|->|10|->|30|->NULL
* enter one of the below options
* enter 1 to insert_front
* enter 2 to delete_front
* enter 3 to display
* enter 4 to insert_rear
* enter 5 to delete_rear
* enter 6 to delete_by_data
* enter 7 to exit
* 5
* the deleted item is 30
* enter one of the below options
* enter 1 to insert_front
* enter 2 to delete_front
* enter 3 to display
* enter 4 to insert_rear
* enter 5 to delete_rear
* enter 6 to delete_by_data
* enter 7 to exit
* 3
* |20|->|10|->NULL
* enter one of the below options
* enter 1 to insert_front
* enter 2 to delete_front
* enter 3 to display
* enter 4 to insert_rear
* enter 5 to delete_rear
* enter 6 to delete_by_data
* enter 7 to exit
* 2
* the deleted item is 20
* enter one of the below options
* enter 1 to insert_front
* enter 2 to delete_front
* enter 3 to display
* enter 4 to insert_rear
* enter 5 to delete_rear
* enter 6 to delete_by_data
* enter 7 to exit
* 3
* |10|->NULL
* enter one of the below options
* enter 1 to insert_front
* enter 2 to delete_front
* enter 3 to display
* enter 4 to insert_rear
* enter 5 to delete_rear
* enter 6 to delete_by_data
* enter 7 to exit
* 6
* give data to delete_from_data: 10
* enter one of the below options
* enter 1 to insert_front
* enter 2 to delete_front
* enter 3 to display
* enter 4 to insert_rear
* enter 5 to delete_rear
* enter 6 to delete_by_data
* enter 7 to exit
* 3
* NULL
* enter one of the below options
* enter 1 to insert_front
* enter 2 to delete_front
* enter 3 to display
* enter 4 to insert_rear
* enter 5 to delete_rear
* enter 6 to delete_by_data
* enter 7 to exit
* 7
*/
