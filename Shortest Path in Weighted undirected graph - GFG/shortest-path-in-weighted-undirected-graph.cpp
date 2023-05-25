//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<vector<vector<int>>> adj(n+1);
        for(auto vec : edges){
            adj[vec[0]].emplace_back(vector<int> {vec[1], vec[2]});
            adj[vec[1]].emplace_back(vector<int> {vec[0], vec[2]});
        }
        
        vector<int> dist(n+1, INT_MAX), last(n+1, -1), res;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        pq.push({0, 1});
        dist[1] = 0;
        last[1] = 1;
        
        while(!pq.empty()){
            auto p = pq.top();
            int d = p.first, node = p.second;
            pq.pop();
            if(dist[node] < d) continue;
            for(auto vec : adj[node])
                if(vec[1] + d < dist[vec[0]]){
                    dist[vec[0]] = vec[1] + d;
                    last[vec[0]] = node;
                    pq.push({dist[vec[0]], vec[0]});
                }
        }
        
        if(last[n] == -1) return {-1};

        int node = n;
        while(last[node] != node){
            res.emplace_back(node);
            node = last[node];
        }
        res.emplace_back(1);
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends