//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    bool checkDFS(vector<int> adj[], vector<int>& visited, int index) {
        visited[index] = 1;
        
        for (int i : adj[index]) {
            if (visited[i] == 1) {
                return true;  // Cycle detected
            }
            else if (visited[i] == 0 && checkDFS(adj, visited, i)) {
                return true;
            }
        }
        
        visited[index] = 2;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> visited(V, 0);  // 0: unvisited, 1: visiting, 2: visited
        
        for (int i = 0; i < V; i++) {
            if (visited[i] == 0 && checkDFS(adj, visited, i)) {
                return true;
            }
        }
        
        return false;
    }
};




//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends