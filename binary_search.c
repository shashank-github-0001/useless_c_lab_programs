#include <stdio.h>

int binary_search(int*, int, int, int);

int main() {
    int n;
    printf("give the size of array\n");
    scanf("%d", &n);
    int arr[n];
    printf("give the array\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int key;
    printf("give the key variable: ");
    scanf("%d", &key);
    int a = sizeof(arr)/sizeof(int)-1;
    int ans = binary_search(arr, key, 0, a);
    if ( ans == -1) {
        printf("key not found");
        return 0;
    }
    printf("key found at:  %d", ans); 
}

int binary_search(int* arr, int key, int start, int end) {
    int mid = (start+end)/2;
    if ( arr[mid] == key) {
        return mid;
    }
    else if ( arr[mid] > key) return binary_search(arr, key, start, mid-1);
    else return binary_search(arr, key, mid+1, end);
}

