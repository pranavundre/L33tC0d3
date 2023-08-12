class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> grid(m+1, vector<int> (n+1, 0));
        grid[1][1] = 1;
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
                grid[i][j] += obstacleGrid[i-1][j-1] ? -grid[i][j] : grid[i-1][j] + grid[i][j-1];
        return grid[m][n];
    }
};
