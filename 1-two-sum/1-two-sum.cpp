class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        for(int i = 0; i < nums.size()-1; i++)
            if (count(nums.begin(), nums.end(), target-nums[i]))
                for(int j = i+1; j<nums.size(); j++)
                    if(nums[j]==(target-nums[i])){
                        ret.push_back(i);
                        ret.push_back(j);
                        return ret;
                    }
        return ret;
    }
};