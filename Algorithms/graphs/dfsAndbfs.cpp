#include <cstdio>
#include <vector>
#include <queue>


const int MAX_VERTICES = 100000;
const int SOURCE = 1;

int n, m;
std::vector<int> adjList[MAX_VERTICES + 1];
bool visited[100000 + 1];


void dfs(int u)
{
    // Mark the current vertex as visited
    visited[u] = true;
    printf("%d ", u); // Print the dfs traversal

    // Traverse all adjecent to U vertices
    for (int v : adjList[u])
    {
        // Go recursively in V if it is NOT visited
        if (!visited[v])
        {
            dfs(v);
        }
    }
}


void bfs(int source)
{
    // Add source vertex to the queue
    std::queue<int> q;
    q.push(source);

    // Mark the source vertex as used
    visited[source] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        printf("%d ", u); // Print the bfs traversal

        // Traverse all adjecent to U vertices
        for (int v : adjList[u])
        {
            // Add V to the queue if it is NOT used
            if (!visited[v])
            {
                q.push(v);
                visited[v] = true;
            }
        }
    }    

}