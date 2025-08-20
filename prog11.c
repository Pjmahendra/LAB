#include<stdio.h>
#include<math.h>
//Programs for summation of series 1+X+X^2+X^3+…with different time complexities.
int summation(int a,int r,int n){
    int i=1;
    long long sum=0;
    while(i<=n){
        sum += a;
         a=a*r;
        i++;   
    }
    return printf("sum: %lld ",sum);
}
int sum(int a,int r,int n){
    long long sum=0;
    if (r == 1) {
        sum = a * n;
    } else {
        sum = (a * ((int)pow(r, n) - 1)) / (r - 1);
    }
    printf("%lld\n ", sum);
    return 0;
}
int main(){
    int n;int a=1;int r;
    printf("Enter the value of r and n: ");
    scanf("%d",&r);
    scanf("%d",&n);
    summation(a,r,n);
    sum(a,r,n);
    return 0;
}