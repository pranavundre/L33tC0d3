class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        
        int n = nums.size(), first = 0;
        if(n==0) return res;

        vector<pair<int, int>> intv;
        for(int i = 0; i < n-1; i++){
            if(nums[i+1] != nums[i] + 1){
                intv.push_back({nums[first], nums[i]});
                first = i+1;
            }
        }
        intv.push_back({nums[first], nums[n-1]});

        for(auto p : intv){
            string temp;
            if(p.first == p.second) temp = to_string(p.first);
            else temp = to_string(p.first) + "->" + to_string(p.second);
            res.push_back(temp);
        }

        return res;
    }
};
