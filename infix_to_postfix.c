#include <ctype.h>
#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
    char infix[20];
    char postfix[20];
} store_shit;

void infix_to_postfix(char*, char*);
int sprecedence(char);
int iprecedence(char);

int main() {
    store_shit store;
    printf("please enter a valid infix expression\n");
    scanf("%s", store.infix);
    infix_to_postfix(store.infix, store.postfix);
    printf("postfix expression is %s\n", store.postfix);
}


void infix_to_postfix(char* infix, char* postfix) {
    char stack[20];
    int top = -1;
    int j = 0;
    for (int i = 0; *(infix+i) != '\0'; i++) {
        if (isalnum(*(infix+i))) {
            postfix[j++] = *(infix+i);
        }
        else if (*(infix+i) == '(') {
            stack[++top] = *(infix+i);
        }
        else if (*(infix+i) == ')') {
            while (stack[top] != -1 && stack[top] != '(') {
                postfix[j++] = stack[top--];
            }
            top--;
        }
        else {
            while (stack[top] != -1 && iprecedence(*(infix+i)) <= sprecedence(stack[top])) {
                postfix[j++] = stack[top--];
            }
            stack[++top] = *(infix+i);
        }
    }
    while ( stack[top] != -1 ) {
        postfix[j++] =  stack[top--];
    }
    postfix[j++] = '\0';
}


int sprecedence( char a ) {
    switch ( a ) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default : return -1;
    }
}


int iprecedence( char a ) {
    switch ( a ) {
        case '^': return 4;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default : return -1;
    }
}

/*
 * output
 * please enter a valid infix expression
 * (a*b+c^d)
 * postfix expression is ab*cd^+
 */
