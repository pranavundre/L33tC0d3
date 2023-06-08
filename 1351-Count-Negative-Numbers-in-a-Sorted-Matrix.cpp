class Solution {
public:
    int binSearch(vector<int> vec, int l, int r){
        while(l < r){
            int mid = (l+r)>>1;
            if(vec[mid] < 0){
                if(mid == 0 || vec[mid-1] >= 0) return mid;
                r = mid;
            }
            else l = mid+1;
        }
        return vec[l] < 0 ? l : l+1;
    }
    
    int countNegatives(vector<vector<int>>& grid) {
        int lastNeg = 0, n = grid.size(), m = grid[0].size(), count = 0;
        for(int i = n-1; i >= 0; i--){
            lastNeg = binSearch(grid[i], lastNeg, m-1);
            if(lastNeg == m) break;
            int temp = m - lastNeg;
            count += temp;
        }
        return count;
    }
};
