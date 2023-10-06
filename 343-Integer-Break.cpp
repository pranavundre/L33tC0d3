class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 1);
        for(int i = 2; i <= n; i++) 
            for(int j = i-1; j >= i/2; j--) 
                dp[i] = max(dp[i], max(dp[j]*(i-j), j*(i-j)));
        return dp[n];
    }
};
