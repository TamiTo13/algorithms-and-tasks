/* https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/description/?fbclid=IwAR2_yBOPYRd4ksJLp4tUTUHbD597LFla_bJIq5G05LVvuUsHbw5T_9wJjQ4*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

struct Solution {
      
    pair<long long,long long> calc(unordered_map<int,vector<int> > & g,int v,unordered_set<int> & visited,int seats)
    {
        visited.insert(v);
        long long count=0;
        long long collected=1;
        for(long long u:g[v])
        if(!visited.count(u))
        {
            auto tmp=calc(g,u,visited,seats);
            collected += tmp.second;
            count+=tmp.first;
            count += ceil((double)tmp.second/(double)seats);
        }
        return {count,collected};
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        unordered_map<int,vector<int> > g;
        for(auto e:roads)
            {
                g[e[0]].push_back(e[1]);
                g[e[1]].push_back(e[0]);
            }
        unordered_set<int> visited;

        return calc(g,0,visited,seats).first;
    }
};