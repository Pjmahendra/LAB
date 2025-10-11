#include <stdio.h>
#include <limits.h>
 
#define MAX 20
#define INF 9999
 
int main() {
   int n;
   int cost[MAX][MAX];
   int visited[MAX] = {0};
   int edges = 0, minCost = 0;
 
   printf("Enter number of vertices: ");
   scanf("%d", &n);
 
   printf("Enter adjacency matrix (use 9999 for no edge):\n");
   for (int i = 0; i < n; i++) {
       for (int j = 0; j < n; j++) {
           scanf("%d", &cost[i][j]);
       }
   }
 
   visited[0] = 1; // Start from vertex 0
 
   printf("\nEdges in MST (Prim’s):\n");
   while (edges < n - 1) {
       int min = INF, u = -1, v = -1;
       for (int i = 0; i < n; i++) {
           if (visited[i]) {
               for (int j = 0; j < n; j++) {
                   if (!visited[j] && cost[i][j] < min) {
                       min = cost[i][j];
                       u = i;
                       v = j;
                   }
               }
           }
       }
 
       if (u != -1 && v != -1) {
           printf("%d - %d : %d\n", u, v, min);
           visited[v] = 1;
           minCost += min;
           edges++;
       }
   }
 
   printf("Total cost of MST = %d\n", minCost);
   return 0;
}