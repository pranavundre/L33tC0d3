class Solution {
public:
    void bfs(vector<vector<int>>& graph, vector<int>& vis, int node){
        queue<int> q;
        q.emplace(node);
        vis[node]++;
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            for(int i = 0; i < graph[temp].size(); i++) if(graph[temp][i] == 1 && vis[i]++ == 0) q.emplace(i);
        }
    }
    int findCircleNum(vector<vector<int>>& graph) {
        vector<int> vis(graph.size(), 0);
        int res = 0;
        for(int i = 0; i < vis.size(); i++) if(vis[i] == 0 && ++res) bfs(graph, vis, i);
        return res;
    }
};
