/*
 * AdjacencyListRepresentation.c
 *
 *  Created on: 03-11-2025
 *      Author: saif
 * 
 * 
 * In this representation all the vertices connected to a vertex are listed on an adjencency list for that vertex v.
 * 
 * This can easily be implemented with linked lists.That means , for each vertex v we use a linked list and list nodes represents
 * the connection between v and other vertices to which v has an edge.
*/



#include <stdio.h>
#include <stdlib.h>

// Structure for an adjacency list node
struct AdjListNode {
    int dest;
    struct AdjListNode* next;
};

// Structure for an adjacency list
struct AdjList {
    struct AdjListNode* head;
};

// Structure for a graph
struct Graph {
    int V; // Number of vertices
    struct AdjList* array;
};

// Function to create a new adjacency list node
struct AdjListNode* newAdjListNode(int dest) {
    struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph of V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

    // Create an array of adjacency lists. Size V for V vertices
    graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));

    // Initialize each adjacency list as empty by making head as NULL
    for (int i = 0; i < V; ++i) {
        graph->array[i].head = NULL;
    }
    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Since the graph is undirected, add an edge from dest to src also
    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Function to print the adjacency list representation of the graph
void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->V; ++v) {
        struct AdjListNode* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl) {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

// Main function to demonstrate graph creation and printing
int main() {
    int V = 6; // Number of vertices
    struct Graph* graph = createGraph(V);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5); // Adding an edge to the 6th vertex (index 5)
    addEdge(graph, 2, 5); // Another edge involving the 6th vertex

    // Print the adjacency list representation
    printGraph(graph);

    // Free allocated memory (important for preventing memory leaks)
    for (int i = 0; i < V; ++i) {
        struct AdjListNode* current = graph->array[i].head;
        struct AdjListNode* next;
        while (current != NULL) {
            next = current->next;
            free(current);
            current = next;
        }
    }
    free(graph->array);
    free(graph);

    return 0;
}