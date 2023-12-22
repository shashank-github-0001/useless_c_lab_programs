#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10


void push(int, int*, int*);
void pop(int*, int*);
void display(int*, int*);

int main() {
    int stack[MAX_SIZE];
    int top = -1;
    while (1) {
        int option;
        printf("Enter 1 to push\nEnter 2 to pop\nEnter 3 to display\nEnter 4 to exit\n");
        scanf("%d", &option);
        switch(option) {
            case 1:
                printf("give the element that you want to push\n");
                int element;
                scanf("%d", &element);
                push(element, stack, &top);
                break;
            case 2:
                pop(stack, &top);
                break;
            case 3:
                display(stack, &top);
                break;
            case 4:
                exit(0);
        }
    }
}


void push(int element, int* stack, int* top) {
    *top = *top + 1;
    stack[*top] = element;
}

void pop(int* stack, int* top) {
    *top = *top - 1;
}

void display(int* stack, int* top) {
    for (int i = *top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}


/*
* Enter 1 to push
* Enter 2 to pop
* Enter 3 to display
* Enter 4 to exit
* 1
* give the element that you want to push
* 10
* Enter 1 to push
* Enter 2 to pop
* Enter 3 to display
* Enter 4 to exit
* 1
* give the element that you want to push
* 20
* Enter 1 to push
* Enter 2 to pop
* Enter 3 to display
* Enter 4 to exit
* 3
* 20
* 10
* Enter 1 to push
* Enter 2 to pop
* Enter 3 to display
* Enter 4 to exit
* 2
* Enter 1 to push
* Enter 2 to pop
* Enter 3 to display
* Enter 4 to exit
* 3
* 10
* Enter 1 to push
* Enter 2 to pop
* Enter 3 to display
* Enter 4 to exit
* 4
* */
