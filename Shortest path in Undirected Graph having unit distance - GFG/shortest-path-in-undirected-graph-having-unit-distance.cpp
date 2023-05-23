//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<vector<int>> adj(N);
        vector<int> dist(N, INT_MAX), vis(N, 0);
        queue<int> q;
        q.push(src);
        dist[src] = 0;
        vis[src] = 1;
        
        for(auto p : edges){
            adj[p[0]].emplace_back(p[1]);
            adj[p[1]].emplace_back(p[0]);
        }

        while(!q.empty()){
            // int size = q.size();
            int temp = q.front();
            q.pop();
            for(int i : adj[temp]){
                dist[i] = min(dist[i], 1 + dist[temp]);
                if(vis[i]++ == 0) q.push(i);
            }
        }
        
        for(int i = 0; i < N; i++){
            if(vis[i] == 0) dist[i] = -1;
        }
        
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends