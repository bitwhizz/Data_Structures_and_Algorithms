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
    int vertex;
    struct AdjListNode* next;
};

// Structure for a graph
struct Graph {
    int num_vertex; // Number of vertices
    struct AdjListNode** adjlist;
};

// Function to create a new adjacency list node
struct AdjListNode* newAdjListNode(int vertex) {
    struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph of num_vertex vertices
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

// Function to print the adjacency list representation of the graph
void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->num_vertex; ++v) {
        struct AdjListNode* pCrawl = graph->adjlist[v];
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl) {
            printf("-> %d", pCrawl->vertex);
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
        struct AdjListNode* current = graph->adjlist[i];
        struct AdjListNode* next;
        while (current != NULL) {
            next = current->next;
            free(current);
            current = next;
        }
    }
    free(graph->adjlist);
    free(graph);

    return 0;
}


/*
  Adjacency list of vertex 0
 head -> 4-> 1

 Adjacency list of vertex 1
 head -> 4-> 3-> 2-> 0

 Adjacency list of vertex 2
 head -> 5-> 3-> 1

 Adjacency list of vertex 3
 head -> 4-> 2-> 1

 Adjacency list of vertex 4
 head -> 5-> 3-> 1-> 0

 Adjacency list of vertex 5
 head -> 2-> 4
*/