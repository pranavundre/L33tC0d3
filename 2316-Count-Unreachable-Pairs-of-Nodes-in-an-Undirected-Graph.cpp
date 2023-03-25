class Solution {
public:
    void dfs(int node, long long &count,vector<bool>&visited,vector<int>adj[]){
        visited[node]=true;
        count++;
        for(auto it: adj[node])
            if(!visited[it]) dfs(it,count,visited,adj);
        return ;
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];// creating a adjacency list of n nodes
        for(auto it: edges){
        // since it is a undirected edge so the edges are bidirectional
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        // creating a visited vector for checking if the node is visited or not
        vector<bool>visited(n,false);
        long long ans=0;// store the ans
        long long temp=0;// store the total number of nodes in the previously visited component
        for(int i=0;i<n;i++){
            if(!visited[i]){
                long long count=0; // store the total number of node in the component
                dfs(i,count,visited,adj);
                ans+=(temp*count);// add the multiplication of total number of previously visited nodes * the total number of nodes of the current component
                temp+=count;// add the total number of nodes of the current component to temp
            }
        }
        return ans;
    }
};
