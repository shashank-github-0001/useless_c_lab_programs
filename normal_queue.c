#include <stdio.h>
#define size 4

int q[size];
int r=-1,f=0;

void enqueue(int item) {
    if(r==size-1) printf("Queue overflow \n");
    else q[++r]=item;
}

void dequeue() {
    if(r<f) printf("underflow \n");
    else printf("deleted item=%d \n", q[f++]);
}

void display() {
    if(r<f) {
        printf("Queue empty \n");
        return;
    }

    for(int i=f;i<=r;i++) {
        printf( "%d \t",q[i]);
    }
}

int main() {
    int ch,item;
    while(1) {
        printf("1: insert\n2: delete\n3:display\n4: exit\n");
        printf("Enter ur choice\n");
        scanf("%d",&ch);
        switch(ch) {
            case 1: printf("Enter item\n");
                    scanf("%d\n",&item);
                    enqueue(item);
                    break;

            case 2: dequeue();
                    break;

            case 3: display();
                    break;

            default: return 0;
        }
    }

    return 0;
}

/*
 * 1: insert
 * 2: delete
 * 3:display
 * 4: exit
 * Enter ur choice
 * 1
 * Enter item
 * 10
 * 1
 * 1: insert
 * 2: delete
 * 3:display
 * 4: exit
 * Enter ur choice
 * Enter item
 * 20
 * 1
 * 1: insert
 * 2: delete
 * 3:display
 * 4: exit
 * Enter ur choice
 * Enter item
 * 30
 * 1
 * 1: insert
 * 2: delete
 * 3:display
 * 4: exit
 * Enter ur choice
 * Enter item
 * 40
 * 3
 * 1: insert
 * 2: delete
 * 3:display
 * 4: exit
 * Enter ur choice
 * 10 	20 	30 	40 	1: insert
 * 2: delete
 * 3:display
 * 4: exit
 * Enter ur choice
 * 4
 */
