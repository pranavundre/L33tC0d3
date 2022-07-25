class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret(2, -1);
        if(nums.size()==0)
            return ret;
        
        for(int i = 0; i < nums.size(); i++)
            if(nums[i]==target){
                ret[0] = i;
                ret[1] = i;
                break;
            }
        
        for(int i = nums.size()-1; i >= 0; i--)
            if(nums[i]==target){
                ret[1]=i;
                break;
            }
        
        return ret;
    }
};