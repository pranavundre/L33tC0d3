//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    vector<int> dir = {0, -1, 0, 1, 0};
    
    void dfs(vector<vector<int>>& grid, int r, int c, int r0, int c0, vector<pair<int, int>> &vec) {
        int m = grid.size(), n = grid[0].size();
        
        grid[r][c] = 0;
        vec.push_back({r0-r, c0-c});  
        
        for (int i = 0; i < 4; i++) {
            int nr = r + dir[i];
            int nc = c + dir[i + 1];
            
            if (nr >= 0 && nc >= 0 && nr < m && nc < n && grid[nr][nc] == 1) {
                dfs(grid, nr, nc, r0, c0, vec);
            }
        }
    }
    
    int countDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        set<vector<pair<int, int>>> st;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    vector<pair<int, int>> temp;
                    dfs(grid, i, j, i, j, temp);
                    st.insert(temp);
                }
            }
        }
        
        return st.size();
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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends