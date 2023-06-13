class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        map<string, pair<int, int>> mp;
        for(int i = 0; i < n; i++){
            string row = "", col = "";
            for(int j = 0; j < n; j++) {
                row += to_string(grid[i][j]) + ".";
                col += to_string(grid[j][i]) + ".";
            }
            mp[row].first++;
            mp[col].second++;
        }
        int count = 0;
        for(auto p : mp) count += p.second.first*p.second.second;
        return count;
    }
};
