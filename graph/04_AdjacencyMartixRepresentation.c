/*
 * AdjacencyMartixRepresentation.c
 *
 *  Created on: 03-11-2025
 *      Author: saif

To represent graphs we need number of Vertices , the number of edges 
and also there Interconnections.

In the method , we use a matrix with size V x V .

The values of the matrix is boolean.Letus assume that matrix is Adj. The value of
Adj[u,v] is set to 1 if there is an edge from vertex u to vertex v and 0 otherwise.


The code below is undirected graph.
*/


#include <stdio.h>
#include <stdlib.h>

// Structure to represent a graph
typedef struct {
    int vertices;
    int** adjMatrix;
} Graph;

// Function to create a graph with a given number of vertices
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    if (graph == NULL) {
        perror("Failed to allocate memory for graph");
        exit(EXIT_FAILURE);
    }
    graph->vertices = vertices;

    // Allocate memory for the adjacency matrix (2D array)
    graph->adjMatrix = (int**)malloc(vertices * sizeof(int*));
    if (graph->adjMatrix == NULL) {
        perror("Failed to allocate memory for adjacency matrix rows");
        free(graph);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < vertices; i++) {
        graph->adjMatrix[i] = (int*)calloc(vertices, sizeof(int)); // Initialize with zeros
        if (graph->adjMatrix[i] == NULL) {
            perror("Failed to allocate memory for adjacency matrix columns");
            // Free previously allocated rows
            for (int j = 0; j < i; j++) {
                free(graph->adjMatrix[j]);
            }
            free(graph->adjMatrix);
            free(graph);
            exit(EXIT_FAILURE);
        }
    }
    return graph;
}

// Function to add an edge to the graph (undirected)
void addEdge(Graph* graph, int src, int dest) {
    if (src < 0 || src >= graph->vertices || dest < 0 || dest >= graph->vertices) {
        printf("Invalid vertices for adding edge: %d or %d\n", src, dest);
        return;
    }
    graph->adjMatrix[src][dest] = 1; // Mark edge from src to dest
    graph->adjMatrix[dest][src] = 1; // Mark edge from dest to src (for undirected graph)
}

// Function to display the adjacency matrix
void displayAdjMatrix(Graph* graph) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->vertices; i++) {
        for (int j = 0; j < graph->vertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to free the allocated memory for the graph
void freeGraph(Graph* graph) {
    if (graph == NULL) return;
    if (graph->adjMatrix != NULL) {
        for (int i = 0; i < graph->vertices; i++) {
            free(graph->adjMatrix[i]);
        }
        free(graph->adjMatrix);
    }
    free(graph);
}

int main() {
    int numVertices = 6; // Define the number of vertices

    // Create a graph with 6 vertices
    Graph* graph = createGraph(numVertices);

    // Add some edges (example)
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);

    // Display the adjacency matrix
    displayAdjMatrix(graph);

    // Free the allocated memory
    freeGraph(graph);

    return 0;
}