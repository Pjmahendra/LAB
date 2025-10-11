#include <stdio.h>
#include <stdlib.h>
 
#define MAX 30
 
typedef struct {
   int u, v, w;
} Edge;
 
int parent[MAX];
int find(int i) {
   while (parent[i] != i)
       i = parent[i];
   return i;
}
void unionSet(int i, int j) {
   int a = find(i);
   int b = find(j);
   parent[a] = b;
}
 
int main() {
   int n, e;
   Edge edges[MAX];
 
   printf("Enter number of vertices: ");
   scanf("%d", &n);
   printf("Enter number of edges: ");
   scanf("%d", &e);
 
   printf("Enter edges (u v w):\n");
   for (int i = 0; i < e; i++) {
       scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].w);
   }
   for (int i = 0; i < n; i++)
       parent[i] = i;
   for (int i = 0; i < e - 1; i++) {
       for (int j = 0; j < e - i - 1; j++) {
           if (edges[j].w > edges[j + 1].w) {
               Edge temp = edges[j];
               edges[j] = edges[j + 1];
               edges[j + 1] = temp;
           }
       }
   }
 
   int count = 0, minCost = 0;
   printf("\nEdges in MST (Kruskal’s):\n");
   for (int i = 0; i < e; i++) {
       int u = edges[i].u;
       int v = edges[i].v;
       int w = edges[i].w;
 
       if (find(u) != find(v)) {
           unionSet(u, v);
           printf("%d - %d : %d\n", u, v, w);
           minCost += w;
           count++;
       }
       if (count == n - 1)
           break;
   }
 
   printf("Total cost of MST = %d\n", minCost);
   return 0;
}
