#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* bucketArray[10];

void insertSorted(struct node** head, int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL || (*head)->data >= value) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct node* current = *head;
    while (current->next != NULL && current->next->data < value) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

void bucketSort(int arr[], int n) {
    for (int i = 0; i < 10; i++) {
        bucketArray[i] = NULL;
    }

    for (int i = 0; i < n; i++) {
        int index = arr[i] / 10;
        if (index > 9) index = 9;
        insertSorted(&bucketArray[index], arr[i]);
    }

    int k = 0;
    for (int i = 0; i < 10; i++) {
        struct node* temp = bucketArray[i];
        while (temp != NULL) {
            arr[k++] = temp->data;
            temp = temp->next;
        }
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements (0–99): ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bucketSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
