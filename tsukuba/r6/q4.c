#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100
// キューを管理する変数
int q[MAX_QUEUE_SIZE];
int tail = 0;
int head = 0;

// キューが空かどうか判定する関数
int isEmpty() {
    if (head == tail) return 1;
    else return 0;
}

// キューが満杯かどうか判定する関数
int isFull() {
    if (head == (tail+1) % MAX_QUEUE_SIZE) return 1;
    else return 0;
}

// キューに要素を追加する関数
void enqueue(int value) {
    if (isFull()) printf("Error: Queue is full\n");
    else {
        q[tail] = value;
        tail++;
        if (tail == MAX_QUEUE_SIZE) tail = 0;
    }
}

// キューから要素を取り出す関数
int dequeue() {
    int item;
    if (isEmpty()) {
        printf("Error: Queue is empty\n");
        return -1;
    } else {
        item = q[head];
        head++;
        if (head == MAX_QUEUE_SIZE) head = 0;
    }
    return item;
}

// グラフの隣接リストを表す構造体
typedef struct Element {
    int vertex;
    struct Element* nextElement;
} Element;

// グラフに辺を追加する関数
void addEdge(Element* g[], int u, int v) {
    Element* newElement = (Element*)malloc(sizeof(Element));
    newElement->vertex = v; //（ア）
    newElement->nextElement = g[u]; //（イ）
    g[u] = newElement; //（ウ）

    newElement = (Element*)malloc(sizeof(Element));
    newElement ->vertex = u; //（エ）
    newElement->nextElement = g[v]; //（オ）
    g[v] = newElement; //（カ）
}

// グラフ探索を行う関数
void graphSearch(Element* g[], int startVertex, int numVertices) {
    int visited[numVertices];
    int dist[numVertices];

    for (int i = 0; i < numVertices; i++) {
        visited[i] = 0;
        dist[i] = -1;
    }

    visited[startVertex] = 1;
    enqueue(startVertex);
    dist[startVertex] = 0;

    while (!isEmpty()) {
        int currentVertex = dequeue(); //（キ）
        printf("%d %d\n", currentVertex, dist[currentVertex]);
        Element* tempElement = g[currentVertex];
        while (tempElement != NULL) {
            int adjVertex = tempElement->vertex;
            if (visited[adjVertex] == 0) {
                visited[adjVertex] = 1;
                dist[adjVertex] = dist[currentVertex]+1; //（ク）
                enqueue(adjVertex); //（ケ）
            }
            tempElement = tempElement->nextElement;
        }
    }
}

int main() {
    int numVertices = 8;
    Element* g[numVertices];
    for (int i = 0; i < numVertices; i++) {
        g[i] = NULL;
    }

    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 0, 4);
    addEdge(g, 1, 3);
    addEdge(g, 1, 6);
    addEdge(g, 2, 5);
    addEdge(g, 3, 7);
    addEdge(g, 4, 6);
    addEdge(g, 5, 6);
    addEdge(g, 5, 7);

    int startVertex = 0;
    graphSearch(g, startVertex, numVertices);
    return 0;
}
