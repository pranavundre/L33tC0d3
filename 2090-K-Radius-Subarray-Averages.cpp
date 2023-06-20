class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        long long prevSum = 0, n = nums.size(), window = 2*k + 1;
        vector<int> result(n, -1);
        if(n < window) return result;

        for(int i = 0; i <= n; i++)
            if(i < window) prevSum += nums[i];
            else{
                result[i-k-1] = prevSum/window;
                if(i < n) prevSum += (nums[i] - nums[i - window]);
            }

        return result;
    }
};
