/*
 * AdjacencyListRepresentation.c
 *
 *  Created on: 04-11-2025
 *      Author: saif
 * 
 * THe BFS algorithm works similar to level - order traversal of the trees.
 * Like level-order traversal , BFS also uses queues. 
 * in fact , level ordere traversal got inspired from BFS.
 * BFS works level by level. Initially , BFS starts at a given vertex ,
 * which is at level 0;
 * 
 * In first stage it visits all the vertices at level 1.
 * In the second stage it visits all the vertices at second level.
 * These ne vertices are the once ehich are adjecent to level 1 vertices.
 * BFS continues this process untill all the levels of the graph are completed.
 * Generally queue data structure is used for sorting the verticies of a level.
 * 
 * As similar to DFS , assume that initailly all vertices are marked unvisited (false).
 * vertices that have been processed and removed from the queue are marked visited (true).
 * 
 * we use a queue to represent the visisted set as it will keep the 
 * vertices in order of when they were first visisted.
 * 
 */

#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the adjacency list
struct AdjListNode {
    int dest;
    struct AdjListNode* next;
};

// Structure for an adjacency list
struct AdjList {
    struct AdjListNode *head;
};

// Structure for the graph
struct Graph {
    int V; // Number of vertices
    struct AdjList* array;
};

// Structure for a queue node
struct QNode {
    int data;
    struct QNode* next;
};

// Structure for a queue
struct Queue {
    struct QNode *front, *rear;
};

// Function to create a new adjacency list node
struct AdjListNode* newAdjListNode(int dest) {
    struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));
    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;
    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add edge from src to dest
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Add edge from dest to src (for undirected graph)
    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Function to create a new queue node
struct QNode* newQNode(int data) {
    struct QNode* temp = (struct QNode*) malloc(sizeof(struct QNode));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*) malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to add an item to the queue
void enqueue(struct Queue* q, int data) {
    struct QNode* temp = newQNode(data);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

// Function to remove an item from the queue
int dequeue(struct Queue* q) {
    if (q->front == NULL)
        return -1; // Queue is empty

    struct QNode* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return data;
}

// Function to check if queue is empty
int isEmpty(struct Queue* q) {
    return (q->front == NULL);
}

// BFS traversal function
void BFS(struct Graph* graph, int startVertex) {
    int* visited = (int*) malloc(graph->V * sizeof(int));
    for (int i = 0; i < graph->V; i++)
        visited[i] = 0; // Initialize all vertices as not visited

    struct Queue* q = createQueue();

    visited[startVertex] = 1;
    enqueue(q, startVertex);

    while (!isEmpty(q)) {
        int currentVertex = dequeue(q);
        printf("%d ", currentVertex);

        struct AdjListNode* temp = graph->array[currentVertex].head;
        while (temp) {
            int adjVertex = temp->dest;
            if (visited[adjVertex] == 0) {
                visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
    free(visited);
    free(q); // Free the queue structure itself
}

int main() {
    int V = 5; // Number of vertices
    struct Graph* graph = createGraph(V);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);

    printf("BFS traversal starting from vertex 0: \n");
    BFS(graph, 0);
    printf("\n");

    return 0;
}