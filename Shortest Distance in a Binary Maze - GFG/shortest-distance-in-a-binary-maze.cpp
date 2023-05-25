//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    public:
    vector<int> dir{0, 1, 0, -1, 0};
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        vis[source.first][source.second] = 1;
        
        queue<pair<int, int>> q;
        q.push(source);
        int dist = -1;
        
        while(!q.empty()){
            int size = q.size();
            dist++;
            while(size--){
                auto p = q.front();
                q.pop();
                
                if(p == destination) return dist;
                int r = p.first;
                int c = p.second;
                
                for(int i = 0; i < 4; i++){
                    int nr = r + dir[i];
                    int nc = c + dir[i+1];
                    
                    if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc] == 1 && vis[nr][nc]++ == 0){
                        q.push({nr, nc});
                    }
                }
            }
        }
        
        return -1;
        
        
        
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends