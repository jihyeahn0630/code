#include <iostream>
#include <vector>
#include <string>
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n, m;
int go(vector<string> &board, vector<bool> &check, int x, int y) {
    int ans = 0;
    for (int k=0; k<4; k++) {
         int nx = x+dx[k];
         int ny = y+dy[k];
 
		
        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            if (check[board[nx][ny]-'A'] == false) {
             check[board[nx][ny]-'A'] = true;
             int next = go(board, check, nx, ny);
             if (ans < next) {
                 ans = next;
                 }
             check[board[nx][ny]-'A'] = false;
             }
         }
     }
     return ans + 1;
}

int main() {
   
     cin >> n >> m;
     vector<string> board(n);
    
     for (int i=0; i<n; i++) {
         cin >> board[i];
     }
    
     vector<bool> check(26);
     check[board[0][0]-'A'] = true;
     cout << go(board, check, 0, 0) << endl;
 
    return 0;
}
