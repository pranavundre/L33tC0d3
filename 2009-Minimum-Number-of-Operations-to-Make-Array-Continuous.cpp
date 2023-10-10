class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), maxC = 0;
        queue<int> q;
        sort(nums.begin(), nums.end());
        for(int i : nums){
            while(!q.empty() && q.front() <= i - n) q.pop();
            if(q.empty() || q.back() != i) q.push(i);
            maxC = max(maxC, static_cast<int>(q.size()));
        }
        return n - maxC;
    }
};
