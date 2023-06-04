//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges, int dt) {
        
        vector<vector<int>> matrix(n, vector<int> (n, 1e9));
        
        for(auto vec: edges) matrix[vec[0]][vec[1]] = matrix[vec[1]][vec[0]] = vec[2];
        
        for(int i = 0; i < n; i++) matrix[i][i] = 0;

        for(int a = 0; a < n; a++)
    	    for(int i = 0; i < n; i++)
    	        for(int j = 0; j < n; j++)
    	            matrix[i][j] = min(matrix[i][j], matrix[i][a] + matrix[a][j]);

        int minCity = INT_MAX, res;
        for(int i = 0; i < n; i++){
            int neighb = 0;
            for(int j = 0; j < n; j++) if(matrix[i][j] <= dt) neighb++;
            if(neighb <= minCity) {
                minCity = neighb;
                res = i;
            }
        }

        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends