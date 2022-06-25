class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int c = 0;
        
        if(nums.size()<=2)
            return true;
        
        if(nums[nums.size()-1] < nums[nums.size()-2]){
            nums[nums.size()-1] = nums[nums.size()-2];
            c++;
        }
        
        for(int i = nums.size()-1; i > 0; i--){
            if(nums[i]<nums[i-1]){
                if(nums[i-1] < nums[i+1])
                    nums[i] = nums[i-1];
                else // if(nums[i-1] > nums[i+1])
                    nums[i-1] = nums[i];
                c++;
                if(c>1)
                    return false;
            }
            if(c>1)
                return false; 
        }
        
        return true;
        
    }
};
        // for(int i = 0; i < nums.size()-1; i++){
        //     if(nums[i]>nums[i+1]){
        //         if(nums[i]>nums[i+2])
        //             nums[i] = nums[i+1];
        //         else
        //             nums[i+1]=nums[i];
        //         c++;
        //         i=i-2;
        //     }
        //     if(c>1)
        //         return false;
        // }
        // return true;