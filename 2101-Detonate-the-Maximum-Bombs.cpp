class Solution {
public:
    int bfs(vector<vector<int>> adj, int index, vector<int> vis){
        queue<int> q;
        q.push(index);
        vis[index]++;
        int node = 1;

        while(!q.empty()){
            int temp = q.front();
            q.pop();
            
            for(int i : adj[temp]){
                if(vis[i]++ == 0){
                    node++;
                    q.push(i);
                }
            }
        }
        return node;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++){
            long long x1 = bombs[i][0], y1 = bombs[i][1], r1 = bombs[i][2];
            for(int j = 0; j < n; j++){
                if(i != j){
                    long long x2 = abs(x1 - bombs[j][0]), y2 = abs(y1 - bombs[j][1]);
                    if(x2*x2 + y2*y2 <= r1*r1) adj[i].push_back(j);
                }
            }
        }

        vector<int> vis(n, 0);
        int maxCount = INT_MIN;

        for(int i = 0; i < n; i++){
            int count = bfs(adj, i, vis);
            maxCount = max(count, maxCount);
        }

        return maxCount;
    }
};
