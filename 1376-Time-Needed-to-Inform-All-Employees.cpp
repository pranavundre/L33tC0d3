class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        queue<int> q;
        q.push(headID);
        int time = 0;
        for(int i = 0; i < n; i++) if(manager[i] != -1) adj[manager[i]].push_back(i);
        while(!q.empty()){
            int temp = q.front(), currT = informTime[temp];
            q.pop();
            for(int i : adj[temp]) {
                q.push(i);
                informTime[i] += currT;
                time = max(time, informTime[i]);
            }
        }
        return time;
    }
};
