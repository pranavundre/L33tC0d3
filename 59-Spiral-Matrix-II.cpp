class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int> (n, -1));
        int i = 0, r = 0, c = 0, dir = 0;
        while(i++ < n*n){
            if(dir++%4 == 0){
                while(c<n){
                    if(res[r][c] > 0) break;
                    res[r][c++] = i++;
                }
                c--;
                r++;
            }
            if(dir++%4 == 1){
                while(r<n){
                    if(res[r][c] > 0) break;
                    res[r++][c] = i++;
                }
                r--;
                c--;
            }
            if(dir++%4 == 2){
                while(c>=0){
                    if(res[r][c] > 0) break;
                    res[r][c--] = i++;
                }
                c++;
                r--;
            }
            if(dir++%4 == 3){
                while(r>=0){
                    if(res[r][c] > 0) break;
                    res[r--][c] = i++;
                }
                i--;
                r++;
                c++;
            }
        }
        return res;
    }
};
