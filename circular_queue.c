#include <stdio.h>
#define size 4
int q[size];
int r=-1,f=0;
int count=0;

void enqueue(int item) {
    if(count==size) printf("Queue overflow \n");
    else {
        r=(r+1)%size;
        q[r]=item;
        count++;
    }    
}

void dequeue() {
    if(count==0) printf("underflow \n");
    else {
        printf("deleted item=%d \n", q[f]);
        f=(f+1)%size;
        count--;
    }    
}

void display() {
    if(count==0)  printf("Queue empty \n");
    else {
        for(int i=0;i<count;i++) {
            printf( "%d \t",q[(f+i)%size]);
        }
    }
}


void main() {
    int ch,item;
    for(;;) {
        printf("1: insert 2: delete  3:display 4: exit \n");
        printf("Enter ur choice \n");
        scanf("%d",&ch);
        switch(ch) {
            case 1: printf("Enter item \n");
                    scanf("%d",&item);
                    enqueue(item);
                    break;
                    
            case 2: dequeue();
                    break;
                    
            case 3: display();
                    break;
                    
            default: return;
        }
    }
    
}
