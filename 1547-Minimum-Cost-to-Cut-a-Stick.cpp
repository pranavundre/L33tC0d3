class Solution {
public:
    int minCost(int n, vector<int>& A) {
        A.push_back(0);
        A.push_back(n);
        sort(begin(A), end(A));
        int N = A.size(), inf = INT_MAX;
        vector<vector<int>> dp(N, vector<int>(N, inf));
        for (int i = 0; i + 1 < N; ++i) dp[i][i + 1] = 0;
        for (int i = 0; i + 2 < N; ++i) dp[i][i + 2] = A[i + 2] - A[i];
        for (int i = N - 4; i >= 0; --i) {
            for (int j = i + 3; j < N; ++j) {
                int val = inf;
                for (int k = i + 1; k < j; ++k) val = min(val, dp[i][k] + dp[k][j]);
                dp[i][j] = val + A[j] - A[i];
            }
        }
        return dp[0][N - 1];
    }
};
