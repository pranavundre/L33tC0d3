class Solution {
public:
    const int MOD = 1'000'000'007;
    
    int numWays(int steps, int arrLen) {
        arrLen = min(steps / 2 + 1, arrLen);
        vector<vector<int>> dp(arrLen, vector<int>(steps + 1, -1));
        return calculateWays(steps, 0, dp);
    }
    
    int calculateWays(int steps, int pos, vector<vector<int>>& dp) {
        if (steps < pos) return 0;
        if (steps == 0) return 1;
        if (dp[pos][steps] != -1) return dp[pos][steps];
        int ways = 0;
        if (pos < dp.size() - 1) ways = (ways + calculateWays(steps - 1, pos + 1, dp)) % MOD;
        if (pos > 0) ways = (ways + calculateWays(steps - 1, pos - 1, dp)) % MOD;
        ways = (ways + calculateWays(steps - 1, pos, dp)) % MOD;
        dp[pos][steps] = ways;
        return ways;
    }
};
