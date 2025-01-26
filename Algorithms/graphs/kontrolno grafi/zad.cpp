#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

using p = pair<int, int>;
using level = pair<p, int>;

const int DX[4] = {1, -1, 0, 0};
const int DY[4] = {0 , 0, 1, -1};

//int N, M = 600;
bool visited[600][600];
string matrix[600];

bool inBound(int x, int y, int r,int c) {
    return x>=0 && x<r && y >=0 && y <c;
}
int bfs(const p& source, std::vector<p> endgame, bool** visited,int r,int c)
{
    // Add source vertex to the queue
    std::queue<level> q; //coordinates and path size
    q.push({source, 0});

    // Mark the source vertex as used
    visited[source.first][source.second] = true;

    while (!q.empty())
    {
        level current = q.front();
        printf("%d %d", current.first, current.second);
        cout<<endl;
        int level_path = current.second;
        q.pop();

        //printf("%d ", u); // Print the bfs traversal
        for(p end : endgame) {
        if(current.first.first == end.first && current.first.second ==end.second) {
            //cout<<level_path;
            //cout<<endl;
            return level_path;
        }
        }

        int row = current.first.first;
        int column = current.first.second;
        //cout<<row<<" "<<column<<endl;
        // Traverse all adjecent to U vertices
        for (int v = 0; v < 4; v++)
        {
            if ( inBound(row+DX[v],column+DY[v],r,c) &&  !visited[row+DX[v]][column+DY[v]] && matrix[row+DX[v]][column+DY[v]] == '.')
            {   
                //cout<<row+DX[v]<<" "<<column+DY[v]<<endl;
                q.push({{row+DX[v],column+DY[v]}, level_path+1});
                visited[row+DX[v]][column+DY[v]] = true;
            }
        }
    }

    return 0;    
}

void re(bool** matrix, int r, int c){
    for(int i = 0; i< r; i++) {
        for(int j = 0; j< c; j++) {
            matrix[i][j] = false;
        }
    }
}

int solve(int rows, int columns, std::vector<p> food) {
    int result = 0;
    bool** visited = new bool*[rows];
    for(int i = 0; i<rows; i++) {
        visited[i] = new bool[columns];
    }

    for(int i = 0; i <rows; i++) {
        for(int j = 0; j <columns; j++) {
            //cout<<i<<" "<<j;
            if(matrix[i][j] == '.') {
                result += bfs({i,j}, food, visited, rows, columns);
                re(visited,rows,columns);
            }
        }   
    }

    //cout<<result;
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k;
    scanf("%d %d %d", &n,&m,&k);

    for(short i = 0; i <n; i++) {
        cin>>matrix[i];
    }

    vector<p> food;
    int fst, snd;
    for(int i = 0; i<k; i++) {
        scanf("%d %d", &fst, &snd);
        food.push_back({fst-1, snd-1});
    }


    cout<<solve( n, m, food);
    return 0;
}