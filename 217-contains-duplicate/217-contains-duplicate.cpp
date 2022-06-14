class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for(int i = 0; i < nums.size(); i++)
            st.emplace(nums[i]);
        if(st.size()<nums.size())
            return true;
        return false;
    }
};