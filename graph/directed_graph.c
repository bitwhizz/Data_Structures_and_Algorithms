/*
The values of matrix are boolean. Let us assume
the matrix is Adj. The value Adj[u, v] is set to 1 if there is an edge from vertex u to vertex v and 0
otherwise.
In the matrix, each edge is represented by two bits for undirected graphs. That means, an edge
from u to v is represented by 1 value in both Adj[u,v ] and Adj[u,v].

If the graph is a directed graph then we need to mark only one entry in the adjacency matrix.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Graph
{
  int V;
  int E;
  int **Adj;
};

//The code reads a graph with adjacency matrix representations
struct Graph *adjMatrixofGraph(void)
{
  int i=0,u=0,v=0;
  struct Graph *G = (struct Graph*)malloc(sizeof(struct Graph));

  if(!G){
    printf("Memory Error");
    return 0;
  }
  printf("Number of Verticies:");
  scanf("%d",&G->V);
  printf("Number of Verticies:");
  scanf("%d",&G->E);
  printf("G->V %d\n",G->V);
  printf("G->E %d\n",G->E);

  G->Adj = (int **)malloc(sizeof(G->V*G->V));

  if(!G->Adj){
    printf("Memory Error");
    return 0;
  }

  for(u=0;u<G->V;u++){
    for(v=0;v<G->V;v++){
        *((G->Adj+u)+v)=0;
    }
  }

 for(i=0;i<G->E;i++){
   //Read an edge
  printf("Reading edge u -> v:\n");
   scanf("%d",&u);
   scanf("%d",&v);
   //For unidirected graph set both the bits
      *((G->Adj+u)+v)=(int *)1;
      *((G->Adj+v)+u)=(int *)1;
 }
 for(u=0;u<G->V;u++){
   for(v=0;v<G->V;v++){
     printf("%d\t",*(int *)((G->Adj+u)+v));
   }
   printf("\n");
 }

return G;
}

int main(void)
{
  printf("start\n");
  struct Graph *M =  (struct Graph*)adjMatrixofGraph();
  printf("\n");
  for(int u=0;u<M->V;u++){
    for(int v=0;v<M->V;v++){
      printf("%d\t",*(int *)((M->Adj+u)+v));
    }
    printf("\n");
  }

  return 0;
}

/*
The adjacency matrix representation is good if the graphs are dense.

The matrix requires O(V2)
bits of storage and O(V2) time for initialization.

*/
