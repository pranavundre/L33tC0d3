class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size(), ans = nums[0];
        priority_queue<pair<int, int>> maxh;
        maxh.push({nums[0], 0});
        for(int i = 1; i < n; i++){
            while(maxh.top().second < i - k)  maxh.pop();
            nums[i] = max(nums[i], nums[i] + maxh.top().first);
            maxh.push({nums[i], i});
            ans = max(ans, nums[i]);
        }
        return ans;
    }
};
