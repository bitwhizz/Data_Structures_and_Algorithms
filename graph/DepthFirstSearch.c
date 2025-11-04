/*
 * AdjacencyListRepresentation.c
 *
 *  Created on: 04-11-2025
 *      Author: saif
 * 
 * DFS algorithm works in a manner similar ro preorder traversal of the trees.
 * Like preorder traversal, internally this algorithm also uses stack.
 */

#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the adjacency list
struct AdjListNode {
    int dest;
    struct AdjListNode* next;
};

// Structure for the adjacency list itself
struct AdjList {
    struct AdjListNode *head;
};

// Structure for the graph
struct Graph {
    int V; // Number of vertices
    struct AdjList* array;
};

// Structure for a stack node
struct StackNode {
    int data;
    struct StackNode* next;
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
    for (int i = 0; i < V; ++i) {
        graph->array[i].head = NULL;
    }
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

// Stack operations
struct StackNode* newStackNode(int data) {
    struct StackNode* stackNode = (struct StackNode*) malloc(sizeof(struct StackNode));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

int isEmpty(struct StackNode* root) {
    return !root;
}

void push(struct StackNode** root, int data) {
    struct StackNode* stackNode = newStackNode(data);
    stackNode->next = *root;
    *root = stackNode;
}

int pop(struct StackNode** root) {
    if (isEmpty(*root)) return -1; // Or handle error appropriately
    struct StackNode* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

// Iterative DFS function
void iterativeDFS(struct Graph* graph, int startNode) {
    struct StackNode* stack = NULL;
    int* visited = (int*) calloc(graph->V, sizeof(int)); // Initialize all to 0 (not visited)

    push(&stack, startNode);

    while (!isEmpty(stack)) {
        int u = pop(&stack);

        if (!visited[u]) {
            visited[u] = 1; // Mark as visited
            printf("%d ", u);

            // Push all unvisited adjacent vertices to the stack
            struct AdjListNode* temp = graph->array[u].head;
            while (temp != NULL) {
                if (!visited[temp->dest]) {
                    push(&stack, temp->dest);
                }
                temp = temp->next;
            }
        }
    }
    free(visited);
}

int main() {
    int V = 5;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);

    printf("Iterative DFS traversal starting from vertex 0: ");
    iterativeDFS(graph, 0);
    printf("\n");

    return 0;
}
