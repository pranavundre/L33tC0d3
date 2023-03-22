/*
Approach : 
We need to traverse the graph starting from 1 to all connected node and get the shortest path linked to each node we visit.
No need to worry about target, as it is given that there must be a ptah to the target.

Algo:
1. Create a weighted graph.
2. Run BFS from 1
3. which every node encountered, check for all the path liked to the nodes for sortest one; irrespective of it is got visited or not.

*/

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        int ans = INT_MAX; 
        //create a weighted graph
        vector<vector<pair<int, int>>> g(n + 1);
        for(auto r: roads){
            g[r[0]].push_back({r[1], r[2]});
            g[r[1]].push_back({r[0], r[2]});
        }
        vector<int> vis(n+1, 0);
        queue<int> q;
        q.push(1); vis[1] = 1;    //run bfs from 1
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            for(auto i: g[node]){
                ans = min(ans, i.second);   //check for min path length
                if(vis[i.first] != 1){
                    vis[i.first] = 1;
                    q.push(i.first);
                }
            }
        }
        return ans;
    }
};
