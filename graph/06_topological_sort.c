#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 40  // Assume 40 nodes at max in graph
#define INT_MIN 0
// A vertex of the graph
struct node
{
    int vertex;
    struct node *next;
};
// Some declarations
struct node *createNode(int v);
struct Graph
{
    int numVertices;
    int *visited;
    struct node *
        *adjLists;  // we need int** to store a two dimensional array. Similary,
                    // we need struct node** to store an array of Linked lists
};
// Structure to create a stack, necessary for topological sorting
struct Stack
{
    int arr[MAX_SIZE];
    int top;
};
struct Graph *createGraph(int);
void addEdge(struct Graph *, int, int);
void printGraph(struct Graph *);
void topologicalSortIterative(struct Graph *);
struct Stack *createStack();
void push(struct Stack *, int);
int pop(struct Stack *);

int main()
{
    int vertices, edges, i, src, dst;
    printf("Enter the number of vertices\n");
    scanf("%d", &vertices);
    struct Graph *graph = createGraph(vertices);
    printf("Enter the number of edges\n");
    scanf("%d", &edges);
    for (i = 0; i < edges; i++)
    {
        printf("Edge %d \nEnter source: ", i + 1);
        scanf("%d", &src);
        printf("Enter destination: ");
        scanf("%d", &dst);
        addEdge(graph, src, dst);
    }
    printf("One topological sort order is:\n");
    topologicalSortIterative(graph);
    printf("\n");

    // Uncomment below part to get a ready-made example
    /*struct Graph* graph2 = createGraph(4);
    addEdge(graph2, 0, 1);
    addEdge(graph2, 0, 2);
    addEdge(graph2, 1, 2);
    addEdge(graph2, 2, 3);
    printf("One topological sort is:\n");
    topologicalSort(graph2);
    printf("\n");*/
    return 0;
}

// Assuming standard definitions for Node, Graph, and Stack are present

void topologicalSortIterative(struct Graph *graph)
{
    // The final output stack (just like in your recursive version)
    struct Stack *outputStack = createStack();
    
    // A temporary stack to manage our iterative DFS traversal
    struct Stack *traversalStack = createStack();

    int i;
    for (i = 0; i < graph->numVertices; i++)
    {
        if (graph->visited[i] == 0)
        {
            // Push the starting vertex of a component
            push(traversalStack, i);

            while (traversalStack->top != -1)
            {
                // Peek the top element without popping it yet
                int currentVertex = traversalStack->arr[traversalStack->top];

                // Case 1: First time seeing this node
                if (graph->visited[currentVertex] == 0)
                {
                    graph->visited[currentVertex] = 1; // Mark as discovering

                    // Push all unvisited neighbors onto the traversal stack
                    struct node *temp = graph->adjLists[currentVertex];
                    while (temp != NULL)
                    {
                        int connectedVertex = temp->vertex;
                        if (graph->visited[connectedVertex] == 0)
                        {
                            push(traversalStack, connectedVertex);
                        }
                        temp = temp->next;
                    }
                }
                // Case 2: We've already processed its neighbors (or it had none)
                else 
                {
                    // Pop it from the traversal stack since it's fully explored
                    pop(traversalStack);
                    
                    // If it hasn't been finalized into the output yet, do it now
                    // We check a second state or handle duplication protection
                    // In a clean 2-pass/state logic, we ensure it's pushed to output exactly once:
                    if (graph->visited[currentVertex] == 1) 
                    {
                        graph->visited[currentVertex] = 2; // Mark as completely finalized
                        push(outputStack, currentVertex);
                    }
                }
            }
        }
    }

    // Print the contents of the output stack
    while (outputStack->top != -1) 
    {
        printf("%d ", pop(outputStack));
    }
    
    // Clean up local stacks if necessary
    // freeStack(traversalStack);
    // freeStack(outputStack);
}

// Allocate memory for a node
struct node *createNode(int v)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}
// Allocate memory for the entire graph structure
struct Graph *createGraph(int vertices)
{
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(struct node *));
    graph->visited = malloc(vertices * sizeof(int));

    int i;
    for (i = 0; i < vertices; i++)
    {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}
// Creates a unidirectional graph
void addEdge(struct Graph *graph, int src, int dest)
{
    // Add edge from src to dest
    struct node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}
// Utility function to see state of graph at a given time
void printGraph(struct Graph *graph)
{
    int v;
    for (v = 0; v < graph->numVertices; v++)
    {
        struct node *temp = graph->adjLists[v];
        printf("\n Adjacency list of vertex %d\n ", v);
        while (temp)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}
// Creates a stack
struct Stack *createStack()
{
    struct Stack *stack = malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}
// Pushes element into stack
void push(struct Stack *stack, int element)
{
    stack->arr[++stack->top] =
        element;  // Increment then add, as we start from -1
}
// Removes element from stack, or returns INT_MIN if stack empty
int pop(struct Stack *stack)
{
    if (stack->top == -1)
        return INT_MIN;
    else
        return stack->arr[stack->top--];
}


/*
Enter the number of vertices
6
Enter the number of edges
6
Edge 1 
Enter source: 0
Enter destination: 1
Edge 2 
Enter source: 2
Enter destination: 3
Edge 3 
Enter source: 4
Enter destination: 5
Edge 4 
Enter source: 2
Enter destination: 5
Edge 5 
Enter source: 1
Enter destination: 4
Edge 6 
Enter source: 3
Enter destination: 4
One topological sort order is:
2 3 0 1 4 5 
*/