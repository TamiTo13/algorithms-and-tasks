// https://leetcode.com/problems/keys-and-rooms/ //

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:

    bool used[1001];
 
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int counter = 1;
        queue<int> q;
        for(int i = 0; i < rooms[0].size(); ++i){
            q.push(rooms[0][i]);
        }
        used[0] = true;
 
        while(!q.empty()){
            int u = q.front();
            q.pop();
            ++counter;
 
            for(int v : rooms[u]){
                if(!used[v]){
                    q.push(v);
                    used[v] = true;
                }
            }
        }
 
        if(counter != rooms.size()){
            return false;
        }
 
        return true;
    }
};