//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    private:
    vector<int> topoSort(int V, vector<vector<int>> adj) {
        vector<int> indegree(V, 0), res;
        queue<int> q;
        for(int i = 0; i < V; i++) for(int it : adj[i]) indegree[it]++;
        for(int i = 0; i < V; i++) if(indegree[i] == 0) q.push(i);
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            res.emplace_back(temp);
            for(int i : adj[temp]){
                indegree[i]--;
                if(indegree[i] == 0) q.push(i);
            }
        }
	    return res;
	}
    public:
    string findOrder(string dict[], int N, int K) {
        vector<vector<int>> adj(K);
        
        for(int i = 0; i < N-1; i++){
            string s1 = dict[i], s2 = dict[i+1];
            int len = min(s1.size(), s2.size()), p;
            for(p = 0; p < len; p++)
                if(s1[p] != s2[p]) {
                    adj[s1[p]-'a'].push_back(s2[p] - 'a');
                    break;
                }
        }
        
        vector<int> res = topoSort(K, adj);
        
        string order = "";
        for(auto i : res) order += char('a' + i);
        
        return order;
    }
};


//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends