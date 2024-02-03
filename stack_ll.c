#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void push(int);
void pop();
void display();

struct Node* top = NULL;

int main () {
    int choice;
    int data;
    while(1) {
        printf("select one of the option\n");
        printf("1 for push\n");
        printf("2 for pop\n");
        printf("3 for display\n");
        printf("4 for exit\n");
        printf("give the choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: printf("give the data to push: ");
                    scanf("%d", &data);
                    push(data);
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
            default: printf("invalid choice\n");
        }
    }
}

void push(int data) {
    struct Node* temp = malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    if ( top == NULL ) {
        top = temp;
        return;
    }
    temp->next = top;
    top = temp;
}

void pop() {
    if ( top == NULL ) {
        printf("stack underflow\n");
        return;
    }
    struct Node* temp = top;
    top = top->next;
    printf("the deleted element was %d", temp->data);
    free(temp);
}

void display() {
    struct Node* cur = top;
    if( top == NULL ) {
        printf("empty stack\n");
        return;
    }
    while( cur != NULL ) {
        printf("|%d|->", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}


/*
* select one of the option
* 1 for push
* 2 for pop
* 3 for display
* 4 for exit
* give the choice: 1
* give the data to push: 10
* select one of the option
* 1 for push
* 2 for pop
* 3 for display
* 4 for exit
* give the choice: 3
* |10|->NULL
* select one of the option
* 1 for push
* 2 for pop
* 3 for display
* 4 for exit
* give the choice: 1
* give the data to push: 20
* select one of the option
* 1 for push
* 2 for pop
* 3 for display
* 4 for exit
* give the choice: 3
* |20|->|10|->NULL
* select one of the option
* 1 for push
* 2 for pop
* 3 for display
* 4 for exit
* give the choice: 2
* the deleted element was 20select one of the option
* 1 for push
* 2 for pop
* 3 for display
* 4 for exit
* give the choice: 3
* |10|->NULL
* select one of the option
* 1 for push
* 2 for pop
* 3 for display
* 4 for exit
* give the choice: 4
*/
