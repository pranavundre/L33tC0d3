class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size() <= 1)
            return nums.size();
        
        sort(nums.begin(), nums.end());
        
        int f, l, maxl = 1, s = 1;
        bool c = false;
        
        for(int i = 1; i < nums.size(); i++){
            if(nums[i]-nums[i-1] == 1){
                if(c){
                    s++;
                }else{
                    c = true;
                    s++;
                }
            }else if(nums[i]-nums[i-1] == 0){
                c = true;
            }else{
                s = 1;
                c = false;
            }
            maxl = max(maxl, s);
        }
        
        return maxl;
        
    }
};