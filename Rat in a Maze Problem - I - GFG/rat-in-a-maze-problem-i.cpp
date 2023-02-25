//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    void paths(vector<vector<int>> m, vector<string>& ds, int dr[], int dc[], string temp, int r, int c){
        if(r == m.size()-1 && c == m.size()-1){
            ds.push_back(temp);
            return;
        }
        
        string dir = "DLRU";
        for(int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr>=0 && nc>=0 && nr<m.size() && nc<m.size() && m[nr][nc] == 1 && temp[temp.size()-1] != dir[3-i]){
                m[nr][nc] = -1;
                paths(m, ds, dr, dc, temp + dir[i], nr, nc);
                m[nr][nc] = 1;
            }
        }
        
        // if(r != m.size()-1 && m[r+1][c] == 1 && temp[temp.size()-1] != 'U'){
        //     m[r+1][c] = -1;
        //     paths(m, ds, temp + "D", r+1, c);
        //     m[r+1][c] = 1;
        // }
        // if(c!=0 && m[r][c-1] == 1  && temp[temp.size()-1] != 'R'){
        //     m[r][c-1] = -1;
        //     paths(m, ds, temp + "L", r, c-1);
        //     m[r][c-1] = 1;
        // }
        // if(c != m.size()-1 && m[r][c+1] == 1 && temp[temp.size()-1] != 'L'){
        //     m[r][c+1] = -1;
        //     paths(m, ds, temp + "R", r, c+1);
        //     m[r][c+1] = 1;
        // }
        // if(r!=0 && m[r-1][c] == 1 && temp[temp.size()-1] != 'D'){
        //     m[r-1][c] = -1;
        //     paths(m, ds, temp + "U", r-1, c);
        //     m[r-1][c] = 1;
        // }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ds;
        if(m[0][0] == 0) return ds;
        int dr[] = {1,0,0,-1};
        int dc[] = {0,-1,1,0};
        string temp = "";
        paths(m, ds, dr, dc, temp, 0, 0);
        return ds;
    }
};

// 0 1 1 1
// 1 1 1 0 
// 1 0 1 1 
// 0 0 1 1


    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends