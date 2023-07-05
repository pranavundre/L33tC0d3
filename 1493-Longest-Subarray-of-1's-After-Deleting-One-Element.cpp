class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size(), cnt = 0, prevCnt = 0, maxl = 0;
        for(int i = 0; i <= n; i++){
            if(i == n || nums[i] == 0){
                maxl = max(maxl, cnt + prevCnt);
                prevCnt = cnt;
                cnt = 0;
            }
            else cnt++;
        }
        return maxl == n ? n-1 : maxl;
    }
};
