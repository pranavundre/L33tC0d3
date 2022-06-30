class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int ret = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()/2; i++)
            ret = ret + (nums[nums.size() - 1 -i] - nums[i]);
        return ret;
    }
};