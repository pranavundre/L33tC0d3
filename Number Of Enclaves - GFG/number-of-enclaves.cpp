//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  vector<int> dir = {0, -1, 0, 1, 0};
    int numberOfEnclaves(vector<vector<int>> &grid) {
        queue<pair<int, int>> q;
        int m = grid.size(), n = grid[0].size(), count = 0;
        for(int i = 0; i < m; i++){
            if(grid[i][0] == 1) q.push({i, 0});
            if(grid[i][n-1] == 1) q.push({i, n-1});
        }
        for(int i = 1; i < n-1; i++){
            if(grid[0][i] == 1) q.push({0, i});
            if(grid[m-1][i] == 1) q.push({m-1, i});
        }
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            if(grid[r][c] != 1) continue;
            grid[r][c] = 0;
            for(int i = 0; i < 4; i++){
                int nr = r + dir[i];
                int nc = c + dir[i+1];
                if(nr>=0 && nc>=0 && nr<m && nc<n && grid[nr][nc] == 1) q.push({nr, nc});
            }
        }
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j] == 1) count++;
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends