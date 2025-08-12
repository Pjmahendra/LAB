#include <stdio.h>

int binary(int a, int arr[], int n) {
    int M = 0, N = n - 1, mid;
    while (M <= N) {
        mid = M + (N - M) / 2;
        if (arr[mid] == a) {
            return mid;
        } else if (arr[mid] < a) {
            M = mid + 1;
        } else {
            N = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n, x;
    printf("Enter number of elements in an array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements of the array in sorted order: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to be searched: ");
    scanf("%d", &x);
    int z = binary(x, arr, n);
    if (z != -1)
        printf("Element found at index: %d\n", z);
    else
        printf("Element not found\n");
    return 0;
}
