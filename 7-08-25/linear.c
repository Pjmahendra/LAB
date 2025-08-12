#include<stdio.h>

int linear( int arr[],int a, int n){
    for(int i = 0; i < n; i++){
        if(arr[i] == a){
            return i; 
        }
    }
    return -1; 
}
int main(){
    int n;
    printf("enter number of elements of an arraay: ");
    scanf("%d", &n);
    int arr[n];
    printf("enter elements of array: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);   
    }
    printf("eneter the element to be searched: ");
    int a;
    scanf("%d", &a);
    int z=linear(arr, a, n);
    if(z != -1) {
        return printf("element found at index: %d\n", z);
    } else {
        return printf("element not found\n");
    }
}
