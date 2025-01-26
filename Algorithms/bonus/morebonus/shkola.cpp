//Школа от Арената
 
#include<iostream>
#include<vector>
using namespace std;
 
int n, m, q, a, b;
vector<int> adj[501];
bool visited[501];
 
void dfs(int root);
 
int main1(){
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        if(!visited[i]){
            ++ans;
            dfs(i);
        }
    }
 
    cout << ans;
 
    return 0;
}
 
void dfs(int root) {
    visited[root] = true;
 
    for(int node : adj[root]){
        if(!visited[node]){
            dfs(node);
        }
    }
}