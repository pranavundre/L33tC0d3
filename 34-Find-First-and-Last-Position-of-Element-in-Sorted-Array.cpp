class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size(), l = 0, r = n-1;
        vector<int> ret(2, -1);
        while(r >= 0 && l <= r  && ret[0] == -1){
            int mid = (l+r)/2;
            if(nums[mid] == target){
                if(mid == 0 || nums[mid-1] != target) ret[0] = mid;
                r = mid - 1;
            }
            if(nums[mid] < target) l = mid + 1;
            if(nums[mid] > target) r = mid - 1;
        }
        l = ret[0], r = n-1;
        while(l >= 0 && l <= r && ret[1] == -1){
            int mid = (l+r)/2;
            if(nums[mid] == target){
                if(mid == n-1 || nums[mid+1] != target) ret[1] = mid;
                l = mid + 1;
            }
            if(nums[mid] > target) r = mid - 1;
        }
        if(ret[1] == -1) ret[1] = l;
        return ret;
    }
};
