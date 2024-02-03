#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void enque(int);
void deque();
void display();

struct Node* front = NULL;
struct Node* rear = NULL;

int main() {
    int choice;
    int data;
    while(1) {
        printf("select one of the option\n");
        printf("1 for enque\n");
        printf("2 for deque\n");
        printf("3 for display\n");
        printf("4 for exit\n");
        printf("give the choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: printf("give the data to push: ");
                    scanf("%d", &data);
                    enque(data);
                    break;
            case 2: deque();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
            default: printf("invalid choice\n");
        }
    }
}


void enque(int data) {
    struct Node *temp = malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    if( front == NULL ){
        front = temp;
        rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

void deque() {
    if( front == NULL ){
        printf("queue is empty\n");
        return;
    }
    struct Node *temp = front;
    front = front->next;
    printf("deleted item = %d\n", temp->data);
    free(temp);
}

void display() {
    if( front == NULL ){
        printf("queue is empty\n");
        return;
    }
    struct Node *temp = front;
    while( temp != NULL ){
        printf("|%d|->", temp->data);
        temp = temp->next;
    }
}

/*
* select one of the option
* 1 for enque
* 2 for deque
* 3 for display
* 4 for exit
* give the choice: 1
* give the data to push: 10
* select one of the option
* 1 for enque
* 2 for deque
* 3 for display
* 4 for exit
* give the choice: 1
* give the data to push: 20
* select one of the option
* 1 for enque
* 2 for deque
* 3 for display
* 4 for exit
* give the choice: 1
* give the data to push: 30
* select one of the option
* 1 for enque
* 2 for deque
* 3 for display
* 4 for exit
* give the choice: 3
* |10|->|20|->|30|->select one of the option
* 1 for enque
* 2 for deque
* 3 for display
* 4 for exit
* give the choice: 2
* deleted item = 10
* select one of the option
* 1 for enque
* 2 for deque
* 3 for display
* 4 for exit
* give the choice: 2
* deleted item = 20
* select one of the option
* 1 for enque
* 2 for deque
* 3 for display
* 4 for exit
* give the choice: 3
* |30|->select one of the option
* 1 for enque
* 2 for deque
* 3 for display
* 4 for exit
* give the choice: 4
*/
