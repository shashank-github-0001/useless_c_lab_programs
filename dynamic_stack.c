#include <stdio.h>
#include <stdlib.h>
#define init_size 1


void push(int, int*, int*);
void pop(int*);
void display(int*, int*);


int main() {
    //initial size of the stack
    int* a = (int*)malloc(init_size * sizeof(int));
    int top = -1;
    int choice;
    int data;
    while(1) {
        printf("Enter 1 to push\nEnter 2 to pop\nEnter 3 to display\nEnter 0 to exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1: scanf("%d", &data);
                    push(data, a, &top);
                    break;
            case 2: pop(&top);
                    break;
            case 3: display(a, &top);
                    break;
            case 0: exit(0);
        }
    }
    free(a);
} 



void push(int data, int* a, int* top){
    if(*top < init_size - 1) {
        *top = *top + 1;
        a[*top] = data;
    } else {
        a = realloc(a, (*top + 2) * sizeof(int)); //increasing the size 
        if ( a == NULL ) {
            printf("Memory not allocated there was an error\n");
            exit(0);
        }
        *top = *top + 1;
        a[*top] = data;
    }
}



void pop(int* top) {
    if (*top == -1) {
        printf("underflow error\n");
        exit(0);
    } else {
        *top = *top - 1;
    }
}



void display(int* a, int* top) {
    if (*top == -1) {
        printf("Stack is empty\n");
    } else {
        for (int i = *top; i >= 0; i--) {
            printf("%d\n", a[i]); 
        }
    }
}


/*
 * Enter 1 to push
 * Enter 2 to pop
 * Enter 3 to display
 * Enter 0 to exit
 * 1
 * 10
 * Enter 1 to push
 * Enter 2 to pop
 * Enter 3 to display
 * Enter 0 to exit
 * 1
 * 20
 * Enter 1 to push
 * Enter 2 to pop
 * Enter 3 to display
 * Enter 0 to exit
 * 1
 * 30
 * Enter 1 to push
 * Enter 2 to pop
 * Enter 3 to display
 * Enter 0 to exit
 * 3
 * 30
 * 20
 * 10
 * Enter 1 to push
 * Enter 2 to pop
 * Enter 3 to display
 * Enter 0 to exit
 * 0
 */
