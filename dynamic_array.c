#include <stdio.h>
#include <stdlib.h>


int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int* a = malloc(n * sizeof(int));
    if (a == NULL) {
        printf("insufficient memory");
        exit(0);
    }
    printf("Enter %d elements for the array: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("display the array normally");
    for (int i = 0; i < n; i++) {
        printf("%d\n", a[i]);
    }
    printf("display the array pointer\n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", *(a+i));
    }
    free(a);
}


/*
 * Enter the size of the array
 * 2
 * Enter the 2 elements of the array
 * 1
 * 2
 * display the array normally
 * 1
 * 2
 * display the array pointer
 * 1
 * 2
 */
