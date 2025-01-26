#include <vector> 
#include <queue> 
#include <iostream> 
 using namespace std; 
 using PA = pair<long long, int> ;



 const int MININF=1e9;
 vector<pair<long long,int> > gr[20005]; 
 int N,M,K; 
 long long dist[20005];
 bool visited[20005];  
  
 int main() 
 { 
     cin>>N>>M>>K;

    fill(dist,dist+N+2,MININF); 
    fill(visited,visited+N+2,false); 
     
  
     int from,to,a,b; 
     for(int i=0;i<M;++i) 
     { 
         cin>>from>>to>>a>>b; 
         gr[from].push_back({to,b-a}); 
         gr[to].push_back({from,b-a}); 
     } 
  
     priority_queue< pair<long long,int> ,vector< PA > ,greater< PA > > q; 
     q.push({0,1}); 
     dist[1]=0; 
  
     while(!q.empty()) 
     { 
         int v=q.top().second; 
         q.pop(); 
         visited[v]=true; 
         for(int i=0;i<gr[v].size();++i) 
         { 
             int to=gr[v][i].first; 
             int t=gr[v][i].second;

             if(visited[to]) continue; 
             if(dist[to]>dist[v]+t) 
             { 
                 dist[to]=dist[v]+t; 
                 q.push({dist[to],to}); 
             } 
         } 
     } 
  
  
  
     cout<<K-dist[N]<<endl; 
  
  
     return 0; 
 }