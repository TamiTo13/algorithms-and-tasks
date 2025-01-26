#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using Graph = std::vector<std::vector<int>>;

std::unordered_set<int> BFS(int s, const Graph& graph)
{
    // Mark all the vertices as not visited
    std::unordered_set<int> visited;
 
    // Create a queue for BFS
    std::queue<int> queue;
 
    // Mark the current node as visited and enqueue it
    visited.emplace(s-1);
    queue.push(s-1);
 
    while (!queue.empty()) {
        // Dequeue a vertex from queue and print it
        int curr = queue.front();
        std::cout << curr << " ";
        queue.pop();
 
        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (int adjecent : graph[curr]) {
            if (visited.find(adjecent) == visited.end()) {
                //std::cout<<adjecent;
                visited.emplace(adjecent);
                queue.push(adjecent);
            }
        }
        std::cout<<std::endl;
    }

    return visited;
}


 int getMinComponents(const Graph& graph,const int* values) {

    int result = 0;
    std::unordered_set<int> nodes;

    for(int i = 0; i<graph.size(); i++) {
        nodes.emplace(i);
    }
    
    
    while(!nodes.empty())
    {
        auto point = nodes.begin();
        std::unordered_set<int> current = BFS(*point, graph);
        int currentMin = *point;
        //std::cout<<currentMin<<" ";

        for(int number: current) {
            if(number < currentMin) currentMin = number;
            nodes.erase(number);
        }

        result += values[currentMin - 1];
        //std::cout<<result<<" ";
    }

    return result;
 }



int main() {
    Graph graph;
    graph.push_back({2});
    graph.push_back({1});
    graph.push_back({4});
    graph.push_back({3});
    graph.push_back({6});
    graph.push_back({5});
    graph.push_back({8});
    graph.push_back({7});
    graph.push_back({10});
    graph.push_back({9});

    int* topValues = new int[10]{10, 60, 20, 70, 30, 80, 40, 90, 50, 100};
    
    getMinComponents(graph,topValues);

}