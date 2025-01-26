#include <iostream>
#include <vector>
#include <unordered_map>


using Graph = std::unordered_map<std::string,
                                    std::unordered_map<char, std::string>>;

struct Node {
    int data;
    std::vector<Node*> children;
};

void findCheapestPath (
    Node* current,
    int currSum,
    std::vector<Node*>& currPath,
    int& minSum,
    std::vector<Node*>& minPath ) 
{
    if ( !current )
        return;
          
    currSum += current->data;
    currPath.push_back( current );

    if ( current->children.empty() )
    {
        if ( currSum < minSum )
        {
            minPath  = currPath;
            minSum   = currSum;
        }
    }
    else
    {
        for ( size_t i = 0; i < current->children.size(); i++ )
        {
            Node* child =current->children[ i ];

            findCheapestPath( child, currSum, currPath, minSum, minPath );
        }
    }

    currPath.pop_back();
}


void FindAllPaths(std::string name, std::string current,
                                         const Graph& city, std::vector<std::string>& outPlaces) {
    
    const auto& point = city.find(current);
    bool found_path = false;

    if(point != city.end() && !name.empty())
    {
        for(const auto& edge: point ->second)
        {
            if(name[0] == edge.first)
            {
                found_path = true;
                FindAllPaths(name.substr(1), edge.second, city, outPlaces);
            }
        }   
    }

     if (!found_path) 
            outPlaces.push_back(current);
}


int main() {

}