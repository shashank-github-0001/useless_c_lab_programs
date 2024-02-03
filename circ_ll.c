#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void insert_front(int);
void display();
void delete_front();
void insert_rear(int);
void delete_rear();

struct Node *last = NULL;

int main() {
    while (1) {
        printf("choose any one of the option\n");
        printf("1 for insert front\n");
        printf("2 for delete front\n");
        printf("3 for insert rear\n");
        printf("4 for delete rear\n");
        printf("5 for display\n");
        int choice;
        int data;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("give the data to insert front: ");
                scanf("%d", &data);
                insert_front(data);
                break;
            case 2:
                delete_front();
                break;
            case 3:
                printf("give the data to insert rear :");
                scanf("%d", &data);
                insert_rear(data);
                break;
            case 4:
                delete_rear();
                break;
            case 5:
                display();
                break;
        }
    }
}

void insert_front(int data) {
    struct Node *temp = malloc(sizeof(struct Node));
    temp->next = NULL;
    temp->data = data;
    if (last == NULL) {
        last = temp;
        temp->next = last;
        return;
    }
    temp->next = last->next;
    last->next = temp;
}

void display() {
    struct Node *cur = NULL;
    if (last == NULL) {
        printf("NULL\n");
        return;
    }
    cur = last->next;
    do {
        printf("%d->", cur->data);
        cur = cur->next;
    } while (cur != last->next);
}

void delete_front() {
    struct Node *temp;
    if (last == NULL) {
        printf("can't delete from an empty list\n");
        return;
    }
    if (last == last->next) {
        free(last);
        return;
    }
    temp = last->next;
    last->next = last->next->next;
    free(temp);
    temp = NULL;
}

void insert_rear(int data) {
    struct Node *temp = malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    if (last == NULL) {
        last = temp;
        temp->next = last;
        return;
    }
    temp->next = last->next;
    last->next = temp;
    last = temp;
}

void delete_rear() {
    struct Node *temp = NULL;
    if (last == NULL) {
        printf("can't delete from an empty list\n");
        return;
    }
    if (last == last->next) {
        free(last);
        return;
    }
    temp = last;
    while (last->next != temp) {
        last = last->next;
    }
    last->next = temp->next;
    free(temp);
    temp = NULL;
}


/*
* choose any one of the option
* 1 for insert front
* 2 for delete front
* 3 for insert rear
* 4 for delete rear
* 5 for display
* 1
* give the data to insert front: 10
* choose any one of the option
* 1 for insert front
* 2 for delete front
* 3 for insert rear
* 4 for delete rear
* 5 for display
* 5
* 10->choose any one of the option
* 1 for insert front
* 2 for delete front
* 3 for insert rear
* 4 for delete rear
* 5 for display
* 1
* give the data to insert front: 20
* choose any one of the option
* 1 for insert front
* 2 for delete front
* 3 for insert rear
* 4 for delete rear
* 5 for display
* 5
* 20->10->choose any one of the option
* 1 for insert front
* 2 for delete front
* 3 for insert rear
* 4 for delete rear
* 5 for display
* 3
* give the data to insert rear :30
* choose any one of the option
* 1 for insert front
* 2 for delete front
* 3 for insert rear
* 4 for delete rear
* 5 for display
* 5
* 20->10->30->choose any one of the option
* 1 for insert front
* 2 for delete front
* 3 for insert rear
* 4 for delete rear
* 5 for display
* 4
* choose any one of the option
* 1 for insert front
* 2 for delete front
* 3 for insert rear
* 4 for delete rear
* 5 for display
* 5
* 20->10->choose any one of the option
* 1 for insert front
* 2 for delete front
* 3 for insert rear
* 4 for delete rear
* 5 for display
* 2
* choose any one of the option
* 1 for insert front
* 2 for delete front
* 3 for insert rear
* 4 for delete rear
* 5 for display
* 5
* 10->choose any one of the option
* 1 for insert front
* 2 for delete front
* 3 for insert rear
* 4 for delete rear
* 5 for display
*/
