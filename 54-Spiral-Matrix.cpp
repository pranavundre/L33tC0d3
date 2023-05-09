class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size(), n = matrix[0].size(), r = 0, c = 0, dir = 0;
        if(m==1) return matrix[0];
        if(n==1){
            for(int i = 0; i < m; i++) res.emplace_back(matrix[i][0]);
            return res;
        }
        while(res.size() != m*n){
            if(dir++%4 == 0){
                while(c<n){
                    if(matrix[r][c] == -101) break;
                    res.emplace_back(matrix[r][c]);
                    matrix[r][c++] = -101;
                }
                c--;
                r++;
            }
            if(dir++%4 == 1){
                while(r<m){
                    if(matrix[r][c] == -101) break;
                    res.emplace_back(matrix[r][c]);
                    matrix[r++][c] = -101;
                }
                r--;
                c--;
            }
            if(dir++%4 == 2){
                while(c>=0){
                    if(matrix[r][c] == -101) break;
                    res.emplace_back(matrix[r][c]);
                    matrix[r][c--] = -101;
                }
                c++;
                r--;
            }
            if(dir++%4 == 3){
                while(r>=0){
                    if(matrix[r][c] == -101) break;
                    res.emplace_back(matrix[r][c]);
                    matrix[r--][c] = -101;
                }
                r++;
                c++;
            }
        }
        return res;
    }
};
