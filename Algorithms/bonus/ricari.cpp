//Рицари от Арената
 
#include <iostream>
#include <queue>
using namespace std;
 
int n, m, k, x, y, xE, yE;
int board[2001][2001];
queue<pair<int, int>> adj;
int hx[] = {2, 2, -2, -2, 1, -1, 1, -1};
int hy[] = {1, -1, 1, -1, 2, 2, -2, -2};
 
int main(){
    cin >> n >> m >> k;
 
    for(int i = 0; i < m; ++i){
        cin >> x >> y;
        board[x][y] = -1;
    }
 
    for(int i = 0; i < k; ++i){
        cin >> x >> y;
        board[x][y] = 1;
    }
 
    cin >> xE >> yE;
 
    board[xE][yE] = -1;
    adj.push({xE, yE});
    int ans = 1, dist = 0, count = 0, res = 0;
 
    while (!adj.empty()){
        x = adj.front().first;
        y = adj.front().second;
        adj.pop();
        --ans;
 
        for(int i = 0; i < 8; ++i){
            int rX = x + hx[i];
            int rY = y + hy[i];
 
            if(rX >= 0 && rY >= 0 && rX < n &&
               rY < n && board[rX][rY] >= 0){
                if(board[rX][rY] == 1){
                    res = dist + 1;
                    ++count;
                }
                board[rX][rY] = -1;
                adj.push({rX, rY});
            }
        }
 
        if(ans == 0){
            ans = adj.size();
            ++dist;
        }
    }
 
    cout << count << ' ' << res;
 
    return 0;
}