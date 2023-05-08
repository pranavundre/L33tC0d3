class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int res = 0, i = -1, n = mat.size();
        while(++i < n) res += i == (n-i-1) ? mat[i][i] : (mat[i][i]+mat[i][n-i-1]);
        return res;
    }
};
