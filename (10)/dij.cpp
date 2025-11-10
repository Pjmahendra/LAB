#include <iostream>
#include <climits>
using namespace std;

#define MAX 100

struct MinHeap {
    int size;             
    int pos[MAX];       
    int heap[MAX];       
    int dist[MAX];      
};

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void heapify_down(MinHeap &mh, int idx) {
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    int s = idx;

    if (left < mh.size && mh.dist[mh.heap[left]] < mh.dist[mh.heap[s]])
        s = left;

    if (right < mh.size && mh.dist[mh.heap[right]] < mh.dist[mh.heap[s]])
        s = right;

    if (s != idx) {
        mh.pos[mh.heap[s]] = idx;
        mh.pos[mh.heap[idx]] = s;

        swap(mh.heap[s], mh.heap[idx]);

        heapify_down(mh, s);
    }
}

void heapify_up(MinHeap &minh, int idx) {
    int parent = (idx - 1) / 2;

    while (idx > 0 && minh.dist[minh.heap[idx]] < minh.dist[minh.heap[parent]]) {
        minh.pos[minh.heap[idx]] = parent;
        minh.pos[minh.heap[parent]] = idx;

        swap(minh.heap[idx], minh.heap[parent]);

        idx = parent;
        parent = (idx - 1) / 2;
    }
}

void build_heap(MinHeap &minh, int V) {
    for (int i = (minh.size - 1) / 2; i >= 0; i--)
        heapify_down(minh, i);
}

int extract_min(MinHeap &minh) {
    if (minh.size == 0)
        return -1;

    int root = minh.heap[0];

    minh.heap[0] = minh.heap[minh.size - 1];
    minh.pos[minh.heap[0]] = 0;

    minh.size--;
    heapify_down(minh, 0);

    return root;
}

void decrease_key(MinHeap &mh, int vertex, int newDist) {
    mh.dist[vertex] = newDist;

    int idx = mh.pos[vertex];
    heapify_up(mh, idx);
}


void dijkstra(int graph[MAX][MAX], int V, int src) {
    MinHeap minh;
    minh.size = V;

    for (int v = 0; v < V; v++) {
        minh.heap[v] = v;
        minh.pos[v] = v;
        minh.dist[v] = (v == src) ? 0 : INT_MAX;
    }

    build_heap(minh, V);

    int visited[MAX] = {0};

    while (minh.size > 0) {
        int u = extract_min(minh);
        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] > 0 && !visited[v]) {
                if (minh.dist[u] != INT_MAX &&
                    minh.dist[v] > minh.dist[u] + graph[u][v]) {

                    decrease_key(minh, v, minh.dist[u] + graph[u][v]);
                }
            }
        }
    }

    cout << "\nShortest Distances from Source " << src << ":\n";
    for (int i = 0; i < V; i++)
        cout << "Vertex " << i << " → Distance = " << minh.dist[i] << endl;
}

int main() {
    int V;

    cout << "Enter number of vertices: ";
    cin >> V;

    int graph[MAX][MAX];

    cout << "\nEnter Weight Matrix :\n";
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cin >> graph[i][j];

    int src;
    cout << "\nEnter Source Vertex: ";
    cin >> src;

    dijkstra(graph, V, src);

    return 0;
}
