#include <stdio.h>
#include <stdlib.h>


int main() {
    printf("Enter the size of the array\n");
    //takes the size
    int n;
    scanf("%d", &n);
    int* a = (int*)malloc(n * sizeof(int));
    //checks if its refrencing to null or not
    if ( a == NULL) {
        printf("insufficient memory");
        exit(0);
    }
    //takes the input from the array
    printf("Enter the %d elements of the array\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    //prints it in the normal format
    printf("display the array normally\n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", a[i]);
    }
    //prints it with the help of pointer method 
    printf("display the array pointer\n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", *(a+i));
    }
}
