//Dynasty
 
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
 
std::string dynasty() {
    int n;
    std::cin >> n;
    std::unordered_map<std::string, std::string> cards;
 
    for (int i = 0; i < n; i++) {
        std::string father, son;
        std::cin >> father >> son;
        if (cards.find(son) != cards.end() && cards[son] != father) {
            return son;
        }
        cards[son] = father;
    }
 
    int max = 0;
    std::vector<std::string> result;
    std::vector<std::string> noblemanGeneration;
 
    for(const std::pair<std::string, std::string> pair : cards) {
        noblemanGeneration.push_back(pair.first);
        noblemanGeneration.push_back(pair.second);
 
        while (true) {
            if (cards.find(noblemanGeneration.back()) != cards.end()) {
                noblemanGeneration.push_back(cards[noblemanGeneration.back()]);
            } else {
                break;
            }
        }
 
        if (noblemanGeneration.size() > max) {
            max = noblemanGeneration.size();
            result.clear();
            result.push_back(noblemanGeneration.back());
        } else if (noblemanGeneration.size() == max) {
            result.push_back(noblemanGeneration.back());
        }
    }
    std::sort(result.begin(), result.end());
 
    return result.back();
 
}
 
int main() {
    std::cout << dynasty();
    return 0;
}