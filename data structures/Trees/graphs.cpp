#include <iostream>
#include <vector>
#include <unordered_map>

// struct Vertex {
//     char label;
//     std::vector<Vertex> adj; 
// };


using Graph = std::unordered_map<char, std::vector<char>>;

bool isPath(std::string word, const Graph& graph, char current, bool& found) {

    if(word.empty()) 
            found = true;

    const auto& pointer = graph.find(current);

    if(pointer != graph.end() && !word.empty())
    {
        for(const char ver:pointer->second)
        {
            if(ver == word[0]) {
                return isPath(word.substr(1), graph, ver, found);
            }
        }
    }

    return found;
}
