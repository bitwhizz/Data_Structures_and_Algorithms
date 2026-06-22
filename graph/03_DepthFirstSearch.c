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

// Structure for an adjacency list node
struct AdjListNode {
    int vertex;
    struct AdjListNode* next;
};

// Structure for a graph
struct Graph {
    int num_vertex; // Number of vertices
    struct AdjListNode** adjlist;
};

// Structure for a stack node
struct StackNode {
    int data;
    struct StackNode* next;
};


// Function to create a new adjacency list node
struct AdjListNode* newAdjListNode(int vertex) {
    struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph of V vertices
struct Graph* createGraph(int num_vertex) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->num_vertex = num_vertex;

    // Create an array of adjacency lists. Size num_vertex for num_vertex vertices
    graph->adjlist = malloc(num_vertex * sizeof(struct AdjListNode*));

    // Initialize each adjacency list as empty by making head as NULL
    for (int i = 0; i < num_vertex; ++i) {
        graph->adjlist[i] = NULL;
    }
    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->adjlist[src];
    graph->adjlist[src] = newNode;

    // Since the graph is undirected, add an edge from dest to src also
    newNode = newAdjListNode(src);
    newNode->next = graph->adjlist[dest];
    graph->adjlist[dest] = newNode;
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
    int* visited = (int*) calloc(graph->num_vertex, sizeof(int)); // Initialize all to 0 (not visited)

    push(&stack, startNode);

    while (!isEmpty(stack)) {
        int u = pop(&stack);

        if (!visited[u]) {
            visited[u] = 1; // Mark as visited
            printf("%d ", u);

            // Push all unvisited adjacent vertices to the stack
            struct AdjListNode* temp = graph->adjlist[u];
            while (temp != NULL) {
                if (!visited[temp->vertex]) {
                    push(&stack, temp->vertex);
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


/*
Iterative DFS traversal starting from vertex 0: 0 1 3 4 2 
*/