//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> indegree(V, 0);
        int sumDegrees = 0;
        queue<int> q;
        for(int i = 0; i < V; i++){
            for(int it : adj[i]){
                indegree[it]++;
                sumDegrees++;
            }
        }
        for(int i = 0; i < V; i++) if(indegree[i] == 0) q.push(i);
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            for(int i : adj[temp]){
                indegree[i]--;
                sumDegrees--;
                if(indegree[i] == 0) q.push(i);
            }
        }
        return sumDegrees!=0;
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