#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

typedef struct {
    int priority;
    int value;
} priority_queue;


void insert(int, int, priority_queue*, int*);
void delete(priority_queue*, int*);
void display(priority_queue*, int*);
void sort(priority_queue*, int*);

int main() {
    priority_queue pq[MAX_SIZE];
    int top = -1;
    printf("select one of these options\n");
    while(1){
        printf("1:insert\n2:delete\n3:display\n4:exit\n");
        int o;
        scanf("%d", &o);
        switch (o) {
            case 1: {
                        int value;
                        int priority;
                        printf("enter value and priority\n");
                        scanf("%d %d", &value, &priority);
                        insert(value, priority, pq, &top);
                        break;
                    }
            case 2: {
                        delete(pq, &top);
                        break;
                    }
            case 3: {
                        display(pq, &top);
                        break;
                    }
            case 4: exit(0);
        }
    }
}


void delete(priority_queue* pq, int* top) {
    printf("the deleted element is %d and the priority was %d\n", pq->value, pq->priority);
    for(int i = 0; i<=*top; i++) {
        pq[i] = pq[i+1];
    }
    *top = *top - 1;
}

void display(priority_queue* pq, int* top) {
    for(int i = 0; i<=*top; i++) {
        printf("the value is %d\nand the priority is %d\n", (pq+i)->value, (pq+i)->priority);
    }
}

void insert(int value, int priority, priority_queue* pq, int* top) {
    *top = *top + 1;
    (pq+*top)->value = value;
    (pq+*top)->priority = priority;
    printf("the inserted element is %d and the priority is %d\n", pq->value, pq->priority);
    sort(pq, top);
}

void sort(priority_queue* pq, int* top) {
    for(int i = 0; i<=*top; i++) {
        for(int j = i+1; j<=*top; j++) {
            if(pq[i].priority < pq[j].priority) {
                priority_queue temp = pq[i];
                pq[i] = pq[j];
                pq[j] = temp;
            }
        }
    }
}

/*
 * select one of these options
 * 1:insert
 * 2:delete
 * 3:display
 * 4:exit
 * 1
 * enter value and priority
 * 10
 * 1
 * the inserted element is 10 and the priority is 1
 * 1:insert
 * 2:delete
 * 3:display
 * 4:exit
 * 1
 * enter value and priority
 * 20
 * 2
 * the inserted element is 10 and the priority is 1
 * 1:insert
 * 2:delete
 * 3:display
 * 4:exit
 * 3
 * the value is 20
 * and the priority is 2
 * the value is 10
 * and the priority is 1
 * 1:insert
 * 2:delete
 * 3:display
 * 4:exit
 * 2
 * the deleted element is 20 and the priority was 2
 * 1:insert
 * 2:delete
 * 3:display
 * 4:exit
 * 3
 * the value is 10
 * and the priority is 1
 * 1:insert
 * 2:delete
 * 3:display
 * 4:exit
 * 4
 */
