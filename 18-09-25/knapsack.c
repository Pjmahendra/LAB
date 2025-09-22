#include<stdio.h>

void bubbleSort(int arr[], int n,int arr2[]) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                int temp2 = arr2[j];
                arr2[j] = arr2[j+1];
                arr2[j+1] = temp2;
            }
        }
    }
}
void sortByRatio(int weight[], int value[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            double r1 = (double)value[j] / weight[j];
            double r2 = (double)value[j+1] / weight[j+1];
            if (r1 < r2) { 
                int temp = weight[j];
                weight[j] = weight[j+1];
                weight[j+1] = temp;

                int temp2 = value[j];
                value[j] = value[j+1];
                value[j+1] = temp2;
            }
        }
    }
}
void method1(int arr[],int arr2[],int n,int max){                      // min weight algorithm
    int remain=max;
    double pixi=0;int totalw=0;
    double xi;
    for(int i=0;i<n;i++){
        if(totalw+arr[i] <= max){
            remain=remain-arr[i];
            totalw+=arr[i];
            pixi+= arr2[i];
        }else{
            pixi+= arr2[i]*((double)remain/arr[i]);
            totalw+=remain;
            remain=0;
            break;
        }
    }printf("Profit gained by using method1(min weight ): %.2f\n",pixi);
}
void method2(int arr[],int arr2[],int n,int max){                      // max profit algorithm
    int remain=max;
    double pixi=0;int totalw=0;
    double xi;
    for(int i=n-1;i>=0;i--){
        if(totalw+arr[i] <= max){
            remain=remain-arr[i];
            totalw+=arr[i];
            pixi+= arr2[i];
        }else{
            pixi+= arr2[i]*((double)remain/arr[i]);
            totalw+=remain;
            remain=0;
            break;
        }
    }printf("Profit gained by using method2(max profit): %.2f\n",pixi);
}
void method3(int arr[],int arr2[],int n,int max){                      // max profit/weight algorithm
    int remain=max;
    double pixi=0;int totalw=0;
    double xi;
    for(int i=0;i<n;i++){
        if(totalw+arr[i] <= max){
            remain=remain-arr[i];
            totalw+=arr[i];
            pixi+= arr2[i];
        }else{
            pixi+= arr2[i]*((double)remain/arr[i]);
            totalw+=remain;
            remain=0;
            break;
        }
    }printf("Profit gained by optimal solution: %.2f\n",pixi);
}
int main(){
    int max;int n;
    printf("Enter no.of items in the bag:");
    scanf("%d",&n);
    int arr[n];
    int arr2[n];
    printf("Enter the values of items (weight,value)");
    for(int i=0;i<n;i++){
        scanf("%d %d",&arr[i],&arr2[i]);
    }
    printf("enter the weight constraint: ");
    scanf("%d",&max);
    bubbleSort(arr,n,arr2); 
    method1(arr,arr2,n,max);
    bubbleSort(arr2,n,arr);
    method2(arr,arr2,n,max);
    sortByRatio(arr,arr2,n);
    method3(arr,arr2,n,max);
    return 0;
}
