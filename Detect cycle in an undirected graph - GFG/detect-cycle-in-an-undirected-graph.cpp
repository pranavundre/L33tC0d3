//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    void checkDFS(vector<int> adj[], vector<int>& vis, int &index, bool &loop){
        int visCount = 0;
        for(int i : adj[index]){
            if(vis[i] != 0) visCount++;
        }
        if(visCount > 1){
            loop = true;
            return;
        }
        for(int i : adj[index]){
            if(vis[i]++ == 0){
                checkDFS(adj, vis, i, loop);
            }
        }
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        for(int i = 0; i < V; i++){
            if(vis[i]++ == 0){
                bool loop = false;
                checkDFS(adj, vis, i, loop);
                if(loop) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends