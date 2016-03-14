// C++ program to find out whether a given graph is Bipartite or not    
#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

int G[10005][10005];
 
// This function returns true if graph G[V][V] is Bipartite, else false
bool isBipartite(int V, int src)
{
    // Create a color array to store colors assigned to all veritces. Vertex 
    // number is used as index in this array. The value '-1' of  colorArr[i] 
    // is used to indicate that no color is assigned to vertex 'i'.  The value 
    // 1 is used to indicate first color is assigned and value 0 indicates 
    // second color is assigned.
    int colorArr[V];
    memset(colorArr, -1, V*sizeof(int));
 
    // Assign first color to source
    colorArr[src] = 1;
 
    // Create a queue (FIFO) of vertex numbers and enqueue source vertex
    // for BFS traversal
    queue <int> q;
    q.push(src);
 
    // Run while there are vertices in queue (Similar to BFS)
    while (!q.empty())
    {
        // Dequeue a vertex from queue ( Refer http://goo.gl/35oz8 )
        int u = q.front();
        q.pop();
 
        // Find all non-colored adjacent vertices
        for (int v = 0; v < V; ++v)
        {
            // An edge from u to v exists and destination v is not colored
            if (G[u][v] && colorArr[v] == -1)
            {
                // Assign alternate color to this adjacent v of u
                colorArr[v] = not colorArr[u];
                q.push(v);
            }
 
            //  An edge from u to v exists and destination v is colored with
            // same color as u
            else if (G[u][v] && colorArr[v] == colorArr[u])
                return false;
        }
    }
 
    // If we reach here, then all adjacent vertices can be colored with 
    // alternate color
    return true;
}
 
// Driver program to test above function
int main()
{
    int V;
    scanf("%d", &V);

    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < V; ++j)
        {
            scanf("%d", &G[i][j]);
            G[i][j] = not G[i][j];
        }
    }

    isBipartite(V, 0) ? printf("Bazinga!\n") : printf("Fail!\n");
    return 0;
}