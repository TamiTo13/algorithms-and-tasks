/* https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/submissions/?fbclid=IwAR0FLyF7wZlUdDFQghiDDeSaGXoV8OzBnpsXuNwcZM2I1NgX2uzQgpVU9Vs*/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Solution {
    vector<int> graph[1000];
    vector<set<int>> res;
    bool used[1000];

    void dfs(int v)
    {
        used[v]=true;
        for(int u:graph[v])
        {
        if(!used[u])dfs(u);
        for(int x:res[u])res[v].insert(x);
        }
        res[v].insert(v);
    }

    set<int> merge( const set<int> &v1,const set<int> &v2)
    {
        set<int> res;
        for(int a:v1)res.insert(a);
        for(int b:v2)res.insert(b);
            return res;
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        fill(used,used+n,false);
        res=vector<set<int>> (n);
        for(auto e:edges)
       { graph[e[1]].push_back(e[0]);
       }
        for(int i=0;i<n;++i)
        {
            if(!used[i])
            dfs(i);
        }
        vector<vector<int>> final(n);
        for(int i=0;i<n;++i)
        {
            for(int x:res[i])
            if(x!=i)
            final[i].push_back(x);
        }
        return final;
    }
};