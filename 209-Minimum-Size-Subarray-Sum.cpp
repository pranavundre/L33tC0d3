class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0, n = nums.size(), lasti = 0, minl = INT_MAX;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            while(sum >= target) sum -= nums[lasti++];
            if(lasti != 0)sum += nums[--lasti];
            if(sum >= target) minl = min(minl, i - lasti + 1);
        }
        return minl == INT_MAX ? 0 : minl;
    }
};
