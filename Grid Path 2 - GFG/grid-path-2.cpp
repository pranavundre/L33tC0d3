//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    public:
    int mod = (int)(1000000007);
    int totalWays(int n, int m, vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return 0;
        grid[0][0] = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i==0 && j==0) continue;
                else if(grid[i][j]==1) grid[i][j] = 0;
                else{
                    int up = i==0 ? 0 : grid[i-1][j];
                    int left = j==0 ? 0 : grid[i][j-1];
                    grid[i][j] = (up + left) % mod;
                }
            }
        }
        return grid[n-1][m-1];
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < m; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.totalWays(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends