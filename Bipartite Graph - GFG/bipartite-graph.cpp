//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    bool check(vector<int>adj[], vector<int> &color, int index){
        queue<int> q;
        q.push(index);
        color[index] = 0;
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            for(int i : adj[temp])
                if(color[i] == -1){
                    q.push(i);
                    color[i] = !color[temp];
                }
                else if(color[temp] == color[i]) return false;
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
        vector<int> color(V, -1);
        for(int i = 0; i < V; i++) if(color[i] == -1 && !check(adj, color, i)) return false;
        return true;
	}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends