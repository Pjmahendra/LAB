#include <stdio.h>

void findMinMax(int arr[], int low, int high, int *min, int *max) {
    int mid, min1, max1, min2, max2;

    if (low == high) {
        *min = arr[low];
        *max = arr[low];
        return;
    }

    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            *min = arr[low];
            *max = arr[high];
        } else {
            *min = arr[high];
            *max = arr[low];
        }
        return;
    }

    mid = (low + high) / 2;

    findMinMax(arr, low, mid, &min1, &max1);
    findMinMax(arr, mid + 1, high, &min2, &max2);

    *min = (min1 < min2) ? min1 : min2;
    *max = (max1 > max2) ? max1 : max2;
}

int main() {
    int arr[] = {100, 11, 445, 1, 330, 3000};
    int n = sizeof(arr) / sizeof(arr[0]);
    int min, max;

    findMinMax(arr, 0, n - 1, &min, &max);

    printf("Minimum: %d\n", min);
    printf("Maximum: %d\n", max);

    return 0;
}
