#include <math.h>
#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
    char postfix[20];
    int result;
} store_shit;

void result_from_postfix(char*, int*);
int sprecedence(char);
int iprecedence(char);

int main() {
    store_shit store;
    printf("please enter a valid postfix expression\n");
    scanf("%s", store.postfix);
    result_from_postfix(store.postfix, &store.result);
    printf("the value of the give infix expression is %d\n", store.result);
}


void result_from_postfix(char* postfix, int* result) {
    double operator1, operator2;
    double stack[20];
    double temp_result;
    int top = -1;
    for ( int i = 0; *(postfix+i) != '\0'; i++) { 
        switch ( *(postfix+i) ) {
            case '+': 
                operator2 = stack[top--];
                operator1 = stack[top--];
                temp_result = operator1 + operator2;
                stack[++top] = temp_result;
                break;
            case '-': 
                operator2 = stack[top--];
                operator1 = stack[top--];
                temp_result = operator1 - operator2;
                stack[++top] = temp_result;
                break;
            case '*': 
                operator2 = stack[top--];
                operator1 = stack[top--];
                temp_result = operator1 * operator2;
                stack[++top] = temp_result;
                break;
            case '/': 
                operator2 = stack[top--];
                operator1 = stack[top--];
                temp_result = operator1 / operator2;
                stack[++top] = temp_result;
                break;
            case '^': 
                operator2 = stack[top--];
                operator1 = stack[top--];
                temp_result = pow(operator1, operator2);
                stack[++top] = temp_result;
                break;
            default: 
                stack[++top] = *(postfix+i) - '0';
        }
    }
    *(result) = stack[top];
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

