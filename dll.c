#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};


void insert_front(int);
void delete_front();
void display();
void insert_rear(int);
void delete_rear();

struct Node *head = NULL;

int main() {
    while(1){
        printf("choose any one of the option\n");
        printf("1 for insert front\n");
        printf("2 for delete front\n");
        printf("3 for insert rear\n");
        printf("4 for delete rear\n");
        printf("5 for display\n");
        int choice;
        int data;
        scanf("%d", &choice);
        switch(choice){
            case 1: printf("give the data to insert front: ");
                    scanf("%d", &data);
                    insert_front(data);
                    break;
            case 2: delete_front();
                    break;
            case 3: printf("give the data to insert rear: ");
                    scanf("%d", &data);
                    insert_rear(data);
                    break;
            case 4: delete_rear();
                    break;
            case 5: display();
                    break;
        }
    }
}

void insert_front(int data){
    struct Node *temp = malloc(sizeof(struct Node));
    temp->next = NULL;
    temp->prev = NULL;
    temp->data = data;
    if ( head == NULL ) {
        head = temp;
        return;
    }
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void delete_front(){
    if (head == NULL) {
        printf("can't delete from an empty list\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    head = head->next;
    free(head->prev);
    head->prev = NULL;
}

void insert_rear(int data){
    struct Node* temp = malloc(sizeof(struct Node));
    temp->next = NULL;
    temp->prev = NULL;
    temp->data = data;
    if (head == NULL){
        head = temp;
    }
    struct Node* cur;
    cur = head;
    while( cur->next != NULL ){
        cur = cur->next;
    }
    cur->next = temp;
    temp->prev = cur;
}

void delete_rear(){
    struct Node* cur = head;
    if ( head == NULL ) printf("can't delete from an empty list\n");
    while( cur->next->next != NULL ){
        cur = cur->next;
    }
    free(cur->next);
    cur->next = NULL;
}

void display(){
    struct Node* cur;
    if( head == NULL){
        printf("the list is empty\n");
        return;
    }
    cur = head;
    while( cur != NULL ){
        printf("%d<->", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}


/*
* choose any one of the option
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
* 1
* give the data to insert front: 10
* choose any one of the option
* 1 for insert front
* 2 for delete front
* 3 for insert rear
* 4 for delete rear
* 5 for display
* 1
* give the data to insert front: 30
* choose any one of the option
* 1 for insert front
* 2 for delete front
* 3 for insert rear
* 4 for delete rear
* 5 for display
* 5
* 30<->10<->20<->NULL
* choose any one of the option
* 1 for insert front
* 2 for delete front
* 3 for insert rear
* 4 for delete rear
* 5 for display
* 3
* give the data to insert rear: 40
* choose any one of the option
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
* 10<->20<->40<->NULL
* choose any one of the option
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
* 10<->20<->NULL
* choose any one of the option
* 1 for insert front
* 2 for delete front
* 3 for insert rear
* 4 for delete rear
* 5 for display
*/
