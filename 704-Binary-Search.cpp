class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1, m;
        while(l < r){
            m = (l+r)/2;
            if(nums[m] == target) return m;
            if(nums[m] > target) r = m;
            else l = m+1;
        }
        if(nums[l] == target) return l;
        return -1;
    }
};
